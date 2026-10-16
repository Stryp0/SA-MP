// w3.cpp - zone w3 VERIFIED byte-exact reconstructions
// Each block was compiled under VC7.1 and byte-compared OK_LIGHT against samp.dll.
// sub_next/sub_prev alignment stubs used during verification are omitted here.
#include "w3_shared.h"


// ---- a7e20 (rva 0xa7e20) ----

extern void FUNC_100B5790(MATRIX4X4 *st, int idx, DWORD val);

struct CObject_A7E20 {
	char _pad[0xC0];
	WORD m_wC0;
	char _c2[0x18];
	BYTE m_byDA;
	char _db[0x40];
	VECTOR m_v11B; DWORD _x1;
	VECTOR m_v12B; DWORD _x2;
	VECTOR m_v13B;
	void FUNC_1009EB10(MATRIX4X4 *st);
	void FUNC_1009EBC0(MATRIX4X4 st);
	void FUNC_1009EE60(VECTOR v);
	void FUNC_1009ED10(VECTOR v);
	void DoAttachMove();
};
void CObject_A7E20::DoAttachMove()
{
	if (m_wC0 == 0xffff || m_byDA) return;
	FUNC_1009EB10(&g_stAttach);
	g_stAttach.vA = m_v11B;
	g_stAttach.vB = m_v12B;
	g_stAttach.vC = m_v13B;
	FUNC_100B5790(&g_stAttach, 0, *(DWORD*)((char*)this + 0xce));
	FUNC_100B5790(&g_stAttach, 1, *(DWORD*)((char*)this + 0xd2));
	FUNC_100B5790(&g_stAttach, 2, *(DWORD*)((char*)this + 0xd6));
	FUNC_1009EBC0(g_stAttach);
	FUNC_1009EE60(g_vShared);
	FUNC_1009ED10(g_vShared);
}

// ---- a0b80 (rva 0xa0b80) ----
void __stdcall FUNC_100A0B80(DWORD a){}

// ---- a3d60 (rva 0xa3d60) ----
void FUNC_100A3D60(){}

// ---- a5400 (rva 0xa5400) ----
int FUNC_100A5400(){ return 2; }

// ---- a55f0 (rva 0xa55f0) ----
int FUNC_100A55F0(){ return 0; }

// ---- a23a0 (rva 0xa23a0) ----
struct C_A23A0 { char _p[4]; BYTE b4; __declspec(noinline) BYTE Get(); };
BYTE C_A23A0::Get() { return b4; }

// ---- a0fa0 (rva 0xa0fa0) ----
extern const char c_a0fb5[],c_a0fbd[],c_a0fc5[],c_a0fcd[],c_a0fd5[],c_a0fdd[],c_a0fe5[],c_a0fed[];
extern const char c_a0ff5[],c_a0ffd[],c_a1005[],c_a100d[],c_a1015[],c_a101d[],c_a1025[],c_a102d[];
extern const char c_a1035[],c_a103d[],c_a1045[],c_a104d[],c_a1055[],c_a105d[],c_a1065[],c_a106d[];
extern const char c_a1075[],c_a107d[],c_a1085[],c_a108d[],c_a1095[],c_a109d[],c_a10a5[],c_a10ad[];
extern const char c_a10b5[],c_a10bd[],c_a10c5[],c_a10cd[],c_a10d5[],c_a10dd[],c_a10e5[],c_a10ed[];
extern const char c_a10f5[],c_a10fd[],c_a1105[];
const char *__stdcall FUNC_100A0FA0(int n)
{
	switch (n - 1) {
	case 0: return c_a0fb5; case 1: return c_a0fbd; case 2: return c_a0fc5; case 3: return c_a0fcd;
	case 4: return c_a0fd5; case 5: return c_a0fdd; case 6: return c_a0fe5; case 7: return c_a0fed;
	case 8: return c_a0ff5; case 9: return c_a0ffd; case 10: return c_a1005; case 11: return c_a100d;
	case 12: return c_a1015; case 13: return c_a101d; case 14: return c_a1025; case 15: return c_a102d;
	case 19: return c_a1035; case 20: return c_a103d; case 21: return c_a1045; case 22: return c_a104d;
	case 23: return c_a1055; case 24: return c_a105d; case 25: return c_a1065; case 26: return c_a106d;
	case 27: return c_a1075; case 28: return c_a107d; case 29: return c_a1085; case 30: return c_a108d;
	case 31: return c_a1095; case 32: return c_a109d; case 33: return c_a10a5; case 34: return c_a10ad;
	case 35: return c_a10b5; case 36: return c_a10bd; case 37: return c_a10c5; case 38: return c_a10cd;
	case 39: return c_a10d5; case 40: return c_a10dd; case 43: return c_a10e5;
	case 16: case 17: case 18: case 41: case 42: case 44: case 45: case 47: case 48:
	case 51: case 52: case 53: return c_a1105;
	default: return c_a1105;
	case 46: return c_a10ed; case 49: return c_a10f5; case 50: return c_a10fd;
	}
}

