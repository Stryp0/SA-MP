// w3_semantic.cpp — zone w3 semantic twins: readable C++, correct semantics,
// NOT byte-verified (reason noted in each header comment).
#include "w3_shared.h"


// ---- a84c0 (rva 0xa84c0) ----
// semantic twin: MSVC folds flag-check+return-1 differently (jne+shared tail vs je+mid-block). 4 byte-order diffs.
	char _pad[0xbe];
	WORD m_wBE;
	WORD m_wC0;
	char _c2[0xed];
	BYTE m_by1AF;
	__declspec(noinline) int FUNC_100A84C0();
};
int CObject_A84::FUNC_100A84C0()
{
	DWORD *tab;
	CObject_A84 *o;
	if (m_wC0 != 0xffff) {
		if (!g_pPool) return 0;
		tab = *(DWORD**)(*(DWORD*)(g_pPool + 0x3de) + 0xc);
		if (!tab) return 0;
		if (m_wC0 > 0x3e8) return 0;
		if (!tab[m_wC0 + 1]) return 0;
		o = (CObject_A84*)tab[m_wC0 + 0x3e9];
		if (!o) return 0;
		if (!(o->m_by1AF & 1)) return 0;
		return 1;
	}
	if (m_wBE != 0xffff) return 1;
	return m_by1AF & 1;
}
int __cdecl sub_next(){ return 0; }

// ---- a8530 (rva 0xa8530) ----
// semantic twin: regalloc differs (ebp=this vs esi=this) though control flow matches.
	char _p[0x110b];
	DWORD f110B[0x11];
	char _q[0x11*4];
	DWORD f118B;
	char _r[0x257-0x18f];
	DWORD f257[0x11];
	DWORD f2DB[0x11];
	__declspec(noinline) void FUNC_100A8530(int model, int slot, const char *t1, const char *t2, int p6);
};
void CObject_A85::FUNC_100A8530(int model, int slot, const char *t1, const char *t2, int p6)
{
	int tries, ok;
	DWORD *v;
	if (slot < 0x11 && (tries = 0, model < 1 || (ok = FUNC_100B4570(model), ok != 0))) {
		v = &f110B[slot + 0x43];
		if (*v) {
			FUNC_100B3960((void*)*v);
			*v = 0;
			if (f110B[slot]) f110B[slot] = 0;
		}
		if (model < 1) {
			if (model == 0 && !g_blankTex) {
				FUNC_100B2B90("blanktex", "blanktex", 1);
				g_blankTex = FUNC_100B2C60("blanktex", "blanktex");
			}
			if (model == 0) *v = g_blankTex;
		} else {
			ok = FUNC_100A0970(model);
			if (!ok) {
				FUNC_100A0940(model, 2);
				FUNC_100A0960();
				ok = FUNC_100A0970(model);
				while (!ok) {
					tries++;
					if (tries > 0xfa) {
						*v = 0;
						goto done;
					}
					Sleep(2);
					ok = FUNC_100A0970(model);
				}
			}
			*v = FUNC_100B2C60(t1, t2);
done:
			if (!FUNC_100B4700(model) && (tries = FUNC_100A0970(model), tries != 0))
				FUNC_100A09A0(model, 0);
		}
		f257[slot] = p6;
		f2DB[slot] = 1;
		f118B = 1;
	}
}
int __cdecl sub_next(){ return 0; }

// ---- a8340 (rva 0xa8340) ----
// semantic twin: control flow matches; MSVC spills arg0 to [ebp+8] in original, differs in prologue/scheduling.
	char _p[0x40];
	Entity *m_p40;
	__declspec(noinline) void FUNC_100A8340(DWORD a0, float *v1, float *v2);
};
void CObject_A83::FUNC_100A8340(DWORD a0, float *v1, float *v2)
{
	Entity *e = m_p40;
	float x, y, z, sx, sy, sz;
	if (e && a0) {
		sx = v2[0] * g_fScale;
		sy = v2[1] * g_fScale;
		sz = v2[2] * g_fScale;
		x = v1[0]; y = v1[1]; z = v1[2];
		union { DWORD d; PFN_A8340 p; } u;
		u.d = 0x54d570;
		(e->*u.p)(a0, x, y, z, sx, sy, sz);
	}
}
int __cdecl sub_next(){ return 0; }

