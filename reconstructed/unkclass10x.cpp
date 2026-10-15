// Reconstructed UI/mouse-drag class near CUnkClass10 (zone w2).
// VERIFIED byte-exact: CUnkClass10G::FUNC_10073550, FUNC_10073460.
// SEMANTIC (compiles, not byte-verified): FUNC_10073780, FUNC_10073210, FUNC_10073480.

typedef int BOOL;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;
typedef int LONG;
typedef char *PCHAR;
typedef void *PVOID;
typedef void *HWND;

typedef struct tagPOINT { LONG x, y; } POINT;
typedef struct tagRECT { LONG left, top, right, bottom; } RECT;
typedef struct tagMATRIX { float m[4][4]; } MATRIX;
typedef struct tagVECTOR { float x, y, z; } VECTOR;

#define TRUE 1
#define FALSE 0
#define NULL 0

__declspec(dllimport) BOOL __stdcall GetCursorPos( POINT *p );
__declspec(dllimport) BOOL __stdcall SetCursorPos( int x, int y );
__declspec(dllimport) BOOL __stdcall ClientToScreen( HWND h, POINT *p );
__declspec(dllimport) BOOL __stdcall ScreenToClient( HWND h, POINT *p );
__declspec(dllimport) HWND __stdcall SetCapture( HWND h );
__declspec(dllimport) BOOL __stdcall ReleaseCapture();
__declspec(dllimport) BOOL __stdcall ClipCursor( const RECT *r );

extern int (__cdecl *pFn_12E350)( int );

extern HWND g_hwnd;
extern void *g_pNetGame;
extern void *g_pGame;
extern void *g_pD3DDev;

class CObj3
{
public:
	void FUNC_1009F8F0( float *a, float *b, float *c );
	void FUNC_1009F780();
	void FUNC_1009EB10( void *p );
	float FUNC_1009F190();
	void FUNC_100A80A0( void *p );
	void FUNC_100A9BD0( float a, float b, float c, float d, float e, float f, float g );
};

class CPoolObj3
{
public:
	BYTE _p0[4];
	DWORD m_pSlots[1000];
	CObj3 *m_pObj[1000];
	CObj3 *FUNC_10002DE0( WORD id );
};

class CPools3
{
public:
	BYTE _p0[0xc];
	CPoolObj3 *m_pObjPool;
};

class CPedPool3
{
public:
	int FUNC_100AF5D0( int *a, int *b );
	CObj3 *FUNC_10013680( int id );
	void *FUNC_10071B30( int id );
	void FUNC_100AEC10( void *p, int n );
};

class CNetGame3
{
public:
	BYTE _p0[0x3de];
	CPools3 *m_pPools;
};

class CD3DDev3
{
public:
	virtual void __stdcall stub0();
	virtual void __stdcall stub4();
	virtual void __stdcall stub8();
	virtual void __stdcall stubC();
	virtual void __stdcall stub10();
	virtual void __stdcall stub14();
	virtual void __stdcall stub18();
	virtual void __stdcall stub1C();
	virtual void __stdcall stub20();
	virtual void __stdcall stub24();
	virtual void __stdcall stub28();
	virtual void __stdcall stub2C();
	virtual void __stdcall ShowCursor( int b );
};

class CGame3
{
public:
	CPedPool3 *FUNC_10001010();
	void FUNC_100A06F0( int a, int b );
};

extern "C" float __cdecl FUNC_100B48E0( float );
extern "C" void __cdecl FUNC_100B4D10( float *out, float *mat, float *in );

extern CNetGame3 *pNetGame;
extern CGame3 *pGame;
extern CD3DDev3 *pD3DDev;
extern HWND g_hwndC;
extern int (__stdcall *pFnShowCursor)( int );

class CUnkClass10G
{
public:
	BYTE _p0[8];
	RECT field_8[7];
	int field_78;
	int field_7C;
	DWORD field_80;
	DWORD field_84;
	WORD field_88;
	int field_8A;
	BYTE _p8E[4];
	float field_92;
	float field_96;
	float field_9A;
	BYTE _p9E[4];
	BYTE field_A2;
	BYTE field_A3;
	BYTE field_A4;
	BYTE field_A5;
	BYTE field_A6;
	POINT field_A7;
	POINT field_AF;
	DWORD field_B7;
	DWORD field_BB;
	DWORD field_BF;
	BYTE field_C3[0x40];
	DWORD field_103;
	DWORD field_107;
	DWORD field_10B;
	DWORD field_10F;
	int field_113;

