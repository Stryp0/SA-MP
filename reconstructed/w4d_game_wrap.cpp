// w4 scratch batch 4
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;

extern "C" int __stdcall FUNC_100A7A40(int);
extern "C" int __cdecl FUNC_100680F0(void *, const char *, ...);
extern "C" int __cdecl FUNC_100B14C0(int, int, int);
extern "C" int __cdecl FUNC_100B4F10(int, int, int, int, int, int, int, int, int, int, int, int, int);
extern "C" int __stdcall FUNC_100B3BD0(int);
extern "C" int __cdecl FUNC_100B2310(void *, int, ...);
extern "C" DWORD dword_1026eb28;
extern "C" DWORD dword_1026eb80;
extern "C" DWORD DAT_00c97b20;
extern "C" void __cdecl free(void *);

// --- @ 0xB1500 / 0xB1510: call-through thunks returning arg ---
#pragma optimize("y", off)
int FUNC_100B1500(int a1)
{
	((void(__cdecl *)(int))0x74c800)(a1);
	return a1;
}
int FUNC_100B1510(int a1)
{
	((void(__cdecl *)(int, int))0x74c7d0)(a1, 0xfff);
	return a1;
}
#pragma optimize("y", on)

// --- @ 0xB1530 (64): stdcall getter p->f_34 ---
int __stdcall FUNC_100B1530(int p)
{
	volatile int r = 0;
	if (p)
		r = *(int *)(p + 0x34);
	return r;
}

// --- @ 0xB1570 (80): release old vtbl obj, store new ---
void __stdcall FUNC_100B1570(int p, int v)
{
	volatile int *r;
	if (!p)
		return;
	r = *(int **)(p + 0x34);
	if (!r)
		return;
	((void(__fastcall *)(int))(*(int **)r)[2])((int)r);
	*(int *)(p + 0x34) = v;
}

// --- @ 0xB15C0 (160): dump object fields via handler ---
void *FUNC_100B15C0(char *p)
{
	if (*(char *)p == 1) {
		int *o = *(int **)(p + 0x18);
		if (o) {
			DWORD h = dword_1026eb80;
			int n = o[9];
			if (h)
				FUNC_100680F0((void *)h, (const char *)0x100ed304, n);
			for (int i = 0; i < n; i++) {
				int e = ((int *)o[8])[i];
				if (!e)
					continue;
				int e0 = *(int *)e;
				h = dword_1026eb80;
				if (e0) {
					if (!h)
						continue;
					FUNC_100680F0((void *)h, (const char *)0x100ed2e0, i, e0 + 0x10);
				} else {
					if (!h)
						continue;
					FUNC_100680F0((void *)h, (const char *)0x100ed2bc, i);
				}
			}
		}
	}
	return p;
}

// --- @ 0xB16A0 (48): call B14C0 on a1->f_4 ---
void __stdcall FUNC_100B16A0(int *a1)
{
	int e = a1[1];
	if (e)
		FUNC_100B14C0(e, 0x100b1680, 0);
}

// --- @ 0xB21A0 / 0xB2200: versioned call returning pair ---
long long FUNC_100B21A0(int a1)
{
	typedef int(__cdecl *fn7)(int, int, int, int, int, int, int);
	fn7 fp = (fn7)((-(int)(dword_1026eb28 != 1) & 0x50) + 0x74bdd0);
	int r;
	DAT_00c97b20 = 0;
	r = fp(0, a1, 0x41b1a0, 0x41b1c0, 0x41b1b0, (int)fp, 0);
	DAT_00c97b20 = 1;
	return ((long long)0x41b1b0 << 32) | (unsigned)r;
}
long long FUNC_100B2200(int a1, int a2)
{
	typedef int(__cdecl *fn6)(int, int, int, int, int, int);
	fn6 fp = (fn6)((-(int)(dword_1026eb28 != 1) & 0x50) + 0x74be70);
	int r;
	DAT_00c97b20 = 0;
	r = fp(a1, a2, 0x41b2f0, 0x41b300, (int)fp, 0);
	DAT_00c97b20 = 1;
	return ((long long)0x41b300 << 32) | (unsigned)r;
}

// --- @ 0xB6850 (48): two call-through ---
int FUNC_100B6850(void)
{
	int r;
	r = ((int(__cdecl *)(int, int))0x40fc30)(0x30, 0);
	((void(__cdecl *)())0x40fb60)();
	return r;
}

// --- @ 0xB6880: fastcall range check + call ---
long long __fastcall FUNC_100B6880(int a1_ecx, unsigned a2_edx, int p3, unsigned p4, int p5)
{
	if (p4 < *(unsigned *)(p3 + 4))
		return (long long)a2_edx << 32;
	((void(__cdecl *)(int, int, int))0x537ce0)(p3 + 0x20, *(int *)(p3 + 4) - 0x18, p5);
	return 1;
}

// --- @ 0xB68C0: thiscall scalar deleting dtor ---
struct s68C0 {
	int f_0;
	char _4[9];
	char f_D;
	s68C0 *FUNC_100B68C0(BYTE flag);
};
s68C0 *s68C0::FUNC_100B68C0(BYTE flag)
{
	if (f_D && f_0) {
		free((void *)f_0);
		f_0 = 0;
	}
	if (flag & 1)
		free(this);
	return this;
}

// --- @ 0xB6A80: forward 13 args ---
void FUNC_100B6A80(int *p1, int p2)
{
	FUNC_100B4F10(p1[0], p1[1], p1[2], p1[3], p2, p2 + 4, p2 + 8, p2 + 0x10,
		p2 + 0x14, p2 + 0x18, p2 + 0x20, p2 + 0x24, p2 + 0x28);
}

// --- @ 0xB7190: thiscall toggle field via B2310 ---
struct s7190 {
	char _0[0x44];
	int f_44;
	char _48[4];
	int f_4C;
	char _50[8];
	int f_58;
	void FUNC_100B7190(int);
};
void s7190::FUNC_100B7190(int on)
{
	if (f_4C) {
		if (FUNC_100B3BD0(f_44) && **(int **)f_4C != 0x863c40) {
			if (on) {
				FUNC_100B2310((void *)0x100ed59c, f_44, 1, 1, 1, 1, 1);
				FUNC_100B2310((void *)0x100ed68c, f_44, 0);
				f_58 = 1;
			} else {
				FUNC_100B2310((void *)0x100ed59c, f_44, 0, 0, 0, 0, 0);
				FUNC_100B2310((void *)0x100ed68c, f_44, 1);
				f_58 = 0;
			}
		}
	}
}
