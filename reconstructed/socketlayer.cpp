// Reconstructed small helpers + SocketLayer::SendTo (zone w2).
// VERIFIED byte-exact: SocketLayer-adjacent thunks 0x5A550/0x598B0, FUNC_10071920,
//   FUNC_10071B20, FUNC_1006A740, FUNC_1006F440/450, FUNC_100684B0/4D0, FUNC_10071AC0,
//   FUNC_1006DE40, FUNC_100696F0.
// SEMANTIC (not byte-verified): SocketLayer::SendTo, FUNC_10067450.

// batch: small zone-w2 functions
#include <string.h>
typedef unsigned int UINT;
typedef UINT SOCKET;
typedef unsigned short USHORT;
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef int BOOL;
typedef char *PCHAR;
#define INVALID_SOCKET ((SOCKET)(~0))
#define SOCKET_ERROR (-1)
#define AF_INET 2
#pragma pack(push,1)
struct sockaddr { unsigned short sa_family; char sa_data[14]; };
struct in_addr { unsigned long s_addr; };
struct sockaddr_in { short sin_family; unsigned short sin_port; struct in_addr sin_addr; char sin_zero[8]; };
#pragma pack(pop)
extern "C" unsigned short __stdcall htons( unsigned short );
extern "C" int __stdcall sendto( SOCKET s, const char *buf, int len, int flags, const struct sockaddr *to, int tolen );
extern "C" int __stdcall WSAGetLastError();

extern char g_sendBuffer[];
void EncodeSendPacket( char *dest, const char *src, int *len );

class SocketLayer
{
public:
	int SendTo( SOCKET s, const char *data, int length, unsigned int binaryAddress, unsigned short port );
};

int SocketLayer::SendTo( SOCKET s, const char *data, int length, unsigned int binaryAddress, unsigned short port )
{
	if( s == INVALID_SOCKET )
		return -1;

	int len;
	sockaddr_in sa;
	sa.sin_port = htons( port );
	sa.sin_addr.s_addr = binaryAddress;
	sa.sin_family = AF_INET;

	EncodeSendPacket( g_sendBuffer, data, &length );

	void *pSendTo_ = ( void * ) sendto;
	do {
		len = ( ( int ( __stdcall * )( SOCKET, const char *, int, int, const struct sockaddr *, int ) ) pSendTo_ )
			( s, g_sendBuffer, length, 0, ( const sockaddr* ) & sa, sizeof( struct sockaddr_in ) );
	} while( len == 0 );

	if( len != SOCKET_ERROR )
		return 0;

	return WSAGetLastError();
}

// --- 0x71920 / 0x71ac0 class (settings/dialog-ish singleton) ---
class CXdSub
{
public:
	char _p[0x13];
	char field_13;
	void FUNC_100908E0( float f );
};

class CXd
{
public:
	char _p0[0x20];
	CXdSub *field_20;
	int field_24;

	void FUNC_10071920();
	void FUNC_10071930();
	void FUNC_100719E0();
	void FUNC_10071AC0();
};

void CXd::FUNC_10071AC0()
{
	if( !field_24 )
		return;
	FUNC_10071930();
	if( field_20 )
		field_20->FUNC_100908E0( 10.0f );
	FUNC_100719E0();
}

// --- 0x71b20 ---
class CXe
{
public:
	char _p0[0xad];
	char field_ad[1];
	char *FUNC_10071B20();
};

// --- 0x6a740 / 0x6f440 / 0x6f450 class ---
class CXf
{
public:
	char _p0[0x4d];
	int field_4d;
	int field_51[1];

	void FUNC_1006A740( int i, int v );
	int FUNC_1006F440();
	int FUNC_1006F450( int i );
};

// --- 0x6de40 ---
class CXg
{
public:
	int field_0;
	void FUNC_1006DCD0();
	int FUNC_1006DE40( int a1, int a2, int a3 );
};

int CXg::FUNC_1006DE40( int a1, int a2, int a3 )
{
	if( field_0 && a1 == 0x202 )
	{
		FUNC_1006DCD0();
		return 1;
	}
	return 0;
}

// --- 0x696f0 ---
class CXh2
{
public:
	void FUNC_100A06F0( int a, int b );
};
extern CXh2 *pGameG2;
#pragma comment(linker,"/alternatename:_pGameG2=_g_1026ebac")

class CXh
{
public:
	char _p0[0x14e0];
	int field_14e0;
	void FUNC_100696F0();
};

void CXh::FUNC_100696F0()
{
	if( field_14e0 )
		pGameG2->FUNC_100A06F0( 2, 0 );
}

// --- 0x67450 ---
class CXi
{
public:
	char _p0[0x132];
	int field_132[0x189c];

	void FUNC_10067450();
};

void CXi::FUNC_10067450()
{
	int *d = field_132;
	int *s = ( int * )( ( char * ) this + 0x22e );
	memcpy( d, s, sizeof( field_132 ) );
}
// --- 0x684b0 / 0x684d0 (CSt fields) ---
class CXj
{
public:
	char _p0[0xc];
	char field_c;
	char _pd[0x63da - 0xd];
	int field_63da;

	void FUNC_100684B0( char v );
	char FUNC_100684D0();
};

// --- 0x5a550 / 0x598b0 noreturn-forwarder thunks ---
class CXk
{
public:
	__declspec(noreturn) void FUNC_100588C0();
};

void __stdcall FUNC_1005A550( int a, int b, CXk *p ) { p->FUNC_100588C0(); }
void __stdcall FUNC_100598B0( int a, int b, CXk *p ) { p->FUNC_100588C0(); }

void CXd::FUNC_10071920() { field_20->field_13 = 0; field_24 = 0; }
char *CXe::FUNC_10071B20() { return field_ad; }
void CXf::FUNC_1006A740( int i, int v ) { field_51[i] = v; }
int CXf::FUNC_1006F440() { return field_4d; }
int CXf::FUNC_1006F450( int i ) { return field_51[i]; }
void CXj::FUNC_100684B0( char v ) { field_c = v; field_63da = 1; }
char CXj::FUNC_100684D0() { return field_c; }
