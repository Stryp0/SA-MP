// w4 scratch batch 9 - more f_4C accessors
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" int __cdecl FUNC_100B61E0(int);
extern "C" int __stdcall FUNC_100B3BD0(int);
extern "C" int __cdecl FUNC_100B2310(void *, int, ...);
extern "C" int __cdecl FUNC_1001EB90(int);
extern "C" int __cdecl FUNC_10001150(int);
extern "C" int __cdecl FUNC_10001120(int);
extern "C" void __cdecl FUNC_100A0940(int, int);
extern "C" void __cdecl FUNC_100A0960(void);
extern "C" DWORD DAT_1026eb94;
extern "C" DWORD DAT_1026dfd8;
extern "C" DWORD DAT_100ed63c;
extern "C" DWORD DAT_100ed650;
extern "C" DWORD DAT_100ed664;
extern "C" void __stdcall Sleep(DWORD);

struct s7CX {
	char _0[0x44];
	int f_44;
	char _48[4];
	int f_4C;
	int FUNC_100B7CF0();
	int FUNC_100B7D70();
	int FUNC_100B7E00();
	void FUNC_100B7E50(char);
	int FUNC_100B7EB0();
	int FUNC_100B7FC0(short);
};

int s7CX::FUNC_100B7CF0()
{
	if (f_4C) {
		int t = FUNC_100B61E0(f_4C);
		if (t != 2 && t != 4 && t != 7 && t != 6) {
			int e = *(int *)(f_4C + 0x4c4);
			if (e && DAT_1026eb94) {
				int u = FUNC_1001EB90(e);
				if ((short)u != -1) {
					if (FUNC_10001150(u))
						return FUNC_10001120(u);
				}
			}
			return 0;
		}
	}
	return 0;
}

int s7CX::FUNC_100B7D70()
{
	if (f_4C && FUNC_100B3BD0(f_44)) {
		short s = *(short *)(f_4C + 0x22);
		if (s == 0x1b3 || s == 0x1c2 || s == 0x248 || s == 0x24f ||
			s == 0x25e || s == 0x25f || s == 0x260 || s == 0x262 ||
			s == 0x263)
			return 1;
	}
	return 0;
}

int s7CX::FUNC_100B7E00()
{
	if (f_4C && FUNC_100B3BD0(f_44)) {
		short s = *(short *)(f_4C + 0x22);
		if (s == 0x1b9 || s == 0x1d0 || s == 0x1d1 || s == 0x252 ||
			s == 0x1f5 || s == 0x234)
			return 1;
	}
	return 0;
}

void s7CX::FUNC_100B7E50(char v)
{
	if (f_4C && FUNC_100B3BD0(f_44)) {
		if (!v) {
			*(BYTE *)(f_4C + 0x4a8) |= 8;
			*(BYTE *)(f_4C + 0x428) &= 0xbf;
			return;
		}
		*(BYTE *)(f_4C + 0x4a8) &= 0xf7;
		*(BYTE *)(f_4C + 0x428) |= 0x40;
	}
}

int s7CX::FUNC_100B7EB0()
{
	if (f_4C && FUNC_100B3BD0(f_44))
		return (*(BYTE *)(f_4C + 0x4a8) >> 3) & 1;
	return 1;
}

int s7CX::FUNC_100B7FC0(short id)
{
	int local_4;
	if (!f_4C || !FUNC_100B3BD0(f_44) ||
		!f_4C || FUNC_100B61E0(f_4C) != 1)
		return 0;
	local_4 = (int)this;
	DAT_1026dfd8 = id;
	if (!FUNC_100B2310(&DAT_100ed650, id)) {
		FUNC_100A0940(id, 2);
		FUNC_100A0960();
		FUNC_100B2310(&DAT_100ed664, id);
		int n = 0x14;
		do {
			if (FUNC_100B2310(&DAT_100ed650, id))
				break;
			Sleep(1);
		} while (--n);
	}
	if (!FUNC_100B2310(&DAT_100ed650, id))
		return 0;
	FUNC_100B2310(&DAT_100ed63c, f_44, id, &local_4);
	return 1;
}
