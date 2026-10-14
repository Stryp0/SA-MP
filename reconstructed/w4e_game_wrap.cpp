// w4 scratch batch 5
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;

extern "C" int __stdcall FUNC_100A7A40(int);
extern "C" DWORD dword_1026eb28;
extern "C" int __cdecl FUNC_1009C8C0(void);
extern "C" int __cdecl FUNC_1009C8B0(int);
extern "C" void __cdecl FUNC_100AFC70(void *, void *);
extern "C" void __cdecl FUNC_100B3B10(void *, void *, void *, int *, int, int, int, int, int, int, int, int);
extern "C" int __cdecl FUNC_100AF890(void *);
extern "C" int __thiscall_member_unused__;
extern "C" int __cdecl FUNC_100A0330(int, int, int, int, int, int, int, int, int, int);
extern "C" void __cdecl FUNC_1009F630(int);
extern "C" void __cdecl FUNC_1009F040(int, int, int);
extern "C" int __cdecl FUNC_100B10E0(void *);

// --- @ 0xB4680 (64): model flags word getter ---
unsigned FUNC_100B4680(int m)
{
	int p = FUNC_100A7A40(m);
	if (p)
		return *(unsigned short *)(p + 10);
	return 0xffffffff;
}

// --- @ 0xB67B0 (160): copy 16 dwords from selected entity record ---
int FUNC_100B67B0(int p1, int *p2, int p3)
{
	int *q;
	if (p1 && *(int *)p1 != 0x863c40) {
		q = (int *)(p1 + 0x18);
		if (*q) {
			int fsel = dword_1026eb28 != 1 ? 0x7c51e0 : 0x7c51a0;
			int r1 = ((int(__cdecl *)(int))0x734a40)(*q);
			int r2 = ((int(__cdecl *)(int, int))fsel)(r1, p3);
			int *src = (int *)(*(int *)(r1 + 8) + r2 * 0x40);
			int i;
			for (i = 0x10; i; i--)
				*p2++ = *src++;
			return 1;
		}
	}
	return 0;
}

// --- @ 0xB10E0 (176): thiscall weapon-fire check -> out vec3 ---
struct s10E0 {
	char _0[0x2a4];
	int f_2A4;
	char _2A8[8];
	char f_2B0;
	int FUNC_100B10E0(int *);
};
int s10E0::FUNC_100B10E0(int *out)
{
	char c;
	int hit = 0;
	float tmp1[12];
	float tmp2[12];
	float res[3];
	if (!f_2A4)
		return 0;
	if (!f_2B0)
		c = (char)FUNC_1009C8C0();
	else
		c = (char)FUNC_1009C8B0((f_2A4 & ~0xff) | (int)f_2B0);
	if (c == '5' || c == '7' || c == 'A') {
		FUNC_100AFC70(tmp1, tmp2);
		FUNC_100B3B10(tmp1, tmp2, res, &hit, 0, 1, 1, 1, 0, 0, 0, 0);
		if (hit) {
			out[0] = *(int *)&res[0];
			out[1] = *(int *)&res[1];
			out[2] = *(int *)&res[2];
		}
		return hit;
	}
	return 0;
}

// --- @ 0xB1190 / 0xB12F0: thiscall checkpoint spawn/clear ---
extern "C" long __cdecl __time32(long *);
extern "C" void __cdecl FUNC_100CB069(long);
struct s1190 {
	char _0[0x2f9];
	int f_2F9;
	void FUNC_100B1190();
	void FUNC_100B12F0();
};
void s1190::FUNC_100B1190()
{
	int lc[3];
	if (FUNC_100AF890(lc)) {
		if (!f_2F9) {
			long t = __time32(0);
			FUNC_100CB069(t);
			f_2F9 = FUNC_100A0330(0x4b52, 0, 0, 0, 0, 0, 0, 0x43480000, 0, 0);
			FUNC_1009F630(0);
			((void(__fastcall *)(int))(*(int **)f_2F9)[1])(f_2F9);
		}
		FUNC_1009F040(lc[0], lc[1], lc[2]);
		return;
	}
	if (f_2F9) {
		((void(__fastcall *)(int, int))(*(int **)f_2F9)[0])(f_2F9, 1);
		f_2F9 = 0;
	}
}
void s1190::FUNC_100B12F0()
{
	int lc[3];
	if (FUNC_100B10E0(lc)) {
		if (!f_2F9) {
			long t = __time32(0);
			FUNC_100CB069(t);
			f_2F9 = FUNC_100A0330(0xbf9, 0, 0, 0, 0, 0, 0, 0x43480000, 0, 0);
			FUNC_1009F630(0);
			((void(__fastcall *)(int))(*(int **)f_2F9)[1])(f_2F9);
		}
		FUNC_1009F040(lc[0], lc[1], lc[2]);
		return;
	}
	if (f_2F9) {
		((void(__fastcall *)(int, int))(*(int **)f_2F9)[0])(f_2F9, 1);
		f_2F9 = 0;
	}
}
