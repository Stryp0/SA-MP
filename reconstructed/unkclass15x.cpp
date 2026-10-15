// Reconstructed D3D/camera helper classes near CUnkClass15 (zone w2).
// VERIFIED byte-exact: FUNC_1006C670 (CUnkClass15), CUnkClass15C::FUNC_1006BF90.
// SEMANTIC (compiles, not byte-verified): CUnkClass15B::FUNC_1006C9B0.

// CUnkClass15::FUNC_1006C670 — render a model into the preview raster
// .text 0x6c670-0x6cc60, SEH-framed

#include <windows.h>

typedef struct { float x, y, z; } VECTOR;
typedef struct { float m[16]; } MAT16;


extern void * RwRasterCreate( int w, int h, int flags, int type );          // 0x100b16d0
extern void * FUNC_100B1720( void *pRaster );                               // raster lock
extern float FUNC_100B6360( int nModel );                                  // model bound radius
extern void FUNC_100B5790( MAT16 *pMat, int nIdx, float fVal );            // matrix elem store
extern void FUNC_100B19B0( void *p1, void *p2, void *p3 );
extern void FUNC_100B1C40( void *p1 );
extern void FUNC_100B18F0( void *p1, void *p2, int n );
extern void FUNC_100B1920( void *p1 );
extern void FUNC_100B1BC0( void *p1 );
extern void FUNC_100B1950( void *p1 );
extern void FUNC_100B1C00( void *p1 );
extern void FUNC_100C3E20( int nState, int nValue );                       // RwRenderStateSet
extern short __stdcall FUNC_100B4700( void *p1 );
extern void __stdcall FUNC_100A7A40( void *p1 );

class CEntObj
{
public:
	CEntObj( int nModel, int a2, int a3, float fR, VECTOR v, int a8, int a9, int a10, int a11 );
	char m_pad0[0x3c];
	int field_40;
	char m_pad[0x1158];
	void FUNC_1009EB10( float *pOut );
	void FUNC_1009FD00( MAT16 m );
	void FUNC_1009EEF0( VECTOR *pOut );
	void FUNC_1009F040( float fX, float fY, float fZ );
	int  FUNC_1009FA60();
	void *FUNC_1009EF50( void *p1 );
	void FUNC_1009FB20();
	virtual void vfunc0( int a1 );
};

class CDlgMgr
{
public:
	void FUNC_100A09A0( void *p1, int a2 );
};

extern CDlgMgr *pDialogMisc; // @0x1026ebac

class CUnkClass15
{
public:
	void *m_pCamera;   // +0
	void *m_pFrame;    // +4
	void *m_pLight;    // +8
	void *m_pTexture;
	void *m_pRaster1;
	void *m_pRaster2;  // +0x14
	int field_18;

	void *FUNC_1006C670( int nModel, float fArg2, VECTOR *pPos, float fScale );
};

void *CUnkClass15::FUNC_1006C670( int nModel, float fArg2, VECTOR *pPos, float fScale )
{
	CEntObj *pObj;
	void *pLock;
	void *pv;
	void *p2;
	MAT16 m;
	int nZero;
	VECTOR vPos;
	VECTOR vOut;
	int nAfter1;
	int nAfter2;

	nZero = 0;
	vPos.x = 0.0f;
	vPos.y = 0.0f;
	vPos.z = 0.0f;
	pLock = RwRasterCreate( 0x100, 0x100, nZero, 0x505 );
	pv = FUNC_100B1720( pLock );
	if( !pLock || !pv )
		return 0;

	if( nModel == 0x55d || nModel == 0xc2e || nModel == 0xde0 || nModel == 0xde1 )
		nModel = 0x48c7;

	pObj = new CEntObj( nModel, 0, 0, 50.0f, vPos, 0, 0, 0, 0 );
	if( !pObj || !pObj->field_40 )
		return pv;

	*(volatile float *)&fScale = ( -0.1f - FUNC_100B6360( nModel ) * 2.25f ) * fScale;
	memset( &m, 0, sizeof( m ) );
	pObj->FUNC_1009EB10( (float *)&m );
	if( nModel == 0x48c7 )
		FUNC_100B5790( &m, 2, 180.0f );
	else
	{
		if( pPos->x != 0.0f )
			FUNC_100B5790( &m, 0, pPos->x );
		if( pPos->y != 0.0f )
			FUNC_100B5790( &m, 1, pPos->y );
		if( pPos->z != 0.0f )
			FUNC_100B5790( &m, 2, pPos->z );
	}
	pObj->FUNC_1009FD00( m );
	pObj->FUNC_1009EEF0( &vOut );
	pObj->FUNC_1009F040( -vOut.x, fArg2, 50.0f - ( vOut.z - 50.0f ) );

	p2 = 0;
	if( !pObj->FUNC_1009FA60() )
		p2 = pObj->FUNC_1009EF50( pLock );
	FUNC_100B19B0( m_pCamera, pLock, m_pRaster2 );
	FUNC_100B1C40( m_pCamera );
	FUNC_100B18F0( m_pCamera, &fArg2, 3 );
	FUNC_100B1920( m_pCamera );
	FUNC_100B1BC0( m_pLight );
	FUNC_100C3E20( 6, 1 );
	FUNC_100C3E20( 8, 1 );
	FUNC_100C3E20( 7, 2 );
	FUNC_100C3E20( 0xe, 0 );
	if( pObj->FUNC_1009FA60() )
		pObj->FUNC_1009FB20();
	FUNC_100A7A40( pLock );
	FUNC_100B1950( m_pCamera );
	FUNC_100B1C00( m_pLight );
	pObj->vfunc0( 1 );
	if( p2 )
	{
		if( !FUNC_100B4700( pLock ) )
			pDialogMisc->FUNC_100A09A0( pLock, 0 );
	}
	return pv;
}

