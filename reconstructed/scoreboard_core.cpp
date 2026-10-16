// Reconstructed scoreboard/dialog internals (zone w2 batch 4).
// SEMANTIC (not byte-verified): FUNC_1006DC00, FUNC_1006DA60, FUNC_1006D800,
//   FUNC_1006FA20, FUNC_1006B650, FUNC_100740E0, FUNC_1006ED30.

// batch 4: remaining w2 functions — semantic twins (x87/SEH/virtual-dispatch codegen)
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;
typedef int BOOL;
typedef long HRESULT;
typedef void *PVOID;
typedef void *HWND;
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
struct CXRect { int left, top, right, bottom; };
struct CXPoint { int x, y; };
extern "C" {
__declspec(dllimport) int __stdcall ClientToScreen( HWND, CXPoint * );
__declspec(dllimport) int __stdcall GetClientRect( HWND, CXRect * );
}
extern "C" void __cdecl FUN_10001010( void *, void * );
extern "C" int __cdecl FUN_100AF5D0( void *, void * );
extern "C" void __cdecl FUN_100A06F0( int, int );
extern "C" int __cdecl FUN_1006DA10();
extern "C" int __cdecl FUN_10002DE0( int );
extern "C" double __cdecl FUN_1009F190();
extern "C" void __cdecl FUN_1006DA60();
extern "C" void __cdecl FUN_1006B200( int *out, char *s, int a );
extern "C" void __cdecl FUN_1009EB10();
extern "C" void __cdecl FUN_10071D20( void *, int );
extern "C" int __cdecl FUN_1009F030( double );
extern "C" void __cdecl FUN_1006BC70();
extern "C" void __cdecl FUN_1006BC90( int *, char *, DWORD, int, int );
extern "C" void __cdecl FUN_1006BC80();
extern "C" void __cdecl FUN_100B60C0();
extern "C" void __cdecl FUN_1008C6C0( void * );
extern "C" void *__cdecl FUN_1008ED90( int );
extern "C" void __cdecl FUN_10086410( DWORD, DWORD, int );
extern "C" void __cdecl FUN_10090D10( int, char *, int, int, int, int, int, int, int );
extern "C" void __cdecl FUN_100910B0( int, char *, int, int, int, int, int, int * );
extern "C" int __cdecl FUN_10065E10( char * );
extern "C" void __cdecl FUN_10085EC0( int );
extern "C" void __cdecl FUN_100859E0();
extern "C" void __cdecl FUN_1006B4E0( int, char *, int, int, int, int, int, DWORD, int );
extern "C" void *__cdecl operator_new( unsigned int );
extern "C" int __cdecl D3DXCreateTexture();
extern "C" int __cdecl D3DXCreateRenderToSurface();

extern "C" int g_1026eb94;
extern "C" int g_1026eb84;
extern "C" int g_1026ebac;
extern "C" int g_1026eb40;
extern "C" double g_100ea688;
extern "C" HWND g_0xc97c1c;
#pragma comment(linker,"/alternatename:_g_1026eb94=_x_1026eb94")
#pragma comment(linker,"/alternatename:_g_1026eb84=_x_1026eb84")
#pragma comment(linker,"/alternatename:_g_1026ebac=_x_1026ebac")
#pragma comment(linker,"/alternatename:_g_1026eb40=_x_1026eb40")
#pragma comment(linker,"/alternatename:_g_100ea688=_x_100ea688")
#pragma comment(linker,"/alternatename:_g_0xc97c1c=_x_0c97c1c")

// ---------- FUN_1006dc00 ----------
class CXpV
{
public:
	virtual int FUNC_30( int );
};

class CXp2
{
public:
	int field_0;
	unsigned short field_4;
	void FUNC_1006DC00();
};

void CXp2::FUNC_1006DC00()
{
	int tmp1[1], tmp2[1];
	if( !field_0 )
		return;
	FUN_10001010( tmp1, tmp2 );
	unsigned int u = FUN_100AF5D0( tmp1, tmp2 );
	bool have = ( u & 8 ) != 0;
	if( !have )
	{
		( *( int ( __stdcall ** )( void *, int ) ) ( *( int * ) g_1026eb40 + 0x30 ) )( ( void * ) g_1026eb40, 1 );
		FUN_100A06F0( 3, 0 );
	}
	else
		FUN_100A06F0( 0, 1 );
	field_4 = 0xffff;
	if( *( int * ) ( g_1026ebac + 0x61 ) )
	{
		unsigned short id = ( unsigned short ) FUN_1006DA10();
		int *pool = *( int ** ) ( *( int * ) ( g_1026eb94 + 0x3de ) + 0xc );
		if( id != 0xffff && id < 0x3e9 && pool[ 1 + id ]
			&& FUN_10002DE0( id )
			&& FUN_1009F190() < g_100ea688 )
		{
			field_4 = id;
			FUN_1006DA60();
		}
	}
}

