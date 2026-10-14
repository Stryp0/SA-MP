// Zone w3 semantic twins — readable C++, correct semantics, NOT byte-verified.
// Each function emits functionally equivalent code but differs in MSVC
// scheduling/block-order (documented per function).

// ---- a84c0 ----
// semantic twin: MSVC folds flag-check+return-1 differently (jne+shared tail vs je+mid-block). 4 byte-order diffs.
#include "pre.h"
struct PoolA { char _p[0x3de]; DWORD *f3DE; };
extern DWORD g_pPool;
struct CObject_A84 {
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

// ---- a8530 ----
// semantic twin: regalloc differs (ebp=this vs esi=this) though control flow matches.
#include "pre.h"
extern "C" void __stdcall Sleep(DWORD ms);
extern int FUNC_100B4570(int id);
extern void FUNC_100B3960(void *p);
extern void FUNC_100B2B90(const char*, const char*, int);
extern int FUNC_100B2C60(const char*, const char*);
extern int FUNC_100A0970(int id);
extern void FUNC_100A0940(int id, int n);
extern void FUNC_100A0960();
extern void FUNC_100A09A0(int id, int n);
extern short FUNC_100B4700(int id);
extern int g_blankTex;
struct CObject_A85 {
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

// ---- a8340 ----
// semantic twin: control flow matches; MSVC spills arg0 to [ebp+8] in original, differs in prologue/scheduling.
#include "pre.h"
extern float g_fScale;
struct Entity;
typedef void (Entity::*PFN_A8340)(DWORD,float,float,float,float,float,float);
struct CObject_A83 {
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

// ---- a83c0 ----
// semantic twin: euler->matrix math correct; MSVC FPU stack scheduling differs.
#include "pre.h"
#include <math.h>
extern float g_fRad;
struct CObject_A83C {
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

// ---- a9080 ----
// semantic twin: matches control flow; original uses ebp-frame spill of thiscall callee regs MSVC won't reproduce.
#include "pre.h"
struct EntB;
typedef void (EntB::*VFN_A9080)(int);
struct EntB { DWORD vt; };
struct CObject_A908 {
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

// ---- a9040 ----
// semantic twin: same as a9080 frame quirk; sets entity flag then calls vt[0x4c].
#include "pre.h"
struct EntB;
typedef void (EntB::*VFN_A9040)();
struct EntB { DWORD vt; char _p[0x18]; DWORD f1C; };
struct CObject_A904 {
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

// ---- a8f60 ----

// ---- a4950 ----

// ---- a7f50 ----
// semantic twin: circular range check; MSVC emits shared xor-al tail in original, mine splits it.
#include "pre.h"
struct PoolB;
extern PoolB *g_pPoolB;
struct PoolB {
	void FUNC_100A0AE0(BYTE *a, BYTE *b);
};
struct CObject_A7F {
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

// ---- 845e0 ----
// semantic twin: same loop semantics; MSVC schedules arg0 load before push, original after.
#include "pre.h"
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
