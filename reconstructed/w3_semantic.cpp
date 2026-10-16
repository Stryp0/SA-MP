// w3_semantic.cpp - zone w3 semantic twins: readable C++, correct semantics,
// NOT byte-verified (reason noted in each header comment).
#include "w3_shared.h"


// ---- a84c0 (rva 0xa84c0) ----
// semantic twin: MSVC folds flag-check+return-1 differently (jne+shared tail vs je+mid-block). 4 byte-order diffs.
struct CObject_A84_A84C0 {
	char _pad[0xbe];
	WORD m_wBE;
	WORD m_wC0;
	char _c2[0xed];
	BYTE m_by1AF;
	__declspec(noinline) int FUNC_100A84C0();
};
int CObject_A84_A84C0::FUNC_100A84C0()
{
	DWORD *tab;
	CObject_A84_A84C0 *o;
	if (m_wC0 != 0xffff) {
		if (!g_pPool) return 0;
		tab = *(DWORD**)(*(DWORD*)(g_pPool + 0x3de) + 0xc);
		if (!tab) return 0;
		if (m_wC0 > 0x3e8) return 0;
		if (!tab[m_wC0 + 1]) return 0;
		o = (CObject_A84_A84C0*)tab[m_wC0 + 0x3e9];
		if (!o) return 0;
		if (!(o->m_by1AF & 1)) return 0;
		return 1;
	}
	if (m_wBE != 0xffff) return 1;
	return m_by1AF & 1;
}

// ---- a8530 (rva 0xa8530) ----
// semantic twin: regalloc differs (ebp=this vs esi=this) though control flow matches.
struct CObject_A85_A8530 {
	char _p[0x110b];
	DWORD f110B[0x11];
	char _q[0x11*4];
	DWORD f118B;
	char _r[0x257-0x18f];
	DWORD f257[0x11];
	DWORD f2DB[0x11];
	__declspec(noinline) void FUNC_100A8530(int model, int slot, const char *t1, const char *t2, int p6);
};
void CObject_A85_A8530::FUNC_100A8530(int model, int slot, const char *t1, const char *t2, int p6)
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

// ---- a8340 (rva 0xa8340) ----
// semantic twin: control flow matches; MSVC spills arg0 to [ebp+8] in original, differs in prologue/scheduling.
struct Entity;
typedef void (Entity::*PFN_A8340)(DWORD,float,float,float,float,float,float);
struct CObject_A83_A8340 {
	char _p[0x40];
	Entity *m_p40;
	__declspec(noinline) void FUNC_100A8340(DWORD a0, float *v1, float *v2);
};
void CObject_A83_A8340::FUNC_100A8340(DWORD a0, float *v1, float *v2)
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

// ---- a83c0 (rva 0xa83c0) ----
// semantic twin: euler->matrix math correct; MSVC FPU stack scheduling differs.
struct CObject_A83C_A83C0 {
	char _p[0xad];
	float m_fAD, m_fB1, m_fB5;
	char _q[0x26];
	float m_fDB, m_fDF, m_fE3, m_fE7, m_fEB, m_fEF, m_fF3, m_fF7, m_fFB, m_fFF, m_f103;
	__declspec(noinline) void FUNC_100A83C0(float x, float y, float z);
};
void CObject_A83C_A83C0::FUNC_100A83C0(float x, float y, float z)
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

// ---- a9080 (rva 0xa9080) ----
// semantic twin: matches control flow; original uses ebp-frame spill of thiscall callee regs MSVC won't reproduce.
struct EntB;
typedef void (EntB::*VFN_A9080)(int);
struct CObject_A908_A9080 {
	char _p[0x40];
	EntB *m_p40;
	char _q[0x1150];
	BYTE m_by1194;
	__declspec(noinline) void FUNC_100A9080();
};
void CObject_A908_A9080::FUNC_100A9080()
{
	EntB *e = m_p40;
	union { DWORD d; VFN_A9080 p; } u;
	if (e && e->vt != 0x863c40 && m_by1194) {
		u.d = *(DWORD*)(e->vt + 0x50);
		(e->*u.p)(1);
		m_by1194 = 0;
	}
}

