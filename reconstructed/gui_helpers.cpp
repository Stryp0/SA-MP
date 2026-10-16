// Reconstructed UI/scoreboard/container helpers (zone w2 batch 3).
// VERIFIED byte-exact: FUNC_10070880 (row 0x708A5), FUNC_1006F480 (row 0x6F4C9).
// SEMANTIC (not byte-verified): FUNC_1006A870, FUNC_1006ACA0, FUNC_1006DB80,
//   FUNC_1006F860, FUNC_10072BC0, FUNC_10073AE0, FUNC_10074480, FUNC_10066AB0.

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
__declspec(dllimport) HWND __stdcall GetDesktopWindowX( void );
__declspec(dllimport) int __stdcall GetWindowRectX( HWND, CXRect * );
}

extern "C" void __cdecl FUN_1006B200( int *out, char *s, int a );
extern "C" void __cdecl FUN_1006A760();
extern "C" void __cdecl FUN_1006AC70( int );
extern "C" void __cdecl FUN_1008C7F0();
extern "C" void __cdecl FUN_100A06F0( int, int );
extern "C" void __cdecl FUN_100A05D0();
extern "C" void __cdecl FUN_10069580();
extern "C" void __cdecl FUN_10069480();
extern "C" void __cdecl FUN_10072AC0( int );
extern "C" void __cdecl FUN_100728B0( int );
extern "C" int __cdecl FUN_100B5F90( short * );
extern "C" int __cdecl FUN_100A0920();
extern "C" void __cdecl FUN_100A0440();
extern "C" void __cdecl FUN_1006B4E0( int, char *, int, int, int, int, int, DWORD, int );
extern "C" void __cdecl FUN_100B60C0();
extern "C" void __cdecl FUN_10070860();
extern "C" int __cdecl FUN_1009EB10();
extern "C" double __cdecl FUN_1009F190();
extern "C" void __cdecl FUN_10071D20( void *, int );
extern "C" int __cdecl FUN_1009F030( double );
extern "C" void __cdecl FUN_1006BC70();
extern "C" void __cdecl FUN_1006BC90( int *, char *, DWORD, int, int );
extern "C" void __cdecl FUN_1006BC80();

extern "C" int g_1026eb94;   // game ptr
extern "C" int g_1026eb84;
extern "C" int g_1026ebac;
extern "C" char g_10140d50;
extern "C" char g_1012e7b8;
extern "C" char g_1012e5a8[];
extern "C" char g_1012e398[];
extern "C" int g_00c17048;
extern "C" int g_00c17044;
extern "C" short g_10136ea8[];
extern "C" int g_10136ea4;
extern "C" char g_10140aec[];
extern "C" HWND g_0xc97c1c;
extern "C" double g_100ea688;
#pragma comment(linker,"/alternatename:_g_1026eb94=_x_1026eb94")
#pragma comment(linker,"/alternatename:_g_1026eb84=_x_1026eb84")
#pragma comment(linker,"/alternatename:_g_1026ebac=_x_1026ebac")
#pragma comment(linker,"/alternatename:_g_10140d50=_x_10140d50")
#pragma comment(linker,"/alternatename:_g_1012e7b8=_x_1012e7b8")
#pragma comment(linker,"/alternatename:_g_1012e5a8=_x_1012e5a8")
#pragma comment(linker,"/alternatename:_g_1012e398=_x_1012e398")
#pragma comment(linker,"/alternatename:_g_00c17048=_x_00c17048")
#pragma comment(linker,"/alternatename:_g_00c17044=_x_00c17044")
#pragma comment(linker,"/alternatename:_g_10136ea8=_x_10136ea8")
#pragma comment(linker,"/alternatename:_g_10136ea4=_x_10136ea4")
#pragma comment(linker,"/alternatename:_g_10140aec=_x_10140aec")
#pragma comment(linker,"/alternatename:_g_0xc97c1c=_x_0c97c1c")
#pragma comment(linker,"/alternatename:_g_100ea688=_x_100ea688")

// ---------- FUN_1006a870 ----------
class CXdObj
{
public:
	virtual void FUNC_38( int );
	virtual void FUNC_40( int );
};

class CXsSub
{
public:
	char field_0;
	char field_1;
	char field_2;
	char _p3[0x10];
	char field_13;
	char field_14;
	char _p15;
	char field_16[0x110];
	int field_126;
};

class CXs
{
public:
	char _p0[0x28];
	CXsSub *field_28;
	CXdObj *field_2c;
	int field_30;
	char _p34[0x218];
	int field_24c;
	int field_250;

	void FUNC_1006A870( int a );
};

void CXs::FUNC_1006A870( int a )
{
	int out[2];
	field_250 = a;
	FUN_1006B200( out, (char*)0x100e637c, 0 );
	strcpy( field_28->field_16, ">Updating models.." );
	field_28->field_14 = 1;
	field_28->field_126 = out[0] + 4;
	field_28->field_1 = 0;
	field_28->field_2 = 0;
	field_28->field_13 = 1;
	if( field_2c )
	{
		field_2c->FUNC_40( 1 );
		field_2c->FUNC_38( 1 );
	}
	FUN_1006A760();
	field_30 = 1;
}

// ---------- FUN_1006aca0 ----------
class CXtItem;
class CXt
{
public:
	CXtItem **field_0;
	int field_4;
	void FUNC_1006ACA0();
};

