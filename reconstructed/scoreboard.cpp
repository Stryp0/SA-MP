// Reconstructed CScoreBoard column-header renderer (zone w2).
// SEMANTIC (compiles, not byte-verified): CScoreBoard::FUNC_1006F0B0.

// Scratch reconstruction of FUNC_1006F0B0 — scoreboard header renderer
// "Players: %d" + id/name/score/ping column headers, centered bg panel.

#include <windows.h>
#include <stdio.h>
#include <string.h>


extern int sprintf( char *str, const char *fmt, ... );

class CScoreBG
{
public:
	char	_pad0[0x116];
	int		field_116;
	int		field_11a;

	void FUNC_100908E0( float f );
};

class CSbList
{
public:
	int FUNC_100139F0( int a1 );
};

class CSbNetObj
{
public:
	int		field_0;
	CSbList *field_4;
};

class CSbGame
{
public:
	char		_pad0[0x131];
	char		field_131[0x100];
	char		_pad231[0x3de - 0x231];
	CSbNetObj	*field_3de;

	void FUNC_10008F10();
};

extern CSbGame *g_pGame2_sb;

class CSbFontSvc
{
public:
	char	_pad0[0x24];
	int		field_24;

	void FUNC_1006B4E0( int a1, char *pStr, RECT rc, int a4, int color, int a6 );
	void FUNC_1006B2B0( int *pOut, char *pStr, int a3 );
};

extern CSbFontSvc *g_pFontSvc_sb;


extern int dword_0C17044;
extern int dword_0C17048;

class CScoreBoard
{
public:
	int			field_0;	// +0x00 guard
	int			field_4;	// +0x04 cached count
	float		field_8;	// +0x08 x
	float		field_c;	// +0x0c y
	float		field_10;	// +0x10 col unit
	float		field_14;	// +0x14 width
	float		field_18;	// +0x18 height
	float		field_1c;	// +0x1c row height
	int			field_20;
	float		field_24;	// +0x24 name col fraction
	float		field_28;	// +0x28 ping col fraction
	float		field_2c;	// +0x2c score col fraction
	int			field_30;
	CScoreBG	*field_34;	// +0x34 bg panel

	void FUNC_1006ED30();
	void FUNC_1006F0B0();
};

void CScoreBoard::FUNC_1006F0B0()
{
	char sz[8];
	char buf[0x40];
	RECT rc;
	int nX, nY;
	int nCnt;
	int nW, nH;
	int eax1, eax2;
	CScoreBG *pBg;
	CSbList *pList;

	if( field_0 == 0 )
		return;

	if( g_pGame2_sb )
	{
		nCnt = g_pGame2_sb->field_3de->field_4->FUNC_100139F0( 0 ) + 1;
		if( nCnt != field_4 )
		{
			field_4 = nCnt;
			FUNC_1006ED30();
		}
		g_pGame2_sb->FUNC_10008F10();
	}

	pBg = field_34;
	if( pBg )
	{
		nW = dword_0C17044;
		if( nW > 0 )
		{
			nH = dword_0C17048;
			if( nH > 0 )
			{
				eax2 = (int)(field_18);
				nY = nH / 2 - eax2 / 2;
				eax1 = (int)(field_14);
				nX = nW / 2 - eax1 / 2;
				pBg->field_116 = nX;
				pBg->field_11a = nY;
			}
		}
		field_34->FUNC_100908E0( 10.0f );
	}

	nCnt = 0;
	if( g_pGame2_sb && ( pList = g_pGame2_sb->field_3de->field_4 ) )
		nCnt = pList->FUNC_100139F0( 0 ) + 1;

	sprintf( buf, "Players: %d", nCnt );

	rc.left = (int)(field_8 + 5.0f);
	rc.top = (int)(field_c + 5.0f);
	rc.bottom = (int)(field_8 + field_14);
	rc.right = (int)(field_1c + field_c);
	g_pFontSvc_sb->FUNC_1006B4E0( 0, g_pGame2_sb->field_131, rc, 0x120, 0xffbebebe, 1 );

	g_pFontSvc_sb->FUNC_1006B2B0( (int *)sz, "Players: 10000", 0 );

	eax1 = (int)(field_14 - (float)*(int *)sz + field_8);
	nX = eax1;
	eax1 = (int)(field_8 + field_14);

	rc.left = nX;
	rc.top = nY;
	rc.right = eax1;
	rc.bottom = eax2;
	g_pFontSvc_sb->FUNC_1006B4E0( 0, buf, rc, 0x120, 0xffbebebe, 1 );

	// "id" column
	eax1 = (int)(field_10 * 10.0f + field_8);
	eax2 = (int)(field_10 * 56.0f + field_8);
	{
		int nRowH = (int)(field_1c);
		int nTopAdj = nRowH - g_pFontSvc_sb->field_24 - 3;
		nY = (int)(field_c + (float)nTopAdj);
		int nBot = (int)(field_c + (float)nRowH);
		rc.left = eax1;
		rc.top = nY;
		rc.right = eax2;
		rc.bottom = nBot;
		g_pFontSvc_sb->FUNC_1006B4E0( 0, "id", rc, 0x120, 0xff95b0d0, 1 );

		// "name" column — advance by field_24 * width
		{
			int nAdv = (int)(field_24 * field_14);
			eax1 += nAdv;
			eax2 += nAdv;
			rc.left = eax1;
			rc.right = eax2;
			g_pFontSvc_sb->FUNC_1006B4E0( 0, "name", rc, 0x120, 0xff95b0d0, 1 );
		}
		// "score" column — field_2c
		{
			int nAdv = (int)(field_2c * field_14);
			eax1 += nAdv;
			eax2 += nAdv;
			rc.left = eax1;
			rc.right = eax2;
			g_pFontSvc_sb->FUNC_1006B4E0( 0, "score", rc, 0x120, 0xff95b0d0, 1 );
		}
		// "ping" column — field_28
		{
			int nAdv = (int)(field_28 * field_14);
			eax1 += nAdv;
			eax2 += nAdv;
			rc.left = eax1;
			rc.right = eax2;
			g_pFontSvc_sb->FUNC_1006B4E0( 0, "ping", rc, 0x120, 0xff95b0d0, 1 );
		}
	}
}
