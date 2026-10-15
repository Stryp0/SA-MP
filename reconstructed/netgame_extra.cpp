// Zone w1 byte-exact functions (OK_LIGHT verified under VC2003)
// canonical shared globals
struct CChat { void Print(const char *fmt, ...); };
struct CObj_6ACE0 { void Notify(char a, int b, int c, int d, int e, int f, int g); };
extern CChat *g_1026eb80;
extern CObj_6ACE0 *g_1026eb58;
// .text:10001C30 — byte-exact verified
extern "C" void FUNC_10010001010();
extern "C" void FUNC_100100ABE70();
extern "C" void FUNC_100100ABFC0();
extern "C" int g_0x10118878;
extern "C" int g_0x10118860;
extern "C" int g_0x1011887c;
extern "C" int g_0x1026ebac;
__declspec(naked) void FUNC_10001C30() {
	__asm {
		pushad
		mov dword ptr [g_0x1011887c], esi
		mov dword ptr [g_0x10118878], 1
		cmp dword ptr [g_0x1026ebac], 0
		je _L1c82
		mov ecx, dword ptr [g_0x1026ebac]
		call FUNC_10010001010
		mov dword ptr [g_0x10118860], eax
		mov ecx, dword ptr [g_0x10118860]
		call FUNC_100100ABE70
		test eax, eax
		je _L1c82
		mov ecx, dword ptr [g_0x10118860]
		call FUNC_100100ABFC0
		test eax, eax
		jne _L1c82
		mov dword ptr [g_0x10118878], 0
_L1c82:
		push dword ptr [g_0x10118878]
		mov ecx, dword ptr [g_0x1011887c]
		mov ebx, 0x4859d0
		call ebx
		popad
		mov ebx, 0x47bf2b
		jmp ebx
	}
}
// .text:10002090 — byte-exact verified
extern "C" void FUNC_10010001CE0();
extern "C" int g_0xa43c7c;
extern "C" int g_0x10118868;
extern "C" int g_0xa43c84;
extern "C" int g_0x10118874;
extern "C" int g_0xa43c78;
extern "C" int g_0x1011886c;
extern "C" int g_0x10118870;
extern "C" int g_0xa43c80;
__declspec(naked) void FUNC_10002090() {
	__asm {
		pushad
		push 4
		mov ecx, esi
		mov ebx, 0x464080
		call ebx
		mov eax, dword ptr [g_0xa43c7c]
		mov dword ptr [g_0x1011886c], eax
		mov ecx, dword ptr [g_0xa43c80]
		mov dword ptr [g_0x10118870], ecx
		mov edx, dword ptr [g_0xa43c84]
		mov dword ptr [g_0x10118874], edx
		mov eax, dword ptr [g_0xa43c78]
		mov dword ptr [g_0x10118868], eax
		mov ecx, dword ptr [g_0x10118868]
		push ecx
		mov edx, dword ptr [g_0x10118874]
		push edx
		mov eax, dword ptr [g_0x10118870]
		push eax
		mov ecx, dword ptr [g_0x1011886c]
		push ecx
		call FUNC_10010001CE0
		add esp, 0x10
		popad
		mov ebx, 0x47bf2b
		jmp ebx
	}
}
struct CObj_10002D30 { char _p[4]; int m_04; int Get04(); };
int CObj_10002D30::Get04() { return m_04; }
extern "C" int __cdecl fclose(void*);
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char*);

struct CObj_1000CBF0 { void **m_ppItems; unsigned long m_nItems; char _p[0x20b]; int m_213;
	void RemoveDownload(int *info, int a3, int a4); };
