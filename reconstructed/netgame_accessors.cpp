// reconstructed from samp.dll 0.3.7-R5 — zone w1
// every function below compiled under VS .NET 2003 (/Ox /Og /Ob1 /Oi /Ot /Oy /MT /Zp1 /EHsc /Gy)
// and verified byte-exact against the DLL range shown (OK_LIGHT, relocs masked).
// Class layouts are minimal "views": only the members the function touches are modelled.

// .text:10001000 — returns this
struct CView_00001000 { CView_00001000* GetThis(); };
CView_00001000* CView_00001000::GetThis() { return this; }


// .text:100010A0 — reads member at +0x10
struct CView_000010A0 { char _pad[16]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_000010A0::Get() { return m_field; }


// .text:10012770 — reads member at +0
struct CView_00012770 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_00012770::Get() { return m_field; }


// .text:100136B0 — no-op
struct CView_000136B0 { void F(); };
void CView_000136B0::F() {}


// .text:10013EE0 — returns this
struct CView_00013EE0 { CView_00013EE0* GetThis(); };
CView_00013EE0* CView_00013EE0::GetThis() { return this; }


// .text:10001760 — no-op (2 args)
struct CView_00001760 { void F(int a0,int a1); };
void CView_00001760::F(int a0,int a1) {}


// .text:100180C0 — no-op
struct CView_000180C0 { void F(); };
void CView_000180C0::F() {}


// .text:10001A40 — reads member at +0x26
struct CView_00001A40 { char _pad[38]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00001A40::Get() { return m_field; }


// .text:10001A50 — reads member at +0
struct CView_00001A50 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_00001A50::Get() { return m_field; }


// .text:1001E790 — reads member at +0
struct CView_0001E790 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_0001E790::Get() { return m_field; }


// .text:1001FDB0 — reads member at +0
struct CView_0001FDB0 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_0001FDB0::Get() { return m_field; }


// .text:100206A0 — reads member at +4
struct CView_000206A0 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_000206A0::Get() { return m_field; }


// .text:10020B70 — returns pointer to member at +0x18
struct CView_00020B70 { char _pad[24]; unsigned long m_field; unsigned long* Get(); };
unsigned long* CView_00020B70::Get() { return &m_field; }


// .text:10020CC0 — reads member at +4
struct CView_00020CC0 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00020CC0::Get() { return m_field; }


// .text:10021060 — reads member at +4
struct CView_00021060 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00021060::Get() { return m_field; }


// .text:10021620 — reads member at +4
struct CView_00021620 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00021620::Get() { return m_field; }


// .text:10021640 — reads member at +4
struct CView_00021640 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00021640::Get() { return m_field; }


// .text:10024BA0 — reads member at +4
struct CView_00024BA0 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00024BA0::Get() { return m_field; }


// .text:100255B0 — reads member at +6
struct CView_000255B0 { char _pad[6]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_000255B0::Get() { return m_field; }


// .text:10025D10 — no-op (12 args)
struct CView_00025D10 { void F(int a0,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10,int a11); };
void CView_00025D10::F(int a0,int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8,int a9,int a10,int a11) {}


// .text:10025D60 — reads member at +4
struct CView_00025D60 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00025D60::Get() { return m_field; }


// .text:10026BA0 — reads member at +0
struct CView_00026BA0 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_00026BA0::Get() { return m_field; }


// .text:10026BB0 — reads member at +8
struct CView_00026BB0 { char _pad[8]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00026BB0::Get() { return m_field; }


// .text:10027590 — reads member at +4
struct CView_00027590 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00027590::Get() { return m_field; }


// .text:10027620 — reads member at +4
struct CView_00027620 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00027620::Get() { return m_field; }


// .text:10027640 — reads member at +4
struct CView_00027640 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00027640::Get() { return m_field; }


// .text:10027760 — reads member at +4
struct CView_00027760 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00027760::Get() { return m_field; }


// .text:10027A40 — reads member at +4
struct CView_00027A40 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00027A40::Get() { return m_field; }


// .text:10027DD0 — reads member at +4
struct CView_00027DD0 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00027DD0::Get() { return m_field; }


// .text:10028090 — reads member at +0x1c
struct CView_00028090 { char _pad[28]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00028090::Get() { return m_field; }


// .text:1002CA80 — reads member at +0xc
struct CView_0002CA80 { char _pad[12]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0002CA80::Get() { return m_field; }


// .text:1002CD90 — reads member at +4
struct CView_0002CD90 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0002CD90::Get() { return m_field; }


// .text:10002D20 — reads member at +0
struct CView_00002D20 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_00002D20::Get() { return m_field; }


// .text:10002D40 — reads member at +0x59
struct CView_00002D40 { char _pad[89]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00002D40::Get() { return m_field; }


// .text:1002F370 — no-op (1 arg)
struct CView_0002F370 { void F(int a0); };
void CView_0002F370::F(int a0) {}


// .text:1002F380 — no-op (1 arg)
struct CView_0002F380 { void F(int a0); };
void CView_0002F380::F(int a0) {}


// .text:1002F4D0 — reads member at +4
struct CView_0002F4D0 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0002F4D0::Get() { return m_field; }


// .text:10007E50 — no-op
struct CView_00007E50 { void F(); };
void CView_00007E50::F() {}


// .text:10008530 — reads member at +0x30
struct CView_00008530 { char _pad[48]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00008530::Get() { return m_field; }


// .text:10008E50 — no-op (1 arg)
struct CView_00008E50 { void F(int a0); };
void CView_00008E50::F(int a0) {}


// .text:10009530 — reads member at +0x14
struct CView_00009530 { char _pad[20]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_00009530::Get() { return m_field; }


// .text:100095B0 — returns -1
struct CView_000095B0 { int Get(); };
int CView_000095B0::Get() { return -1; }


// .text:1000BBC0 — reads member at +0
struct CView_0000BBC0 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000BBC0::Get() { return m_field; }


// .text:1000BBD0 — reads member at +4
struct CView_0000BBD0 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000BBD0::Get() { return m_field; }


// .text:1000BCA0 — reads member at +0
struct CView_0000BCA0 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000BCA0::Get() { return m_field; }


// .text:1000BFF0 — returns 1
struct CView_0000BFF0 { int Get(); };
int CView_0000BFF0::Get() { return 1; }


// .text:1000C000 — no-op
struct CView_0000C000 { void F(); };
void CView_0000C000::F() {}


// .text:1000C8C0 — reads member at +4
struct CView_0000C8C0 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000C8C0::Get() { return m_field; }


// .text:1000C8F0 — reads member at +4
struct CView_0000C8F0 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000C8F0::Get() { return m_field; }


// .text:1000C920 — reads member at +4
struct CView_0000C920 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000C920::Get() { return m_field; }


// .text:1000C960 — reads member at +4
struct CView_0000C960 { char _pad[4]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000C960::Get() { return m_field; }


// .text:1000E440 — reads member at +4
struct CView_0000E440 { char _pad[8]; unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000E440::Get() { return m_field; }


// .text:1000E580 — reads member at +4
struct CView_0000E580 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000E580::Get() { return m_field; }


// .text:1000E590 — reads member at +4
struct CView_0000E590 { unsigned long m_field; unsigned long Get(); };
unsigned long CView_0000E590::Get() { return m_field; }