// ---- a83c0 (rva 0xa83c0) ----
// semantic twin: euler->matrix math correct; MSVC FPU stack scheduling differs.
	char _p[0xad];
	float m_fAD, m_fB1, m_fB5;
	char _q[0x26];
	float m_fDB, m_fDF, m_fE3, m_fE7, m_fEB, m_fEF, m_fF3, m_fF7, m_fFB, m_fFF, m_f103;
	__declspec(noinline) void FUNC_100A83C0(float x, float y, float z);
};
void CObject_A83C::FUNC_100A83C0(float x, float y, float z)
{
	float rx, ry, cx, sx, cy, sy, cz, sz;
	m_fAD = x;
	ry = y * g_fRad;
	m_fB1 = y;
	m_fB5 = z;
	cx = cos(x * g_fRad);
	rx = cx;
	sx = sin(x * g_fRad);
	cy = cos(ry);
	sy = sin(ry);
	cz = cos(z * g_fRad);
	sz = sin(z * g_fRad);
	m_fDB = cz * cy - sz * sx * sy;
	m_fDF = sz * cy + cz * sx * sy;
	m_fE3 = -(sy * rx);
	m_fEB = -(sz * rx);
	m_fEF = cz * rx;
	m_fF3 = sx;
	m_fFB = cz * sy + sz * sx * cy;
	m_fFF = sz * sy - cz * sx * cy;
	m_f103 = cy * rx;
}
int __cdecl sub_next(){ return 0; }

// ---- a9080 (rva 0xa9080) ----
// semantic twin: matches control flow; original uses ebp-frame spill of thiscall callee regs MSVC won't reproduce.
	char _p[0x40];
	EntB *m_p40;
	char _q[0x1150];
	BYTE m_by1194;
	__declspec(noinline) void FUNC_100A9080();
};
void CObject_A908::FUNC_100A9080()
{
	EntB *e = m_p40;
	union { DWORD d; VFN_A9080 p; } u;
	if (e && e->vt != 0x863c40 && m_by1194) {
		u.d = *(DWORD*)(e->vt + 0x50);
		(e->*u.p)(1);
		m_by1194 = 0;
	}
}
int __cdecl sub_next(){ return 0; }

// ---- a9040 (rva 0xa9040) ----
// semantic twin: same as a9080 frame quirk; sets entity flag then calls vt[0x4c].
	char _p[0x40];
	EntB *m_p40;
	char _q[0x1150];
	BYTE m_by1194;
	__declspec(noinline) void FUNC_100A9040();
};
void CObject_A904::FUNC_100A9040()
{
	EntB *e = m_p40;
	union { DWORD d; VFN_A9040 p; } u;
	if (e && e->vt != 0x863c40) {
		e->f1C |= 0x10000000;
		u.d = *(DWORD*)(m_p40->vt + 0x4c);
		(m_p40->*u.p)();
		m_by1194 = 1;
	}
}
int __cdecl sub_next(){ return 0; }

