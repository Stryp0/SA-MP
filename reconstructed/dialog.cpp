// Reconstructed CDialog::Show (zone w2).
// SEMANTIC (compiles, not byte-verified): FUNC_1006FFB0.

// scratch reconstruction of samp.dll+0x6ffb0 (1637B)
// CDialog::Show(iDialogID, iStyle, szCaption, szInfo, szButton1, szButton2, iUnk)

#include <string.h>
#include <stdlib.h>

#pragma function(memcpy)

typedef char *PCHAR;
typedef unsigned char BYTE;

class CDlgFont
{
public:
	char	_pad[0x108];
	int		field_108;
};

class CDlgSub;

class CDlgCtrl
{
public:
	virtual void _v0();
	virtual void _v1();
	virtual void _v2();
	virtual void _v3();
	virtual void _v4();
	virtual void _v5();
	virtual void _v6();
	virtual void _v7();
	virtual void _v8();
	virtual void _v9();
	virtual void _v10();
	virtual void _v11();
	virtual void _v12();
	virtual void _v13();
	virtual void FUNC_VTBL38(int a1);
	virtual void _v15();
	virtual void FUNC_VTBL40(int a1);
	virtual void _v17();
	virtual void _v18();
	virtual void FUNC_VTBL4C();

	void FUNC_10087B40( char *pText );
};

class CDlgSub
{
public:
	virtual void _v0();
	virtual void _v1();
	virtual void _v2();
	virtual void _v3();
	virtual void _v4();
	virtual void _v5();
	virtual void _v6();
	virtual void _v7();
	virtual void _v8();
	virtual void _v9();
	virtual void _v10();
	virtual void _v11();
	virtual void _v12();
	virtual void _v13();
	virtual void FUNC_VTBL38(int a1);
	virtual void _v15();
	virtual void FUNC_VTBL40(int a1);
	virtual void _v17();
	virtual void _v18();
	virtual void FUNC_VTBL4C();

	int		_pad4;
	int		field_8;
	int		field_C;
	int		field_10;
	int		field_14;
	char	_pad18[0x35];
	int		field_4D;
	int		field_51[3];
	char	_pad5D[2];
	BYTE	field_5F;
	char	_pad60[0xc6];
	BYTE	field_126;
	char	_pad127[0xc];
	int		field_133;

	void FUNC_10085580( char *pText );
	void FUNC_1008A9F0( int a1 );
};

class CDlgWindow
{
public:
	char	_pad0[0x13];
	BYTE	field_13;
	BYTE	field_14;
	char	_pad15;
	char	field_16[0x110];
	int		field_126;
	char	_pad12A[0x10];
	CDlgFont *field_13A;
	char	_pad13E[0x20];
	CDlgCtrl *field_15E;
	int		field_162;

	CDlgFont *FUNC_100870C0( int a1 );
	CDlgCtrl *FUNC_10087270( int a1, int a2 );
	void FUNC_10084A30( CDlgSub *pDlg );
};

class CDlgMgr
{
public:
	int *FUNC_1006B200( int *pOut, const void *pStr, int a3 );
	int *FUNC_1006B2B0( int *pOut, char *pStr, int a3 );
};

class CD3DHook14E0
{
public:
	char	_pad[0x14e0];
	int		field_14E0;
	void FUNC_10069580();
};

extern CDlgMgr *pFontMgr;         // @0x1026eb9c
extern CD3DHook14E0 *pD3DHook;    // @0x1026eb84
extern char byte_100E59C9;        // "" in dll .rdata
extern unsigned short wstr_100E637C[];   // "YhXWVUyx"

class CDialog
{
public:
	int		field_0;
	int		field_4;
	int		field_8;
	int		field_C;
	int		field_10;
	int		field_14;
	int		field_18;
	CDlgWindow *m_pWindow;   // +0x1c
	CDlgSub *m_pDlg1;        // +0x20  (list dialog)
	CDlgSub *m_pDlg2;        // +0x24  (edit dialog)
	int		m_bActive;       // +0x28
	int		m_iStyle;        // +0x2c
	int		m_iDialogID;     // +0x30
	char   *m_szInfo;        // +0x34
	int		m_sizeX;         // +0x38
	int		m_sizeY;         // +0x3c
	char	m_szCaption[65]; // +0x40
	int		m_iUnk;          // +0x81
	char	_pad85[0x208];
	int		m_rowAdj[16];    // +0x28d

