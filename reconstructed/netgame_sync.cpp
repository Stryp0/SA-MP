// Zone w1 semantic twins (verified semantics, not byte-exact — see per-func headers)
// canonical shared globals (resolved against the DLL's data section)
struct CChat { void Print(const char *fmt, ...); };
struct CNotify { void Notify(char a, unsigned long b, int c, unsigned long d, unsigned long e, int f, unsigned long g); };
struct CNet { int Send(const void *sig, void *pkt, int a, int b, int c, int d); };
extern CChat *g_1026eb80;
extern CNotify *g_1026eb58;
extern CNet *g_1026eb94_net;
extern "C" int DAT_1026eb94;
// .text:100249A0 — SEMANTIC TWIN: correct semantics, not byte-verified
// per-packet opcode dispatch inside the RNC handler
extern "C" void __cdecl FUNC_10024910(int a, int pkt);
extern "C" void __cdecl FUNC_100240B0(int a, int b, unsigned short c, int d);
extern "C" void __cdecl FUNC_10024940(int a, int pkt);
extern "C" void __cdecl FUNC_10023610(int a, int pkt);
extern "C" void __cdecl FUNC_10024260(int a, int pkt);
extern "C" void __cdecl FUNC_100244B0(int a, int pkt);
extern "C" void __cdecl FUNC_100245C0(int a, int pkt);
extern "C" char __cdecl FUNC_10024750(int a, int pkt, int extra);
int __cdecl FUNC_100249A0(int a1, int pkt) {
	char op = **(char**)(pkt + 0x10);
	switch (op) {
	case 0x1e: FUNC_10024910(a1, pkt); return 1;
	case 0x20:
	case 0x21:
		FUNC_100240B0(a1, *(int*)(pkt + 2), *(unsigned short*)(pkt + 6),
			(op != 0x21) + '=');
		return 1;
	case 0x22: FUNC_10024940(a1, pkt); return 1;
	case 0x39: FUNC_10023610(a1, pkt); return 0;
	case 0x3a: FUNC_10024260(a1, pkt); return 0;
	case 0x3b: FUNC_100244B0(a1, pkt); return 0;
	case 0x3c: FUNC_100245C0(a1, pkt); break;
	case 0x3d:
	case 0x3e:
		if (FUNC_10024750(a1, pkt, ((int)**(char**)(pkt + 0x10) >> 8) | (op << 24))) {
			**(char**)(pkt + 0x10) = (**(char**)(pkt + 0x10) == '=') + '*';
			return 1;
		}
	}
	return 0;
}
// .text:10029EA0 — SEMANTIC TWIN: correct semantics, not byte-verified
// rebuilds the priority queues from the object links each sync round
extern "C" void __cdecl FUNC_10027650(int);
extern "C" void __cdecl FUNC_10029CE0(int,int*);
struct CObj_10029EA0 { char _p[0x18]; int m_18;
	void Rebuild(int *q, int arg3, int arg4, int *arg5, int arg6); };