// ---- 9e0be (rva 0x9e0be) ----
void FUNC_1009E0C0(){ g_flag50 = 0; }

// ---- 85443 (rva 0x85443) ----
void __stdcall FUNC_10085450(DWORD a){}

// ---- a8f10 (rva 0xa8f10) ----
DWORD __cdecl FUNC_100A8F10(DWORD a){ return a; }

// ---- adfc0 (rva 0xadfc0) ----
void __stdcall FUNC_100ADFC0(DWORD a, DWORD b, DWORD c){}

// ---- ae0a0 (rva 0xae0a0) ----
struct C_AE0A0 { char _p[0x48]; DWORD f48; __declspec(noinline) DWORD Get(); };
DWORD C_AE0A0::Get() { return f48; }

// ---- ace30 (rva 0xace30) ----
int __cdecl FUNC_100ACE30(){ return 0; }

// ---- 9637c (rva 0x9637c) ----
DWORD __stdcall FUNC_10096380(DWORD a, DWORD b, DWORD c)
{
	if (!a || b > 0x7fffffff) return 0x80070057;
	return FUNC_100781C0(a, b, c);
}

// ---- a8000 (rva 0xa8000) ----
float __stdcall FUNC_100A8000(float a, float b)
{
	b = FUNC_100B48E0(b) - a;
	return FUNC_100B48E0(b);
}

// ---- aba50 (rva 0xaba50) ----
struct C_ABA50 { char _p[0x2fd]; char buf[0x2c]; DWORD f329; __declspec(noinline) char *Get(); };
char *C_ABA50::Get() { return f329 ? buf : 0; }

// ---- a7400 (rva 0xa7400) ----
void FUNC_100A7400(){ memset(g_pArr, 0, 0x60); }

// ---- 871da (rva 0x871da) ----
struct C_871DA { __declspec(noinline) void *Self(); };
void *C_871DA::Self() { return this; }

// ---- 8436e (rva 0x8436e) ----
struct C_8436E { __declspec(noinline) void *Self(); __declspec(noinline) void *Self2(); };
void *C_8436E::Self() { return this; }
void *C_8436E::Self2() { return this; }

// ---- a8110 (rva 0xa8110) ----
struct CObject_A8_A8110 {
	char _pad[0xbe];
	volatile WORD m_wBE;
	volatile WORD m_wC0;
	VECTOR m_vC2;
	VECTOR m_vCE;
	BYTE m_byDA;
	__declspec(noinline) void AttachVehicle(WORD w, VECTOR *po, VECTOR *pr);
	__declspec(noinline) void AttachObject(WORD w, VECTOR *po, VECTOR *pr, BYTE b);
};
void CObject_A8_A8110::AttachVehicle(WORD w, VECTOR *po, VECTOR *pr)
{
	if (w == 0xffff) {
		m_wBE = w;
		m_vC2.x = 0; m_vC2.y = 0; m_vC2.z = 0;
		m_vCE.x = 0; m_vCE.y = 0; m_vCE.z = 0;
	} else {
		m_wBE = w;
		m_vC2.x = po->x; m_vC2.y = po->y; m_vC2.z = po->z;
		m_vCE.x = pr->x; m_vCE.y = pr->y; m_vCE.z = pr->z;
	}
}
void CObject_A8_A8110::AttachObject(WORD w, VECTOR *po, VECTOR *pr, BYTE b)
{
	if (w == 0xffff) {
		m_wC0 = w;
		m_vC2.x = 0; m_vC2.y = 0; m_vC2.z = 0;
		m_vCE.x = 0; m_vCE.y = 0;
		m_byDA = 1;
		m_vCE.z = 0;
	} else {
		m_wC0 = w;
		m_vC2.x = po->x; m_vC2.y = po->y; m_vC2.z = po->z;
		m_vCE.x = pr->x; m_vCE.y = pr->y;
		m_vCE.z = pr->z; m_byDA = b;
	}
}

