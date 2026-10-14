// w4 scratch batch 7 - f_4C family accessors
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" int __cdecl FUNC_100B61E0(int);
extern "C" int __stdcall FUNC_100B3BD0(int);
extern "C" int __cdecl FUNC_100B3C60(void);
extern "C" float flt_100e5940;
extern "C" float flt_100e5b2c;
extern "C" float flt_100e6114;
extern "C" float flt_100e6110;

struct s7X {
	char _0[0x44];
	int f_44;
	char _48[4];
	int f_4C;
	int FUNC_100B7420();
	void FUNC_100B74D0(BYTE);
	void FUNC_100B75A0(int);
	int FUNC_100B7630();
	void FUNC_100B7900(float);
	BYTE FUNC_100B7A30();
	void FUNC_100B7AC0(int, int, BYTE);
};

int s7X::FUNC_100B7420()
{
	if (f_4C) {
		int i = FUNC_100B3C60();
		if (i && (*(unsigned *)(i + 0x46c) & 0x100) &&
			f_4C == *(int *)(i + 0x58c))
			return 1;
	}
	return 0;
}

void s7X::FUNC_100B74D0(BYTE v)
{
	if (f_4C && FUNC_100B3BD0(f_44)) {
		if (f_4C && FUNC_100B61E0(f_4C) == 4)
			return;
		if (f_4C && FUNC_100B61E0(f_4C) == 5)
			return;
		if (f_4C && FUNC_100B61E0(f_4C) == 3)
			return;
		*(BYTE *)(f_4C + 0x1f6) = v;
		*(BYTE *)(f_4C + 0x514) = v;
	}
}

#pragma optimize("y", off)
void s7X::FUNC_100B75A0(int v)
{
	volatile int t0 = 0;
	volatile int t1 = 0;
	if (f_4C && FUNC_100B61E0(f_4C) == 5) {
		float f = *(float *)(f_4C + 0x9cc);
		if (v == 1) {
			if (f == flt_100e5940)
				((void(__cdecl *)())0x6cac20)();
		} else if (v == 0 && f == flt_100e5b2c) {
			((void(__cdecl *)())0x6cac70)();
		}
	}
}

int s7X::FUNC_100B7630()
{
	volatile int t0 = 0;
	volatile int t1 = 0;
	if (f_4C && FUNC_100B61E0(f_4C) == 5) {
		if (*(float *)(f_4C + 0x9cc) != flt_100e5940)
			return 1;
	}
	return 0;
}

void s7X::FUNC_100B7900(float v)
{
	if (v <= flt_100e6114 && flt_100e6110 <= v && f_4C)
		*(float *)(f_4C + 0x5a4) = v;
}

BYTE s7X::FUNC_100B7A30()
{
	int e;
	BYTE r;
	char c;
	if (!f_4C)
		return 0;
	if (FUNC_100B61E0(f_4C) == 1) {
		e = f_4C;
		r = (*(char *)(e + 0x5a5) != 0) << 1;
		if (*(char *)(e + 0x5a6))
			r |= 1;
		r <<= 1;
		if (*(char *)(e + 0x5a7))
			r |= 1;
		c = *(char *)(e + 0x5a8);
	} else {
		if (!f_4C)
			return 0;
		if (FUNC_100B61E0(f_4C) != 2)
			return 0;
		r = *(char *)(f_4C + 0x65c) != 0;
		c = *(char *)(f_4C + 0x65d);
	}
	r <<= 1;
	if (c)
		r |= 1;
	return r;
}

void s7X::FUNC_100B7AC0(int a, int b, BYTE c)
{
	int e;
	if (!f_4C)
		return;
	if (FUNC_100B61E0(f_4C) != 1) {
		if (!f_4C)
			return;
		if (FUNC_100B61E0(f_4C) != 5)
			return;
	}
	if (a == 0 && b == 0 && c == 0) {
		e = f_4C;
		if (*(int *)(e + 0x5b4) || *(int *)(e + 0x5a9) || *(int *)(e + 0x5b0))
			((void(__cdecl *)())0x6a3440)();
	}
}
