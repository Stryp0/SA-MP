// w4 scratch batch 2 — game-code wrappers and getters
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;

extern "C" int __stdcall FUNC_100A7A40(int);
extern "C" int __cdecl FUNC_100B1410(DWORD);
extern "C" void __cdecl FUNC_100B14C0(void *, void *, int);
extern "C" int __cdecl FUNC_100B4680(int);
extern "C" int __cdecl FUNC_100B39F0(int);
extern "C" void __cdecl FUNC_100B39B0(int);
extern "C" void __cdecl FUNC_100B39D0(int);
extern "C" void __fastcall FUNC_100AECB0(void *);
extern "C" DWORD dword_1026eb28;

// --- @ 0xB1450 (32): if (p && *p == 1) return p + 0x7c ---
int FUNC_100B1450(char *p)
{
	if (p && *p == 1)
		return (int)(p + 0x7c);
	return 0;
}

// --- @ 0xB1470 (32): clear field of model record ---
void FUNC_100B1470(int iModel)
{
	int *p = (int *)FUNC_100A7A40(iModel);
	if (p)
		p[5] = 0;
}

// --- @ 0xB1680 (32): return arg if first byte == 1 ---
int FUNC_100B1680(BYTE *p)
{
	return *p == 1 ? (int)p : 0;
}

// --- @ 0xB1660 (32): stdcall, forward [a+4] ---
void __stdcall FUNC_100B1660(void *a)
{
	void *p = *(void **)((char *)a + 4);
	if (p)
		FUNC_100B14C0(p, (void *)0x100b15c0, 0);
}

#pragma optimize("y", off)
// --- @ 0xB1D80 (32): two GTA calls through absolute addrs ---
int FUNC_100B1D80(int a1)
{
	int r = ((int (__cdecl *)(int))0x734a40)(a1);
	return ((int (__cdecl *)(int))0x7c51d0)(r);
}

// --- @ 0xB2170 (48): local holds result of GTA call ---
int FUNC_100B2170(int a1)
{
	int r = 0;
	r = ((int (__cdecl *)(int))0x4d60e0)(a1);
	return r;
}

// --- @ 0xB2260 (48): fp-select then call(1) ---
void FUNC_100B2260()
{
	void (__cdecl *fp)(int);
	fp = (void (__cdecl *)(int))(dword_1026eb28 == 1 ? 0x7f3560 : 0x7f35a0);
	fp(1);
}

// --- @ 0xB2290 (64): bounded lookup ---
int FUNC_100B2290(DWORD a1, int a2, int a3)
{
	int r = FUNC_100B1410(a2);
	if (!r)
		return 0;
	if (a3 > r)
		return 0;
	volatile int t = 0;
	t = *(int *)(a2 + 8) - 0x40;
	return t;
}

// --- @ 0xB1490 (48): call fixed GTA addr with 3 args ---
int FUNC_100B1490(int a1, int a2, int a3)
{
	int r = 0;
	int (__cdecl *fp)(int, int, int) = (int (__cdecl *)(int, int, int))0x749b70;
	r = fp(a1, a2, a3);
	return r;
}

// --- @ 0xB14C0 (64): fp-select then 3-arg call ---
int FUNC_100B14C0B(int a1, int a2, int a3)
{
	int (__cdecl *fp)(int, int, int);
	int r;
	fp = (int (__cdecl *)(int, int, int))(dword_1026eb28 == 1 ? 0x7f1200 : 0x7f1240);
	r = fp(a1, a2, a3);
	return r;
}

// --- @ 0xB1E40 (64): fp-select variant ---
int FUNC_100B1E40(int a1, int a2, int a3)
{
	int r = 0;
	int (__cdecl *fp)(int, int, int);
	fp = (int (__cdecl *)(int, int, int))(dword_1026eb28 == 1 ? 0x7ec9d0 : 0x7eca10);
	r = fp(a1, a2, a3);
	return r;
}

// --- @ 0xB2040 (96): model lookup + GTA thiscall ---
int FUNC_100B2040(int iModel)
{
	int *p;
	int m2;
	int r;
	p = (int *)FUNC_100A7A40(iModel);
	if (!p)
		return 0;
	m2 = FUNC_100B4680(iModel);
	((void(__fastcall *)(int *))0x4c4d50)(p);
	r = FUNC_100B39F0(m2);
	if (!r) {
		FUNC_100B39B0(m2);
		FUNC_100B39D0(m2);
	}
	return 1;
}

#pragma optimize("y", on)
// --- @ 0xB1270 (48): thiscall dispatch ---
struct sB1270 {
	char _0[0x2de];
	int f_2DE;
	int f_2E2;
	void FUNC_100B1270();
};
extern "C" void __fastcall FUNC_100B0760(void *);
void sB1270::FUNC_100B1270()
{
	if (f_2DE)
		FUNC_100B0760(this);
	if (f_2E2)
		FUNC_100AECB0(this);
}

// --- @ 0xB78E0 (32): thiscall float getter with fallback ---
struct sB78E0 {
	char _0[0x4c];
	int f_4C;
	float FUNC_100B78E0();
};
float sB78E0::FUNC_100B78E0()
{
	if (!f_4C)
		return *(float *)0x100e5940;
	return *(float *)(f_4C + 0x5a4);
}