// ---- a9040 (rva 0xa9040) ----
// semantic twin: same as a9080 frame quirk; sets entity flag then calls vt[0x4c].
struct EntB;
typedef void (EntB::*VFN_A9040)();
struct CObject_A904_A9040 {
	char _p[0x40];
	EntB *m_p40;
	char _q[0x1150];
	BYTE m_by1194;
	__declspec(noinline) void FUNC_100A9040();
};
void CObject_A904_A9040::FUNC_100A9040()
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

// ---- a7f50 (rva 0xa7f50) ----
// semantic twin: circular range check; MSVC emits shared xor-al tail in original, mine splits it.
struct PoolB;
struct CObject_A7F_A7F50 {
	char _p[0x1199];
	BYTE m_by1199;
	BYTE m_by119A;
	BYTE m_by119B;
	__declspec(noinline) BYTE FUNC_100A7F50(int a0);
};
BYTE CObject_A7F_A7F50::FUNC_100A7F50(int a0)
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

// ---- a1610 (rva 0xa1610) ----
// semantic twin: bubble-sort+alloc loop; 2 scheduling diffs (inc placement, folded for-test).
struct PoolN;
struct ObjA1610_A1610 {
	char _p[0x6e];
	BYTE m_by6E[0xd4];
	__declspec(noinline) void FUNC_100A1610(BYTE *arr);
};
void ObjA1610_A1610::FUNC_100A1610(BYTE *arr)
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

// ---- a1c10 (rva 0xa1c10) ----
// semantic twin: frame-limit logic correct; x87 store interleaving differs (kept semantic per w4 tip).
struct ObjA1C_A1C10 {
	char _p[0x5d];
	DWORD m_5D;
	__declspec(noinline) void FUNC_100A1C10();
	void FUNC_100A0010();
	int FUNC_10001010();
	int FUNC_100ACCD0();
	void FUNC_100A0090(int a, int b);
};
void ObjA1C_A1C10::FUNC_100A1C10()
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