	void FUNC_100721F0( int n );
	void FUNC_100720A0();
	void FUNC_100723C0();
	void FUNC_10072BC0( int n );
	void FUNC_10072210( int n, float f );
	int FUNC_100728B0( int n );
	BOOL FUNC_10072C30( float *pMat, float fS );
	void FUNC_10073210( int nAxis, float fS );
	void FUNC_10073460( int nAxis, float fS );
	void FUNC_10073480();
	int FUNC_10073550( int msg, int w, int l );
	void FUNC_10073780();
};

void CUnkClass10G::FUNC_10073460( int nAxis, float fS )
{
	if( field_78 == 1 )
		FUNC_10073210( nAxis, fS );
	else if( field_78 == 2 )
		FUNC_10072210( nAxis, fS );
}

void CUnkClass10G::FUNC_10073480()
{
	POINT pt;
	int nDelta;
	int a, b;
	BYTE al;
	DWORD nAxis;

	DWORD nMode;
	nAxis = 0;
	GetCursorPos( &pt );
	al = 0;
	nMode = field_113;
	if( nMode == 0 )
	{
		al = field_A4;
		nAxis = field_B7;
	}
	else if( nMode == 1 )
	{
		al = field_A5;
		nAxis = field_BB;
	}
	else if( nMode == 2 )
	{
		al = field_A6;
		nAxis = field_BF;
	}
	if( field_7C == 1 )
	{
		if( nAxis ) goto selx;
		goto sely;
	}
	if( nAxis ) goto sely;
	goto selx;
sely:
	if( al ) { a = field_A7.y; b = pt.y; }
	else     { a = pt.y; b = field_A7.y; }
	goto seld;
selx:
	if( al ) { a = field_A7.x; b = pt.x; }
	else     { a = pt.x; b = field_A7.x; }
seld:;
	nDelta = a - b;
	if( nDelta != 0 )
	{
		FUNC_10073460( nMode, (float)nDelta * 0.01f );
		FUNC_100723C0();
	}
}

int CUnkClass10G::FUNC_10073550( int msg, int w, int l )
{
	POINT pt;
	CPoolObj3 *pool;
	CObj3 *obj;

	if( !field_80 )
		return 0;
	if( msg == 0x201 )
	{
		if( field_A3 )
			return 0;
		if( field_113 == -1 )
			return 0;
		if( field_113 != 0 && field_113 != 1 && field_113 != 2 )
			return 0;
		field_A3 = 1;
		GetCursorPos( &field_A7 );
		GetCursorPos( &field_AF );
		ScreenToClient( g_hwnd, &field_AF );
		SetCapture( g_hwnd );
		pFnShowCursor( 0 );
		ClipCursor( NULL );
		obj = pNetGame->m_pPools->m_pObjPool->FUNC_10002DE0( field_88 );
		if( obj )
			obj->FUNC_1009EB10( &field_C3 );
		return 1;
	}
	if( msg == 0x202 )
	{
		if( field_A3 )
		{
			field_A3 = 0;
			ReleaseCapture();
			pFnShowCursor( 1 );
			if( field_113 == 0 )
			{
				pt.x = field_8[0].left;
				pt.y = field_8[0].top;
			}
			else if( field_113 == 1 )
			{
				pt.x = field_8[1].left;
				pt.y = field_8[1].top;
			}
			else if( field_113 == 2 )
			{
				pt.x = field_8[2].left;
				pt.y = field_8[2].top;
			}
			else
			{
				pt.x = field_AF.x;
				pt.y = field_AF.y;
			}
			ClientToScreen( g_hwnd, &pt );
			SetCursorPos( pt.x, pt.y );
			FUNC_100720A0();
			return 1;
		}
		if( field_113 == 3 )
		{
			FUNC_100721F0( 0 );
			return 1;
		}
		if( field_113 == 4 )
		{
			FUNC_100721F0( 1 );
			return 1;
		}
		if( field_113 == 5 )
		{
			FUNC_100721F0( 2 );
			return 1;
		}
		if( field_113 == 0xa )
		{
			FUNC_10072BC0( 1 );
			return 1;
		}
		return 0;
	}
	if( msg == 0x200 )
	{
		if( !field_A3 )
			return 0;
		FUNC_10073480();
		return 1;
	}
	return 0;
}