void CObj_1000CBF0::RemoveDownload(int *info, int a3, int a4) {
	if (!info) info = (int*)((char*)this + 0x222);
	if (*(void**)info) {
		fclose(*(void**)info);
		*(int*)info = 0;
		DeleteFileA((const char*)info + 0x19);
	}
	if (*(unsigned int*)((char*)info + 0x15) < m_nItems &&
	    *(int*)(*(int*)this + *(unsigned int*)((char*)info + 0x15) * 4)) {
		*(char*)(*(int*)(*(int*)this + *(unsigned int*)((char*)info + 0x15) * 4) + 6) = 1;
	}
	if (g_1026eb58)
		g_1026eb58->Notify(*(char*)(info + 1), *(int*)((char*)info + 0x11), 3,
			*(int*)((char*)info + 5), 0, a3, a4);
	m_213 = 2;
}
struct CPool2_1000CD70 {
	void **m_ppItems; unsigned long m_nItems;
	char _p[0x20f]; int m_217;
	char _q[4]; char m_21f;
	int CountPending();
};
int CPool2_1000CD70::CountPending() {
	if (!m_21f) return -1;
	unsigned long n = m_nItems, i = 0; int cnt = 0;
	if (n) {
		do {
			if (i < n && m_ppItems[i]) {
				char *p = (char*)m_ppItems[i];
				if (!p[6] && (p[7] == 1 ||
					(p[7] == 2 && (*(int*)(p + 8) == m_217 || *(int*)(p + 8) == -1)))) {
					if (!p[0] || !p[1]) cnt++;
				}
			}
			i++;
		} while (i != n);
	}
	return cnt;
}
extern "C" int __cdecl _snprintf(char*, unsigned int, const char*, ...);
extern void * __cdecl FUNC_1000C7F49(char *path, const char *mode);
extern char m_100e5d34[];


struct CObj_1000D750 {
	char m_dir[9]; int m_3cd; char _p[0x11];
	char FillDownloadInfo(int a, int b, int *info);
	long GetAt(unsigned int i);
	char _q[0x215]; int m_213; char _r[0x1340-0x217-0x128];
	int RequestDownload(int a, int b);
};
int CObj_1000D750::RequestDownload(int a, int b) {
	if (!FillDownloadInfo(a, b, (int*)((char*)this + 0x222))) {
		if (g_1026eb80)
			g_1026eb80->Print("Can't fill download info for CRC: 0x%X", b);
	} else {
		*(int*)((char*)this + 0x1340) = 0;
		void *f = FUNC_1000C7F49((char*)this + 0x23b, m_100e5d34);
		*(void**)((char*)this + 0x222) = f;
		if (f) {
			if (g_1026eb58)
				g_1026eb58->Notify(*(char*)((char*)this + 0x226), *(int*)((char*)this + 0x233),
					0, 0, *(int*)((char*)this + 0x22b), -1, 0);
			*(int*)((char*)this + 0x213) = 1;
			return 1;
		}
	}
	return 0;
}
#pragma pack(push,1)
struct CRec_1000DDB0 {
	int m_00, m_04, m_08, m_0c, m_10;
	char b_14, b_15;
	int m_16, m_1a;
	char b_1e;
	int m_1f;
	char b_23;
	int m_24, m_28, m_2c, m_30, m_34, m_38, m_3c, m_40, m_44, m_48;
	CRec_1000DDB0* Init();
};
#pragma pack(pop)
CRec_1000DDB0* CRec_1000DDB0::Init() {
	m_08 = 0; m_10 = 0; m_0c = 0;
	b_14 = 0; b_15 = 0; b_1e = 0;
	m_1a = 0; m_16 = 0; m_24 = 0; m_28 = 0;
	m_00 = 0; m_04 = 0; m_1f = 0;
	m_2c = 0; m_30 = 0; m_34 = 0; m_38 = 0; m_3c = 0; m_40 = 0;
	b_23 = 0; m_44 = 0; m_48 = 0;
	return this;
}
extern "C" char s_100e7394[], s_100e7384[], s_100e7370[], s_100e7364[], s_100e7354[], s_100e7340[];
extern "C" char s_100e7330[], s_100e731c[], s_100e7308[], s_100e72f8[], s_100e72e4[], s_100e72dc[];
const char* __stdcall FUNC_100033B90(unsigned char id) {
	switch (id) {
	case 0xc8: return s_100e7394;
	case 0xc9: return s_100e7384;
	case 0xca: return s_100e7370;
	case 0xcb: return s_100e7364;
	case 0xcc: return s_100e7354;
	case 0xcd: return s_100e7340;
	case 0xce: return s_100e7330;
	case 0xcf: return s_100e731c;
	case 0xd0: return s_100e7308;
	case 0xd1: return s_100e72f8;
	case 0xd2: return s_100e72e4;
	case 0xd3: return s_100e72f8;
	case 0xd4: return s_100e72e4;
	default:
		return s_100e72dc;
	}
}
