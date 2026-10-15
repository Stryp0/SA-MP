// Reconstructed input/key dispatch + settings (zone w2).
// VERIFIED byte-exact: CSt::GetField13/61/8/24, CSt::ToggleField0, CSt::FUNC_100612C0,
//   sub_10061360, sub_10061590 (ESC/chat-key handler).
// SEMANTIC (compiles, not byte-verified): sub_10061310.

// Scratch reconstruction for 0x612b4-0x6164f cluster
typedef int BOOL;
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

// --- extern globals (alternatename'd) ---
class CX84
{
public:
	char pad[0x14e0];
	int field_14e0;
	void FUNC_10069580();
	void FUNC_10069480();
	bool FUNC_10069810();
	void FUNC_10069630();
	void FUNC_100696A0();
};
extern CX84 *pHookG;
#pragma comment(linker,"/alternatename:_pHookG=_g_1026eb84")

class CX4c
{
public:
	int field_0;
	void FUNC_1006E9E0( int );
};
extern CX4c *pXG;
#pragma comment(linker,"/alternatename:_pXG=_g_1026eb4c")

class CX50
{
public:
	char pad[0x28];
	int field_28;
	void FUNC_10070630( int );
};
extern CX50 *pY;
#pragma comment(linker,"/alternatename:_pY=_g_1026eb50")

class CGm
{
public:
	int IsMenuActive();
};
extern CGm *pGameG;
#pragma comment(linker,"/alternatename:_pGameG=_g_1026ebac")

// --- small getters on a settings-ish class ---
class CSt
{
public:
	int field_0;		// 0x0
	int field_4;		// 0x4
	int field_8;		// 0x8
	char pad_c[0x13-0xc];
	char field_13;		// 0x13
	char pad_14[0x24-0x14];
	int field_24;		// 0x24
	char pad_28[0x61-0x28];
	int field_61;		// 0x61
	char pad_65[0x63da-0x65];
	int field_63da;		// 0x63da

	char GetField13();
	int GetField61();
	int GetField8();
	int GetField24();
	void ToggleField0();
	void FUNC_100612C0();
	void FUNC_100672D0();
	void FUNC_10067330();
};

char CSt::GetField13() { return field_13; }
int CSt::GetField61() { return field_61; }
int CSt::GetField8() { return field_8; }
int CSt::GetField24() { return field_24; }
void CSt::ToggleField0() { field_0 = (field_0 == 0); }
void CSt::FUNC_100612C0()
{
	field_63da = 1;
	if( !field_8 )
		field_8 = 2;
	else if( field_8 == 1 )
		field_8 = 0;
	else if( field_8 == 2 )
		field_8 = 1;
}

// --- 0x61310: save/toggle table entry around callback ---
extern "C" int *g_pTbl;
#pragma comment(linker,"/alternatename:_g_pTbl=_x_c97c48")
extern "C" int g_Idx[];
#pragma comment(linker,"/alternatename:_g_Idx=_x_c97c18")

#pragma optimize( "y", off )
int sub_10061310()
{
	int *pIdx = g_Idx;
	int n = *pIdx;
	int *pE = g_pTbl + n * 5;
	pE[4] = (pE[4] == 0);
	int saved[1];
	saved[0] = n;
	*pIdx = -1;
	((void (__cdecl *)(int))0x745c70)( saved[0] );
	*pIdx = saved[0];
	return 0;
}
#pragma optimize( "", on )

// --- 0x61590: ESC / chat-key handler ---
int __cdecl sub_10061590( int wParam )
{
	if( pHookG && pHookG->field_14e0 )
	{
		if( wParam == 0x1b )
		{
			pHookG->FUNC_10069580();
			return 1;
		}
		return 0;
	}
	if( pXG && pXG->field_0 )
	{
		if( wParam == 0x1b )
		{
			pXG->FUNC_1006E9E0( 1 );
			return 1;
		}
		return 0;
	}
	if( pY && pY->field_28 )
	{
		if( wParam == 0x1b )
		{
			pY->FUNC_10070630( 0 );
			return 1;
		}
		return 0;
	}
	if( wParam == 0x54 || wParam == 0x60 || wParam == 0x74 )
	{
		if( pHookG && !( pY && pY->field_28 ) && !pGameG->IsMenuActive() )
		{
			pHookG->FUNC_10069480();
			return 1;
		}
	}
	return 0;
}

// --- more externs for the key dispatcher ---
extern CSt *pStG;
#pragma comment(linker,"/alternatename:_pStG=_g_1026eb80")
extern "C" int g_EB94;
#pragma comment(linker,"/alternatename:_g_EB94=_g_1026eb94")
extern "C" int *g_pEB88;
#pragma comment(linker,"/alternatename:_g_pEB88=_g_1026eb88")
extern "C" int g_E8;
#pragma comment(linker,"/alternatename:_g_E8=_g_1026dfe8")
extern "C" int g_E64;
#pragma comment(linker,"/alternatename:_g_E64=_g_1012de64")
extern "C" void __cdecl FUNC_10068B80( const char *s );


// --- 0x61360: virtual-key dispatcher ---
int __cdecl sub_10061360( int a )
{
	switch( a )
	{
	case 0xd:
		if( pY && pY->field_28 )
			pY->FUNC_10070630( 1 );
		return 0;
	case 0x75:
		if( pHookG->field_14e0 )
			pHookG->FUNC_10069580();
		else
			pHookG->FUNC_10069480();
		return 0;
	case 0x76:
		pStG->FUNC_100612C0();
		return 0;
	case 0x77:
		g_E64 = 1;
		return 0;
	case 0x78:
		{
			int *p = g_pEB88;
			*p = ( *p == 0 );
		}
		return 0;
	case 0x21:
		if( g_EB94 && pStG && !pHookG->FUNC_10069810() )
			pStG->FUNC_100672D0();
		return 0;
	case 0x22:
		if( g_EB94 && pStG && !pHookG->FUNC_10069810() )
			pStG->FUNC_10067330();
		return 0;
	case 0x6d:
		if( g_E8 )
			FUNC_10068B80( "Str" );
		return 0;
	case 0x1b:
		if( pHookG->field_14e0 )
		{
			if( !pHookG->FUNC_10069810() )
				pHookG->FUNC_10069580();
		}
		return 0;
	case 0x26:
		if( pHookG->field_14e0 && !pHookG->FUNC_10069810() )
			pHookG->FUNC_10069630();
		return 0;
	case 0x28:
		if( pHookG->field_14e0 && !pHookG->FUNC_10069810() )
			pHookG->FUNC_100696A0();
		return 0;
	}
	return 0;
}
