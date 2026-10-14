// w4 scratch batch 1
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;

extern "C" int __stdcall FUNC_100A7A40(int);
extern "C" void __cdecl FUNC_100B3090();
extern "C" void __cdecl FUNC_100B31A0();
extern "C" void __stdcall FUNC_100BA7D0(void *, int);
extern "C" DWORD dword_1011742C;
extern "C" float flt_859524;
extern "C" float flt_859520;

// --- CGame::GetHudVertScale @ 0xB2AD0 (16) ---
float FUNC_100B2AD0()
{
	return *(float *)0x859524;
}

// --- CGame::GetHudHorizScale @ 0xB2AE0 (16) ---
float FUNC_100B2AE0()
{
	return *(float *)0x859520;
}

// --- GameDisableCheatCodes @ 0xB3B60 (16) ---
void FUNC_100B3B60()
{
}

// --- @ 0xB7690 (16) : return 0 ---
int FUNC_100B7690()
{
	return 0;
}

// --- model-info getters @ 0xB4100 / 0xB4140 / 0xB4180 (64 each) ---
int FUNC_100B4100(int iModel)
{
	int *p;
	if (iModel < 0)
		return 0;
	if (iModel > 0x7530)
		return 0;
	p = (int *)FUNC_100A7A40(iModel);
	if (!p)
		return 0;
	if (*p != 0x85bdc0)
		return 0;
	p = (int *)FUNC_100A7A40(iModel);
	return *(int *)(*p + 0x28);
}

int FUNC_100B4140(int iModel)
{
	int *p;
	if (iModel < 0)
		return 0;
	if (iModel > 0x7530)
		return 0;
	p = (int *)FUNC_100A7A40(iModel);
	if (!p)
		return 0;
	if (*p != 0x85bdc0)
		return 0;
	p = (int *)FUNC_100A7A40(iModel);
	return *(int *)(*p + 0x2c);
}

int FUNC_100B4180(int iModel)
{
	int *p;
	if (iModel < 0)
		return 0;
	if (iModel > 0x7530)
		return 0;
	p = (int *)FUNC_100A7A40(iModel);
	if (!p)
		return 0;
	if (*p != 0x85bdc0)
		return 0;
	p = (int *)FUNC_100A7A40(iModel);
	return *(int *)(*p + 0x24);
}

// --- @ 0xB1D70 (16): if(!p) return 0; return *(p+4) ---
int FUNC_100B1D70(void *p)
{
	if (!p)
		return 0;
	return *(int *)((char *)p + 4);
}

// --- @ 0xB13F0 (32): vtable call through global object ---
#pragma optimize("y", off)
int FUNC_100B13F0(int a1, int a2)
{
	typedef int (__cdecl *fn2)(int, int);
	(*(fn2 **)0xc97b24)[8](a1, a2);
	return a2;
}
#pragma optimize("y", on)

// --- @ 0xB3A80 (32): local filled by helper ---
int FUNC_100B3A80()
{
	int x;
	x = 0;
	FUNC_100BA7D0(&x, 4);
	return x;
}

// --- @ 0xB6530 (32): forward 3 args through fn ptr global ---
int __stdcall FUNC_100B6530(int a1, int a2, int a3)
{
	return ((int(__cdecl *)(int, int, int))dword_1011742C)(a1, a2, a3);
}

// --- byte getters via FUNC_100A7A40 @ 0xB64A0 ---
BYTE __stdcall FUNC_100B64A0(int iModel)
{
	BYTE *p = (BYTE *)FUNC_100A7A40(iModel);
	BYTE r = 0;
	if (p)
		r = p[0x12];
	return r;
}

// --- word getter @ 0xB64C0 ---
WORD __stdcall FUNC_100B64C0(int iModel)
{
	BYTE *p = (BYTE *)FUNC_100A7A40(iModel);
	WORD r = 0;
	if (p)
		r = *(WORD *)(p + 0x12);
	return r;
}

// --- thiscall field_9A3 dispatch @ 0xB3480 ---
struct sB3480 {
	char _0[0x9a3];
	int field_9A3;
	void FUNC_100B3480();
};
void sB3480::FUNC_100B3480()
{
	if (field_9A3 != -1)
		FUNC_100B3090();
	else
		FUNC_100B31A0();
}

// --- thiscall byte getter @ 0xB3B00 ---
struct s3B00 {
	char _0[0x0c];
	BYTE f_C;
	BYTE FUNC_100B3B00();
};
BYTE s3B00::FUNC_100B3B00()
{
	return f_C;
}

// --- thiscall dword getters 0xB8220 / 0xB8240 ---
struct s8220 {
	char _0[0x50];
	int f_50;
	int f_54;
	int FUNC_100B8220();
	int FUNC_100B8240();
};
int s8220::FUNC_100B8220() { return f_50; }
int s8220::FUNC_100B8240() { return f_54; }

// --- thiscall getters 0xB95F0 (dword@2) / 0xBAAE0 (dword@0x12) / 0xBAAF0 (byte@0x1a) ---
struct s95F0 {
	char _0[2];
	int f_2;
	int FUNC_100B95F0();
};
int s95F0::FUNC_100B95F0() { return f_2; }

struct sAAE0 {
	char _0[0x12];
	int f_12;
	char _pad[4];
	BYTE f_1a;
	int FUNC_100BAAE0();
	BYTE FUNC_100BAAF0();
};
int sAAE0::FUNC_100BAAE0() { return f_12; }
BYTE sAAE0::FUNC_100BAAF0() { return f_1a; }