// ---- a7f50 (rva 0xa7f50) ----
// semantic twin: circular range check; MSVC emits shared xor-al tail in original, mine splits it.
	char _p[0x1199];
	BYTE m_by1199;
	BYTE m_by119A;
	BYTE m_by119B;
	__declspec(noinline) BYTE FUNC_100A7F50(int a0);
};
BYTE CObject_A7F::FUNC_100A7F50(int a0)
{
	BYTE lo, hi, cl, al;
	lo = 0; hi = 0;
	if (m_by1199) {
		if (g_pPoolB) g_pPoolB->FUNC_100A0AE0(&hi, &lo);
	}
	cl = m_by119B;
	al = m_by119A;
	if (cl > al) {
		if (lo < al) return 0;
		if (lo >= cl) return 0;
		return 1;
	} else if (cl < al) {
		if (lo >= al) return 1;
		if (lo >= cl) return 0;
		return 1;
	}
	return 0;
}
int __cdecl sub_next(){ return 0; }

// ---- 845e0 (rva 0x845e0) ----
// semantic twin: same loop semantics; MSVC schedules arg0 load before push, original after.
DWORD __stdcall FUNC_100845E0(WORD *s, int n, DWORD *out)
{
	int rem = n;
	if (rem) {
		while (*s) {
			s++;
			if (!--rem) return 0x80070057;
		}
		if (out) *out = n - rem;
		return 0;
	}
	return 0x80070057;
}
int __cdecl sub_next(){ return 0; }

// ---- a1610 (rva 0xa1610) ----
// semantic twin: bubble-sort+alloc loop; 2 scheduling diffs (inc placement, folded for-test).
	char _p[0x6e];
	BYTE m_by6E[0xd4];
	__declspec(noinline) void FUNC_100A1610(BYTE *arr);
};
void ObjA1610::FUNC_100A1610(BYTE *arr)
{
	int i, j, t, idx, *pi;
	BYTE bt, *q;
	int local_350[212];
	memset(m_by6E, 0, 0xd4);
	i = 400;
	do {
		if (i >= 0) {
			if (i < 20000 && FUNC_100B2310((const char*)0x100ec5a8, i))
				FUNC_100B2310((const char*)0x100ec6ac, i);
		} else if (g_pNet && g_pNet->FUNC_1000D150(i) && !FUNC_100B3D30(i)) {
			g_pNet->FUNC_1000D1D0(i);
		}
	} while (++i != 0x264);
	i = 0;
	do { local_350[i] = i + 400; } while (++i != 0xd4);
	for (i = 0xd3; i > 0; i--) {
		q = arr + 1;
		pi = local_350 + 1;
		j = i;
		do {
			if (*q > q[-1]) {
				t = pi[-1];
				bt = q[-1];
				q[-1] = *q;
				pi[-1] = pi[0];
				*q = bt;
				pi[0] = t;
			}
			pi++;
			j--;
			q++;
		} while (j);
	}
	i = 0;
	do {
		if (arr[i]) {
			idx = local_350[i];
			FUNC_100B2310((const char*)0x100ec56c, idx);
			FUNC_100B2310((const char*)0x100ec580);
			*(BYTE*)(idx - 0x122 + (DWORD)this) = 1;
		}
	} while (++i != 0x50);
}
int __cdecl sub_next(){ return 0; }