// ---- a8240 (rva 0xa8240) ----
struct CObject_A82_A8240 {
	char _pad[0x44];
	DWORD m_dw44;
	char _p48[0x7a];
	VECTOR m_vC2;
	VECTOR m_vCE;
	__declspec(noinline) void FUNC_100A8240(CObject_A82_A8240 *pOther);
};
void CObject_A82_A8240::FUNC_100A8240(CObject_A82_A8240 *pOther)
{
	if (!FUNC_100B2310((const char *)0x100ecd2c, m_dw44)) {
		FUNC_100B2310((const char *)0x100ecd18, m_dw44, pOther->m_dw44,
			m_vC2.x, m_vC2.y, m_vC2.z, m_vCE.x, m_vCE.y, m_vCE.z);
	}
}

// ---- a82c0 (rva 0xa82c0) ----
struct CObject_A82_A82C0 {
	char _pad[0x44];
	DWORD m_dw44;
	char _p48[0x7a];
	VECTOR m_vC2;
	VECTOR m_vCE;
	__declspec(noinline) void FUNC_100A82C0(CObject_A82_A82C0 *pOther);
};
void CObject_A82_A82C0::FUNC_100A82C0(CObject_A82_A82C0 *pOther)
{
	if (!FUNC_100B2310((const char *)0x100ecd2c, m_dw44)) {
		FUNC_100B2310((const char *)0x100ecd40, m_dw44, pOther->m_dw44,
			m_vC2.x, m_vC2.y, m_vC2.z, m_vCE.x, m_vCE.y, m_vCE.z);
	}
}

// ---- a9e30 (rva 0xa9e30) ----
struct CObject_A9_A9E30 {
	char _p[0x118b];
	DWORD m_118B;
	DWORD m_118F;
	BYTE m_by1193;
	__declspec(noinline) void FUNC_100A9E30();
	void FUNC_100A8C00();
	void FUNC_100A9040();
};
void CObject_A9_A9E30::FUNC_100A9E30()
{
	if (m_118B && m_118F) {
		FUNC_100A8C00();
		if (m_by1193) FUNC_100A9040();
	}
	m_118F = 1;
}

// ---- a9e70 (rva 0xa9e70) ----
struct CObject_A9E_A9E70 {
	char _p[0x1cb];
	DWORD m_1CB;
	DWORD m_1CF;
	EntityA *m_1D3;
	char _q[0xfb4];
	DWORD m_118B;
	DWORD m_118F;
	BYTE m_by1193;
	__declspec(noinline) void FUNC_100A9E70();
	void FUNC_100A9080();
	EntityA *FUNC_1009FA60();
};
void CObject_A9E_A9E70::FUNC_100A9E70()
{
	EntityA *e;
	if (m_118B) {
		if (m_by1193) FUNC_100A9080();
		g_101A25F8 = 0;
		g_101A25FC = 0;
		if (m_1CB || m_1CF) {
			e = FUNC_1009FA60();
			if (e && m_1D3 == e && e->f4)
				FUNC_100B14C0((void*)e->f4, (void*)0x100a8b50, this);
		}
	}
}

// ---- a90d0 (rva 0xa90d0) ----
struct CObject_A90_A90D0 {
	char _p[0x40];
	EntA *m_p40;
	__declspec(noinline) BYTE FUNC_100A90D0();
	EntA *FUNC_1009FA60();
};
BYTE CObject_A90_A90D0::FUNC_100A90D0()
{
	EntA *a;
	EntX *x;
	if (m_p40 && m_p40->vt != 0x863c40 &&
		(a = FUNC_1009FA60()) && (x = a->f4) &&
		x->b0 == 1 && (x = x->f18) && (x->b8 & 8))
		return 1;
	return 0;
}

// ---- a8fa0 (rva 0xa8fa0) ----
struct CObject_A8F_A8FA0 {
	char _p[0x40];
	EntC *m_p40;
	char _q[0xa];
	DWORD m_dw4E;
	__declspec(noinline) void FUNC_100A8FA0();
};
void CObject_A8F_A8FA0::FUNC_100A8FA0()
{
	EntC *e;
	if (m_p40 && m_p40->vt != 0x863c40 &&
		(e = FUNC_100A7A40(m_dw4E)) != 0)
		e->f12 &= ~1;
}