void CObj_10029EA0::Rebuild(int *q, int arg3, int arg4, int *arg5, int arg6) {
	unsigned int n = q[1];
	if (!n) {
		FUNC_10027650(arg3);
		FUNC_10029CE0(arg4, arg5);
		return;
	}
	char result = (char)(int)arg5;
	int *pi = (int*)*q;
	int *dst = (int*)(arg6 + 4);
	for (unsigned int i = 0; i < n; i++) {
		int e = *pi;
		char *l = *(char**)(*arg5 + e * 4);
		if (!*l && e != -1) {
			switch (dst[1]) {
			case 0: {
				int t = *(int*)(*(int*)(m_18) + 0x20 + e * 0x24);
				if (!t) {
					result = (*(int*)(l + 1) - *(int*)(*dst + 1)) == 0;
				} else if (t - 1 == 0) {
					unsigned char *pb = *(unsigned char**)(*dst + 5);
					result = pb[0] == 0;
				}
				break;
			}
			default:
				break;
			}
		}
		pi++;
	}
}
// .text:1002E250 — SEMANTIC TWIN: correct semantics, not byte-verified
// RakNet packet-class dispatch: switch on the leading opcode byte
extern "C" void __cdecl FUNC_1002E1B0(int,int);
extern "C" void __cdecl FUNC_1002D8E0(int);
extern "C" void __cdecl FUNC_1002DE90(int,int);
int __stdcall FUNC_1002E250(int self, int pkt) {
	char op;
	int *d;
	op = **(char**)(pkt + 0x10);
	switch (op) {
	case 0x21:
		FUNC_1002D8E0(pkt);
		return 0;
	case 0x24:
		FUNC_1002DE90(pkt, 1);
		return 0;
	case 0x50:
		if (*(int*)(pkt + 8) > 0xd && *(char*)(*(int*)(pkt + 0x10) + 0xd) == 0x30)
			FUNC_1002DE90(pkt, 0);
		return 0;
	default:
		d = (int*)(pkt + 2);
		FUNC_1002E1B0(*d, *(short*)(d + 1));
		return 1;
	}
	return 1;
}
// .text:1002FAD0 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// tiny wrapper: enters the guard, runs the body, unwinds — std cleanup thunk
extern "C" void __cdecl FUNC_1002F640();
extern "C" void __cdecl FUNC_1002F4A0();
void __cdecl FUNC_1002FAD0() {
	FUNC_1002F640();
	FUNC_1002F4A0();
}
// .text:10030FE0 — SEMANTIC TWIN: correct semantics, not byte-verified
// RakNet packet-class dispatch: routes connection sub-packets by opcode
extern "C" void __cdecl FUNC_10030830(int,int);
extern "C" void __cdecl FUNC_10030BC0(int,int);
extern "C" void __cdecl FUNC_10030F20(int,int);
extern "C" void __cdecl FUNC_100302D0(int,int);
extern "C" void __cdecl FUNC_1002FF70(int,int);
int __stdcall FUNC_10030FE0(int self, int pkt) {
	char op = **(char**)(pkt + 0x10);
	int *d;
	switch (op) {
	case 0x20: FUNC_10030830(pkt, *(int*)(pkt + 4)); return 0;
	case 0x21: FUNC_10030BC0(pkt, *(int*)(pkt + 4)); return 0;
	case 0x22: FUNC_10030F20(pkt, *(int*)(pkt + 4)); return 0;
	case 0x26: FUNC_1002FF70(pkt, *(int*)(pkt + 4)); return 0;
	default:
		d = (int*)(pkt + 2);
		FUNC_100302D0(*d, *(short*)(d + 1));
		return 1;
	}
	return 1;
}
// .text:10031690 — SEMANTIC TWIN: correct semantics, not byte-verified
// claims a client slot bitmask for a channel; returns channel id or -1
extern "C" int  __cdecl FUNC_100311B0(int);
extern "C" char __cdecl FUNC_100336E0(void*);
extern "C" void __cdecl FUNC_10031240(int a, unsigned int bits, unsigned short hi);
struct CObj_10031690 { char _p[0x10]; unsigned int *m_10; unsigned int m_14;
	int Claim(int arg, unsigned short tag, int chan); };
int CObj_10031690::Claim(int arg, unsigned short tag, int chan) {
	int id = -1;
	if (chan == 0 || (id = FUNC_100311B0(chan)) != -1) {
		unsigned int i = 0;
		if (m_14) {
			do {
				if (FUNC_100336E0(&arg)) {
					unsigned int *slot = (unsigned int*)((char*)m_10 + 6 + i * 10);
					if (chan == 0) { *slot = 0xffff; return id; }
					*slot |= 1u << (id & 0x1f);
					return id;
				}
				i++;
			} while (i < m_14);
		}
		unsigned int bits;
		if (chan == 0) bits = 0xffff;
		else bits = 1u << (id & 0x1f);
		FUNC_10031240(arg, (bits << 16) | tag, (unsigned short)(bits >> 16));
	}
	return id;
}
// .text:10032860 — SEMANTIC TWIN: correct semantics, not byte-verified
// RakNet packet-class dispatch: un-wrapper aware opcode switch (0x28 prefix)
extern "C" void __cdecl FUNC_10031CF0(int,int);
extern "C" void __cdecl FUNC_100327F0(int,int);
extern "C" void __cdecl FUNC_10031F10(int,int);
int __stdcall FUNC_10032860(int self, int pkt) {
	char *p = *(char**)(pkt + 0x10);
	char op;
	int *d;
	if (*(int*)(pkt + 8) > 5 && p[0] == 0x28) op = p[5];
	else op = p[0];
	switch (op) {
	case 0x20: FUNC_10031CF0(pkt, *(int*)(pkt + 4)); return 0;
	case 0x21: FUNC_10031F10(pkt, *(int*)(pkt + 4)); return 0;
	default:
		d = (int*)(pkt + 2);
		FUNC_100327F0(*d, *(short*)(d + 1));
		return 0;
	}
	return 0;
}
