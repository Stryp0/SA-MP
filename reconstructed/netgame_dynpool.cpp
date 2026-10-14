// reconstructed from samp.dll 0.3.7-R5 — zone w1
// the "dynamic pool" family: void **items + ulong count pairs with
// SetSize/GetAt/RemoveAt/Compact/Find/SetAt — four near-identical copies exist
// in the binary (four different pool owner classes share this shape).
// verified byte-exact (OK_LIGHT) unless a SEMANTIC TWIN comment says otherwise.

// .text:1000C970 — resizes the item array to n slots (frees at 0, reallocs+zero-fills on grow) — first copy
extern "C" void __cdecl free(void*);
extern "C" void* __cdecl realloc(void*, unsigned int);
struct CDynPool_1000C970 {
	void **m_ppItems; unsigned long m_nItems;
	char SetSize(unsigned long n);
};
char CDynPool_1000C970::SetSize(unsigned long n) {
	if (n == 0) {
		if (m_ppItems) { free(m_ppItems); m_ppItems = 0; }
		m_nItems = 0;
		return 1;
	}
	void *p = realloc(m_ppItems, n * 4);
	if (!p) return 0;
	m_ppItems = (void**)p;
	unsigned long i = m_nItems;
	if (i < n) {
		do { m_ppItems[i] = 0; i++; } while (i != n);
	}
	m_nItems = n;
	return 1;
}


// .text:1000C9E0 — same SetSize as 1000C970 — second copy
extern "C" void __cdecl free(void*);
extern "C" void* __cdecl realloc(void*, unsigned int);
struct CDynPool_1000C9E0 {
	void **m_ppItems; unsigned long m_nItems;
	char SetSize(unsigned long n);
};
char CDynPool_1000C9E0::SetSize(unsigned long n) {
	if (n == 0) {
		if (m_ppItems) { free(m_ppItems); m_ppItems = 0; }
		m_nItems = 0;
		return 1;
	}
	void *p = realloc(m_ppItems, n * 4);
	if (!p) return 0;
	m_ppItems = (void**)p;
	unsigned long i = m_nItems;
	if (i < n) {
		do { m_ppItems[i] = 0; i++; } while (i != n);
	}
	m_nItems = n;
	return 1;
}


// .text:1000CA50 — same SetSize as 1000C970 — third copy
extern "C" void __cdecl free(void*);
extern "C" void* __cdecl realloc(void*, unsigned int);
struct CDynPool_1000CA50 {
	void **m_ppItems; unsigned long m_nItems;
	char SetSize(unsigned long n);
};
char CDynPool_1000CA50::SetSize(unsigned long n) {
	if (n == 0) {
		if (m_ppItems) { free(m_ppItems); m_ppItems = 0; }
		m_nItems = 0;
		return 1;
	}
	void *p = realloc(m_ppItems, n * 4);
	if (!p) return 0;
	m_ppItems = (void**)p;
	unsigned long i = m_nItems;
	if (i < n) {
		do { m_ppItems[i] = 0; i++; } while (i != n);
	}
	m_nItems = n;
	return 1;
}


// .text:1000CAC0 — same SetSize as 1000C970 — fourth copy
extern "C" void __cdecl free(void*);
extern "C" void* __cdecl realloc(void*, unsigned int);
struct CDynPool_1000CAC0 {
	void **m_ppItems; unsigned long m_nItems;
	char SetSize(unsigned long n);
};
char CDynPool_1000CAC0::SetSize(unsigned long n) {
	if (n == 0) {
		if (m_ppItems) { free(m_ppItems); m_ppItems = 0; }
		m_nItems = 0;
		return 1;
	}
	void *p = realloc(m_ppItems, n * 4);
	if (!p) return 0;
	m_ppItems = (void**)p;
	unsigned long i = m_nItems;
	if (i < n) {
		do { m_ppItems[i] = 0; i++; } while (i != n);
	}
	m_nItems = n;
	return 1;
}


// .text:1000CB30 — shrinks the item array to one past the last used slot
// .text:1000CB30 — shrinks the pool's capacity to one past the last used slot
// SEMANTIC TWIN — correct semantics, not byte-verified (register-allocation differences)
struct CDynPool_1000CB30 {
	void **m_ppItems; unsigned long m_nItems;
	char SetSize(unsigned long n);
	void Compact();
};
void CDynPool_1000CB30::Compact() {
	int last = -1;
	unsigned long n = m_nItems;
	if (n) {
		void **p = m_ppItems;
		for (int i = 0; i != (int)n; i++, p++)
			if (*p) last = i;
	}
	if (last == -1) {
		SetSize(0);
	} else {
		SetSize(last + 1);
	}
}


