// w4 scratch batch 3
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;

extern "C" int __stdcall FUNC_100A7A40(int);
extern "C" int __cdecl FUNC_100B61E0(int);
extern "C" int __stdcall FUNC_100B3BD0(int);
extern "C" DWORD dword_1011742C;
extern "C" DWORD dword_100e5238;
extern "C" float flt_100e5940;

// --- @ 0xB63B0 (96): set field on model sub-struct, return float ---
float FUNC_100B63B0(int m, float f)
{
	volatile int *p;
	volatile DWORD sub = 0;
	if (!FUNC_100A7A40(m))
		return flt_100e5940;
	p = (int *)FUNC_100A7A40(m);
	sub = p[5];
	if (!sub)
		return flt_100e5940;
	*(DWORD *)(sub + 0x24) = *(DWORD *)&f;
	return f;
}

// --- @ 0xB6550 (80): vtbl swap around a call ---
static DWORD s_saved;
static BYTE s_ret;
BYTE __stdcall FUNC_100B6550(int a1, int a2, int a3)
{
	s_saved = **(DWORD **)0x10117430;
	**(DWORD **)0x10117430 = 0x1026cf80;
	s_ret = ((BYTE(__cdecl *)(int, int, int))dword_1011742C)(a1, a2, a3);
	**(DWORD **)0x10117430 = s_saved;
	return s_ret;
}

// --- @ 0xB7870 (48): thiscall, set fields + indirect call ---
struct s7870 {
	char _0[0x4c];
	int f_4C;
	char _50[0x19];
	int f_69;
	int f_6D;
	int FUNC_100B7870();
};
int s7870::FUNC_100B7870()
{
	if (f_4C && *(int *)(f_4C + 0x460)) {
		f_6D = 1;
		f_69 = (*(int(__cdecl **)())&dword_100e5238)();
		return 1;
	}
	return 0;
}

// --- @ 0xB7B80 / 0xB7BB0 / 0xB7BE0: thiscall field getters via B61E0 ---
struct s7B80 {
	char _0[0x4c];
	int f_4C;
	int FUNC_100B7B80();
	int FUNC_100B7BB0();
	BYTE FUNC_100B7BE0();
};
int s7B80::FUNC_100B7B80()
{
	if (f_4C && FUNC_100B61E0(f_4C) == 1)
		return *(int *)(f_4C + 0x5b4);
	return 0;
}
int s7B80::FUNC_100B7BB0()
{
	if (f_4C && FUNC_100B61E0(f_4C) == 1)
		return *(int *)(f_4C + 0x5a9);
	return 0;
}
BYTE s7B80::FUNC_100B7BE0()
{
	if (f_4C && FUNC_100B61E0(f_4C) == 1)
		return *(BYTE *)(f_4C + 0x5b0);
	return 0;
}

// --- @ 0xB7DD0 (48): thiscall, word compare 0x20d ---
struct s7DD0 {
	char _0[0x44];
	int f_44;
	char _48[4];
	int f_4C;
	int FUNC_100B7DD0();
};
int s7DD0::FUNC_100B7DD0()
{
	return (f_4C && FUNC_100B3BD0(f_44))
		? (*(WORD *)(f_4C + 0x22) == 0x20d)
		: 0;
}
