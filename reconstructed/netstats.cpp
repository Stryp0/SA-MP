// Reconstructed CNetStats::Draw network-stats overlay (zone w2).
// SEMANTIC (compiles, not byte-verified): FUNC_10060D70.

#include <stdio.h>
#include <string.h>
#include <windows.h>
// Scratch reconstruction of CNetStats::Draw (FUNC_10060D70) - "Client Network Stats" overlay

typedef unsigned char BYTE;

extern "C" __declspec(dllimport) DWORD __stdcall GetTickCount(void);
extern "C" __declspec(dllimport) int __stdcall FUNC_PMCIMPORT(void *a, int b);  // imp 0x100e5218

char byte_10129E60[0x400];
char byte_10125E60[0x400];
char byte_10125A60[0x400];
int  dword_10118990;
int  dword_1026B3D8;
int  dword_0C17044;
void *dword_1026EB9C;

class CRakPeer
{
public:
	char _pad[0xb8];
	unsigned __int64 u64Recv;	// +0xb8
	char _pad2[0x18];
	unsigned __int64 u64Sent;	// +0xd8
};

class CNetObj
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
	virtual void _v14();
	virtual void _v15();
	virtual void _v16();
	virtual void _v17();
	virtual bool FUNC_V48();
	virtual void _v19();
	virtual void _v20();
	virtual void _v21();
	virtual void _v22();
	virtual void _v23();
	virtual void _v24();
	virtual void _v25();
	virtual void _v26();
	virtual void _v27();
	virtual void _v28();
	virtual void _v29();
	virtual void _v30();
	virtual void _v31();
	virtual void _v32();
	virtual void _v33();
	virtual void _v34();
	virtual void _v35();
	virtual void _v36();
	virtual void _v37();
	virtual void _v38();
	virtual void _v39();
	virtual void _v40();
	virtual void _v41();
	virtual void _v42();
	virtual void _v43();
	virtual void _v44();
	virtual void _v45();
	virtual void _v46();
	virtual void _v47();
	virtual void _v48();
	virtual void _v49();
	virtual void _v50();
	virtual CRakPeer *FUNC_VCC();
};

class CVehEnt
{
public:
	char _pad[0x22];
	WORD wModel;
	char _pad2[0x28];
};

class CVehSlot
{
public:
	char _pad[0x4c];
	CVehEnt *pEnt;
};

class CVehiclePool
{
public:
	int field_1134[0x7d0];
	int field_3074[0x7d0];
};

class CSubObj
{
public:
	CVehiclePool *pPool;	// +0
	void *field_4;			// font owner
	void *field_8;
	void *field_C;			// str obj
};

class CFontX
{
public:
	char _pad[0x104];
	void *field_104;		// +0x104
	int __cdecl FUNC_1003AB0();
	int __cdecl FUNC_1003AF0();
};

class CFontOwner
{
public:
	char _pad[0x26];
	CFontX *pFont;			// +0x26
};

class CGameMain2
{
public:
	CNetObj *pNetObj;		// +0
	char _pad[0x3da];
	CSubObj *pSub;			// +0x3de
};

class CGame
{
public:
	void *FUNC_100A15F0();
	void *FUNC_100A15D0();
	void *FUNC_100A15E0();
	int FUNC_100A00F0( void *a, int b, int c );
	int FUNC_100A1780( int a );
};

CGameMain2 *g_pGame2;
CGame *pGameG;

int FUNC_100B3E00();
int FUNC_10036610( void *a, char *b, int c );
int __stdcall FUNC_100C6208( int a );

class CStrObj
{
public:
	char *FUNC_1012830();
	int FUNC_100ABE70();
};

class CFontSvc
{
public:
	void FUNC_1006B200( int *pSize, char *str, int a );
	void FUNC_1006B360( int a, char *str, RECT rc, int fmt, int flag );
};

class CNetStats
{
public:
	int field_0;
	int field_4;
	DWORD field_8;
	int field_C;
	int field_10;
	void *m_pD3DDevice;

	void Draw();
};