// ---------- FUN_1006da60 ----------
class CXq2b
{
public:
	unsigned short field_0;
	unsigned short field_4;
	void FUNC_1006DA60();
};

void CXq2b::FUNC_1006DA60()
{
	int vec[3];
	char m[48];
	char buf[260];
	if( !g_1026eb94 )
		return;
	int *tbl = *( int ** ) ( *( int * ) ( g_1026eb94 + 0x3de ) + 0xc );
	unsigned short id = field_4;
	if( id >= 0x3e9 || !tbl[ 1 + id ] || !tbl[ 0xfa4 / 4 + id ] )
		return;
	if( FUN_1009F190() >= g_100ea688 )
		return;
	FUN_1009EB10();
	vec[0] = 0; vec[1] = 0; vec[2] = 0;
	FUN_10071D20( m, 0x3f800000 );
	double f = FUN_1009F190();
	int type = FUN_1009F030( f );
	_snprintf( buf, sizeof( buf ), "[id: %d, type: %d]\nDistance: %.2fm\n", id, type );
	FUN_1006BC70();
	FUN_1006BC90( vec, buf, 0xffd47b75, 1, 0 );
	FUN_1006BC80();
}

// ---------- FUN_1006d800 ----------
class CXuV
{
public:
	virtual int FUNC_20();
	virtual int FUNC_30( void ** );
	virtual int FUNC_48( int );
};

class CXu2
{
public:
	CXuV *field_0;
	int field_4;
	CXuV *field_8;
	CXuV *field_c;
	void FUNC_1006D800();
};

void CXu2::FUNC_1006D800()
{
	PVOID *tex = 0;
	field_0->FUNC_20();
	if( D3DXCreateTexture() >= 0 )
	{
		field_8->FUNC_48( 0 );
		field_c->FUNC_30( ( void ** ) &tex );
		D3DXCreateRenderToSurface();
	}
}

// ---------- FUN_1006fa20 ----------
class CXwV
{
public:
	virtual void FUNC_4();
	virtual void FUNC_38( int );
	virtual void FUNC_40( int );
	virtual void FUNC_48( int );
	virtual void FUNC_4C();
};
class CXwSub : public CXwV
{
public:
	int field_4;
	int field_8;
	int field_c;
	int field_10;
	int field_14;
	char _p18[0x35];
	int field_4d;
	char _p51[0xdc];
	int field_12f;
	int field_133;
};

class CXw2
{
public:
	int field_0;
	int field_4;
	int field_8;
	int field_c;
	int field_10;
	int field_14;
	int field_18;
	int field_1c;
	CXwSub *field_20;
	int field_24;

	void FUNC_1006FA20( int a );
};

void CXw2::FUNC_1006FA20( int a )
{
	field_1c = a;
	if( !a )
		return;
	void *mem = operator_new( 0x158 );
	field_20 = mem ? ( CXwSub * ) FUN_1008ED90( field_1c ) : 0;
	FUN_1008C6C0( field_20 );
	CXwSub *s = field_20;
	s->field_8 = 10;
	s->field_c = 10;
	s->FUNC_4C();
	s->field_14 = field_10 - 100;
	s->field_10 = field_c;
	s->FUNC_4C();
	s->FUNC_4();
	FUN_10086410( 0xc8ffffff, 0xc8808080, 0 );
	s->field_4d = 0;
	s->FUNC_38( 0 );
	s->FUNC_40( 0 );
	FUN_10090D10( 0x14, "BUTTON1", 10, 5, field_14, field_18, 0, 0, 0 );
	FUN_10090D10( 0x15, "BUTTON2", 0x6e, 5, field_14, field_18, 0, 0, 0 );
	FUN_100910B0( 0x13, (char*)0x100e59c9, 10, 0xaf, 0x23a, 0x28, 1, &field_24 );
	if( FUN_10065E10( (char*)0x100ea2e4 ) )
	{
		FUN_10085EC0( 1 );
		FUN_100859E0();
	}
	FUN_10086410( 0xf0050505, 0xc8808080, 0 );
	( *( void ( __stdcall ** )( int ) ) ( *( int * ) field_24 + 0x48 ) )( -1 );
	*( DWORD * ) ( field_24 + 0x133 ) = 0xff969696;
	*( DWORD * ) ( field_24 + 0x12f ) = 0xffb92228;
	*( DWORD * ) ( field_24 + 0x12b ) = 0xff0a0a0f;
	( *( void ( __stdcall ** )( int ) ) ( *( int * ) field_24 + 0x38 ) )( 0 );
	( *( void ( __stdcall ** )( int ) ) ( *( int * ) field_24 + 0x40 ) )( 0 );
}

