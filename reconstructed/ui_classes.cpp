// Reconstructed UI/container helpers (zone w2).
// VERIFIED byte-exact: FUNC_1006B0D0, FUNC_1006BB30, FUNC_100718B0, FUNC_10077D90,
//   FUNC_1006E8B0/C0/D0.
// SEMANTIC (not byte-verified): CNetStats deleting dtor, FUNC_10066560,
//   CXm container trio (AA80/ABD0/AC10), FUNC_1006BDF0, FUNC_10071820, FUNC_1007C230.

// batch 2: zone-w2 small/mid functions
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;
typedef long HRESULT;
typedef void *PVOID;
typedef void *HWND;
typedef char *PCHAR;
struct RECT { int left, top, right, bottom; };
#include <string.h>

extern "C" void __stdcall Sleep( DWORD );
extern "C" int __stdcall GetWindowRectX( HWND, RECT * );

// --- 0x60d00 CNetStats deleting dtor ---
class CNetStats
{
public:
	virtual ~CNetStats();
	virtual void Draw();
	char field_4;
	void FUNC_10060AA0();
};

CNetStats::~CNetStats()
{
	if( field_4 )
		FUNC_10060AA0();
}

// --- 0x66560 ---
extern "C" char byte_1012e7b8;
#pragma comment(linker,"/alternatename:_byte_1012e7b8=_x_1012e7b8")
extern "C" char byte_101027d2;
#pragma comment(linker,"/alternatename:_byte_101027d2=_x_101027d2")
extern "C" int g_1012e7b4;
#pragma comment(linker,"/alternatename:_g_1012e7b4=_x_1012e7b4")
extern "C" void __cdecl FUNC_100C622C( int h );

class CXl
{
public:
	char field_0;
	int FUNC_10066560( int a1 );
};

int CXl::FUNC_10066560( int a1 )
{
	if( !field_0 )
	{
		if( !byte_1012e7b8 )
			return 0;
	}
	byte_101027d2 = 1;
	if( a1 )
	{
		while( byte_1012e7b8 )
			Sleep( 2 );
	}
	FUNC_100C622C( g_1012e7b4 );
	g_1012e7b4 = 0;
	return 1;
}

// --- container class: 0x6aa80 / 0x6abd0 / 0x6ac10 ---
class CXmItem
{
public:
	char _p[5];
	int field_5;
};

class CXm
{
public:
	CXmItem **field_0;
	int field_4;

	bool FUNC_1006AA10( int n );
	void FUNC_1006AA80();
	int FUNC_1006ABD0( int v );
	int FUNC_1006AC10( CXmItem *e );
};

void CXm::FUNC_1006AA80()
{
	int i = 0;
	int last = -1;
	if( field_4 )
	{
		for( ; i < field_4; i++ )
			if( field_0[i] )
				last = i;
	}
	FUNC_1006AA10( last + 1 );
}

int CXm::FUNC_1006ABD0( int v )
{
	for( int i = 0; i < field_4; i++ )
	{
		CXmItem *e = field_0[i];
		if( e->field_5 == v )
			return i;
	}
	return -1;
}

int CXm::FUNC_1006AC10( CXmItem *e )
{
	int n = field_4;
	CXmItem **arr = field_0;
	int i = 0;
	if( n )
	{
		for( ; i < n; i++ )
			if( !arr[i] )
				break;
		if( i >= 0 && i < n )
		{
			arr[i] = e;
			return i;
		}
	}
	if( !FUNC_1006AA10( field_4 + 1 ) )
		return -1;
	field_0[field_4] = e;
	return field_4;
}

// --- 0x6b0d0 ---
class CXnSub
{
public:
	char _p[0x13];
	char field_13;
};

class CXn
{
public:
	char _p0[0x28];
	CXnSub *field_28;
	char _p2c[4];
	int field_30;
	char _p34[0x218];
	int field_24c;
	int field_250;

	void FUNC_1006ACA0();
	void FUNC_1006B0D0();
};

void CXn::FUNC_1006B0D0()
{
	field_28->field_13 = 0;
	field_30 = 0;
	FUNC_1006ACA0();
	field_24c = 0;
	field_250 = -1;
}

// --- 0x6bb30 dialog-show wrapper ---
class CXy
{
public:
	char _p0[0x28];
	int field_28;
	void FUNC_10070630( int );
	void FUNC_1006FFB0( int, int, char *, char *, char *, char *, int );
};
extern CXy *pY2;
#pragma comment(linker,"/alternatename:_pY2=_g_1026eb50")

