// w4 scratch batch 14 - last game funcs (semantic twins)
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" int __cdecl FUNC_1009F3D0(void);
extern "C" void __cdecl FUNC_1009F040(void);
extern "C" void __cdecl FUNC_1009EB10(void *);
extern "C" void __cdecl FUNC_1009EBC0(void);
extern "C" void __cdecl FUNC_1009EC80(void);
extern "C" void __cdecl FUNC_100AEA80(void);
extern "C" void __cdecl FUNC_100B4D10(void);
extern "C" void __cdecl FUNC_100B5790(void);
extern "C" void __cdecl FUNC_100B5940(void);
extern "C" int __cdecl FUNC_100B4100(int);
extern "C" int __cdecl FUNC_100B4180(int);
extern "C" int __cdecl FUNC_100AEBB0(int);
extern "C" void __cdecl FUNC_100B57E0(int, int, int, int);
extern "C" void __cdecl FUNC_100B58A0(int, int *, float *);
extern "C" int __cdecl FUNC_100B2310(void *, int, ...);
extern "C" int __cdecl FUNC_100B3C30(int);
extern "C" int __cdecl FUNC_100AEEB0(int);
extern "C" void __cdecl FUNC_100AEE50(int);
extern "C" int __cdecl FUNC_1000D110(int);
extern "C" int __cdecl FUNC_1000D150(int);
extern "C" int __cdecl FUNC_1000D190(int);
extern "C" int __cdecl FUNC_1000D2C0(int);
extern "C" int __cdecl FUNC_1000D320(int);
extern "C" int __cdecl FUNC_100B3DD0(int);
extern "C" int __cdecl FUNC_100B3DB0(int);
extern "C" int __cdecl FUNC_100B4570(int);
extern "C" int __cdecl FUNC_1006C9B0(int, int, int, int);
extern "C" int __cdecl FUNC_1006C3C0(int, int, int, int, int, int);
extern "C" int __cdecl FUNC_1006C140(int, int, int, int);
extern "C" long long __cdecl FUNC_100B2B20(void);
extern "C" void *__cdecl FUNC_100A9110(int, int, int, int, int, int, int, int, int, int, int);
extern "C" void __cdecl FUNC_100A8530(int, int, int, int, int);
extern "C" void __cdecl FUNC_1009F630(int);
extern "C" void *__cdecl operator_new(unsigned);
extern "C" int __cdecl FUNC_100A7A40(int);
extern "C" double __cdecl atan2(double, double);
extern "C" int __cdecl FUNC_100B41F0(float *);
extern "C" float flt_100e5940;
extern "C" float flt_100e6128;
extern "C" float flt_100e6124;
extern "C" float flt_100e5b2c;
extern "C" float flt_100ec314;
extern "C" float flt_100ed2b8;
extern "C" float flt_100ed2b4;
extern "C" float flt_100ea16c;
extern "C" float flt_100ed2b0;
extern "C" DWORD DAT_1026eb98;
extern "C" DWORD DAT_1026b568[];
extern "C" DWORD DAT_100ece98;
extern "C" DWORD DAT_100ed12c;
extern "C" DWORD DAT_100ed210;
extern "C" DWORD DAT_101172c4;

// --- @ 0xB6720 (144): copy vec + heading angle ---
void FUNC_100B6720(int *p, float *o, float *o2)
{
	int *c;
	if ((c = *(int **)((char *)p + 0x14)) != 0) {
		o[0] = (float)c[0xc];
		o[1] = (float)c[0xd];
		o[2] = (float)c[0xe];
		float a = (float)atan2(-((float *)c)[4], ((float *)c)[5]) * flt_100e6128;
		if (a >= flt_100e5940)
			a -= flt_100e6124;
		*o2 = a;
	}
}
// --- @ 0xB0580 (480): per-slot textdraw/render update loop ---
struct s0580 {
	char _0[0x2a8];
	void FUNC_100B0580();
};
void s0580::FUNC_100B0580()
{
	char *p = (char *)this;
	int *slots = (int *)(p + 0x27c);
	int first = 0;
	for (int i = 0; i < 10; i++) {
		if (*(int *)(p + 0x4c + i * 4) != 1)
			continue;
		if (!slots[i] || !*(int *)(slots[i] + 0x40))
			continue;
		float *fv = (float *)(p + 0x88 + i * 0x34);
		if (!FUNC_1009F3D0()) {
			FUNC_1009F040();
		} else {
			if (!first) {
				int e = *(int *)(p + 0x2a4);
				if (e)
					((void(__cdecl *)())0x532b20)();
				first = 1;
			}
			int *obj = *(int **)(slots[i] + 0x40);
			int vt = *obj;
			((void(__cdecl *)())*(int *)(vt + 0xc))();
			float sel = *(fv - 4);
			int e2 = *(int *)(p + 0x2a4);
			int *pw = (int *)*(int *)(*(int *)(e2 + 0x488 + (int)sel * 4) + 0x14);
			DWORD buf[16];
			FUNC_100AEA80();
			FUNC_100B4D10();
			if (fv[0] != flt_100e5940) { FUNC_100B5790(); }
			if (fv[1] != flt_100e5940) { FUNC_100B5790(); }
			if (fv[2] != flt_100e5940) { FUNC_100B5790(); }
			FUNC_100B5940();
			FUNC_1009EBC0();
			FUNC_1009EC80();
			((void(__cdecl *)())*(int *)(vt + 8))();
		}
	}
}
