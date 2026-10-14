// w4 scratch batch 8
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" float flt_100e60a0;
extern "C" DWORD DAT_00b74498;
extern "C" DWORD DAT_100ed524;
extern "C" DWORD DAT_100ed538;
extern "C" DWORD DAT_100ed54c;
extern "C" DWORD DAT_100ed560;
extern "C" int __cdecl FUNC_100B2310(void *, int, ...);
extern "C" float __cdecl FUNC_1009F0C0(void);
extern "C" int __cdecl FUNC_100B7130(void);
extern "C" void __cdecl FUNC_1009F400(void);
extern "C" void __cdecl FUNC_1009EF50(int);

// --- @ 0xB65A0 (48): pair return thunk ---
#pragma optimize("y", off)
long long FUNC_100B65A0(int a1, int a2)
{
	int r = ((int(__cdecl *)(int, int))0x411e70)(a1, a2);
	return ((long long)a2 << 32) | (unsigned)r;
}
#pragma optimize("y", on)

// --- @ 0xB4760 (144): iterate entity table with SEH guard ---
void FUNC_100B4760(unsigned model, int a2)
{
	__try {
		int arr[15];
		int *p;
		int i;
		for (i = 0xf; i; i--)
			*p++ = 0;
		p = arr;
		for (i = 0xf; i; i--)
			*p++ = 0;
	} __finally {
	}
	int e = *(int *)((char *)&DAT_00b74498 + 4);
	int n = 14000;
	do {
		if (e && model == *(unsigned short *)(e + 0x22)) {
			FUNC_1009F400();
			FUNC_1009EF50(a2);
		}
		e += 0x38;
	} while (--n);
}

// --- @ 0xB76E0 (352): thiscall pickup/spawn state machine ---
struct s76E0 {
	char _0[0x44];
	int f_44;
	char _48[0x1d];
	char f_65;
	char _66[0x0e];
	int f_B4;
	char _B8[0x0c];
	int f_4C;
	char _50[0x14];
	void FUNC_100B76E0();
};
void s76E0::FUNC_100B76E0()
{
	if (!f_4C)
		return;
	if (*(char *)((char *)this + 100) == 0) {
		if (f_65 && f_B4) {
			FUNC_100B2310(&DAT_100ed538, f_B4);
			f_65 = 0;
			f_B4 = 0;
		}
		float f = FUNC_1009F0C0();
		if (f >= flt_100e60a0 || FUNC_100B7130()) {
			if ((FUNC_100B7130() || FUNC_1009F0C0() >= flt_100e60a0) && f_B4) {
				FUNC_100B2310(&DAT_100ed538, f_B4);
				f_B4 = 0;
			}
		} else if (!f_B4) {
			FUNC_100B2310(&DAT_100ed524, f_44, 1, 2, &f_B4);
			FUNC_100B2310(&DAT_100ed54c, f_B4, 0x3ec);
		}
	} else if (f_65 == 0) {
		int *pb = &f_B4;
		if (f_B4) {
			FUNC_100B2310(&DAT_100ed538, f_B4);
			*pb = 0;
		}
		FUNC_100B2310(&DAT_100ed524, f_44, 1, 3, pb);
		FUNC_100B2310(&DAT_100ed54c, *pb, 0x3ee);
		FUNC_100B2310(&DAT_100ed560, *pb, 3);
		f_65 = 1;
	}
}