void __cdecl FUNC_1006BB30()
{
	if( !pY2->field_28 )
		pY2->FUNC_1006FFB0( 1, 0, (char*)0x100ea460, (char*)0x100ea470, (char*)0x100ea614, (char*)0x100e59c9, 0 );
}

// --- 0x6bdf0 ---
class CXo2
{
public:
	char _p0[0x14];
	int field_14;
};
class CXo
{
public:
	char _p0[0x60];
	CXo2 *field_60;
};
extern CXo *g_0xc1703c;
#pragma comment(linker,"/alternatename:_g_0xc1703c=_x_0c1703c")

int __cdecl FUNC_1006BDF0()
{
	int a = 0;
	CXo *b = g_0xc1703c;
	if( !b )
		return ( int ) b;
	a = b->field_60->field_14;
	return a;
}

// --- 0x6e8b0/0x6e8c0/0x6e8d0 getters ---
class CXp
{
public:
	int field_0;
	char _p4[0x1e];
	int field_22;
	int field_24;

	int FUNC_1006E8B0();
	int FUNC_1006E8C0();
	int FUNC_1006E8D0();
};

// --- 0x71820 / 0x718b0: same class as earlier 0x71920/0x71ac0 cluster (CXd-like) ---
class CXqSub
{
public:
	char _p0[0x13];
	char field_13;
	char field_14;
	char _p15[1];
	char field_16[0x100];
	int field_116;
	int field_11a;
	int field_11e;
	int field_122;
	int field_126;
	void FUNC_100908E0( float f );
};

class CXqFont
{
public:
	void FUNC_1006B200( int *out, char *s, int a );
};
extern CXqFont *g_pFontSvc;
#pragma comment(linker,"/alternatename:_g_pFontSvc=_g_1026eb9c")
extern "C" HWND g_0xc97c1c;
#pragma comment(linker,"/alternatename:_g_0xc97c1c=_x_0c97c1c")

class CXq
{
public:
	char _p0[4];
	int field_4;
	int field_8;
	int field_c;
	int field_10;
	char _p14[0xc];
	CXqSub *field_20;
	int field_24;

	void FUNC_10071820();
	void FUNC_100718B0();
};

void CXq::FUNC_10071820()
{
	RECT r;
	CXqSub *sub = field_20;
	sub->field_11e = field_c;
	sub->field_122 = field_10;
	GetWindowRectX( g_0xc97c1c, &r );
	field_4 = r.right - field_c - 5;
	field_8 = r.bottom - field_10 - 0xa;
	sub->field_116 = field_4;
	sub->field_11a = field_8;
}

void CXq::FUNC_100718B0()
{
	int out[2];
	g_pFontSvc->FUNC_1006B200( out, (char*)0x100e637c, 0 );
	strcpy( field_20->field_16, (char*)0x100ea734 );
	field_20->field_14 = 1;
	field_20->field_126 = out[1] + 4;
	field_20->field_13 = 1;
	FUNC_10071820();
	field_24 = 1;
}

// --- 0x77d90 ---
extern "C" HRESULT __cdecl FUNC_100772C0( void *a, int b, unsigned int c );
HRESULT __cdecl FUNC_10077D90( void *a, int b, unsigned int c )
{
	c >>= 1;
	if( !a || !b || ( int ) c < 1 )
		return 0x80070057;
	return FUNC_100772C0( a, b, c );
}

// --- 0x7c230 ---
extern "C" HRESULT __cdecl FUNC_10078110( char *dst, int rem, const char *src );
HRESULT __cdecl FUNC_1007C230( void *a1, int cchMax, char *dst, const char *src )
{
	int rem = cchMax;
	char *p = dst;
	if( rem )
	{
		while( rem && *p ) { ++p; --rem; }
		if( rem )
		{
			int used = cchMax - rem;
			return FUNC_10078110( p, cchMax - used, src );
		}
	}
	return 0x80070057;
}

int CXp::FUNC_1006E8B0() { return field_0; }
int CXp::FUNC_1006E8C0() { return *( int * ) ( ( char * ) this + 0x22 ); } // unaligned dword read
int CXp::FUNC_1006E8D0() { return *( int * ) ( ( char * ) this + 0x24 ); }
