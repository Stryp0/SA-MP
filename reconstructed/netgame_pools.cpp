// reconstructed from samp.dll 0.3.7-R5 — zone w1
// every function below compiled under VS .NET 2003 (/Ox /Og /Ob1 /Oi /Ot /Oy /MT /Zp1 /EHsc /Gy)
// and verified byte-exact against the DLL range shown (OK_LIGHT, relocs masked).
// Class layouts are minimal "views": only the members the function touches are modelled.

// .text:100010D0 — bounds-checked word-indexed lookup into the +0x1f8a pointer table (max index 0x3ec)
struct CView_000010D0 { char _p[0x1f8a]; void* m_t[1]; void* Get(unsigned short w); };
void* CView_000010D0::Get(unsigned short w) {
	if (w <= 0x3ec) {
		void* p = m_t[w];
		if (p) return p;
	}
	return 0;
}


// .text:100015E0 — iterates the 0x800-entry dword table at +0xe800; calls Proc(i) on used slots
struct CView_000015E0 { char _p[0xe800]; int m_t[0x800]; void Proc(int i); void Update(); };
void CView_000015E0::Update() {
	for (int i = 0; (unsigned short)i < 0x800; i++)
		if (m_t[i]) Proc(i);
}


// .text:10001610 — bounds-checked pool slot getter: returns entry when its slot state is set (players at +4, state at +0xfa4)
struct CView_00001610 { char _p0[4]; void* m_players[0x3e8]; int m_state[0x3e8]; void* Get(unsigned short w); };
void* CView_00001610::Get(unsigned short w) {
	if (w >= 0x3e8) return 0;
	if (m_state[w]) return m_players[w];
	return 0;
}


// .text:10012830 — counts non-null entries in the 1000-entry table at +4
struct CView_00012830 { char _p[4]; void* m_t[1000]; int CountUsed(); };
int CView_00012830::CountUsed() {
	int n = 0;
	void** p = m_t;
	int i = 1000;
	do {
		if (*p) n++;
		p++;
	} while (--i);
	return n;
}


// .text:1000BFC0 — linear search by id over a 6-element table (stride 0x230) at +0x1457; -1 on miss
struct E_0000BFC0 { long m_id; char _rest[0x230 - 4]; };
struct CView_0000BFC0 { char _p[0x1457]; E_0000BFC0 m_e[6]; int Find(long id); };
int CView_0000BFC0::Find(long id) {
	for (int i = 0; i != 6; i++)
		if (m_e[i].m_id == id) return i;
	return -1;
}


// .text:1000C8D0 — bounds-checked element getter on a ptr-array + count pair
struct CView_0000C8D0 { void** m_arr; unsigned long m_count; void* Get(unsigned long i); };
void* CView_0000C8D0::Get(unsigned long i) {
	if (i >= m_count) return 0;
	return m_arr[i];
}


// .text:1000C900 — bounds-checked element getter on a ptr-array + count pair
struct CView_0000C900 { void** m_arr; unsigned long m_count; void* Get(unsigned long i); };
void* CView_0000C900::Get(unsigned long i) {
	if (i >= m_count) return 0;
	return m_arr[i];
}


// .text:1000D450 — clears element i, calls Cleanup(), returns success
struct CView_0000D450 { void** m_arr; unsigned long m_count; void Cleanup(); bool Remove(unsigned long i); };
bool CView_0000D450::Remove(unsigned long i) {
	if (i >= m_count) return false;
	m_arr[i] = 0;
	Cleanup();
	return true;
}


// .text:10002DC0 — word store into the +0x8e34 word table
struct CView_00002DC0 { char _p[0x8e34]; unsigned short m_w[1]; void Set(unsigned short i, unsigned short v); };
void CView_00002DC0::Set(unsigned short i, unsigned short v) { m_w[i] = v; }

