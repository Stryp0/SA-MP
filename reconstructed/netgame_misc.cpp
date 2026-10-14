// reconstructed from samp.dll 0.3.7-R5 — zone w1
// every function below compiled under VS .NET 2003 (/Ox /Og /Ob1 /Oi /Ot /Oy /MT /Zp1 /EHsc /Gy)
// and verified byte-exact against the DLL range shown (OK_LIGHT, relocs masked).
// Class layouts are minimal "views": only the members the function touches are modelled.

// .text:10002CF0 — stores local player camera ext-zoom and aspect-ratio floats through out params
extern float __cdecl GameGetLocalPlayerCameraExtZoom();
extern float __cdecl GameGetLocalPlayerAspectRatio();
struct CView_00002CF0 { void Get(float* a, float* b); };
void CView_00002CF0::Get(float* a, float* b) {
	*a = GameGetLocalPlayerCameraExtZoom();
	*b = GameGetLocalPlayerAspectRatio();
}


// .text:100083D0 — setter: stores arg at +0 and returns this
struct CView_000083D0 { void* m_p; CView_000083D0* Set(void* p); };
CView_000083D0* CView_000083D0::Set(void* p) { m_p = p; return this; }


// .text:10008760 — reports the '{FFFFFF}SA-MP {B9C9BF}0.3.7-R5 {FFFFFF}Started' banner through the chat window when present
extern void __cdecl AddDebugMessage(void* w, const char* s);
extern void* g_pChatWindow;
struct CView_00008760 { void Show(); };
void CView_00008760::Show() {
	if (g_pChatWindow)
		AddDebugMessage(g_pChatWindow, "{FFFFFF}SA-MP {B9C9BF}0.3.7-R5 {FFFFFF}Started");
}


// .text:1000A360 — std::string _Myptr equivalent: inline buffer when capacity < 16 else heap pointer
struct CView_0000A360 { char _a[4]; union { char _Buf[16]; char* _Ptr; } _bx; unsigned long _Mysize; unsigned long _Myres; char* Myptr(); };
char* CView_0000A360::Myptr() { if (_Myres >= 16) return _bx._Ptr; return _bx._Buf; }


// .text:1000A370 — operator new wrapper
void* __stdcall Alloc(unsigned int n) { return ::operator new(n); }


// .text:1000BB40 — releases the owned buffer (+0xd ownership flag, +0 pointer) and clears it
extern "C" void __cdecl free(void*);
struct CView_0000BB40 { void* m_p; char _p[9]; char m_bOwn; void Release(); };
void CView_0000BB40::Release() {
	if (m_bOwn && m_p) { free(m_p); m_p = 0; }
}


// .text:1000BBE0 — zero-initializes 14 members and returns this (ctor/reset)
#pragma pack(push,1)
struct CView_0000BBE0 {
	long m_0, m_4, m_8, m_c;
	char m_10, m_11;
	long m_12, m_16;
	char m_1a;
	long m_1b, m_1f, m_23;
	short m_27, m_29;
	CView_0000BBE0* Init();
};
#pragma pack(pop)
CView_0000BBE0* CView_0000BBE0::Init() {
	m_4 = 0; m_c = 0; m_8 = 0; m_10 = 0; m_11 = 0; m_1a = 0;
	m_16 = 0; m_12 = 0; m_0 = 0; m_1b = 0; m_1f = 0; m_23 = 0;
	m_27 = 0; m_29 = 0;
	return this;
}


// .text:1000C890 — zeroes two members and returns this
struct CView_0000C890 { long m_0, m_4; CView_0000C890* Init(); };
CView_0000C890* CView_0000C890::Init() { m_0 = 0; m_4 = 0; return this; }


// .text:1000C930 — zeroes two members and returns this
struct CView_0000C930 { long m_0, m_4; CView_0000C930* Init(); };
CView_0000C930* CView_0000C930::Init() { m_0 = 0; m_4 = 0; return this; }


// .text:10013700 — clears flag +0x10a and sets +4 to 1
struct CView_00013700 { char _p4[4]; int m_4; char _p[0x102]; char m_10a; void Reset(); };
void CView_00013700::Reset() { m_10a = 0; m_4 = 1; }


// .text:10017C50 — zeroes fields at +0x2da and +0x2e2
struct CView_00017C50 { char _p[0x2da]; int m_2da; int _gap; int m_2e2; void Reset(); };
void CView_00017C50::Reset() { m_2da = 0; m_2e2 = 0; }

