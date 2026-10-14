// w4 scratch batch 12 - big game funcs
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" int __cdecl FUNC_1009F3D0(void);
extern "C" int __cdecl FUNC_100A73B0(void);
extern "C" int __cdecl FUNC_100ADA00(void);
extern "C" void __cdecl FUNC_100AD230(int, int, int, int, int, int, int, int);
extern "C" int __cdecl FUNC_100ADB70(int);
extern "C" void __cdecl FUNC_100ADC00(void);
extern "C" void __cdecl FUNC_1009EB10(void *);
extern "C" int __cdecl FUNC_100B2310(void *, int, ...);
extern "C" int __cdecl FUNC_100B3C30(int);
extern "C" void __cdecl FUNC_1009F630(int);
extern "C" void __cdecl FUNC_100A8530(int, int, int, int, int);
extern "C" int __cdecl FUNC_100AEEB0(int);
extern "C" void __cdecl FUNC_100AEE50(int);
extern "C" int __cdecl FUNC_1000D150(int);
extern "C" int __cdecl FUNC_1000D190(int);
extern "C" int __cdecl FUNC_1000D320(int);
extern "C" void *__cdecl FUNC_100A9110(int, int, int, int, int, int, int, int, int, int, int);
extern "C" int __cdecl FUNC_100B4100(int);
extern "C" int __cdecl FUNC_100B4180(int);
extern "C" int __cdecl FUNC_100AEBB0(int);
extern "C" void __cdecl FUNC_100B57E0(int, int, int, int);
extern "C" void __cdecl FUNC_100B58A0(int, int *, float *);
extern "C" void *__cdecl operator_new(unsigned);
extern "C" float flt_100e5b2c;
extern "C" float flt_100ec314;
extern "C" float flt_100ed2b8;
extern "C" float flt_100ed2b4;
extern "C" float flt_100ea16c;
extern "C" float flt_100ed2b0;
extern "C" double dbl_100e8dd8;
extern "C" double dbl_100ed298;
extern "C" double dbl_100ed2a0;
extern "C" double dbl_100ed2a8;
extern "C" double dbl_100ed280;
extern "C" double dbl_100ea960;
extern "C" double dbl_100ed288;
extern "C" double dbl_100ed290;
extern "C" DWORD DAT_100ece98;
extern "C" DWORD DAT_100ed12c;
extern "C" DWORD DAT_100ed210;
extern "C" DWORD DAT_10116dd8;
extern "C" DWORD DAT_101172c4;
extern "C" DWORD DAT_1026eb98;
extern "C" char s_DANCE_LOOP_10116e18[];