// ---------- FUN_1006b650 ----------
class CXxV
{
public:
	virtual int FUNC_20();
	virtual int FUNC_2C();
	virtual int FUNC_38( CXxV *a, int b, int c, int *r, int e );
};

class CXx2
{
public:
	char _p0[0x10];
	CXxV *field_10;
	CXxV *field_14;
	char _p18[4];
	char *field_1c;

	void FUNC_1006B650( char *s );
};

void CXx2::FUNC_1006B650( char *s )
{
	int r[4];
	if( !s || !*s )
		return;
	CXxV *v = field_14;
	v->FUNC_20();
	if( strlen( s ) >= 0x186a1 )
		return;
	strcpy( field_1c, s );
	FUN_100B60C0();
	int w = strlen( field_1c );
	r[0] = -0x4b0f111c;
	( *( int ( __stdcall ** )( CXxV *, int, int, int * ) ) ( *( int * ) field_10 + 0x38 ) )( v, 0, w, r );
	r[0] += 2;
	( *( int ( __stdcall ** )( CXxV *, int, int, int * ) ) ( *( int * ) field_10 + 0x38 ) )( v, 0, w, r );
	r[0] -= 2;
	( *( int ( __stdcall ** )( CXxV *, int, int, int * ) ) ( *( int * ) field_10 + 0x38 ) )( v, 0, w, r );
	v->FUNC_2C();
}

// ---------- FUN_100740e0 ----------
extern "C" int __cdecl FUN_10074860( int *, int * );
extern "C" void __cdecl FUN_1006FCA0( int * );

int __cdecl FUNC_100740E0( int *a )
{
	int pt[2] = { 0, 0 };
	CXPoint scr = { 0, 0 };
	CXRect rc;
	ClientToScreen( g_0xc97c1c, &scr );
	GetClientRect( g_0xc97c1c, &rc );
	rc.left += scr.x;
	rc.right += scr.x;
	rc.top += scr.y;
	rc.bottom += scr.y;
	return FUN_10074860( a, pt );
}

// ---------- FUN_1006ed30: scoreboard player-list rebuild + sort ----------
extern "C" int __cdecl FUN_10088E70( int );
extern "C" void __cdecl FUN_1008C7F0();
extern "C" int __cdecl FUN_100139F0( int );
extern "C" int __cdecl FUN_10003F20();
extern "C" int __cdecl FUN_1000E470( unsigned int );
extern "C" int __cdecl FUN_1006E880( unsigned int );
extern "C" char *__cdecl FUN_100175C0( unsigned int );
extern "C" int __cdecl FUN_1006E850( unsigned int );
extern "C" void __cdecl FUN_100010F0( unsigned int );
extern "C" int __cdecl FUN_10016180();
extern "C" void __cdecl FUN_1008A7F0( char *, int, int );
extern "C" int __cdecl FUN_1008A9C0( int );
extern "C" void __cdecl FUN_10088E00( int, int, char * );
extern "C" void __cdecl FUN_1008A9F0( int );
extern "C" void __cdecl FUN_10085400();
extern "C" void __cdecl FUN_10085320();
extern "C" void *__cdecl calloc( unsigned int, unsigned int );
extern "C" void __cdecl free( void * );

struct CPlayerListEntry   // 0x2d-byte rows
{
	DWORD field_0;		// +0x00 (from FUN_10003f20, row 0 only)
	char  name[0x1d];	// +0x04
	int   field_21;		// +0x21 ping/order
	int   field_25;		// +0x25 score
	unsigned int id;	// +0x29? (stored at pcVar14+0x1d => +0x25?) -- kept as raw layout below
};

