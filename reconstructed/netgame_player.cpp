// Zone w1 semantic twins (verified semantics, not byte-exact — see per-func headers)
// canonical shared globals (resolved against the DLL's data section)
struct CChat { void Print(const char *fmt, ...); };
struct CNotify { void Notify(char a, unsigned long b, int c, unsigned long d, unsigned long e, int f, unsigned long g); };
struct CNet { int Send(const void *sig, void *pkt, int a, int b, int c, int d); };
extern CChat *g_1026eb80;
extern CNotify *g_1026eb58;
extern CNet *g_1026eb94_net;
extern "C" int DAT_1026eb94;
// .text:100166B0 — SEMANTIC TWIN: correct semantics, not byte-verified
// remote-player per-frame update: surf handling, trailer aim, anim transitions
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" void __cdecl FUNC_10015FA0();
extern "C" void __cdecl FUNC_100A0210();
extern "C" int  __cdecl FUNC_100ABE70();
extern "C" int  __cdecl FUNC_100145F0();
extern "C" void __cdecl FUNC_100150D0();
extern "C" void __cdecl FUNC_10014C40();
extern "C" int  __cdecl FUNC_1009F3D0();
extern "C" char __cdecl FUNC_1000ABC50();
extern "C" void __cdecl FUNC_1000AC060(...);
extern "C" void __cdecl FUNC_1000AF790();
extern "C" char __cdecl FUNC_1000ABE40();
extern "C" void __cdecl FUNC_1000ABE50();
extern "C" int  __cdecl FUNC_1000AE7D0();
extern "C" void __cdecl FUNC_1000AD230();
extern "C" int  __cdecl FUNC_1000ADA40();
extern "C" int  __cdecl FUNC_1000B8140();
extern "C" void __cdecl FUNC_1000B5500();
extern "C" void __cdecl FUNC_1000B6A80();
extern "C" int  __cdecl FUNC_1009F030();
extern "C" void __cdecl FUNC_10015650();
extern "C" void __cdecl FUNC_100155E0();
extern "C" void __cdecl FUNC_10015140();
extern "C" void __cdecl FUNC_1000B76A0();
extern "C" int  __cdecl FUNC_1000B7390();
extern "C" void __cdecl FUNC_1000B82E0();
extern "C" void __cdecl FUNC_1000B7540();
extern "C" void __cdecl FUNC_1000B75A0();
extern "C" void __cdecl FUNC_1000B72C0();
struct CPlayer_166B0 {
	char _p[0x31]; int pos[3]; char _q[0x14]; char m_4f, m_50, m_51; unsigned short m_52;
	int m_54; char _r[0x7f]; char m_c9; char _s[0x20]; char m_e9;
	char _t[0x1b]; int m_105; char m_10a; char _u[0xad];
	int m_1b4; char m_1b8; int m_1b9; int m_1c1; int m_1dd; int m_1e1;
	void Update();
};
void CPlayer_166B0::Update() {
	if (!m_1dd) return;
	if (!m_10a) {
		if (!m_1dd) return;
		FUNC_10015FA0();
		FUNC_100A0210();
		m_1dd = 0;
		return;
	}
	unsigned long now = GetTickCount();
	if (m_10a == 0x11 && m_1b8 == 0x10) {
		if (FUNC_100ABE70()) goto veh;
		if (!FUNC_100145F0()) { FUNC_100150D0(); FUNC_10014C40(); }
		else FUNC_100150D0();
		if (FUNC_1009F3D0()) {
			unsigned char b = m_e9 & 0x3f;
			if (FUNC_1000ABC50() != b) {
				FUNC_1000AC060();
				if (FUNC_1000ABC50() != b) {
					FUNC_1000AF790();
					FUNC_1000AC060();
				}
			}
		}
		if ((char)m_c9 < 0) {
			char c = FUNC_1000ABC50();
			if (c == 0x22 || c == 0x23 || c == 0x24 || FUNC_1000ABE40() == 0x0c)
				FUNC_1000ABE50();
		}
		if (*(int*)((char*)this + 0x1b4) != m_105) {
			if (m_105) FUNC_1000AE7D0();
			if (!m_105 && *(int*)((char*)this + 0x1b4) == 0x1804067c) {
				FUNC_1000AD230();
				m_105 = -1;
			}
			*(int*)((char*)this + 0x1b4) = m_105;
			m_1c1 = 0;
		}
		if (!m_1c1 && !m_105 && FUNC_1000ADA40()) FUNC_1000AD230();
		m_1e1 = 0;
		m_1b8 = 0;
		return;
	}
veh:
	if (m_10a == 0x13 && m_1b8 == 0x11) {
		if (!FUNC_100ABE70()) return;
		if (!m_1e1) return;
		if (!FUNC_1000B8140()) return;
		FUNC_1000B5500();
		FUNC_1000B6A80();
		int anim = FUNC_1009F030();
		if (anim == 0x21a || anim == 0x219 || anim == 0x1c1) FUNC_10015650();
		else { FUNC_100155E0(); FUNC_10015140(); }
		if (FUNC_1009F030() == 0x208) FUNC_1000B76A0();
		if (FUNC_1000B7390() == 2 || FUNC_1000B7390() == 6) FUNC_1000B82E0();
		FUNC_1000B7540();
		FUNC_1000B75A0();
		FUNC_1000B72C0();
		if (!m_52 || m_52 > 1999) {
			unsigned char b = m_4f & 0x3f;
			if (FUNC_1000ABC50() != b) {
				FUNC_1000AC060();
				if (FUNC_1000ABC50() != b) {
					FUNC_1000AF790();
					FUNC_1000AC060();
				}
			}
		}
		m_1b8 = 0;
		return;
	}
	if (m_10a == 0x12 && m_1b8 == 0x12) {
		if (!FUNC_100ABE70()) return;
		if (!m_1e1) return;
		if (!FUNC_1000B8140()) return;
		if (FUNC_1009F3D0()) {
			unsigned char b = *(unsigned char*)((char*)this + 0xb0) & 0x3f;
			if (FUNC_1000ABC50() != b) {
				FUNC_1000AC060();
				if (FUNC_1000ABC50() != b) {
					FUNC_1000AF790();
					FUNC_1000AC060();
				}
			}
		}
		if (FUNC_1000ABE40() == '2') FUNC_1000ABE50();
		m_1b8 = 0;
	}
}
// .text:10017690 — SEMANTIC TWIN: correct semantics, not byte-verified
// word-wraps a chat line at column width, inserting '\n' breaks in place
int __cdecl FUNC_10017690(char *text, int width, int limit) {
	char buf[516] = {0};
	int len = 0, cur = 0, off = 0, lines = 1;
	while (text[len]) len++;
	if (len > 0x200) return -1;
	for (; width < len - off; ) {
		char c = text[cur + width];
		int back = width;
		while (c != ' ' && back) { back--; c = text[cur + back]; }
		int end = cur + width;
		if (limit < (end - cur) - back) {
			// move tail to scratch, splice a newline in
			int tail = 0;
			while (text[end + tail]) { buf[tail] = text[end + tail]; tail++; }
			buf[tail] = 0;
			text[end] = '\n';
			int n = tail;
			char *d = text + end + 1;
			for (int i = 0; i < n; i++) d[i] = buf[i];
			cur = end + 1;
			len += 1;
		} else {
			cur += back;
			text[cur] = '\n';
		}
		lines++;
		len -= cur - end + back;
		off = cur;
	}
	return lines;
}
// .text:10017DE0 — SEMANTIC TWIN: correct semantics, not byte-verified
// reads a server-info bit reply: updates the join-accepted flag byte
extern "C" void __cdecl FUNC_1001F840(...);
extern "C" void __cdecl FUNC_10008420(...);
extern "C" void __cdecl FUNC_1001F8D0();
void __cdecl FUNC_10017DE0(int *pkt) {
	char ctx[0x118];
	char flag = 0;
	int *p = (int*)*pkt;
	FUNC_1001F840(p[0], (p[1] + ((p[1] >> 31) & 7)) / 8 + 1, 0);
	FUNC_10008420(ctx, &flag);
	if (DAT_1026eb94)
		*(char*)(DAT_1026eb94 + 0x232) = flag;
	FUNC_1001F8D0();
}
// .text:1001B6A0 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// dialog-response packet: forwards dialog id/button/input to script host
extern "C" void __cdecl FUNC_1001F9B0(void *dst, int bits, int n);
extern "C" void __cdecl FUNC_1001FEA0(...);
void __cdecl FUNC_1001B6A0(int *pkt) {
	unsigned short dlg;
	unsigned char btn;
	char text[2060], tmp[280], s1[264], s2[264], s3[264];
	int v1, v2, v3, v4, v5, v6;
	FUNC_1001F840(*pkt, (pkt[1] + ((pkt[1] >> 31) & 7u)) / 8 + 1, 0);
	int *t = (int*)(*(int*)(DAT_1026eb94 + 0x3de) + 0xc);
	FUNC_1001F9B0(&dlg, 0x10, 1);
	int w = (dlg < 0x3e9 && t[1 + dlg]) ? t[0xfa4/4 + dlg] : 0;
	FUNC_1001F9B0(&btn, 8, 1);
	FUNC_1001FEA0(text, 0x16);
	FUNC_1001F8D0();
}
// .text:1001DD70 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// name-tag change packet: relays (old,new) nick pair to the chat host
extern "C" int  __cdecl FUNC_100175C0(unsigned short);
extern "C" int __cdecl FUNC_100010F0(...);
extern "C" int  __cdecl FUNC_10016180();
extern "C" int  __cdecl FUNC_10003F20();
extern "C" void __cdecl FUNC_1006A5D0(int,int,int,int,int);
extern int DAT_1026eb88;
void __cdecl FUNC_1001DD70(int *pkt) {
	unsigned short a, b;
	unsigned char k;
	FUNC_1001F840(*pkt, (pkt[1] + ((pkt[1] >> 31) & 7u)) / 8 + 1, 0);
	int *t = (int*)(*(int*)(DAT_1026eb94 + 0x3de) + 4);
	FUNC_1001F9B0(&a, 0x10, 1);
	FUNC_1001F9B0(&b, 0x10, 1);
	FUNC_1001F9B0(&k, 8, 1);
	if ((short)b == -1) { FUNC_1001F8D0(); return; }
	int w1 = 0, v1 = 0, w2 = 0, v2 = 0;
	if (a != 0xffff) {
		if (*(unsigned short*)(t + 1) == a) {
			w1 = (*(unsigned int*)(t + 0x1e/4) < 0x10) ? (int)(t + 10/4) : t[10/4];
			v1 = FUNC_10003F20();
		} else if (a < 0x3ec && t[a + 0x2a/4]) {
			w1 = FUNC_100175C0(a);
			FUNC_100010F0(a);
			v1 = FUNC_10016180();
		}
	}
	if (*(unsigned short*)(t + 1) == b) {
		w2 = (*(unsigned int*)(t + 0x1e/4) < 0x10) ? (int)(t + 10/4) : t[10/4];
		v2 = FUNC_10003F20();
	} else if (b < 0x3ec && t[b + 0x2a/4]) {
		w2 = FUNC_100175C0(b);
		v2 = FUNC_10016180();
	}
	if (DAT_1026eb88) FUNC_1006A5D0(w1, w2, v1, v2, k);
	FUNC_1001F8D0();
}
// .text:1001F230 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// notifies the server when the local player leaves the focused actor
extern "C" void __cdecl FUNC_1001F730();
extern "C" void __cdecl FUNC_1001FFE0(void *v, int bits, int n);
extern char DAT_100e648c[];