// .text:1000CB70 — returns 1 if an item has field+0x46==id and flag +4 set — first copy
struct CDynPool_1000CB70 {
	void **m_ppItems; unsigned long m_nItems;
	char FindById46(int id);
};
char CDynPool_1000CB70::FindById46(int id) {
	unsigned long n = m_nItems, i = 0;
	if (n) {
		do {
			int p;
			if (i < n && (p = (int)m_ppItems[i]) != 0 && *(int*)(p + 0x46) == id && *(char*)(p + 4) != 0)
				return 1;
			i++;
		} while (i != n);
	}
	return 0;
}


// .text:1000CBB0 — returns 1 if an item has field+0x4a==id and flag +5 set — second copy
struct CDynPool_1000CBB0 {
	void **m_ppItems; unsigned long m_nItems;
	char FindById4A(int id);
};
char CDynPool_1000CBB0::FindById4A(int id) {
	unsigned long n = m_nItems, i = 0;
	if (n) {
		do {
			int p;
			if (i < n && (p = (int)m_ppItems[i]) != 0 && *(int*)(p + 0x4a) == id && *(char*)(p + 5) != 0)
				return 1;
			i++;
		} while (i != n);
	}
	return 0;
}


// .text:1000CC70 — finds the index of the item whose id (field+0x46 or +0x4a by mode) matches
// .text:1000CC70 — SEMANTIC TWIN: correct semantics, not byte-verified (register-allocation differs)
struct CDynPool_1000CC70 {
	void **m_ppItems; unsigned long m_nItems;
	long FindById(char mode, int id);
};
long CDynPool_1000CC70::FindById(char mode, int id) {
	unsigned long n = m_nItems, i = 0;
	if (n) {
		do {
			if (i < n) {
				void *p = m_ppItems[i];
				if (p) {
					long v;
					if (mode == 1) {
						v = *(int*)((char*)p + 0x46);
					} else if (mode == 2) {
						v = *(int*)((char*)p + 0x4a);
					} else {
						goto next;
					}
					if (v == id) return i;
				}
			}
next:		i++;
		} while (i != n);
	}
	return -1;
}


// .text:1000CED0 — returns 1 immediately when +0x21f disabled; else scans for field+0x46/+0x4a==id
struct CPool2_1000CED0 {
	void **m_ppItems; unsigned long m_nItems;
	char _p[0x217]; char m_21f;
	char HasId(int id);
};
char CPool2_1000CED0::HasId(int id) {
	if (!m_21f) return 1;
	int n = m_nItems; unsigned long i = 0;
	if (n > 0) {
		do {
			if (i < n && m_ppItems[i] &&
				(*(int*)((char*)m_ppItems[i] + 0x46) == id || *(int*)((char*)m_ppItems[i] + 0x4a) == id))
				return 1;
			i++;
		} while ((int)i < n);
	}
	return 0;
}


// .text:1000CDE0 — when +0x21f set, scans first n slots for id with paired flag bytes +2/+3
struct CPool2_1000CDE0 {
	void **m_ppItems; unsigned long m_nItems;
	char _p[0x217]; char m_21f;
	char Check(int n, int id);
};
char CPool2_1000CDE0::Check(int n, int id) {
	if (!m_21f) return 0;
	int i = 0;
	if (n > 0) {
		do {
			if (i < m_nItems && m_ppItems[i]) {
				int p = (int)m_ppItems[i];
				if ((*(int*)(p + 0x46) == id && *(char*)(p + 2) != 0) ||
					(*(int*)(p + 0x4a) == id && *(char*)(p + 3) != 0)) return 1;
			}
			i++;
		} while (i < n);
	}
	return 0;
}


// .text:1000D480 — SetAt: grows via SetSize when i>=count, then stores
struct CDynPool_1000D480 {
	void **m_ppItems; unsigned long m_nItems;
	char SetSize(unsigned long n);
	char SetAt(unsigned long i, void *p);
};
char CDynPool_1000D480::SetAt(unsigned long i, void *p) {
	if (i >= m_nItems && !SetSize(i + 1)) return 0;
	m_ppItems[i] = p;
	return 1;
}