void CNetStats::Draw()
{
	BYTE arr[0xd4];
	char szTmp[0x100];
	int pmc[0x0c];
	int nVeh, nModels, i;
	CRakPeer *pServer;
	void *p1;
	void *p2;
	void *pStr;
	char *pCur;
	CVehiclePool *pPool;
	CFontOwner *pFO;
	CFontX *pFont;
	int sz[2], sz2[2];
	int right, top, bottom;
	RECT rc;

	if( !g_pGame2 )
		return;
	if( !g_pGame2->pNetObj )
		return;
	if( !g_pGame2->pNetObj->FUNC_V48() )
		return;
	pServer = g_pGame2->pNetObj->FUNC_VCC();

	if( GetTickCount() - field_8 > 1000 )
	{
		field_8 = GetTickCount();
		field_10 = (int)( pServer->u64Sent >> 3 ) - field_4;
		field_4 = (int)( pServer->u64Sent >> 3 );
		field_C = (int)( pServer->u64Recv >> 3 ) - field_0;
		field_0 = (int)( pServer->u64Recv >> 3 );
	}

	float fDown = field_10 ? (float)(DWORD)field_10 * 0.0009765625f : 0.0f;
	float fUp = field_C ? (float)(DWORD)field_C * 0.0009765625f : 0.0f;

	pFO = (CFontOwner *)g_pGame2->pSub->field_4;
	pFont = pFO->pFont;
	pStr = pFont->field_104;

	sprintf( byte_10129E60, "Download Rate: %.2f KB/s\nUpload Rate: %.2f KB/s\n", fDown, fUp );

	memset( arr, 0, 0xd4 );
	pPool = g_pGame2->pSub->pPool;
	{
		CStrObj *pSObj = (CStrObj *)g_pGame2->pSub->field_C;
		nVeh = 0;
		nModels = 0;
		i = 0;
		pCur = pSObj ? pSObj->FUNC_1012830() : 0;
	}
	if( pPool )
	{
		p1 = pGameG->FUNC_100A15F0();
		for( int w = 0; w != 0x7d0; w++ )
		{
			if( (WORD)w < 0x7d0 )
			{
				int nFlag = pPool->field_3074[(WORD)w];
				if( nFlag )
				{
					nVeh++;
					if( ( nFlag ? (CVehSlot *)pPool->field_1134[(WORD)w] : 0 )->pEnt )
						arr[( nFlag ? (CVehSlot *)pPool->field_1134[(WORD)w] : 0 )->pEnt->wModel - 400]++;
				}
			}
		}
		i = 0;		i = 0;		i = 0;		i = 0;		i = 0;		i = 0;		i = 0;
		do
		{
			if( arr[i] )
				nModels++;
			i++;
		}
		while( i < 0xd4 );
		i = FUNC_100B3E00();
		i = pGameG->FUNC_100A00F0( pStr, dword_10118990, i );
		i = pGameG->FUNC_100A1780( (BYTE)i );
		sprintf( szTmp, "Vehicles: %u\nVehicle Models: %u\nVehicle Models Loaded: %u\nRWObjects: %u\n", nVeh, nModels, p1, i );
		strcat( byte_10129E60, szTmp );
	}
	if( pStr )
	{
		if( ((CStrObj *)pStr)->FUNC_100ABE70() )
			sprintf( byte_10125E60, "InCar Send Rate: %u\n", pFont->FUNC_1003AB0() );
		else
			sprintf( byte_10125E60, "OnFoot Send Rate: %u\n", pFont->FUNC_1003AF0() );
		strcat( byte_10129E60, byte_10125E60 );
	}
	if( pGameG )
	{
		p1 = pGameG->FUNC_100A15D0();
		p2 = pGameG->FUNC_100A15E0();
		if( p1 && p2 )
			sprintf( byte_10125E60, "Streaming Mem: %uMB Total: %uMB System: %uMB\n", (DWORD)p1 >> 20, (DWORD)p2 >> 20, dword_1026B3D8 );
		strcat( byte_10129E60, byte_10125E60 );
	}
	memset( pmc, 0, 0x28 );
	if( FUNC_100C6208( FUNC_PMCIMPORT( pmc, 0x28 ) ) )
	{
		sprintf( byte_10125E60, "Process Mem: %uKB Working Set: %uKB\n", pmc[8] >> 10, pmc[3] >> 10 );
		strcat( byte_10129E60, byte_10125E60 );
	}
	FUNC_10036610( pServer, byte_10125E60, 4 );
	strcat( byte_10129E60, byte_10125E60 );

	((CFontSvc *)dword_1026EB9C)->FUNC_1006B200( sz, byte_10129E60, 0 );
	((CFontSvc *)dword_1026EB9C)->FUNC_1006B200( sz2, "Y", 0 );

	right = dword_0C17044 - 0x96;
	rc.left = 0xa;
	rc.top = 0xa;
	rc.right = right;
	rc.bottom = sz2[1] + 0xa;
	((CFontSvc *)dword_1026EB9C)->FUNC_1006B360( 0, "Client Network Stats", rc, 0xff8888ee, 1 );
	top = sz2[1] + 0xa;
	bottom = top + sz2[1];
	pCur = byte_10129E60;
	if( *pCur )
	{
		i = 0;
		for( ;; )
		{
			char c = *pCur;
			byte_10125A60[i] = c;
			if( c == '\n' )
			{
				byte_10125A60[i] = 0;
				rc.left = 0xa;
				rc.top = top;
				rc.right = right;
				rc.bottom = bottom;
				((CFontSvc *)dword_1026EB9C)->FUNC_1006B360( 0, byte_10125A60, rc, -1, 1 );
				top += sz2[1];
				bottom += sz2[1];
				i = 0;
			}
			else
				i++;
			pCur++;
			if( !*pCur )
				break;
		}
	}
}