	void FUNC_1006F860();
	void FUNC_1006FBF0( char *pStr, int *pDims );
	void FUNC_1006FCE0( char *pStr, int *pDims, int a3 );
	void FUNC_1006F500();

	void FUNC_1006FFB0(int iDialogID, int iStyle, PCHAR szCaption, PCHAR szInfo,
		PCHAR szButton1, PCHAR szButton2, int iUnk);
};

void CDialog::FUNC_1006FFB0(int iDialogID, int iStyle, PCHAR szCaption, PCHAR szInfo,
	PCHAR szButton1, PCHAR szButton2, int iUnk)
{
	if( iDialogID < 0 )
	{
		if( m_bActive )
			FUNC_1006F860();
		return;
	}

	if( pD3DHook && pD3DHook->field_14E0 == 0 )
		;
	else if( pD3DHook )
		pD3DHook->FUNC_10069580();

	m_iDialogID = iDialogID;
	m_iStyle = iStyle;
	m_iUnk = iUnk;

	memset( m_szCaption, 0, 0x41 );
	memcpy( m_szCaption, szCaption, 0x40 );

	if( m_szInfo )
		free( m_szInfo );
	m_szInfo = (char *)calloc( 1, strlen(szInfo) + 0x40 );
	strcpy( m_szInfo, szInfo );

	int nSz[2];
	int *pSize = pFontMgr->FUNC_1006B2B0( nSz, m_szInfo, 0x40 );
	m_sizeX = pSize[0];
	m_sizeY = pSize[1];

	int nDim[2];
	if( strlen(szCaption) )
	{
		pFontMgr->FUNC_1006B200( nDim, wstr_100E637C, 0 );
		strcpy( m_pWindow->field_16, szCaption );
		m_pWindow->field_14 = 1;
		m_pWindow->field_126 = nDim[1] + 4;
	}

	nDim[0] = 0;
	nDim[1] = 0;
	int nHeight;

	switch( m_iStyle )
	{
	case 0:
		field_C = m_sizeX + 0x28;
		{
			int nY = m_sizeY;
			field_10 = m_pWindow->field_126 + nY + field_18 + 0x19;
		}
		m_pDlg2->FUNC_VTBL40( 0 );
		m_pDlg2->FUNC_VTBL38( 0 );
		goto HIDE1;

	case 1:
		field_C = m_sizeX + 0x28;
		{
			int nHdr = m_pWindow->field_126;
			field_10 = (int)(m_pWindow->FUNC_100870C0(1)->field_108 * 0.4f + 14.0f)
				+ m_sizeY + field_18 + nHdr + 0x19;
		}
		m_pDlg2->FUNC_VTBL40( 1 );
		m_pDlg2->FUNC_VTBL38( 1 );
		m_pDlg2->field_5F = ( m_pDlg2->field_126 = 0 );
		m_pDlg2->FUNC_10085580( &byte_100E59C9 );
		m_pDlg1->FUNC_VTBL40( 0 );
		m_pDlg1->FUNC_VTBL38( 0 );
		break;

	case 3:
		field_C = m_sizeX + 0x28;
		{
			int nHdr = m_pWindow->field_126;
			field_10 = (int)(m_pWindow->FUNC_100870C0(1)->field_108 * 0.4f + 14.0f)
				+ m_sizeY + field_18 + nHdr + 0x19;
		}
		m_pDlg2->FUNC_VTBL40( 1 );
		m_pDlg2->FUNC_VTBL38( 1 );
		m_pDlg2->field_5F = ( m_pDlg2->field_126 = 1 );
		m_pDlg2->FUNC_10085580( "" );
HIDE1:
		m_pDlg1->FUNC_VTBL40( 0 );
		m_pDlg1->FUNC_VTBL38( 0 );
		break;

	case 2:
		FUNC_1006FBF0( m_szInfo, nDim );
		field_C = nDim[0] + 0x28;
		if( field_C < 0x190 ) field_C = 0x190;
		if( field_C > 0x320 ) field_C = 0x320;
		if( field_C < 2*field_14 + 0x1e ) field_C = 2*field_14 + 0x1e;
		nHeight = nDim[1] + m_pDlg1->field_133 * 2;
		if( nHeight < 0xc8 ) nHeight = 0xc8;
		else if( nHeight > 0x190 ) nHeight = 0x190;
		field_10 = m_pWindow->field_126 + field_18 + nHeight + 0xf;
		m_pDlg1->field_8 = 5;
		m_pDlg1->field_C = 5;
		m_pDlg1->FUNC_VTBL4C();
		m_pDlg1->field_10 = field_C - 0xa;
		m_pDlg1->field_14 = nHeight;
		m_pDlg1->FUNC_VTBL4C();
		m_pDlg2->FUNC_VTBL40( 0 );
		m_pDlg2->FUNC_VTBL38( 0 );
		m_pDlg1->FUNC_VTBL40( 1 );
		m_pDlg1->FUNC_VTBL38( 1 );
		m_pDlg1->FUNC_VTBL4C();
		break;

	case 4:
		FUNC_1006FCE0( m_szInfo, nDim, 0 );
		field_C = nDim[0] + 0x28;
		if( field_C < 0x190 )
		{
			field_C = 0x190;
			if( m_pDlg1->field_4D > 0 )
			{
				int nDelta = (0x168 - nDim[0]) / m_pDlg1->field_4D;
				for( int i = 0; i != m_pDlg1->field_4D; i++ )
				{
					m_rowAdj[i] += nDelta;
					m_pDlg1->field_51[i] += nDelta;
				}
			}
		}
		if( field_C < 2*field_14 + 0x1e ) field_C = 2*field_14 + 0x1e;
		nHeight = nDim[1] + m_pDlg1->field_133 * 2;
		if( nHeight < 0xc8 ) nHeight = 0xc8;
		else if( nHeight > 0x190 ) nHeight = 0x190;
		field_10 = m_pWindow->field_126 + field_18 + nHeight + 0xf;
		m_pDlg1->field_C = 5;
		goto LISTTAIL;

	case 5:
		FUNC_1006FCE0( m_szInfo, nDim, 1 );
		field_C = nDim[0] + 0x28;
		if( field_C < 0x190 )
		{
			field_C = 0x190;
			if( m_pDlg1->field_4D > 0 )
			{
				int nDelta = (0x168 - nDim[0]) / m_pDlg1->field_4D;
				for( int i = 0; i != m_pDlg1->field_4D; i++ )
				{
					m_rowAdj[i] += nDelta;
					m_pDlg1->field_51[i] += nDelta;
				}
			}
		}
		if( field_C < 2*field_14 + 0x1e ) field_C = 2*field_14 + 0x1e;
		nHeight = nDim[1] + m_pDlg1->field_133 * 2;
		if( nHeight < 0xc8 ) nHeight = 0xc8;
		else if( nHeight > 0x190 ) nHeight = 0x190;
		pFontMgr->FUNC_1006B2B0( nSz, (char *)wstr_100E637C, 0 );
		field_10 = m_pWindow->field_126 + field_18 + nSz[1] + nHeight + 0xf;
		m_pDlg1->field_C = nSz[1] + 5;
LISTTAIL:
		m_pDlg1->field_8 = 5;
		m_pDlg1->FUNC_VTBL4C();
		m_pDlg1->field_14 = nHeight;
		m_pDlg1->field_10 = field_C - 0xa;
		m_pDlg1->FUNC_VTBL4C();
		m_pDlg2->FUNC_VTBL40( 0 );
		m_pDlg2->FUNC_VTBL38( 0 );
		m_pDlg1->FUNC_VTBL40( 1 );
		m_pDlg1->FUNC_VTBL38( 1 );
		m_pDlg1->FUNC_VTBL4C();
		break;
	}

	if( strlen(szButton2) )
	{
		m_pWindow->FUNC_10087270(0x14,0)->FUNC_10087B40( szButton1 );
		m_pWindow->FUNC_10087270(0x15,0)->FUNC_10087B40( szButton2 );
		m_pWindow->FUNC_10087270(0x15,0)->FUNC_VTBL40( 1 );
	}
	else
	{
		m_pWindow->FUNC_10087270(0x14,0)->FUNC_10087B40( szButton1 );
		m_pWindow->FUNC_10087270(0x15,0)->FUNC_10087B40( &byte_100E59C9 );
		m_pWindow->FUNC_10087270(0x15,0)->FUNC_VTBL40( 0 );
	}
	m_pWindow->field_13 = 1;
	if( m_iStyle == 1 || m_iStyle == 3 )
		m_pWindow->FUNC_10084A30( m_pDlg2 );
	if( m_iStyle == 2 || m_iStyle == 4 || m_iStyle == 5 )
	{
		m_pWindow->FUNC_10084A30( m_pDlg1 );
		m_pDlg1->FUNC_1008A9F0( 0 );
	}
	FUNC_1006F500();
	m_bActive = 1;
}