// ---- a0110 (rva 0xa0110) ----
// semantic twin: allocates CObject-ish at first free slot 2..0xd1.
// Original wraps operator_new+ctor in an SEH try block (fs:[0] frame, local_4 EH state)
// which this simplified form does not reproduce byte-wise.
void *operator_new(size_t n);
struct ObjA_A0110 { char _p[0x2a4]; DWORD f2A4; };
ObjA_A0110 *FUNC_100A0110(DWORD a, DWORD b, DWORD c, DWORD d, DWORD e, DWORD f, int p7)
{
	ObjA_A0110 *o;
	BYTE i;
	for (i = 2; i != 0xd2; i++) {
		if (g_SlotUsed[i] != 1) {
			if ((char)i == 0) return 0;
			o = 0;
			{ void *pv = operator_new(0x32d);
			  if (pv) o = (ObjA_A0110*)FUNC_100B0CE0(i, a, b, c, d, e); }
			if (o && o->f2A4) {
				g_SlotUsed[i] = 1;
				FUNC_100B44C0(i, p7 != 0);
			}
			return o;
		}
	}
	return 0;
}// ---- a36c0 (rva 0xa36c0) ----
struct PPool36 {
	void *FUNC_100138C0(void *veh);
	int FUNC_100010B0(void *u);
	int FUNC_1000E470(void *u);
};
struct Npc36 {
	int FUNC_100ACEF0();
	int FUNC_100ACE40();
	char FUNC_100ABC50();
	void FUNC_100AC060(int a, int b);
};
struct NetEnt36 {
	void FUNC_10005AD0(int id, int f);
};
struct PoolEnt36 { DWORD f0; PPool36 *f4; };
struct NetGame36 { char _p[0x3de]; PoolEnt36 *f3DE; };
extern NetGame36 *g_pNetGame;         // 0x1026eb94
extern DWORD *g_pPoolEnt;             // 0x1015073c
extern NetEnt36 *g_pLocalPlayer;      // 0x10150c80
extern WORD g_wEntId;                 // 0x101506d0
extern DWORD g_pEntObj;               // 0x10150984
extern DWORD g_10150a38;              // 0x10150a38
extern WORD __stdcall FUNC_1001EB90(DWORD id);
int FUNC_100A36C0()
{
	PPool36 *pp;
	DWORD *veh;
	void *u;
	if (g_pNetGame) {
		g_pPoolEnt = (DWORD *)g_pNetGame->f3DE->f0;
		pp = g_pNetGame->f3DE->f4;
		g_pLocalPlayer = *(NetEnt36 **)((char *)pp + 0x26);
		g_wEntId = FUNC_1001EB90(g_10150a38);
		if (g_wEntId == 0xffff || g_wEntId >= 0x7d0
			|| !g_pPoolEnt[0xc1d + g_wEntId]
			|| (g_pEntObj = g_pPoolEnt[0x44d + g_wEntId],
				*(DWORD *)(g_pEntObj + 0x60) != 0
				|| *(short *)(*(DWORD *)(g_pEntObj + 0x4c) + 0x22) == 0x23a))
			return 0;
		if (g_pLocalPlayer) {
			if (*(Npc36 **)((char *)g_pLocalPlayer + 0x104)
				&& (*(Npc36 **)((char *)g_pLocalPlayer + 0x104))->FUNC_100ACEF0())
				return 0;
			if (g_pLocalPlayer
				&& *(Npc36 **)((char *)g_pLocalPlayer + 0x104)
				&& (*(Npc36 **)((char *)g_pLocalPlayer + 0x104))->FUNC_100ACE40())
				return 0;
		}
		veh = *(DWORD **)(*(DWORD *)(g_pEntObj + 0x4c) + 0x460);
		if (veh) {
			if (veh[0x166]) return 0;
			u = pp->FUNC_100138C0(veh);
			if (pp->FUNC_100010B0(u) && pp->FUNC_1000E470(u))
				return 0;
		}
		if (*(Npc36 **)((char *)g_pLocalPlayer + 0x104)
			&& (*(Npc36 **)((char *)g_pLocalPlayer + 0x104))->FUNC_100ABC50() == '.')
			(*(Npc36 **)((char *)g_pLocalPlayer + 0x104))->FUNC_100AC060(0, 0);
		g_pLocalPlayer->FUNC_10005AD0(g_wEntId, 0);
	}
	return 1;
}

// ---- ac750 (rva 0xac750) ----
extern WORD g_wA4326C;              // 0xa4326c
extern DWORD g_A4331C;              // 0xa4331c
extern DWORD g_A43320;              // 0xa43320
extern DWORD g_A432E8;              // 0xa432e8
extern DWORD g_A432C0;              // 0xa432c0
void __stdcall FUNC_100AC750(DWORD *a, DWORD b)
{
	DWORD *p, t;
	g_wA4326C = 0;
	t = a[0];
	p = (DWORD *)0xa43318;
	p[0] = t;
	g_A4331C = a[1];
	g_A43320 = a[2];
	g_A432E8 = b;
	g_A432C0 = 0;
}

// ---- acac0 (rva 0xacac0) ----
struct ObjAcac0 {
	char _p[0x2a4];
	struct Sub { char _p2[0x718]; BYTE b718; } *m_p2A4;
	void *FUNC_100ACAC0();
};
struct PoolAcac0 { void *FUNC_100A13E0(DWORD d, int n); };
extern PoolAcac0 *g_pPoolAcac0;       // 0x1026ebac
void *ObjAcac0::FUNC_100ACAC0()
{
	volatile void *r;
	volatile void *out;
	Sub *sub = m_p2A4;
	if (sub) {
		DWORD *slot = sub
			? (DWORD *)((char *)sub + sub->b718 * 0x1c + 0x5a0)
			: 0;
		r = g_pPoolAcac0->FUNC_100A13E0(*slot, 1);
		out = (char *)r + 0x24;
	}
	return (void *)r;
}

