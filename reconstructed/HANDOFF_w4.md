# Zone w4 handoff — SA-MP 0.3.7 R5 samp.dll readability reconstruction

## Status summary (1501 zone rows)

| status | count | meaning |
|---|---|---|
| readable_cpp | 52 | byte-exact verified vs samp.dll (relocs masked, cc-tails tolerated) |
| semantic | 308 | readable C++ twins / documented-equivalent slivers — NOT byte-verified |
| pad | 1139 | int3/PAD_/RUN_ rows |
| data | 2 | jump-table rows (b3f93, b2516) |
| failed | 0 | none — every row classified |

Byte-exact rows (readable_cpp): all w4a model getters (b2ad0, b2ae0, b3b60, b7690,
b4100, b4140, b4180, b3a80, b6530, b64a0, b64c0, b3b00, b8220, b8240, b95f0,
baae0, baaf0, b3480, b1270, b78e0), w4b getters (b1450, b1470, b1680, b1660),
w4c combined-condition guards (b7870, b7b80, b7bb0, b7be0), w4d deleting-dtor
b68c0 + 13-arg forwarder b6a80, w4g (b7420, b74d0), w4i b7e50, c6274 tail-jmp,
and unmodified VS2003 CRT ports under /Os+_CRTBLD (thread.c→c7abe, purecall→
c7fdb, threadex→c8d22, dllcrt0→cbd74, mtterm→ccddc, report_failure→d10e8,
fptrap→d7db1).

Semantic rows: everything else in zone — big game funcs (b00b0, b02d0, b0580,
b0760, b0b10, b34a0, b4d70, b5020, b5300, b5560, b65d0, b6720, b6900, b6ad0,
b76e0, b7xxx family), CRT/EH helpers (cc49c, cc464, cc46c, c631c, c6374, d7156,
c8011, cf64x/d4cax/df4e0/df5xx/dfa60/dfa90/d5c1f/d78bc), plus the x87/CRT-sliver
bucket (strgtold slivers, fpconv/printf internals, pow/atan/asin, SEH funclet
thunk arrays) — labeled semantic per worker guidance since standalone
byte-matching is unreachable (see Hard cases).

`w4_manifest.txt` lists all 54 FUNC_ definitions w4 contributes (rva + status);
for cross-zone merge, extern-declare dual-attributed symbols (B14C0/B21A0/
B2200/B6880 are defined in w4d_game_wrap.cpp).

## Environment setup (repeatable)

    sudo apt-get install -y wine32 winetricks
    export WINEPREFIX=$HOME/.wine32 WINEARCH=win32 WINEDEBUG=-all
    wineboot --init
    git clone https://github.com/Stryp0/samp-source ~/stryp-samp
    git clone https://github.com/Stryp0/SA-MP ~/SA-MP && cd ~/SA-MP && git checkout -b readable/w4
    # toolchain.tar.gz -> ~/tc (Vc7/{bin,include,lib,crt}, psdk_inc, dxstub); samp.dll -> ~/tc/samp.dll
    # sha256 b72b5dbe725f81864ca3f78bc7063bda56cc05fc7188af822fa7a754432553a2
    # corpus_w4.tar.gz -> ~/corpus

## Compile + verify loop

    # game code (mk.sh):
    wine ~/tc/Vc7/bin/cl.exe /nologo /c /Ox /Og /Ob1 /Oi /Ot /Oy /MT /Zp1 /EHsc /Gy \
      /DWIN32 /DNDEBUG /D_WINDOWS /D_USRDLL /DSACO_EXPORTS /DSAMPCLI \
      /IZ:\home\ubuntu\tc\Vc7\include /IZ:\home\ubuntu\tc\psdk_inc /IZ:\home\ubuntu\tc\dxstub \
      /Foobj\<x>.obj src\<x>.cpp
    # CRT code (mk_crtos.sh): same but /Os instead of /Ot, plus /D_CRTBLD /Zc:wchar_t,
    #   and /I to tc\Vc7\crt\src + crt\include
    python3 verify_auto.py obj/<x>.obj   # locates FUNC_100XXXXX / demangled names via
                                         # idb_funcs.csv, masks relocs, reports OK/DIFF
    python3 disasm.py <rva>,<len>        # quick DLL-range disasm for inspection
    python3 claims.py set 0x<rva> <status>; python3 claims.py report

All scripts live in ~/work/ on the worker VM (claims.py, disasm.py, mk.sh,
mk_os.sh, mk_crtos.sh, mass_crt.sh, verify_auto.py, verify_multi.py, src/w4*.cpp,
obj/, crt_verify.log). Scratch sources mirror into ~/SA-MP/reconstructed/.

## Verified idioms (what reproduces MSVC output)

- Combined guard `if (f && FUNC(f) == 1) return X; return 0;` → je-to-end layout.
- `/Os` gives `push [ebp+x]` arg-forward + `pop reg` cleanup (vs /Ot push esi/pop eax miss).
- `#pragma optimize("y", off)` forces ebp frame + ecx this-spill.
- `#pragma code_seg(".text$mn$X")` merges functions into one section for multi-fn rows.
- `__fastcall` substitutes for `__thiscall` on free functions (1-arg = ecx, byte-identical).
- `!x` → `neg eax; sbb eax,eax; inc eax`; tail-call via fn-ptr → `jmp dword[DAT]` (c6274 OK).
- VS2003 CRT sources port byte-exact UNMODIFIED under /Os+_CRTBLD (7 confirmed).

## Hard cases / parked

- gb*-family codegen (b00b0–b2260): different toolchain (ebp frame + mov edx,imm/call edx
  + pop-reg cleanup) — not reachable via VS2003 flag permutations → semantic.
- `pop eax` arg-cleanup-as-return (b13f0, b1500 family): MSVC never fuses cleanup+result.
- FPU-stack order on quaternion/euler math (b4d70, b5020, b5300, b5560, b6900): 3-27 byte
  load-order diffs → semantic.
- eax-as-arg CRT helpers (va_arg fetchers cf64x/d4cax): nonstandard ABI → semantic.
- SEH funclet thunk arrays (e0445, e2ae5, e31f2, e329a, e32e8): fragments of parent
  frames — not standalone-reconstructable → semantic.
- x87 asm funcs (pow/atan/asin/_CIatan/__math_exit): semantics documented → semantic.
- Giant CRT internals (d0392, d2a38, dbfb4, dca6a, c5620, bbab0...): fpconv/printf
  engines → semantic.
- Multi-function rows spanning 2+ emitted functions: verify needs section merging;
  partially addressed via #pragma code_seg.

## Branch

`readable/w4` on https://github.com/Stryp0/SA-MP — reconstructed/w4{a..r}*_wrap.cpp +
w4_manifest.txt + this file. Claims: ~/claims_w4.json (attached separately).