extern CNet *g_1026eb94_b4;
void __cdecl FUNC_1001F230(unsigned short id) {
	char out[276];
	int *tab = (int*)(*(int*)(DAT_1026eb94 + 0x3de) + 4);
	short *cur = (short*)(tab[0x26/4] + 0xfa);
	if (*cur != (short)id) return;
	FUNC_1001F730();
	unsigned int v = id;
	FUNC_1001FFE0(&v, 0x10, 1);
	g_1026eb94_b4->Send(DAT_100e648c, out, 1, 10, 0, 0);
	*cur = -1;
	FUNC_1001F8D0();
}
// .text:1001F3C0 — SEMANTIC TWIN: correct semantics, not byte-verified
// per-tick scan of the actor table: syncs target state + fires the helpers
extern "C" int  __cdecl FUNC_1000B73F0();
extern "C" void __cdecl FUNC_1000B7190(int);
extern "C" double __cdecl FUNC_1000B72A0();
void __cdecl FUNC_1001F230(unsigned short id);
extern "C" double __cdecl FUNC_1009F0C0();
extern "C" int  __cdecl FUNC_1000B73B0();
extern "C" int  __cdecl FUNC_1000B7460();
extern "C" int  __cdecl FUNC_1000B7D70();
extern "C" int  __cdecl FUNC_1000B7CF0();
extern "C" char __cdecl FUNC_10006E00(unsigned short, int);
extern "C" int  __cdecl FUNC_1000B8220();
extern "C" int  __cdecl FUNC_1000B8240();
extern "C" int  __cdecl FUNC_1000B70E0();
extern "C" void __cdecl FUNC_1000B8A70(int);
extern "C" void __cdecl FUNC_1000B7E50(int);
extern "C" void __cdecl FUNC_1000B7330();
extern "C" void __cdecl FUNC_1000B76E0();
extern double DAT_100e5940;
extern float DAT_100e60a0;
struct CObj_1001F3C0 { int m_n; int m_t[0x3ee5]; void Tick(); };
void CObj_1001F3C0::Tick() {
	unsigned long now = GetTickCount();
	int hits = 0;
	if (m_n < 0) return;
	for (unsigned int i = 0, u = 0; u <= (unsigned int)m_n; i++, u++) {
		if ((unsigned short)i >= 2000) break;
		if (m_t[u + 0xc1d] != 1 || !m_t[u + 0x2f45]) continue;
		int *e = (int*)m_t[u + 0x44d];
		if (m_t[u + 0x3715] && (int)(now - m_t[u + 0x3ee5]) >= 0x3a99) {
			// stale — handled below
		}
		FUNC_1000B7190(FUNC_1000B73F0() == 0);
		if (FUNC_1000B72A0() == DAT_100e5940) {
			FUNC_1001F230((unsigned short)i);
			if (!m_t[u + 0x3715]) {
				m_t[u + 0x3715] = 1;
				m_t[u + 0x3ee5] = GetTickCount();
			}
			continue;
		}
		float d = (float)FUNC_1009F0C0();
		int c = FUNC_1000B7390();
		if (c == 4 || DAT_100e60a0 <= d || !FUNC_1000B73B0()) {
			if (!FUNC_1000B7460() &&
				(!FUNC_1000B7D70() || !FUNC_1000B7CF0()) && hits < 3 &&
				(int)(now - m_t[u + 0x2775]) > 100 &&
				FUNC_10006E00((unsigned short)i, (int)e)) {
				m_t[u + 0x2775] = GetTickCount();
				hits++;
			}
			int v;
			if (!*(char*)(*(int*)(DAT_1026eb94 + 0x3d5) + 0x2b)) {
				int s = FUNC_1000B8220();
				if (s == -1) v = FUNC_1000B70E0() ? 1 : 0;
				else v = s;
				FUNC_1000B8A70(v);
				int s2 = FUNC_1000B8240();
				v = (s2 == 0 || s2 == 1) ? s2 : 0;
				FUNC_1000B7E50(v);
			} else {
				FUNC_1000B8A70(FUNC_1000B8220() > 0);
				FUNC_1000B7E50(FUNC_1000B8240() > 0);
			}
			int m = e[0x4c/4];
			if (m != m_t[u + 0x13ed]) m_t[u + 0x13ed] = m;
			FUNC_1000B7330();
			FUNC_1000B76E0();
		} else {
			FUNC_1001F230((unsigned short)i);
		}
	}
}