class CXy2
{
public:
	int field_0;
	char _p4[0x30];
	int field_34;   // 0xd
	int field_38;   // 0xe — points at the UI object owning +0xeb state
	char _p3c[4];
	int field_40;   // 0x10 — sort mode: 1 = name, 2 = score

	void FUNC_1006ED30();
};

void CXy2::FUNC_1006ED30()
{
	char buf[260];
	char tmp[0x2d];

	if( !g_1026eb94
		|| !*( int * ) ( *( int * ) ( g_1026eb94 + 0x3de ) + 4 )
		|| !field_0 || !field_34 )
		return;

	int prev = FUN_10088E70( -1 );
	int ui = field_38;
	int saved = *( int * ) ( ui + 0xeb );
	FUN_1008C7F0();

	int *src = *( int ** ) ( *( int * ) ( g_1026eb94 + 0x3de ) + 4 );
	int count = FUN_100139F0( 0 );
	unsigned short selfId = *( unsigned short * ) ( src + 1 );
	int slots = count + 1;
	char *rows = ( char * ) calloc( slots, 0x2d );

	// src is an embedded std::string: inline buffer when len < 0x10
	char *name = ( (unsigned int *)src )[ 0x1e / 4 ] < 0x10
		? ( char * ) src + 10
		: *( char ** ) ( ( char * ) src + 10 );
	strcpy( rows + 0x2d, name );

	*( int * ) rows = FUN_10003F20();
	*( int * ) ( rows + 0x25 ) = *src;
	*( int * ) ( rows + 0x29 ) = *( int * ) ( ( char * ) src + 0x22 );
	*( unsigned int * ) ( rows + 0x21 ) = selfId;

	char *dst = rows + 0x31;
	for( unsigned int i = 0; i < 0x3ec; i++ )
	{
		if( (unsigned short) i >= 0x3ec
			|| *( int * ) ( ( char * ) src + i * 4 + 0x2a ) != 1
			|| i == selfId
			|| FUN_1000E470( i ) )
			continue;
		*( int * ) ( dst + 0x25 ) = FUN_1006E880( i );
		strcpy( dst, FUN_100175C0( i ) );
		*( int * ) ( dst + 0x21 ) = FUN_1006E850( i );
		FUN_100010F0( i );
		*( int * ) ( dst - 4 ) = FUN_10016180();
		*( unsigned int * ) ( dst + 0x1d ) = i;
		dst += 0x2d;
	}

	if( field_40 == 1 )
	{
		for( int n = count; n > 0; --n )
		{
			char *a = rows;
			for( int k = count; k > 0; --k, a += 0x2d )
			{
				if( strcmp( a + 0x31, a + 4 ) < 0 )
				{
					memcpy( tmp, a, 0x2d );
					memcpy( a, a + 0x2d, 0x2d );
					memcpy( a + 0x2d, tmp, 0x2d );
				}
			}
		}
	}
	else if( field_40 == 2 )
	{
		for( int n = count; n > 0; --n )
		{
			char *a = rows;
			for( int k = count; k > 0; --k, a += 0x2d )
			{
				if( *( int * ) ( a + 0x25 ) < *( int * ) ( a + 0x52 ) )
				{
					memcpy( tmp, a, 0x2d );
					memcpy( a, a + 0x2d, 0x2d );
					memcpy( a + 0x2d, tmp, 0x2d );
				}
			}
		}
	}

	for( int i = 0; i < slots; i++ )
	{
		char *row = rows + 0x2d + i * 0x2d;
		_snprintf( buf, sizeof( buf ), "%u", *( unsigned int * ) ( row + 0x1d ) );
		FUN_1008A7F0( buf, *( int * ) ( row + 0x1d ), *( int * ) ( row - 4 ) );
		if( FUN_1008A9C0( i ) && *row )
		{
			FUN_10088E00( i, 0, row );
			_snprintf( buf, sizeof( buf ), "%d", *( int * ) ( row + 0x21 ) );
			FUN_10088E00( i, 1, buf );
			_snprintf( buf, sizeof( buf ), "%u", *( unsigned int * ) ( row + 0x25 ) );
			FUN_10088E00( i, 2, buf );
		}
	}

	FUN_1008A9F0( prev < 0 ? -1 : prev );
	free( rows );
	*( int * ) ( ui + 0xeb ) = saved;
	FUN_10085400();
	FUN_10085320();
}
