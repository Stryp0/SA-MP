// w3_shared.h — canonical declarations for symbols shared across zone w3
// reconstructed functions. Address-named helpers are declared once here;
// per-function files only carry their own class/struct layouts.
// Provenance: each body in w3.cpp / w3_semantic.cpp names its RVA + byte len.
#ifndef W3_SHARED_H
#define W3_SHARED_H

typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;
#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif

struct VECTOR { float x, y, z; };
struct MATRIX4X4 {
	VECTOR vA; DWORD u0;
	VECTOR vB; DWORD u1;
	VECTOR vC; DWORD u2;
	DWORD f30, f34, f38, f3c;
};

// entity shapes seen across w3 (vtbl-first GTA objects)
struct EntA { DWORD vt; struct EntX *f4; };          // vt, f4@4
struct EntX {                                        // b0, b8@8, f18@0x18
	BYTE b0;
	char _1[7];
	BYTE b8;
	char _9[0xf];
	EntX *f18;
};
struct EntB { DWORD vt; char _p[0x18]; DWORD f1C; }; // vt, f1C@0x1c
struct EntC { DWORD vt; DWORD f4; char _p8[0xa]; DWORD f12; }; // vt, f4@4, f12@0x12
struct Entity;
struct EntityA { char _p[4]; DWORD f4; };
struct PoolA { char _p[0x3de]; DWORD *f3DE; };
struct PoolB {
	void FUNC_100A0AE0(BYTE *a, BYTE *b);
};
struct PoolN {
	char FUNC_1000D150(int);
	void FUNC_1000D1D0(int);
};

// shared globals (addresses in comments)
extern DWORD g_pPool;          // 0x1026eb94
extern PoolB *g_pPoolB;        // 0x1026ebac
extern PoolN *g_pNet;          // 0x1026eb98
extern DWORD *g_pArr;
extern DWORD g_flag50;         // 0x...50
extern DWORD g_101A25F8;
extern DWORD g_101A25FC;
extern int g_blankTex;         // 0x101a2600
extern DWORD g_10150690;
extern DWORD g_10150694;
extern DWORD g_10150698;
extern float g_1015069C;
extern BYTE g_00BA6794;
extern BYTE g_SlotUsed[];      // 0x10150340
extern float g_fScale;         // 0x100ec550 (deg->rad-ish scale)
extern float g_fRad;
extern float g_100E6148;
extern float g_100EA63C;
extern MATRIX4X4 g_stAttach;   // 0x101a25b8
extern VECTOR g_vShared;
extern void **pHookTable;     // ?dword_10114B08

// CRT / Win32
extern "C" void *memset(void *, int, size_t);
extern "C" void *memcpy(void *, const void *, size_t);
extern "C" void free(void *);
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
extern "C" void __stdcall Sleep(DWORD ms);
void *operator_new(size_t n);

// shared address-named helpers
extern int FUNC_100B2310(const char *fmt, ...);        // log/printf-ish
extern void FUNC_100B14C0(void *a, void *b, void *c);  // entity iterator w/ callback
extern EntC *__stdcall FUNC_100A7A40(DWORD id);
extern DWORD __stdcall FUNC_100781C0(DWORD a, DWORD b, DWORD c);
extern int FUNC_1002E7F0();                            // tick counter
extern int FUNC_100A0970(int id);
extern void FUNC_100A0940(int id, int n);
extern void FUNC_100A0960();
extern void FUNC_100A09A0(int id, int n);
extern int FUNC_100B4570(int id);
extern void FUNC_100B3960(void *p);
extern void FUNC_100B2B90(const char *, const char *, int);
extern int FUNC_100B2C60(const char *, const char *);
extern short __stdcall FUNC_100B4700(int id);
extern char FUNC_100B3D30(int);
extern float FUNC_100B48E0(float v);
extern int FUNC_100B0CE0(int slot, DWORD a, DWORD b, DWORD c, DWORD d, DWORD e);
extern void FUNC_100B44C0(int slot, int f);
extern int  FUNC_100B6880(void *data, unsigned int size, void *obj);
extern void *FUNC_100B6850();
extern void __stdcall FUNC_100B4630(void *list, void *obj);
extern void FUNC_100B1E40(void *ctx, void *dst, unsigned int size);
extern void FUNC_100680F0(void *log, const char *fmt);
extern void *FUNC_100C6982(int a, unsigned int size);

#endif // W3_SHARED_H