// --- @ 0xB00B0 (544): directional-input -> state index state machine ---
void sB00B0();
struct s00B0 {
	char _0[0x2a4];
	int f_2A4;
	char _2A8[8];
	char f_2B0;
	char _2B1[0x21];
	int f_2D2;
	int f_2D6;
	int f_2DA;
	void FUNC_100B00B0();
};
void s00B0::FUNC_100B00B0()
{
	if (!f_2D2 || !f_2A4)
		return;
	if (!FUNC_1009F3D0())
		return;
	if (f_2B0)
		return;
	int i4 = FUNC_100A73B0();
	short s1 = *(short *)(i4 + 0x32);
	short s2 = *(short *)(i4 + 0x30);
	if (!FUNC_100ADA00()) {
		int off = f_2D6 * 0x10;
		FUNC_100AD230((int)(s_DANCE_LOOP_10116e18 + off),
			(int)((char *)&DAT_10116dd8 + off), 0x40800000, 1, 0, 0, 0, 0);
	}
	short s3 = *(short *)(i4 + 0x20);
	int idx = 0;
	if (s1 >= 1 && s2 == 0 && s3 == 0) {
		// idx stays 0
	} else {
		if (s1 < 0 && s2 == 0 && s3 == 0)
			idx = 1;
		else if (s1 == 0) {
			if (s2 < 0 && s3 == 0)
				idx = 2;
			else if (s2 >= 1 && s3 == 0)
				idx = 3;
			else if (s2 < 0 && s3 != 0)
				idx = 10;
			else if (s2 >= 1 && s3 != 0)
				idx = 0xb;
			else
				return;
		} else if (s1 > 0 && s2 < 0 && s3 == 0)
			idx = 4;
		else if (s1 > 0 && s2 > 0 && s3 == 0)
			idx = 5;
		else if (s1 < 0 && s2 < 0 && s3 == 0)
			idx = 6;
		else if (s1 < 0 && s2 > 0 && s3 == 0)
			idx = 7;
		else if (s1 >= 1 && s2 == 0 && s3 != 0)
			idx = 8;
		else if (s1 < 0 && s2 == 0 && s3 != 0)
			idx = 9;
		else if (s1 > 0 && s2 < 0 && s3 != 0)
			idx = 0xc;
		else if (s1 > 0 && s2 > 0 && s3 != 0)
			idx = 0xd;
		else if (s1 < 0 && s2 < 0 && s3 != 0)
			idx = 0xe;
		else if (s1 < 0 && s2 >= 1 && s3 != 0)
			idx = 0xf;
		else
			return;
	}
	if (idx != f_2DA) {
		f_2DA = idx;
		int r = FUNC_100ADB70(idx);
		if (r)
			FUNC_100AD230(r, (int)&DAT_10116dd8 + f_2D6 * 0x10,
				0x40800000, 0, 0, 0, 0, 0);
	}
}

// --- @ 0xB02D0 (688): thiscall set-special-action dispatcher ---
struct s02D0 {
	char _0[0x44];
	int f_44;
	char _48[0x279];
	int f_2C1;
	int f_2C5;
	char _2C9[0x0];
	void FUNC_100B02D0(int);
};
void s02D0::FUNC_100B02D0(int act)
{
	float v[3];
	char m[48];
	int *pu = &f_2C5;
	if (f_2C5)
		FUNC_100ADC00();
	FUNC_1009EB10(m);
	switch (act) {
	case 4:
		FUNC_100B2310(&DAT_100ece98, 0x5cd, (double)v[0], (double)v[1], (double)v[2], pu);
		if (FUNC_100B3C30(*pu)) {
			FUNC_100B2310(&DAT_100ed12c, f_44, *pu, dbl_100e8dd8, dbl_100e8dd8,
				dbl_100e8dd8, 6, 0x10, &DAT_100ed210, &DAT_100ed210, -1);
			f_2C1 = 4;
			return;
		}
		break;
	case 1:
		FUNC_100B2310(&DAT_100ece98, 0x607, (double)v[0], (double)v[1], (double)v[2], pu);
		if (FUNC_100B3C30(*pu)) {
			FUNC_100B2310(&DAT_100ed12c, f_44, *pu, dbl_100ed298, dbl_100ed2a0,
				dbl_100ed2a8, 6, 0x10, &DAT_100ed210, &DAT_100ed210, -1);
			f_2C1 = 1;
			return;
		}
		break;
	case 2:
		FUNC_100B2310(&DAT_100ece98, 0x5ce, (double)v[0], (double)v[1], (double)v[2], pu);
		if (FUNC_100B3C30(*pu)) {
			FUNC_100B2310(&DAT_100ed12c, f_44, *pu, dbl_100ed298, dbl_100ed2a0,
				dbl_100ed290, 6, 0x10, &DAT_100ed210, &DAT_100ed210, -1);
			f_2C1 = 2;
			return;
		}
		break;
	case 3:
		FUNC_100B2310(&DAT_100ece98, 0x60a, (double)v[0], (double)v[1], (double)v[2], pu);
		if (FUNC_100B3C30(*pu)) {
			FUNC_100B2310(&DAT_100ed12c, f_44, *pu, dbl_100ed280, dbl_100ea960,
				dbl_100ed288, 6, 0x10, &DAT_100ed210, &DAT_100ed210, -1);
			f_2C1 = 3;
			return;
		}
		break;
	default:
		return;
	}
	*pu = 0;
}