// .text:1000D4C0 — sets +0x21b; when it equals +4 arms +0x21f, runs FUNC_1000D080 and defaults +0x213 to 2
struct CPool2_1000D4C0 {
	char _p0[4]; int m_4;
	char _p1[0x20b]; int m_213;
	char _p2[4]; int m_21b;
	char m_21f;
	void FUNC_1000D080();
	void SetState(int v);
};
void CPool2_1000D4C0::SetState(int v) {
	m_21b = v;
	if (m_4 == v) {
		m_21f = 1;
		FUNC_1000D080();
		if (!m_213) m_213 = 2;
	}
}


// .text:1000DB30 — frees item i and removes it; -1 when out of range or empty slot
extern "C" void __cdecl free(void*);
struct CDynPool_1000DB30 {
	void **m_ppItems; unsigned long m_nItems;
	char RemoveAt(unsigned long i);
	long FreeAt(unsigned long i);
};
long CDynPool_1000DB30::FreeAt(unsigned long i) {
	if (i < m_nItems) {
		void *p = m_ppItems[i];
		if (p) { free(p); RemoveAt(i); return i; }
	}
	return -1;
}


// .text:1000C540 — parses '0x'-prefixed 8-digit hex string to ulong (thiscall-style ret 4)
extern "C" char* __cdecl strncpy(char*, const char*, unsigned int);
extern "C" unsigned long __cdecl strtoul(const char*, char**, int);
unsigned long __stdcall FUNC_1000C540(const char *s) {
	char c = s[0];
	if (c == '0' && s[1] == 'x') {
		char buf[12];
		strncpy(buf, s + 2, 8);
		return strtoul(buf, 0, 0x10);
	}
	return 0;
}


// .text:1000A2C0 — clears all 100 slots at +0x23d through FUNC_1000B2310 then zeroes them
struct CObj_1000A2C0 { char _p[0x23d]; int m_slots[100]; void Clear(); };
extern void __cdecl FUNC_1000B2310(void *w, int p);
extern int g_100e5958;
void CObj_1000A2C0::Clear() {
	unsigned char i = 0;
	int *p = m_slots;
	do {
		if (*p && i < 100) {
			FUNC_1000B2310(&g_100e5958, *p);
			*p = 0;
		}
		i++;
		p++;
	} while (i < 100);
}


// .text:1000A300 — replaces slot i at +0x23d: frees old, stores result of global-object Create call
// .text:1000A300 — SEMANTIC TWIN: correct semantics, not byte-verified (arg-load form differs)
struct CObj_1000A0D90 { int Create(char a6, int a3, int a4, int a5, int a7, int a8); };
extern CObj_1000A0D90 *g_pObj_1026ebac;
struct CObj_1000A300 { char _p[0x23d]; int m_slots[100];
	void Set(unsigned char i, int a3, int a4, int a5, int a6, int a7, int a8); };
extern void __cdecl FUNC_1000B2310(void *w, int p);
extern int g_100e5958;
void CObj_1000A300::Set(unsigned char i, int a3, int a4, int a5, int a6, int a7, int a8) {
	if (i < 100) {
		if (m_slots[i]) {
			FUNC_1000B2310(&g_100e5958, m_slots[i]);
			m_slots[i] = 0;
		}
		m_slots[i] = g_pObj_1026ebac->Create(a6 & 0xff, a3, a4, a5, a7, a8);
	}
}


// .text:1000DAE0 — calloc-copies a 0x5e-byte record and inserts at index i when its +0xc field is in 0..0x4e20
extern "C" void* __cdecl calloc(unsigned int, unsigned int);
struct Rec94_1000DAE0 { char _0[0xc]; int f_0c; char _r[0x4e]; };
struct CDynPool_1000DAE0 {
	void **m_ppItems; unsigned long m_nItems;
	char SetAt(unsigned long i, void *p);
	long Add(long i, Rec94_1000DAE0 *r);
};
long CDynPool_1000DAE0::Add(long i, Rec94_1000DAE0 *r) {
	Rec94_1000DAE0 *p = (Rec94_1000DAE0*)calloc(1, 0x5e);
	if (r->f_0c >= 0 && r->f_0c <= 0x4e20) {
		*p = *r;
		SetAt(i, p);
		return i;
	}
	return -1;
}

