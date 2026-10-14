// w4 scratch batch 15 - small CRT helpers
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" int __cdecl FUNC_100D97F0(int, int, int);
extern "C" int __cdecl FUNC_100DF8C0(int, int, int, int);
extern "C" int DAT_100e5290;
extern "C" void *__cdecl memset(void *, int, unsigned);

// --- @ 0xCF641 / 0xD4CA3 (9): va_arg int fetcher ---
int __fastcall FUNC_100CF641(int *ap)
{
	*ap += 1;
	return *(int *)(*ap - 1);
}
int __fastcall FUNC_100D4CA3(int *ap)
{
	*ap += 1;
	return *(int *)(*ap - 1);
}

// --- @ 0xCF64A / 0xD4CAC (12): va_arg int64 fetcher ---
long long __fastcall FUNC_100CF64A(int *ap)
{
	*ap += 2;
	return *(long long *)(*ap - 2);
}
long long __fastcall FUNC_100D4CAC(int *ap)
{
	*ap += 2;
	return *(long long *)(*ap - 2);
}

// --- @ 0xCF656 (10): va_arg short fetcher ---
short __fastcall FUNC_100CF656(int *ap)
{
	*ap += 1;
	return *(short *)(*ap - 1);
}

// --- @ 0xD5C1F (21): extract double exponent ---
int __cdecl FUNC_100D5C1F(double d)
{
	return (short)(((*(unsigned *)((char *)&d + 2)) >> 4 & 0xffff07ff) - 0x3fe);
}

// --- @ 0xD78BC (12): zero the 96-bit mantissa ---
void __fastcall FUNC_100D78BC(void *pd)
{
	memset(pd, 0, 12);
}
// --- @ 0xC6274 (6): tail-jump through import ---
int __cdecl FUNC_100C6274(int a)
{
	return ((int(__cdecl *)(int))DAT_100e5290)(a);
}

// --- @ 0xDF4E0 (28): booleanized 3-arg call ---
int __cdecl FUNC_100DF4E0(int a, int b, int c)
{
	return !FUNC_100D97F0(a, c, 0x10);
}

#pragma optimize("y", off)
// --- @ 0xDF5E0..DF640 (20/20/21/21): thiscall flag stores ---
struct sDF {
	int f0;
	int f4;
	void FUNC_100DF5E0();
	void FUNC_100DF600();
	void FUNC_100DF620();
	void FUNC_100DF640();
	void FUNC_100DFA60(int, int, int);
	void FUNC_100DFA90(int, int, int);
};
void sDF::FUNC_100DF5E0() { f0 = 1; }
void sDF::FUNC_100DF600() { f0 = 0; }
void sDF::FUNC_100DF620() { f4 = 1; }
void sDF::FUNC_100DF640() { f4 = 0; }

// --- @ 0xDFA60 / 0xDFA90 (41): set flag then dispatch ---
void sDF::FUNC_100DFA60(int a, int b, int c)
{
	FUNC_100DF5E0();
	FUNC_100DF8C0((int)this, a, b, c);
}
void sDF::FUNC_100DFA90(int a, int b, int c)
{
	FUNC_100DF620();
	FUNC_100DF8C0((int)this, a, b, c);
}