// ---- aa4e0 (rva 0xaa4e0) ----
extern int (__stdcall *g_pfnVP)(void *a, DWORD n, DWORD p, DWORD *o); // 0x100e5184
void FUNC_100AA4E0(DWORD mul)
{
	DWORD old;
	DWORD *p;
	int (__stdcall *vp)(void *, DWORD, DWORD, DWORD *) = g_pfnVP;
	(*vp)((void *)0x411458, 4, 0x40, &old);
	*(DWORD *)0x411458 = mul;
	mul *= 0x2c;
	p = (DWORD *)0x101166f8;
	do {
		(*vp)((void *)(*p + 2), 4, 0x40, &old);
		*(DWORD *)(*p + 2) = mul;
		p++;
	} while (p != (DWORD *)0x10116714);
}

// ---- 9de40 (rva 0x9de40) ----
extern void FUNC_100B3B10(DWORD *a, DWORD *b, DWORD *c, void *d,
	int e, int f, int g, int h, int i, int j, int k, int l, int m);
float FUNC_1009DE40(DWORD *a)
{
	DWORD l0 = a[0];
	DWORD l1 = a[1];
	float f = -100.0f;
	char buf[0x40];
	FUNC_100B3B10(a, &l1, &l0, buf, 1, 0, 0, 1, 1, 1, 0, 0, 0);
	return f;
}

// ---- ada40 (rva 0xada40) ----
extern int FUNC_100B40A0(void *e);
extern void *FUNC_100B4050(void *e);
struct SubA40 {
	DWORD f0;
	char _p[0x14];
	void *f18;
	char _q[0x460];
	struct Nxt { char _p2[0x10]; void *f10; } *f47C;
};
struct ObjAda40 {
	char _p[0x2a4];
	SubA40 *m_p2A4;
	int FUNC_100ADA40();
};
int ObjAda40::FUNC_100ADA40()
{
	void *e;
	SubA40 *s = m_p2A4;
	if (s && s->f0 != 0x863c40) {
		if (s->f18) {
			e = s->f47C->f10;
			if (!e) return 0;
			if (FUNC_100B40A0(e) == 0x191) return 1;
			while (FUNC_100B40A0(e) != 0x191) {
				e = FUNC_100B4050(e);
				if (!e) return 0;
			}
			if (e && FUNC_100B40A0(e) == 0x191) return 1;
		}
	}
	return 0;
}

// ---- a8fd0 (rva 0xa8fd0) ----
struct VECTOR8 { float x, y, z; };
struct MATRIX4X4_8 {
	VECTOR8 vA; DWORD u0;
	VECTOR8 vB; DWORD u1;
	VECTOR8 vC; DWORD u2;
	DWORD f30, f34, f38, f3c;
};
struct ObjA8fd0 {
	char _p[0x40];
	DWORD *m_p40;
	char _q[0xa];
	DWORD m_dw4E;
	char _r[0xa];
	DWORD m_5C, m_60, m_64;
	void FUNC_1009EB10(MATRIX4X4_8 *st);
	void FUNC_100A8FD0();
};
extern int FUNC_100B6410(DWORD, void *);
extern void FUNC_100B4D10(void *, MATRIX4X4_8 *, void *);
void ObjA8fd0::FUNC_100A8FD0()
{
	char buf[0xc];
	float v[3];
	MATRIX4X4_8 st;
	if (m_p40 && *m_p40 != 0x863c40) {
		FUNC_1009EB10(&st);
		if (FUNC_100B6410(m_dw4E, buf)) {
			FUNC_100B4D10(&m_5C, &st, buf);
			return;
		}
		m_5C = *(DWORD *)&v[0];
		m_60 = *(DWORD *)&v[1];
		m_64 = *(DWORD *)&v[2];
	}
}