// ---- a8f20 (rva 0xa8f20) ----
struct CObject_A8F2_A8F20 {
	char _p[0x1c3];
	DWORD m_1C3;
	__declspec(noinline) void FUNC_100A8F20();
	EntC *FUNC_1009FA60();
};
void CObject_A8F2_A8F20::FUNC_100A8F20()
{
	EntC *e = FUNC_1009FA60();
	if (e && !m_1C3 && (e = (EntC*)e->f4) != 0) {
		FUNC_100B14C0(e, (void*)0x100a8f10, this);
		m_1C3 = 1;
	}
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

// ---- a7970 (rva 0xa7970) ----
// FUNC_100a7970 — verify opcode signatures then patch imm32 sites
extern int iGtaVersion;                 // ?dword_1026EB28
extern unsigned char abPatchTblUS[];    // ?dword_10114B10
extern unsigned char abPatchTblEU[];    // ?dword_101158E0
extern unsigned int dwHookValue;        // ?dword_10114B08
extern int bScanDone;                   // ?dword_101A25AC
extern void FUNC_100AA4C0(void *addr, int size);

int __cdecl ScanAndPatch()
{
	int i;
	unsigned char *addr;
	unsigned char op;
	unsigned char *tbl;
	unsigned char *w;

	i = 0;
	do {
		if (iGtaVersion == 1) {
			addr = *(unsigned char **)(abPatchTblUS + i);
			op = *(abPatchTblUS + i + 4);
		} else {
			addr = *(unsigned char **)(abPatchTblEU + i);
			op = *(abPatchTblEU + i + 4);
		}
		if (op == *addr) {
			if (op == 0x8b || op == 0x89 || op == 0x39) {
				w = addr + 3;
				FUNC_100AA4C0(w, 4);
				*(unsigned int *)w = dwHookValue;
			} else if (op == 0xbe || op == 0xbf) {
				w = addr + 1;
				FUNC_100AA4C0(w, 4);
				*(unsigned int *)w = dwHookValue;
			}
		}
		i += 5;
	} while (i != 0xDCF);
	bScanDone = 1;
	return 1;
}

int __cdecl sub_100A7A00(){ return 0; }

// ---- a7a00 (rva 0xa7a00) ----
extern int adwModelInfoTable[];         // ?dword_101625B0 (65535 dwords)
extern void FUNC_100A6FF0();
int __cdecl ScanAndPatch();             // FUNC_100A7970

int __cdecl RelocateModelInfoTable()
{
	memset(adwModelInfoTable, 0, 0x3fffc);
	memcpy(pHookTable, (void *)0xA9B0C8, 0x4e20*4);
	ScanAndPatch();
	FUNC_100A6FF0();
	return 1;
}

// ---- a7b30 (rva 0xa7b30) ----

void __cdecl FreeModelSlot(int i)
{
	void *p = pHookTable[i];
	if (p) {
		free(p);
		pHookTable[i] = 0;
	}
}

// ---- a7cc0 (rva 0xa7cc0) ----
extern void *g_pColList;
extern void *g_pErrLog;
extern const char szErrColMagic[];
extern const char szErrColParse[];
extern const char szErrColAlloc[];

int __cdecl LoadCollisionModel(void *ctx, unsigned int size)
{
	void *buf, *obj;

	if (size > 0x40000)
		return 0;
	buf = FUNC_100C6982(1, size);
	FUNC_100B1E40(ctx, buf, size);
	if (*(unsigned int *)buf != 0x334c4f43) {
		if (g_pErrLog)
			FUNC_100680F0(g_pErrLog, szErrColMagic);
		free(buf);
		return 0;
	}
	obj = FUNC_100B6850();
	if (obj) {
		if (FUNC_100B6880(buf, size, obj)) {
			FUNC_100B4630(g_pColList, obj);
			free(buf);
			return 1;
		}
		if (g_pErrLog)
			FUNC_100680F0(g_pErrLog, szErrColParse);
	} else {
		if (g_pErrLog)
			FUNC_100680F0(g_pErrLog, szErrColAlloc);
	}
	free(buf);
	return 0;
}

// ---- a7d90 (rva 0xa7d90) ----
extern void FUNC_100B21A0(unsigned int id);
extern void FUNC_100B2200(unsigned int id, void *pfn);
extern int __cdecl LoadCollisionModel(void *ctx, unsigned int size);

void __cdecl InstallCollisionLoader()
{
	FUNC_100B21A0(0x253f2ff);
	FUNC_100B2200(0x253f2ff, (void *)LoadCollisionModel);
}// ---- aa540 (rva 0xaa540) ----
void FUNC_100AA540()
{
	BYTE v = 3;
	*(BYTE *)0x71a223 = v;
	*(BYTE *)0x71a5d5 = v;
	*(BYTE *)0x71a247 = v;
	*(BYTE *)0x71a282 = v;
	*(BYTE *)0x71a26a = v;
	*(BYTE *)0x71a2e5 = v;
	*(BYTE *)0x71a3ac = v;
	*(BYTE *)0x71a4b9 = v;
	*(BYTE *)0x71a53c = v;
	*(BYTE *)0x71a37f = v;
	*(BYTE *)0x71a518 = v;
	*(BYTE *)0x71a525 = v;
	*(BYTE *)0x71a54b = v;
	*(BYTE *)0x71a5b6 = v;
	*(BYTE *)0x71a3bb = v;
}

// ---- a8c80 (rva 0xa8c80) ----
BYTE __stdcall FUNC_100A8C80(DWORD code, DWORD *w0, DWORD *w1)
{
	switch (code) {
	case 0xa:  *w0 = 0x20;  *w1 = 0x20;  return 1;
	case 0x14: *w0 = 0x40;  *w1 = 0x20;  return 1;
	case 0x1e: *w0 = 0x40;  *w1 = 0x40;  return 1;
	case 0x28: *w0 = 0x80;  *w1 = 0x20;  return 1;
	case 0x32: *w0 = 0x80;  *w1 = 0x40;  return 1;
	case 0x3c: *w0 = 0x80;  *w1 = 0x80;  return 1;
	case 0x46: *w0 = 0x100; *w1 = 0x20;  return 1;
	case 0x50: *w0 = 0x100; *w1 = 0x40;  return 1;
	case 0x5a: *w0 = 0x100; *w1 = 0x80;  return 1;
	case 0x64: *w0 = 0x100; *w1 = 0x100; return 1;
	case 0x6e: *w0 = 0x200; *w1 = 0x40;  return 1;
	case 0x78: *w0 = 0x200; *w1 = 0x80;  return 1;
	case 0x82: *w0 = 0x200; *w1 = 0x100; return 1;
	case 0x8c: *w0 = 0x200; *w1 = 0x200; return 1;
	default: return 0;
	}
}

// ---- aa120 (rva 0xaa120) ----
extern "C" __declspec(dllimport) int __stdcall VirtualProtect(void *a, DWORD n, DWORD p, DWORD *o);
extern "C" void *memcpy(void *d, const void *s, size_t n);
void FUNC_100AA120(void *dst, const void *src, DWORD n)
{
	DWORD oldProt, oldProt2;
	VirtualProtect(dst, n, 0x40, &oldProt);
	memcpy(dst, src, n);
	VirtualProtect(dst, n, oldProt, &oldProt2);
}

// ---- a9560 (rva 0xa9560) ----
struct ObjA9560;
struct NetA9560 {
	int FUNC_100A0970(int id);
	void FUNC_100A09A0(int id, int a2);
	void FUNC_100A0940(int id, int a2);
};
extern NetA9560 *g_pNetA9560;
struct ObjA9560 {
	char _p[0x49];
	BYTE m_b49;
	DWORD m_dw4A;
	int m_i4E;
	char _q[2];
	float m_f54;
	char _r[0x10];
	float m_f68;
	char _s[0x112d];
	BYTE m_b1199;
	char FUNC_100A7F50();
	float FUNC_1009F190();
	int FUNC_1009FA60();
	void FUNC_1009EF50(int id);
	void FUNC_1009FBB0();
	void FUNC_100A8FA0();
	void FUNC_100A9560();
};
void ObjA9560::FUNC_100A9560()
{
	BYTE flag = m_b1199;
	m_b49 = 0;
	BYTE b = 0;
	if (flag) {
		if (!FUNC_100A7F50()) b = 1;
	}
	float f = FUNC_1009F190();
	m_f68 = f;
	if (f > m_f54 || b) {
		if (FUNC_1009FA60() && ++m_dw4A == 1000) {
			FUNC_1009FBB0();
			m_dw4A = 0;
			if (m_i4E > 0) {
				if (FUNC_100B4700(m_i4E) == 0)
					g_pNetA9560->FUNC_100A09A0(m_i4E, 0);
			}
		}
	} else {
		if (!FUNC_1009FA60()) {
			if (!g_pNetA9560->FUNC_100A0970(m_i4E)) {
				g_pNetA9560->FUNC_100A0940(m_i4E, 2);
				return;
			}
			FUNC_1009EF50(m_i4E);
		}
		if (FUNC_1009FA60()) {
			m_b49 = 1;
			m_dw4A = 0;
			FUNC_100A8FA0();
			return;
		}
	}
}

