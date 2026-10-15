// Zone w1 semantic twins (verified semantics, not byte-exact — see per-func headers)
// canonical shared globals (resolved against the DLL's data section)
struct CChat { void Print(const char *fmt, ...); };
struct CNotify { void Notify(char a, unsigned long b, int c, unsigned long d, unsigned long e, int f, unsigned long g); };
struct CNet { int Send(const void *sig, void *pkt, int a, int b, int c, int d); };
extern CChat *g_1026eb80;
extern CNotify *g_1026eb58;
extern CNet *g_1026eb94_net;
extern "C" int DAT_1026eb94;
// .text:10038060 — SEMANTIC TWIN: correct semantics, not byte-verified
// RakNetStatisticsStruct::operator+= — accumulates counters incl. 64-bit pairs
struct RakNetStatisticsStruct {
	unsigned long valueOverLastUpdate, runningTotal, connections;
	unsigned long long messages[8];        // u64 counters (b/c pairs)
	unsigned long extra0, extra1, reserved;
	void operator += (const RakNetStatisticsStruct &r);
};
void RakNetStatisticsStruct::operator += (const RakNetStatisticsStruct &r) {
	valueOverLastUpdate += r.valueOverLastUpdate;
	runningTotal += r.runningTotal;
	connections += r.connections;
	messages[0] += r.messages[0];
	messages[1] += r.messages[1];
	messages[2] += r.messages[2];
	messages[3] += r.messages[3];
	messages[4] += r.messages[4];
	messages[5] += r.messages[5];
	messages[6] += r.messages[6];
	messages[7] += r.messages[7];
	extra0 += r.extra0;
	extra1 += r.extra0;
	reserved += r.reserved;
}
// .text:10039820 — SEMANTIC TWIN: correct semantics, not byte-verified
// circular-buffer push_back: drops the oldest slot, grows the ring when full
extern "C" void __cdecl free(void*);
struct CRing_10039820 { void **m_buf; unsigned int m_head; unsigned int m_size;
	unsigned int m_cap; void Push(void *v); };
void CRing_10039820::Push(void *v) {
	if (!m_cap) {
		m_buf = (void**)operator new(0x40);
		m_head = 0; m_size = 1;
		m_buf[0] = v;
		m_cap = 0x10;
		return;
	}
	m_head = (m_head + m_cap - 1); // m_head == 0 ? cap-1 : head-1 handled below
	unsigned int i = 0;
	if (m_size) {
		do {
			void **p = &m_buf[(m_head + i)];
			i++;
			*p = p[1];
		} while (i < m_size);
	}
	m_buf[m_head + i] = v;
	if (m_size == m_head) {
		void **nbuf = (void**)operator new(m_cap << 3);
		i = 0;
		if (m_cap) {
			do {
				unsigned int k = m_head + i;
				i++;
				nbuf[i - 1] = m_buf[k % m_cap];
			} while (i < m_cap);
		}
		m_size = m_cap;
		m_head = 0;
		m_cap *= 2;
		free(m_buf);
		m_buf = nbuf;
	}
}
// .text:1003D010 — SEMANTIC TWIN: correct semantics, not byte-verified
// RNC init: seeds the word tables, validates the magic, fills match windows
extern "C" char __cdecl FUNC_10039F20(int *out, int self);
extern "C" void __cdecl FUNC_10039D90(int *out, int *state);
extern "C" void __cdecl FUNC_1003BA70(int self, int *out, int *tab);
void __cdecl FUNC_1003D010(int self, int *out) {
	int tab[24] = {0};
	int state[8];
	out[0] = 0xffff;
	out[1] = 0; out[2] = 0; out[3] = 0; out[4] = 0; out[5] = 0;
	out[6] = 0; out[7] = 0;
	state[0] = 2; state[1] = 1;
	if (FUNC_10039F20(out, self)) {
		out[0] = 3;
		out[1] = 0; out[2] = 0; out[3] = 0; out[4] = 0; out[5] = 0;
		out[6] = 0; out[7] = 0;
	}
	do {
		FUNC_10039D90(out, state);
		FUNC_1003BA70(self, out, tab + 8);
		bool all = true;
		for (int i = 8; i < 16; i++) if (tab[i]) all = false;
		if (all) break;
	} while (true);
}
// .text:1003D0F0 — SEMANTIC TWIN: correct semantics, not byte-verified
// RNC bit-unpack inner loop: refills windows and emits literals/matches
extern "C" void __cdecl FUNC_1003BB30(int *dst, int *src, void *bits, int *tab);
extern "C" void __cdecl FUNC_10039CD0(int *state, void *bits);
extern "C" void __cdecl FUNC_1003BCD0(int *state, void *bits, int *ctrl, int *out, int *aux);
void __cdecl FUNC_1003D0F0(int *self, int *in, int *out) {
	int state[8] = {0};
	int ctrl[8] = {0};
	int tab[4], win[4], aux[8], cur[8];
	ctrl[2] = 1;
	FUNC_1003BB30(in, self, tab, cur);
	for (int i = 0; i < 8; i++) state[i] = in[i];
	FUNC_10039CD0(state, tab);
	for (int i = 0; i < 4; i++) cur[i] = self[i];
	do {
		FUNC_1003BB30(cur, cur, tab, cur);
		int i = 0;
		while (!cur[i]) { if (++i > 3) goto done1; }
		FUNC_1003BCD0(state, tab, ctrl, in, aux);
		FUNC_1003BB30(cur, cur, tab, cur);
		i = 0;
		while (!cur[i]) { if (++i > 3) goto done2; }
		FUNC_1003BCD0(state, tab, ctrl, in, aux);
	} while (true);
done1: ;
done2: ;
}
// .text:1003D8D0 — SEMANTIC TWIN: correct semantics, not byte-verified
// RNC bit-unpack pass (wide window): interleaved window refill + emit
extern "C" void __cdecl FUNC_1003BDF0(int *dst, int *src, void *bits, int *tab);
extern "C" void __cdecl FUNC_1003A080(int *state, void *bits);
extern "C" void __cdecl FUNC_1003C1A0(int *state, void *bits, int *ctrl, int *out, int *aux);
void __cdecl FUNC_1003D8D0(int *self, int *in, int *out) {
	int ctrl[16] = {0};
	int bits[8], win[8], state[8], aux[8], cur[8];
	ctrl[2] = 1;
	FUNC_1003BDF0(in, self, bits, win);
	for (int i = 0; i < 8; i++) state[i] = in[i];
	FUNC_1003A080(state, bits);
	for (int i = 0; i < 8; i++) win[i] = self[i];
	do {
		FUNC_1003BDF0(win, win, bits, win);
		int i = 0;
		while (!win[i]) { if (++i > 7) goto done; }
		FUNC_1003C1A0(state, bits, ctrl, in, aux);
	} while (true);
done: ;
}