// ---- a1c10 (rva 0xa1c10) ----
// semantic twin: frame-limit logic correct; x87 store interleaving differs (kept semantic per w4 tip).
	char _p[0x5d];
	DWORD m_5D;
	__declspec(noinline) void FUNC_100A1C10();
	void FUNC_100A0010();
	int FUNC_10001010();
	int FUNC_100ACCD0();
	void FUNC_100A0090(int a, int b);
};
void ObjA1C::FUNC_100A1C10()
{
	int t, n2, lim;
	t = FUNC_1002E7F0();
	if (!g_10150694) {
		*(float*)0xb7cb5c = 1.0f;
		*(float*)0xb7cb58 = 1.0f;
		*(float*)0x10116718 = 3.0f;
		g_10150694 = FUNC_1002E7F0();
		g_10150698 = g_10150694;
		return;
	}
	FUNC_100A0010();
	g_10150690++;
	if (t - g_10150694 > 0xfa) {
		float x;
		n2 = g_10150690 * 4 - 4;
		if (n2 > 0x10)
			x = g_100EA63C / (float)n2;
		else
			x = g_100E6148;
		g_1015069C = x;
		*(float*)0xb7cb5c = x;
		*(float*)0xb7cb58 = x;
		*(float*)0x10116718 = x * g_100E6148;
		g_10150694 = FUNC_1002E7F0();
		g_10150690 = 0;
	}
	if (FUNC_10001010() && FUNC_10001010() && FUNC_100ACCD0()) {
		if (g_00BA6794 && m_5D < 0x2e) {
			FUNC_100A0090(t - g_10150698, m_5D);
			g_10150698 = FUNC_1002E7F0();
			return;
		}
		t -= g_10150698;
		if (t && t < 0x16) {
			Sleep(0x15 - t);
			g_10150698 = FUNC_1002E7F0();
			return;
		}
	} else if (!g_00BA6794) {
		t -= g_10150698;
		if (t && t < 0xb) Sleep(10 - t);
	} else {
		t -= g_10150698;
		if (t && m_5D && t < (lim = 1000 / (int)m_5D)) {
			Sleep(lim - t - 1);
			g_10150698 = FUNC_1002E7F0();
			return;
		}
	}
	g_10150698 = FUNC_1002E7F0();
}
int __cdecl sub_next(){ return 0; }

// ---- a0110 (rva 0xa0110) ----
// semantic twin: allocates CObject-ish at first free slot 2..0xd1.
// Original wraps operator_new+ctor in an SEH try block (fs:[0] frame, local_4 EH state)
// which this simplified form does not reproduce byte-wise.
void *operator_new(size_t n);
ObjA *FUNC_100A0110(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e, DWORD f, int p7)
{
	ObjA *o;
	BYTE i;
	for (i = 2; i != 0xd2; i++) {
		if (g_SlotUsed[i] != 1) {
			if ((char)i == 0) return 0;
			o = 0;
			{ void *pv = operator_new(0x32d);
			  if (pv) o = (ObjA*)FUNC_100B0CE0(i, a, b, c, d, e); }
			if (o && o->f2A4) {
				g_SlotUsed[i] = 1;
				FUNC_100B44C0(i, p7 != 0);
			}
			return o;
		}
	}
	return 0;
}

// ---- a18a0 (rva 0xa18a0) ----
void FUNC_100A18A0()
{
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100ec9ec))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100ec9ec);
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100ec9e8))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100ec9e8);
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100ec9e0))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100ec9e0);
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100ec9d4))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100ec9d4);
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100e6194))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100e6194);
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100ec9cc))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100ec9cc);
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100ec9c4))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100ec9c4);
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100ec9bc))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100ec9bc);
	if (!FUNC_100B2310((const char*)0x100ec6fc, (const char*)0x100ec9b4))
		FUNC_100B2310((const char*)0x100ec6e8, (const char*)0x100ec9b4);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0xc3b))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0xc3b);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0x5cd))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0x5cd);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0x5ce))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0x5ce);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0x607))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0x607);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0x60a))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0x60a);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0x157))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0x157);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0x156))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0x156);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0x158))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0x158);
	if (!FUNC_100B2310((const char*)0x100ec5a8, (const char*)0x14a))
		FUNC_100B2310((const char*)0x100ec56c, (const char*)0x14a);
}
int __cdecl sub_next(){ return 0; }

// ---- gta_thunks (rva 0xgta_thunks) ----
// semantic twins: GTA SA inline-hook thunks — jump into fixed GTA code addresses;
// not expressible as normal C++ control flow (documented, kept as MASM).
// a3fc0: cmp [esi-0x20],0x27 -> jmp 0x738880/0x7388db   (GTA interior hook)
// a3ff0: ecx!=0 ? jmp edx(*[esp+8] -> 0x63a047) : jmp 0x63a04d
// a4010: eax!=0 ? jmp 0x47eab8 : jmp 0x47eaca