// ---- a9110 (rva 0xa9110) ----
// semantic twin: CObject constructor. The original wraps each init call in an
// SEH __try frame (fs:[0] chain + unwind funclets), which plain C++ cannot
// express byte-wise; the field/store sequence is faithful otherwise.
struct ObjA9110 {
	void **vt;
	DWORD f4[0xf];
	char _p[0x2];
	WORD m_w30;
	char _q[0x8a];
	WORD m_wBE;
	DWORD m_dwC0, m_dwC4, m_dwC8, m_dwCC, m_dwD0, m_dwD4;
	BYTE m_bD8;
	char _r[0x35];
	BYTE m_b10E;
	char _s[0x4f];
	DWORD m_dw160;
	DWORD m_dw164;
	char _t[0x6e];
	BYTE m_b1D6;
	char _u[0x39];
	DWORD m_dw213;
	DWORD m_dw217;
	char _v[0xa];
	BYTE m_b225;
	char _w[0x58];
	DWORD m_dw282;
	char _x[0xe];
	BYTE m_b294;
	char _y[0xe5];
	BYTE m_b37D;
	char _z[0x9];
	DWORD m_dw38A;
	DWORD m_dw38E;
	DWORD m_dw392;
	DWORD m_dw396;
	DWORD m_dw39A;
	BYTE m_b39E;
	char _a2[0x6];
	DWORD m_dw3A8;
	char _b2[0x4f];
	BYTE m_b3FB;
	char _c2[0x6];
	DWORD m_dw405;
	DWORD m_dw409;
	DWORD m_dw40D;
	DWORD m_dw411;
	char _d2[0x97];
	BYTE m_b4AC;
	char _e2[0xce3];
	BYTE m_b1193;
	char _f2[5];
	BYTE m_b1199, m_b119A, m_b119B;
	void FUNC_100A9110(int model, BYTE c28, BYTE c2c, float x, float y, float z);
};
extern int FUNC_100B4570();
extern int __stdcall FUNC_100A7A40(int model);
extern int FUNC_100B64A0(int);
extern int FUNC_100B44E0(int);
extern void FUNC_100B4550(int, int);
extern void FUNC_100AA4C0(int);
extern void FUNC_100B2310(int model, float x, float y, float z, void *cb);
extern void *DAT_100eccf0;
extern BYTE DAT_0046977f;
extern int g_100E5940;
extern void *vt_A9110[];
void ObjA9110::FUNC_100A9110(int model, BYTE c28, BYTE c2c, float x, float y, float z)
{
	int iVar5, iVar3;
	BYTE b2;
	for (int i = 0xf; i; i--)
		f4[i - 1] = 0;
	m_wBE = 0xffff;
	m_w30 = 0xffff;
	m_b1193 = c28;
	vt = vt_A9110;
	m_dw160 = m_dw164 = 0;
	m_dwC0 = m_dwC4 = m_dwC8 = m_dwCC = m_dwD0 = m_dwD4 = 0;
	m_bD8 = 1;
	m_b10E = 0;
	m_dw213 = 0;
	m_dw217 = 0;
	m_b225 = 0;
	m_dw282 = 0;
	m_b294 = 0;
	m_b37D = 0;
	m_dw38A = m_dw38E = m_dw392 = m_dw396 = m_dw39A = 0;
	m_b39E = 0;
	m_dw3A8 = 0;
	m_b3FB = 0;
	m_dw405 = m_dw409 = m_dw40D = m_dw411 = 0;
	m_b4AC = 0;
	m_b1199 = m_b119A = m_b119B = 0;
	if (c28 || c2c) {
		m_b1199 = 1;
		m_b119A = c28;
		m_b119B = c2c;
	}
	iVar5 = FUNC_100B4570();
	if (!iVar5)
		model = 0x48c7;
	iVar5 = FUNC_100A7A40(model);
	b2 = FUNC_100B64A0(iVar5);
	m_b1D6 = (b2 >> 1) & 1;
	if (z != *(float *)&g_100E5940 && iVar5) {
		iVar3 = FUNC_100B44E0(iVar5);
		if (iVar3)
			FUNC_100B4550(iVar5, *(int *)&z);
	}
	if (model < 0) {
		FUNC_100AA4C0(1);
		DAT_0046977f = 0x75;
	}
	FUNC_100B2310(model, x, y, z, &DAT_100eccf0);
}

