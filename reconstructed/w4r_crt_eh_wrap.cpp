// w4 scratch batch 17 - CRT/EH small funcs (semantic twins)
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;

extern "C" int *__cdecl FUNC_100CCE0C(void);
extern "C" int *__cdecl FUNC_100CCE0C_1(int);
extern "C" void __cdecl FUNC_100C67ED(int);
extern "C" int __cdecl FUNC_100C67CC(int);
extern "C" void __cdecl FUNC_100CC34A(int);
extern "C" void __cdecl FUNC_100D4877(int);
extern "C" int __cdecl FUNC_100CE424(void);
extern "C" void __cdecl FUNC_100CE42A(void);
extern "C" int __stdcall GetCPInfo(int, void *);
extern "C" void __stdcall FUNC_throw(int, const char *);

// --- @ 0xCC49C (257): per-thread exception registration ---
void FUNC_100CC49C(int *p)
{
	if (p[2] == -1)
		return;
	FUNC_100C67ED((int)p);
	int *r = (int *)FUNC_100CCE0C()[0x1f];
	if (r[0] == 0xe06d7363 && r[4] == 3
		&& (r[5] == 0x19930520 || r[5] == 0x19930521)) {
		if (FUNC_100C67CC(r[6]))
			FUNC_100CC34A(FUNC_100CCE0C_1(1)[0x1f]);
	}
	FUNC_100CCE0C()[0x1f] = p[2];
	FUNC_100CCE0C()[0x20] = p[3];
}

// --- @ 0xCC464 (56): detect C++ rethrow by magic ---
int FUNC_100CC464(void *rec)
{
	DWORD *r = (DWORD *)rec;
	if (r[0] != 0xe06d7363)
		return 0;
	if (r[4] != 3)
		return 0;
	if (r[5] != 0x19930520 && r[5] != 0x19930521 && r[5] != 0x19930522)
		return 0;
	return 1;
}

// --- @ 0xCC46C (48): EH filter selecting rethrow ---
struct EXCP { DWORD *rec; void *ctx; };
int FUNC_100CC46C(EXCP *pep)
{
	if (pep->rec[0] == 0xe06d7363 && FUNC_100CC464(pep->rec))
		return 1;
	return 0;
}

// --- @ 0xC631C / 0xC6374 (63): _String_base::_Xran ---
void __cdecl FUNC_100C631C(void)
{
	FUNC_throw(1, "invalid string position");
}
void __cdecl FUNC_100C6374(void)
{
	FUNC_throw(1, "invalid string position");
}

// --- @ 0xD7156 (70): _getSystemCP ---
int __cdecl FUNC_100D7156(int cp)
{
	char info[0x14];
	if (GetCPInfo(cp, info))
		return *(int *)(info + 4);
	return 0;
}

// --- @ 0xC8011 (93): __ArrayUnwind ---
void FUNC_100C8011(char *p, unsigned sz, int n, void(__cdecl *dtor)(void *))
{
	char *q = p + sz * n;
	for (int i = 0; i < n; i++) {
		q -= sz;
		dtor(q);
	}
}