// --- func2: 0x6c9b0 — wait for model + render preview into raster ---

extern void * FUNC_100B6250( int nModel );
extern void FUNC_100B6410( int nModel, void *p );
extern void FUNC_100B1CF0( int a1, void *pVec );
extern void FUNC_100B1D20( void *pEnt, int nIdx, float fVal );
extern void FUNC_100B6330( void *p );
extern void FUNC_100B4520( int a1 );
extern void FUNC_100B62B0( void *p );
extern int FUNC_100A7A40_2( int a1 );
extern void (*pSleep)( int ms );              // @0x100e5254 → use global

typedef void (*SLEEPFN)( int );
extern SLEEPFN pSleepFn;

class CDlgMgr2
{
public:
	int  FUNC_100A0970( int a1 );
	void FUNC_100A0940( int a1, int a2 );
	void FUNC_100A0960();
	void FUNC_100A09A0( int a1, int a2 );
};

extern CDlgMgr2 *pDialogMisc2;

class CModelEnt
{
public:
	void *field_4;
};

class CUnkClass15B
{
public:
	void *m_pCamera;
	void *m_pFrame;
	void *m_pLight;
	void *m_pTexture;
	void *m_pRaster1;
	void *m_pRaster2;

	void *FUNC_1006C9B0( int nModel, void *pArg2, VECTOR *pPos, float fScale );
};

void *CUnkClass15B::FUNC_1006C9B0( int nModel, void *pArg2, VECTOR *pPos, float fScale )
{
	void *pRaster;
	void *pv;
	CModelEnt *pM;
	void *pEnt;
	SLEEPFN pSleep;
	float fCam;
	VECTOR v;
	VECTOR vCam;
	int nFlag;

	pRaster = RwRasterCreate( 0x100, 0x100, 0, 0x505 );
	pv = FUNC_100B1720( pRaster );
	if( !pRaster || !pv )
		return 0;

	if( nModel == 0x55d || nModel == 0xc2e || nModel == 0xde0 || nModel == 0xde1 )
		nModel = 0x48c7;

	nFlag = 0;
	if( !pDialogMisc2->FUNC_100A0970( nModel ) )
	{
		nFlag = 1;
		pDialogMisc2->FUNC_100A0940( nModel, 2 );
		pDialogMisc2->FUNC_100A0960();
		pSleep = pSleepFn;
		while( !pDialogMisc2->FUNC_100A0970( nModel ) )
			pSleep( 1 );
	}

	pM = (CModelEnt *)FUNC_100B6250( nModel );
	if( !pM )
		return pv;

	fCam = ( -0.1f - FUNC_100B6360( nModel ) * 2.25f ) * fScale;
	v.x = 0.0f;
	v.y = 0.0f;
	v.z = 0.0f;
	FUNC_100B6410( nModel, &v );

	pEnt = pM->field_4;
	if( pEnt )
	{
		vCam.x = -v.x;
		vCam.y = v.y;
		vCam.z = 50.0f - v.z;
		FUNC_100B1CF0( 1, &vCam );
		if( nModel == 0x48c7 )
			FUNC_100B1D20( pEnt, 2, 180.0f );
		else
		{
			if( pPos->x != 0.0f )
				FUNC_100B1D20( pEnt, 0, pPos->x );
			if( pPos->y != 0.0f )
				FUNC_100B1D20( pEnt, 1, pPos->y );
			if( pPos->z != 0.0f )
				FUNC_100B1D20( pEnt, 2, pPos->z );
		}
	}
	FUNC_100B19B0( m_pCamera, pv, m_pRaster2 );
	FUNC_100B1C40( m_pCamera );
	FUNC_100B18F0( m_pCamera, &fCam, 3 );
	FUNC_100B1920( m_pCamera );
	FUNC_100B1BC0( m_pLight );
	FUNC_100C3E20( 6, 1 );
	FUNC_100C3E20( 8, 1 );
	FUNC_100C3E20( 7, 2 );
	FUNC_100C3E20( 0x1e, 0 );
	FUNC_100C3E20( 0x14, 0 );
	FUNC_100C3E20( 0xe, 0 );
	FUNC_100B6330( pM );
	FUNC_100B4520( (int)FUNC_100A7A40_2( nModel ) );
	FUNC_100B1950( m_pCamera );
	FUNC_100B1C00( m_pLight );
	FUNC_100B62B0( pM );
	if( nFlag )
		pDialogMisc2->FUNC_100A09A0( nModel, 0 );
	return pv;
}