void CUnkClass10G::FUNC_10073780()
{
	int a, b;
	MATRIX m, m2;
	float f;
	int r;

	field_84 = 0;
	if( !field_80 )
		return;
	r = pGame->FUNC_10001010()->FUNC_100AF5D0( &a, &b );
	if( field_A3 )
		pD3DDev->ShowCursor( 0 );
	else if( r & 8 )
		pGame->FUNC_100A06F0( 0, 1 );
	else
	{
		pD3DDev->ShowCursor( 1 );
		pGame->FUNC_100A06F0( 3, 1 );
	}
	if( pNetGame )
	{
		if( field_78 == 1 )
		{
			CPoolObj3 *pool = pNetGame->m_pPools->m_pObjPool;
			if( field_88 <= 0x3e8 && pool->m_pSlots[field_88] )
			{
				CObj3 *obj = pool->m_pObj[field_88];
				if( obj )
				{
					obj->FUNC_1009EB10( &m );
					if( FUNC_10072C30( &m.m[0][0], obj->FUNC_1009F190() * 0.125f ) )
						field_84 = 1;
				}
			}
		}
		else if( field_78 == 2 )
		{
			CObj3 *ped = pGame->FUNC_10001010()->FUNC_10013680( field_8A );
			void *pv = pGame->FUNC_10001010()->FUNC_10071B30( field_8A );
			if( ped )
			{
				ped->FUNC_1009EB10( &m );
				f = ped->FUNC_1009F190();
				if( field_7C == 0 )
				{
					pGame->FUNC_10001010()->FUNC_100AEC10( &m2, ((int*)pv)[1] );
					*(VECTOR*)&m.m[1][0] = *(VECTOR*)&m2.m[1][0];
					*(VECTOR*)&m.m[0][0] = *(VECTOR*)&m2.m[0][0];
					*(VECTOR*)&m.m[2][0] = *(VECTOR*)&m2.m[2][0];
				}
				if( FUNC_10072C30( &m.m[0][0], f * 0.125f ) )
					field_84 = 1;
			}
		}
		if( !field_A3 )
			FUNC_100720A0();
	}
}

void CUnkClass10G::FUNC_10073210( int nAxis, float fS )
{
	void *pC3;
	float w[3];
	float v3[3];
	float v[3];
	MATRIX m;
	CPoolObj3 *pool;
	CObj3 *obj;

	v3[0] = 0;
	v3[1] = 0;
	v3[2] = 0;
	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	pool = pNetGame->m_pPools->m_pObjPool;
	if( field_88 > 0x3e8 )
		return;
	if( !pool->m_pSlots[field_88] )
		return;
	obj = pool->m_pObj[field_88];
	if( !obj )
		return;
	obj->FUNC_1009F8F0( &w[2], &w[1], &w[0] );
	obj->FUNC_1009F780();
	pC3 = &field_C3;
	m = *(MATRIX *)&field_C3;
	v3[0] = m.m[3][0];
	v3[1] = m.m[3][1];
	v3[2] = m.m[3][2];
	if( nAxis == 0 )
	{
		if( field_7C == 0 )
		{
			FUNC_100B4D10( v3, &m.m[0][0], ( v[0] = fS, v ) );
			goto tail;
		}
		if( field_7C == 1 )
		{
			field_92 = FUNC_100B48E0( field_92 + fS * 10.0f );
			obj->FUNC_100A80A0( &field_92 );
		}
	}
	else if( nAxis == 1 )
	{
		if( field_7C == 0 )
		{
			FUNC_100B4D10( v3, &m.m[0][0], ( v[1] = fS, v ) );
			goto tail;
		}
		if( field_7C == 1 )
		{
			field_96 = FUNC_100B48E0( field_96 + fS * 10.0f );
			obj->FUNC_100A80A0( &field_92 );
		}
	}
	else if( nAxis == 2 )
	{
		if( field_7C == 0 )
		{
			FUNC_100B4D10( v3, &m.m[0][0], ( v[2] = fS, v ) );
			goto tail;
		}
		if( field_7C == 1 )
		{
			field_9A = FUNC_100B48E0( field_9A + fS * 10.0f );
			obj->FUNC_100A80A0( &field_92 );
		}
	}
	goto tail;
tail:
	obj->FUNC_100A9BD0( v[0], v[1], v[2], 1.0f, -1000.0f, -1000.0f, -1000.0f );
	m.m[3][0] = v[0];
	m.m[3][1] = v[1];
	m.m[3][2] = v[2];
	FUNC_100728B0( 2 );
	*(MATRIX *)pC3 = m;
}