void CXt::FUNC_1006ACA0()
{
	int n = field_4;
	for( int i = 0; i < n; i++ )
	{
		if( i < field_4 )
		{
			void *e = field_0[i];
			if( e )
			{
				free( e );
				FUN_1006AC70( i );
			}
		}
	}
	FUN_1008C7F0();
}

// ---------- FUN_1006db80 ----------
class CXu
{
public:
	int field_0;
	void FUNC_1006DB80( int v );
};

void CXu::FUNC_1006DB80( int v )
{
	if( field_0 )
	{
		if( !v )
		{
			FUN_100A06F0( 0, 1 );
			if( *( int * ) ( g_1026eb84 + 0x14e0 ) )
			{
				FUN_10069580();
				FUN_10069480();
			}
		}
		if( field_0 )
			goto done;
	}
	if( v )
	{
		FUN_100A06F0( 0, 1 );
		*( int * ) ( g_1026ebac + 0x65 ) = 0;
		FUN_100A05D0();
	}
done:
	field_0 = v;
}

// ---------- FUN_1006f480 (ctor) ----------
class CXv
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
	int field_20;
	int field_24;
	int field_28;
	int field_2c;
	int field_30;
	int field_34;
	char _p38[0x4c];
	int field_84;
	char _p88[1];
	int field_89[0x81];

	CXv *FUNC_1006F480( int a );
};

CXv *CXv::FUNC_1006F480( int a )
{
	field_0 = a;
	field_1c = 0;
	field_28 = 0;
	field_34 = 0;
	field_30 = 0;
	field_2c = 0;
	field_c = 600;
	field_10 = 300;
	field_14 = 100;
	field_18 = 0x1e;
	int *p = ( int * ) ( ( char * ) this + 0x89 );
	for( int i = 0x81; i != 0; --i )
		*p++ = 0;
	return this;
}

// ---------- FUN_1006f860 ----------
class CXw
{
public:
	char _p0[0x1c];
	int field_1c;
	char _p20[8];
	int field_28;
	void FUNC_1006F860();
};

void CXw::FUNC_1006F860()
{
	FUN_100A06F0( 0, 0 );
	*( char * ) ( field_1c + 0x13 ) = 0;
	field_28 = 0;
}

// ---------- FUN_10070880 (ctor) ----------
class CXx
{
public:
	int field_0;
	int field_4;
	int field_8;
	CXx *FUNC_10070880( int a );
};

CXx *CXx::FUNC_10070880( int a )
{
	field_0 = a;
	field_4 = 0;
	field_8 = 0;
	FUN_10070860();
	return this;
}

// ---------- FUN_10072bc0 ----------
class CXz
{
public:
	char _p0[0x78];
	int field_78;
	char _p7c[4];
	int field_80;
	void FUNC_10072BC0( int a );
};

void CXz::FUNC_10072BC0( int a )
{
	field_80 = 0;
	FUN_100A06F0( 0, 1 );
	if( *( int * ) ( g_1026eb84 + 0x14e0 ) )
	{
		FUN_10069580();
		FUN_10069480();
	}
	if( field_78 == 2 )
		FUN_10072AC0( a != 0 );
	if( field_78 == 1 )
		FUN_100728B0( a != 0 );
}

// ---------- FUN_10073ae0 ----------
void __cdecl FUNC_10073AE0()
{
	short c = g_10136ea8[ g_10136ea4 ];
	while( c && ( c == 0x20 || c == 9 || c == 0xa || c == 0xd ) )
		c = g_10136ea8[ ++g_10136ea4 ];
	unsigned int u = FUN_100B5F90( &g_10136ea8[ g_10136ea4 ] );
	while( u != 0xffffffff )
	{
		*( int * ) 0x10136e90 = u | 0xff000000;
		g_10136ea4 += 8;
		c = g_10136ea8[ g_10136ea4 ];
		while( c && ( c == 0x20 || c == 9 || c == 0xa || c == 0xd ) )
			c = g_10136ea8[ ++g_10136ea4 ];
		u = FUN_100B5F90( &g_10136ea8[ g_10136ea4 ] );
	}
	if( g_10140aec[ g_10136ea4 ] )
		++g_10136ea4;
}

// ---------- FUN_10074480 ----------
void __cdecl FUNC_10074480()
{
	if( g_1026ebac )
	{
		if( FUN_100A0920() && !g_10140d50 )
		{
			g_10140d50 = 1;
			FUN_100A0440();
			return;
		}
		if( !FUN_100A0920() && g_10140d50 )
		{
			g_10140d50 = 0;
			FUN_100A0440();
			return;
		}
	}
}

// ---------- FUN_10066ab0 ----------
void __cdecl FUNC_10066AB0( char *self )
{
	char buf[260];
	if( *self && g_1012e7b8 )
	{
		memset( buf, 0, sizeof( buf ) );
		if( strlen( g_1012e5a8 ) && strlen( g_1012e398 ) )
		{
			_snprintf( buf, 0x100, "%s - %s", g_1012e5a8, g_1012e398 );
			FUN_1006B4E0( 0, buf, 0xf, g_00c17048 - 0x14, g_00c17044, g_00c17048 + 0xa, 0x100, 0x99ffffff, 0 );
		}
	}
}
