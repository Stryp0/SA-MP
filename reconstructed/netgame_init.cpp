// Zone w1 semantic twins (verified semantics, not byte-exact — see per-func headers)
// canonical shared globals (resolved against the DLL's data section)
struct CChat { void Print(const char *fmt, ...); };
struct CNotify { void Notify(char a, unsigned long b, int c, unsigned long d, unsigned long e, int f, unsigned long g); };
struct CNet { int Send(const void *sig, void *pkt, int a, int b, int c, int d); };
extern CChat *g_1026eb80;
extern CNotify *g_1026eb58;
extern CNet *g_1026eb94_net;
extern "C" int DAT_1026eb94;
// .text:10001350 — SEMANTIC TWIN: correct semantics, not byte-verified
// nametag render pass: walks the 0x800-slot table and draws distant tags
extern "C" int __cdecl FUNC_10001010(...);
extern "C" void __cdecl FUNC_1006BC70();
extern "C" void __cdecl FUNC_1006BC80();
extern "C" double __cdecl FUNC_1009F2B0(int,int,int);
extern "C" double __cdecl FUNC_1009F0C0();
extern "C" int  __cdecl FUNC_10001150(unsigned short);
extern "C" int  __cdecl FUNC_10001120(unsigned short);
extern "C" void __cdecl FUNC_1009EB10(void*);
extern "C" void __cdecl FUNC_100B4D10(...);
extern "C" int __cdecl FUNC_100010F0(...);
extern "C" int  __cdecl FUNC_10001080();
extern "C" void __cdecl FUNC_100AE480(int, float*);
extern "C" double __cdecl FUNC_1009F190();
extern "C" void __cdecl FUNC_1006BC90(void *pos, int a, int b, int c, unsigned char d);
extern int DAT_1026eb5c;
extern float DAT_100e55f8;
struct CObj_10001350 { char _p[0x19];
	struct Slot_1350 { void *name; int f4; float x,y,z,rad; unsigned short id;
		unsigned short id2; char col; } *s;
	void RenderTags(); };
void CObj_10001350::RenderTags() {
	float pos[3], v[16];
	if (!FUNC_10001010() || !DAT_1026eb94) return;
	int *tab = (int*)(*(int*)(DAT_1026eb94 + 0x3de) + 4);
	if (DAT_1026eb5c) FUNC_1006BC70();
	Slot_1350 *sl = (Slot_1350*)((char*)this + 0x19 - 0x19);
	char *p = (char*)this + 0x19;
	for (int i = 0x800; i; i--) {
		sl = (Slot_1350*)(p - 0x19);
		if (*(int*)sl->name || sl->id) { }
		if (sl->name && *(char*)sl->name) {
			unsigned short id = *(unsigned short*)p;
			unsigned int f4 = sl->f4;
			float fx = 0, fy = 0, fz = 0;
			int have = 0, a2 = sl->f4, a1 = 0;
			unsigned char col = *(unsigned char*)(p - 1);
			if (id == 0xffff) {
				unsigned short id2 = *(unsigned short*)(p + 2);
				if (id2 == 0xffff) {
					double d = FUNC_1009F2B0((int)sl->x, (int)sl->y, (int)sl->z);
					if (d < sl->rad != (d == sl->rad)) {
						fx = sl->x; fy = sl->y; fz = sl->z; have = 1;
					}
				} else if (FUNC_10001150(id2) && FUNC_10001120(id2)) {
					if (FUNC_1009F0C0() < sl->rad != (FUNC_1009F0C0() == sl->rad)) {
						FUNC_1009EB10(v);
						FUNC_100B4D10(&fx, v, &sl->x);
						have = 1;
					}
				}
			} else if (id < 0x3ec && tab[id * 4 + 0x2a/4]) {
				FUNC_100010F0(id);
				if (FUNC_10001080()) {
					int w = FUNC_100010F0(id);
					if (*(int*)(w + 0x1dd)) {
						if (FUNC_1009F0C0() < sl->rad != (FUNC_1009F0C0() == sl->rad)) {
							FUNC_100AE480(8, &fz);
							fx = fz + sl->x;
							fy = v[0] + sl->y;
							fz = (float)(FUNC_1009F190() * DAT_100e55f8 + sl->z + v[0]);
							have = 1;
						}
					}
				}
			}
			if (have) {
				float tp[3] = {fx, fy, fz};
				FUNC_1006BC90(tp, a1, a2, (f4 & 0xff000000) == 0xff000000, col);
			}
		}
		p += 0x1d;
	}
	if (DAT_1026eb5c) FUNC_1006BC80();
}
// .text:10001CE0 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// reports scripted events (enter/exit/use) to the server as packet type 10
extern "C" void __cdecl FUNC_1001F730();
extern "C" int  __cdecl FUNC_100B3BD0(int);
extern "C" short __cdecl FUNC_1001EB90(...);
extern "C" void __cdecl FUNC_1001FFE0(void *v, int bits, int n);
extern "C" void __cdecl FUNC_100B72E0(unsigned int, unsigned int);
extern "C" void __cdecl FUNC_1001F8D0();
extern char DAT_100e5620[];

void __cdecl FUNC_1001CE0(int self, unsigned int a2, unsigned int a3, unsigned int a4) {
	char out[276];
	unsigned int v;
	if (!DAT_1026eb94) return;
	FUNC_1001F730();
	switch (a4) {
	case 1:
		v = FUNC_1001EB90(FUNC_100B3BD0(self)) & 0xffff;
		if (v != 0xffff) {
			FUNC_1001FFE0(&v, 0x20, 1);
			FUNC_1001FFE0(&a2, 0x20, 1);
			FUNC_1001FFE0(&a3, 0x20, 1);
			FUNC_1001FFE0(&a4, 0x20, 1);
			g_1026eb94_net->Send(DAT_100e5620, out, 1, 10, 0, 0);
		}
		break;
	case 3:
		v = FUNC_1001EB90(FUNC_100B3BD0(self)) & 0xffff;
		if (v != 0xffff) {
			FUNC_1001FFE0(&v, 0x20, 1);
			FUNC_1001FFE0(&a2, 0x20, 1);
			FUNC_1001FFE0(&a3, 0x20, 1);
			FUNC_1001FFE0(&a4, 0x20, 1);
			g_1026eb94_net->Send(DAT_100e5620, out, 1, 10, 0, 0);
			if (FUNC_10001120((unsigned short)v))
				FUNC_100B72E0(a2, a3);
		}
		break;
	case 4: {
		unsigned int id = FUNC_1001EB90(FUNC_100B3BD0(self)) & 0xffff;
		int w = FUNC_10001120((unsigned short)id);
		if (id != 0xffff) {
			FUNC_1001FFE0(&id, 0x20, 1);
			FUNC_1001FFE0(&a2, 0x20, 1);
			FUNC_1001FFE0(&a3, 0x20, 1);
			FUNC_1001FFE0(&a4, 0x20, 1);
			g_1026eb94_net->Send(DAT_100e5620, out, 1, 10, 0, 0);
			if (w && *(int*)(w + 0x4c)) {
				int m = *(int*)(w + 0x4c);
				if (!a2) {
					FUNC_100B72E0(*(unsigned char*)(m + 0x434),
						*(unsigned char*)(m + 0x435));
					*(int*)(w + 0x71) = 0;
				} else {
					*(int*)(w + 0x71) = 1;
				}
			}
		}
		break;
	}
	}
	FUNC_1001F8D0();
}
// .text:10004370 — SEMANTIC TWIN: correct semantics, not byte-verified
// resolves a world entity to (type,id) and returns its camera-delta position
extern "C" int  __cdecl FUNC_100B10E0(int);
extern "C" short __cdecl FUNC_100138C0(int);
extern "C" short __cdecl FUNC_10012A10(int);
struct CObj_10004370 { char _p[0x104]; int m_104;
	char Resolve(short *id, float *delta); };
char CObj_10004370::Resolve(short *id, float *delta) {
	float pos[4];
	char kind = 0;
	short s = -1;
	int cam = m_104;
	int e = FUNC_100B10E0((int)pos);
	if (!e) return 0;
	int *t = (int*)(*(int*)(DAT_1026eb94 + 0x3de));
	int *sub = (int*)t[3];
	s = FUNC_100138C0(e);
	if (s != -1) kind = 1;
	else {
		s = FUNC_1001EB90(e);
		if (s != -1) kind = 2;
		else {
			s = FUNC_10012A10(e);
			if (s != -1) kind = 3;
		}
	}
	if (!s) return 0;
	float *p = (float*)(*(int*)(e + 0x14));
	delta[0] = pos[0] - p[0x30/4];
	delta[1] = pos[1] - p[0x34/4];
	delta[2] = pos[2] - p[0x38/4];
	*id = s;
	return kind;
}
// .text:10004440 — SEMANTIC TWIN: correct semantics, not byte-verified
// line-of-sight probes from the camera position: nearest actor/vehicle/object
extern "C" float * __cdecl FUNC_1009C980();
extern "C" void __cdecl FUNC_100B3B10(float *a, float *b, float *hit, int *flag,
	int,int,int,int,int,int,int,int);
extern "C" short __cdecl FUNC_10012E70(float,float*,float*);
extern "C" short __cdecl FUNC_1001EF30(float,float*,float*,float);
extern "C" short __cdecl FUNC_10013D90(float,float*,float*,float);
extern "C" short __cdecl FUNC_10001770(float,float*,float*,float);
extern float DAT_100e583c;
int __cdecl FUNC_10004440(short *out) {
	float *cam = FUNC_1009C980();
	int hit;
	float hx, hy, hz, ex, ey, ez, ox, oy, oz;
	hit = 0;
	ox = cam[0] + cam[3]; oy = cam[1] + cam[4]; oz = cam[2] + cam[5];
	out[0] = -1; out[1] = -1; out[2] = -1; out[3] = -1;
	ex = cam[0] * DAT_100e583c + cam[3];
	ey = cam[1] * DAT_100e583c + cam[4];
	ez = cam[2] * DAT_100e583c + cam[5];
	FUNC_100B3B10(&ox, &ex, &hx, &hit, 1,0,0,0,0,0,0,0);
	if (hit) { ex = hx; ey = hy; ez = hz; }
	short s = FUNC_10012E70(0x42200000, &ox, &ex);
	if (s != -1) out[0] = s;
	ex = cam[0] * DAT_100e583c + cam[3];
	ey = cam[1] * DAT_100e583c + cam[4];
	ez = cam[2] * DAT_100e583c + cam[5];
	FUNC_100B3B10(&ox, &ex, &hx, &hit, 1,0,0,1,0,0,0,0);
	if (hit) { ex = hx; ey = hy; ez = hz; }
	s = FUNC_1001EF30(0x42200000, &ox, &ex, 0x3f800000);
	if (s != -1) out[1] = s;
	ex = cam[0] * DAT_100e583c + cam[3];
	ey = cam[1] * DAT_100e583c + cam[4];
	ez = cam[2] * DAT_100e583c + cam[5];
	FUNC_100B3B10(&ox, &ex, &hx, &hit, 1,1,0,1,0,0,0,0);
	if (hit) { ex = hx; ey = hy; ez = hz; }
	s = FUNC_10013D90(0x41a00000, &ox, &ex, 0x3f400000);
	if (s != -1) out[2] = s;
	s = FUNC_10001770(0x41a00000, &ox, &ex, 0x3f400000);
	if (s != -1) out[3] = s;
	return 1;
}
// .text:10006080 — SEMANTIC TWIN: correct semantics, not byte-verified
// death-respawn countdown: ticks the respawn timer and fires at zero
extern "C" void __cdecl FUNC_100A22C0(int,int,int,int);
extern "C" void __cdecl FUNC_100058D0(int);
struct CObj_10006080 { char _p[0x143]; int m_143; char _q[0x1b7]; int m_2fe;
	char _r[4]; int m_306; void Tick(); };
void CObj_10006080::Tick() {
	if (!m_306) return;
	m_143 = 0;
	char v[48];
	FUNC_1009EB10(v);
	int t = m_2fe;
	if (!t) t = *(int*)(*(int*)(DAT_1026eb94 + 0x3d5) + 0x23);
	m_2fe = t - 1;
	FUNC_100A22C0(0x41d, 0, 0, 0);
	FUNC_100058D0(m_2fe);
}
// .text:10006290 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// sends the player-on-foot sync: position, keys, weapon state at 10Hz
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
extern "C" char __cdecl FUNC_1000ABC50();
extern "C" int  __cdecl FUNC_1000AEF60();
extern "C" short __cdecl FUNC_100018B0(int);
struct CObj_10006290 {
	char _p[0x104]; int m_104;
	char _q[0x79]; unsigned long m_181; short m_185; short m_187; char m_189;
	char m_18a[0xd]; short m_197[8];
	void SendFootSync();
};
void CObj_10006290::SendFootSync() {
	char c = FUNC_1000ABC50();
	char dirty = 0;
	short s2, s3;
	int w;
	if (!m_104) s2 = -1;
	else if (!(w = FUNC_1000AEF60())) s2 = -1;
	else if (!*(int*)(*(int*)(DAT_1026eb94 + 0x3de) + 4)) s2 = -1;
	else s2 = FUNC_100138C0(w);
	if (!m_104) s3 = -1;
	else if (!(w = FUNC_1000AEF60())) s3 = -1;
	else if (!*(int*)(*(int*)(DAT_1026eb94 + 0x3de) + 0x10)) s3 = -1;
	else s3 = FUNC_100018B0(w);
	if (s2 == m_185 && s3 == m_187) {
		if (c == m_189 && GetTickCount() - m_181 < 100) return;
	} else {
		m_185 = s2; m_187 = s3;
		dirty = 1;
	}
	if (c != m_189) m_189 = c;
	FUNC_1001F730();
	char hdr[7]; unsigned int v;
	hdr[0] = 0xcc; FUNC_1001FFE0(hdr, 8, 1);
	v = (unsigned short)m_185; FUNC_1001FFE0(&v, 0x10, 1);
	v = (unsigned short)m_187; FUNC_1001FFE0(&v, 0x10, 1);
	unsigned char idx = 0; v = 0;
	unsigned char *pb = (unsigned char*)m_18a;
	unsigned short *pw = (unsigned short*)m_197;
	char *tab = *(char**)(m_104 + 0x2a4);
	do {
		char *e = tab + v;
		if (*pb != *(unsigned char*)(e + 0x5a0) || *(int*)pw != *(int*)(e + 0x5ac)) {
			*pb = *(unsigned char*)(e + 0x5a0);
			*(int*)pw = *(int*)(tab + 0x5ac + v);
			hdr[0] = idx; FUNC_1001FFE0(hdr, 8, 1);
			hdr[0] = *pb; FUNC_1001FFE0(hdr, 8, 1);
		}
		pb++; pw += 2; v += 4; idx++;
	} while (idx < 8);
	FUNC_1001F8D0();
}
// .text:10006540 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// sends the local player nametag packet: position, name, state icon
extern "C" int __cdecl FUNC_1000AF5D0(...);
extern "C" void __cdecl FUNC_10009D460(void*);
extern "C" unsigned int __cdecl FUNC_10003AF0();
extern "C" void __cdecl FUNC_10020090(...);
extern "C" void __cdecl FUNC_10005210();
extern "C" void __cdecl FUNC_1000A1DB0(int);
extern "C" void __cdecl FUNC_1000ABD70(...);
extern "C" void __cdecl FUNC_1009F040(int,int,float);
extern "C" void __cdecl FUNC_1000AC570(int,int,float);
extern "C" void __cdecl FUNC_1009D780(float,float,float,int,int,int);
extern "C" void __cdecl FUNC_1009D7E0(float,float,float,int);
extern "C" int  __cdecl FUNC_100010B0(unsigned short);
extern "C" void __cdecl FUNC_100B2310(void*,int,unsigned char,int);
extern float DAT_100e5804;
extern char DAT_100e57d0[], DAT_100e57e4[];
struct CPktQ {
	virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3();
	virtual int v4(); virtual int v5();
	virtual int Send(void *pkt, int a, int b, int c); };
struct CObj_10006540 {
	CPktQ *q;
	char _p[0x113]; unsigned long m_113; unsigned long m_117;
	char _q[0x1f8]; char m_30e; char m_30f; unsigned short m_310; int m_314;
	void SendTag();
};
void CObj_10006540::SendTag() {
	unsigned short k1[2], k2[2];
	unsigned int keys;
	int px, py; float pz;
	char tag[48], out[276];
	FUNC_1001F730();
	keys = FUNC_1000AF5D0(k1, k2);
	FUNC_10009D460(tag);
	int *tab = (*(int**)(DAT_1026eb94 + 0x3de)) + 1;
	int t0 = **(int**)(DAT_1026eb94 + 0x3de);
	if (!*tab || !t0) { FUNC_1001F8D0(); return; }
	unsigned long now;
	if (FUNC_10003AF0() < GetTickCount() - m_113) {
		now = GetTickCount(); m_113 = now;
		char hdr[4] = {(char)0xd4};
		FUNC_1001FFE0(hdr, 8, 1);
		struct { unsigned short a,b; unsigned int c; } s = {k1[0],k2[0],keys};
		FUNC_10020090(&s, 0x12);
		q->Send(out, 1, 6, 1);
		if ((unsigned int)(FUNC_10003AF0() * 2) < GetTickCount() - m_117) {
			m_117 = GetTickCount();
			FUNC_10005210();
		}
	}
	FUNC_1000A1DB0(0);
	FUNC_1000ABD70(0x42c80000);
	FUNC_1009F040(px, py, pz + DAT_100e5804);
	if (m_30f == 1) {
		if (m_310 > 0x3eb || !*(int*)(*tab + 0x2a + m_310 * 4)) {
			m_30f = 0; m_314 = 0;
		}
		if (m_30f == 1 && m_310 < 0x3ec && *(int*)(*tab + 0x2a + m_310 * 4)) {
			FUNC_100010F0(m_310);
			if (!FUNC_10001080() || *(char*)(FUNC_100010F0(m_310) + 0x10a) == ' ') {
				m_30f = 0; m_314 = 0;
			}
		}
	}
	if (m_314) goto done;
	if (!m_30f) {
		FUNC_1000AC570(0, 0, 0x41200000);
		FUNC_1009D780(0x42480000, 0x42480000, 0x42480000, 0, 0, 0);
		FUNC_1009D7E0(0x42700000, 0x42700000, 0x42480000, 2);
	} else if (m_30f == 1) {
		unsigned short id = m_310;
		int w = FUNC_100010B0(id);
		if (!w) goto done;
		w = FUNC_100010F0(id);
		if (!*(int*)(w + 0x1dd)) goto done;
		FUNC_100B2310(DAT_100e57e4, *(int*)(*(int*)(w + 0x1dd) + 0x44), m_30e, 2);
	} else if (m_30f == 2) {
		unsigned short id = m_310;
		int w = FUNC_10001150(id);
		if (!w) goto done;
		w = FUNC_10001120(id);
		if (!w) goto done;
		FUNC_100B2310(DAT_100e57d0, *(int*)(w + 0x44), m_30e, 2);
	}
	m_314 = 1;
done:
	FUNC_1001F8D0();
}
// .text:10006BC0 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// sends an on-foot sync record for an entity: resolves actor/vehicle id
struct CPktQ_6bc0 { virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3();
	virtual int v4(); virtual int v5();
	virtual int Send(void *pkt, int a, int b, int c); };
struct CEnt_6BC0 { int f[0x14];
	int mode; int veh; float x,y,z; float vx,vy,vz; };
struct CObj_10006BC0 { CPktQ_6bc0 *q; int m_104;
	void SendSync(CEnt_6BC0 *e); };
void CObj_10006BC0::SendSync(CEnt_6BC0 *e) {
	char out[276];
	if (!m_104) return;
	char mode = 0;
	short id = -1;
	if (FUNC_1000ABC50() == 0x22 && !e->veh) { FUNC_1001F8D0(); return; }
	if (e->veh) {
		int *pi = *(int**)(DAT_1026eb94 + 0x3de);
		if (pi[1] && *pi) {
			id = FUNC_100138C0(e->veh);
			if (id == -1) {
				id = FUNC_1001EB90(e->veh);
				if (id == -1) {
					id = FUNC_10012A10(e->veh);
					if (id == -1) {
						int v = e->veh;
						float acc[3] = {0,0,0};
						if (!*(int*)(v + 0x14)) {
							e->x += *(float*)(v + 4);
							e->y += *(float*)(v + 8);
							e->z += *(float*)(v + 0xc);
						} else {
							FUNC_100B4D10(acc, *(int*)(v + 0x14), &e->x);
							e->x = acc[0]; e->y = acc[1]; e->z = acc[2];
						}
					} else mode = 3;
				} else mode = 2;
			} else mode = 1;
		}
	}
	struct Sync_6BC0 { char mode; short id; int a,b,c,d; float x; int e,f;
		float vx; int vy; float vz; char keys; } s;
	s.a = e->f[1]; s.b = e->f[2]; s.c = e->f[3]; s.d = e->f[4];
	s.x = e->x; s.e = e->f[5]; s.f = e->f[6]; s.vx = e->vx; s.vy = e->vy;
	s.vz = e->vz;
	s.mode = mode; s.id = id; s.keys = FUNC_1000ABC50();
	FUNC_1001F730();
	char hdr[4] = {(char)0xce};
	FUNC_1001FFE0(hdr, 8, 1);
	FUNC_10020090(&s, 0x28);
	q->Send(out, 1, 7, 0);
	FUNC_1001F8D0();
}
// .text:10006E00 — SEMANTIC TWIN: correct semantics, not byte-verified
// picks the best teammate / nearest enemy actor for a target-assist packet
extern "C" int  __cdecl FUNC_1000B7460();
extern "C" int  __cdecl FUNC_1009FDE0();
extern "C" int  __cdecl FUNC_1000B7CF0();
extern "C" void __cdecl FUNC_10004D30(int, char);
extern "C" int  __cdecl FUNC_1009F3D0();
extern "C" void __cdecl FUNC_1000AC1A0(int);
extern float DAT_100e5908;
struct CObj_10006E00 { char _p[0x104]; int m_104;
	int Pick(int arg, int targ); };
int CObj_10006E00::Pick(int arg, int targ) {
	GetTickCount();
	int *tv = (int*)(targ + 0x4c);
	int *tab = (int*)(*(int*)(DAT_1026eb94 + 0x3de) + 4);
	if (!*tv || !m_104 || FUNC_1000B7460()) return 0;
	int t3 = *tv;
	if ((*(int*)(t3 + 0x460) && (*(unsigned int*)(*(int*)(t3 + 0x460) + 0x46c) & 0x100))
		|| FUNC_1009F0C0() > DAT_100e5908 || FUNC_1009FDE0() || FUNC_1000B7CF0()) {
		*(int*)(targ + 0x7f) = 0;
		*(int*)(targ + 0x83) = 0;
		return 0;
	}
	int *list = (int*)(t3 + 0x464);
	for (int i = 0; i < 8; i++) {
		int e = list[i];
		if (e && !*(int*)(e + 0x598)) {
			if (e != *(int*)(*(int*)(m_104) + 0x2a4)) return 0;
			FUNC_10004D30(arg, (char)i + 1);
			return 1;
		}
	}
	unsigned int best = 0;
	float bestf = 100000.0f;
	unsigned int n = *(unsigned int*)(tab + 0x2f3a/4);
	if ((int)n < (int)(unsigned int)*(unsigned short*)(tab + 1))
		n = *(unsigned short*)(tab + 1);
	for (unsigned int i = 0; (int)i <= (int)n; i++) {
		int w = 0;
		if (i == *(unsigned short*)(tab + 1)) {
			w = m_104;
		} else if ((unsigned short)i < 0x3ed) {
			int e = tab[0x1f8a/4 + (i & 0xffff)];
			if (e && *(int*)(e + 0x10)) w = *(int*)(*(int*)(e + 0x10) + 0x1dd);
		}
		if (w && FUNC_1009F3D0()) {
			FUNC_1000AC1A0(targ);
			float d = 0.0f;
			if (!i) bestf = d;
			else if (d < bestf) { bestf = d; best = i; }
		}
	}
	if (best != *(unsigned short*)(tab + 1)) return 0;
	if (bestf < DAT_100e5908 == (bestf == DAT_100e5908)) return 0;
	FUNC_10004D30(arg, 0);
	return 1;
}
// .text:10006FE0 — SEMANTIC TWIN: correct semantics, not byte-verified
// checks the last vehicle-sync sample and triggers the sync-loss handler
extern "C" int  __cdecl FUNC_1000A73B0();
extern "C" unsigned short __cdecl FUNC_1001EC00();
extern "C" void __cdecl FUNC_1000AC060(...);
extern "C" void __cdecl FUNC_1000AC410(int,int);
extern "C" void __cdecl FUNC_10005AD0(unsigned short,int);
extern double DAT_100e590c;
void __cdecl FUNC_10006FE0() {
	int w = FUNC_1000A73B0();
	int *tab = *(int**)(DAT_1026eb94 + 0x3de);
	if (*(short*)(w + 0x10) && !*(short*)(w + 0x40)) {
		unsigned short id = FUNC_1001EC00();
		if (id < 2000 && tab[(id & 0xffff) + 0x3074/4]) {
			int v = FUNC_10001120(id);
			if (FUNC_1009F0C0() < DAT_100e590c) {
				if (FUNC_1000ABC50() == '.') FUNC_1000AC060(0, 0);
				FUNC_1000AC410(*(int*)(v + 0x44), 1);
				FUNC_10005AD0(id, 1);
			}
		}
	}
}
// .text:10007080 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// sends the in-car sync packet: vehicle id, pos, quat, velocity, health
extern "C" char __cdecl FUNC_1000ABBF0();
extern "C" int  __cdecl FUNC_1000AC000();
struct CPktQ_7080 { virtual int v0(); virtual int v1(); virtual int v2();
	virtual int v3(); virtual int v4(); virtual int v5();
	virtual int Send(void *pkt, int a, int b, int c); };
struct CObj_10007080 { CPktQ_7080 *q; char _p[0x82]; int m_82;
	void SendCarSync(); };
void CObj_10007080::SendCarSync() {
	unsigned short k1[2], k2[2];
	char out[276];
	struct CarSync_7080 {
		unsigned short veh, a, b; unsigned int keys; int pos[3];
		int quat[4]; int vel[3]; float hp;
		unsigned char f, hpbyte, weap, flag; unsigned short id; int tr;
	} s;
	FUNC_1001F730();
	int veh = **(int**)(DAT_1026eb94 + 0x3de);
	unsigned int keys = FUNC_1000AF5D0(k1, k2);
	char c = FUNC_1000ABBF0();
	unsigned short *p = (unsigned short*)&s;
	for (int i = 0xf; i; i--) { p[0] = 0; p[1] = 0; p += 2; }
	*p = 0; *(char*)(p + 1) = 0;
	if (!m_82) { FUNC_1001F8D0(); return; }
	s.veh = FUNC_1001EB90(FUNC_1000AC000());
	if (s.veh == 0xffff) { FUNC_1001F8D0(); return; }
	s.a = k1[0];
	s.flag = (s.flag & 0x3f) | (c << 6);
	s.b = k2[0];
	s.keys = keys;
	FUNC_1001F8D0();
}
// .text:100074C0 — SEMANTIC TWIN: correct semantics, not byte-verified
// the game's per-frame update: drives connect state, sync send/recv, dialogs
extern "C" void __cdecl FUNC_10070B90(int);
extern "C" char __cdecl FUNC_1000ABE40();
extern "C" int  __cdecl FUNC_1000ABE10();
extern "C" int  __cdecl FUNC_1000ABE70();
extern "C" int  __cdecl FUNC_1000ABFC0();
extern "C" int  __cdecl FUNC_1000ADB60();
extern "C" void __cdecl FUNC_1000ADB20();
extern "C" int  __cdecl FUNC_1000AE0A0();
extern "C" void __cdecl FUNC_1000AE070(int);
extern "C" int  __cdecl FUNC_1000AE260();
extern "C" void __cdecl FUNC_1000AE1E0();
extern "C" int  __cdecl FUNC_1000ADC90();
extern "C" void __cdecl FUNC_1000ADC00();
extern "C" void __cdecl FUNC_1000ADCA0();
extern "C" void __cdecl FUNC_1000ADFB0(int);
extern "C" void __cdecl FUNC_1000AC790(int);
extern "C" void __cdecl FUNC_10007080();
extern "C" void __cdecl FUNC_1000AD0F0();
extern "C" void __cdecl FUNC_10005810();
extern "C" void __cdecl FUNC_1000A1520(unsigned char);
extern "C" void __cdecl FUNC_10004850();
extern "C" void __cdecl FUNC_1000B00B0();
extern "C" int  __cdecl FUNC_1000ACEF0();
extern "C" void __cdecl FUNC_1000ACF20();
extern "C" int  __cdecl FUNC_1000ACE40();
extern "C" void __cdecl FUNC_1000ACE90();
extern "C" int  __cdecl FUNC_1000ACB60();
extern "C" void __cdecl FUNC_1000ADDF0();
extern "C" void __cdecl FUNC_1000AE520();
extern "C" int  __cdecl FUNC_1000AE790();
extern "C" void __cdecl FUNC_10009D740();
extern "C" void __cdecl FUNC_1000A1F20();
extern "C" void __cdecl FUNC_10005D00();
extern "C" void __cdecl FUNC_10006290();
extern "C" char __cdecl FUNC_1000A0EE0();
extern "C" void __cdecl FUNC_10005970(char);
extern "C" void __cdecl FUNC_10004700();
extern "C" void __cdecl FUNC_1000AC110();
extern "C" void __cdecl FUNC_10002FA0();
extern "C" void __cdecl FUNC_10003FC0();
extern "C" void __cdecl FUNC_10005DE0(unsigned short);
extern "C" int  __cdecl FUNC_1000B7E00();
extern "C" void __cdecl FUNC_1000AFFD0();
extern "C" double __cdecl FUNC_1000B72A0();
extern "C" unsigned int __cdecl FUNC_10003AB0();
extern "C" void __cdecl FUNC_10003730();
void __cdecl FUNC_10006FE0();
extern "C" void __cdecl FUNC_10003F50();
extern "C" int  __cdecl FUNC_10004300(unsigned int,int,int);
extern "C" void __cdecl FUNC_10004F00();
extern "C" int  __cdecl FUNC_1000AC160();
extern "C" void __cdecl FUNC_1000AD080();
extern "C" void __cdecl FUNC_10005590();
extern "C" void __cdecl FUNC_10006540();
extern "C" int  __cdecl FUNC_10003C20();
extern "C" int  __cdecl FUNC_1000ACF90();
extern int DAT_10118990;
extern unsigned long DAT_100fe0a4;
extern unsigned int DAT_100fe0b0;
extern double DAT_100e5940;
struct CObj_100074C0 {
	char _p[0xf0]; int m_f0; int m_f4; unsigned short m_f8; unsigned short m_fa;
	int m_fc; int m_100; int *m_104; int m_108;
	char _q[9]; unsigned long m_117; unsigned long m_11b; char _r[0xab];
	char m_1cf; int m_1d0; char _s[0x12b]; int m_2fa;
	char m_1cb_pad[3];
	char _t[11]; char m_30f; int m_310; int m_314;
	int Update();
};
int CObj_100074C0::Update() {
	if (!m_f0) return 0;
	unsigned int keys, ping;
	unsigned long now;
	if (!m_104) {
		FUNC_10006540();
		*(int*)((char*)this + 0x1cb) = 0;
		return 1;
	}
	FUNC_10070B90(0);
	if ((!m_f4 && FUNC_1000ABE40() == '6') || FUNC_1000ABE10()) {
		if (!m_108) { if (!m_2fa) goto noState; }
		else if (!m_2fa) FUNC_10003C20();
		m_f0 = 0; *(int*)((char*)this + 0x17d) = 0;
	noState:
		m_108 = 0;
		m_30f = 0; m_310 = -1; m_314 = 0;
		if (FUNC_1000ADB60()) FUNC_1000ADB20();
		if (FUNC_1000AE0A0()) FUNC_1000AE070(0);
		if (FUNC_1000AE260()) FUNC_1000AE1E0();
		if (FUNC_1000ADC90()) FUNC_1000ADC00();
		FUNC_1000ADFB0(0);
		FUNC_1000AC790(1);
		if (*(int*)((char*)this + 0x1d0)) {
			*(int*)((char*)this + 0x1d0) = 0;
			(**(void(__cdecl***)())(*m_104 + 4))();
		}
		if (FUNC_1000ABE70() && !FUNC_1000ABFC0()) {
			FUNC_10007080();
			m_fa = FUNC_1001EB90(FUNC_1000AC000());
		}
		FUNC_1000AD0F0();
		FUNC_10005810();
		m_f0 = 0; m_f4 = 1;
		FUNC_1000A1520(0);
		return 1;
	}
	int a, b;
	keys = FUNC_1000AF5D0(&a, &b);
	FUNC_10004850();
	if (FUNC_1000ADB60()) {
		FUNC_1000A1DB0(0);
		FUNC_1000B00B0();
		int w = FUNC_1000A73B0();
		if (*(short*)(w + 0x1e)) FUNC_1000ADB20();
	}
	if (FUNC_1000ACEF0()) FUNC_1000ACF20();
	if (FUNC_1000ACE40()) FUNC_1000ACE90();
	if (FUNC_1000ACB60() && FUNC_1000A73B0() && *(short*)(FUNC_1000A73B0() + 0x1e))
		FUNC_1000AC790(1);
	if ((FUNC_1000AE260() && *(short*)(FUNC_1000A73B0() + 0x1e)) ||
		(FUNC_1000AE260() && FUNC_1000ABE70())) FUNC_1000AE1E0();
	if (FUNC_1000ADC90()) {
		if (!*(short*)(FUNC_1000A73B0() + 0x1e) && !FUNC_1000ABE70())
			FUNC_1000ADCA0();
		else FUNC_1000ADC00();
	}
	FUNC_1000ADDF0();
	if (FUNC_1000ABE70() && FUNC_1000ADB60()) FUNC_1000ADB20();
	FUNC_1000AE520();
	int v = FUNC_1000AE790();
	if (v) { m_fc = v; m_100 = 0; }
	else if (m_fc && m_100) m_fc = 0;
	now = GetTickCount();
	if (DAT_100fe0a4 != (unsigned long)-1 && now - DAT_100fe0a4 > 5000 &&
		!FUNC_1000ABE70()) {
		FUNC_10009D740();
		DAT_100fe0a4 = -1;
	}
	if (*(int*)((char*)this + 0x30a) <= (int)now)
		FUNC_1000A1520(*(unsigned char*)(*(int*)(DAT_1026eb94 + 0x3d5) + 0x21));
	FUNC_1000A1F20();
	if (now - *(unsigned long*)((char*)this + 0x11b) > 1000) {
		FUNC_10005D00();
		*(unsigned long*)((char*)this + 0x11b) = now;
	}
	FUNC_10006290();
	char c = FUNC_1000A0EE0();
	if (c != m_1cf) FUNC_10005970(c);
	FUNC_10004700();
	if (!m_108) {
		if (FUNC_1000ABE40() == '2' && !FUNC_1000ABFC0()) {
			FUNC_1000AC110();
			FUNC_10002FA0();
			FUNC_10003FC0();
			if (now - *(unsigned long*)((char*)this + 0x117) > 1000) {
				*(unsigned long*)((char*)this + 0x117) = now;
				FUNC_10005210();
			}
			if (**(int**)(DAT_1026eb94 + 0x3de))
				m_f8 = FUNC_1001EB90(FUNC_1000AC000());
			int got = FUNC_10001120(m_f8);
			FUNC_10005DE0(m_f8);
			if (got) {
				if (!*(int*)((char*)this + 0x1d0)) {
					if (FUNC_1000B7E00()) {
						(**(void(__cdecl***)())(*m_104 + 8))();
						*(int*)((char*)this + 0x1d0) = 1;
					}
				}
			}
			if (!got || !*(int*)((char*)this + 0x1d0)) {
				if (!got) { FUNC_1000ABD70(0); FUNC_1000AFFD0(); }
			} else if (FUNC_1000B72A0() == DAT_100e5940) {
				FUNC_1000ABD70(0); FUNC_1000AFFD0();
			}
			if (FUNC_10003AB0() < now - *(unsigned long*)((char*)this + 0x10f)) {
				now = GetTickCount();
				*(unsigned long*)((char*)this + 0x10f) = now;
				FUNC_10007080();
			}
		} else if (FUNC_1000ABE40() == 1 || FUNC_1000ABE40() == 0xc) {
			FUNC_10003730();
			FUNC_10002FA0();
			if (*(int*)((char*)this + 0x1d0)) {
				*(int*)((char*)this + 0x1d0) = 0;
				(**(void(__cdecl***)())(*m_104 + 4))();
			}
			FUNC_10006FE0();
			FUNC_10003F50();
			if ((short)m_f8 != -1) { m_fa = m_f8; m_f8 = 0xffff; }
			if (FUNC_10004300(keys, b, a) ||
				FUNC_10003AF0() < now - *(unsigned long*)((char*)this + 0x10f)) {
				now = GetTickCount();
				*(unsigned long*)((char*)this + 0x10f) = now;
				FUNC_10004F00();
			}
			unsigned int gap;
			if ((keys & 0x84) == 0) gap = 1000;
			else if (DAT_10118990 == 2) gap = DAT_100fe0b0;
			else gap = 100;
			if (now - *(unsigned long*)((char*)this + 0x117) >= gap) {
				*(unsigned long*)((char*)this + 0x117) = now;
				FUNC_10005210();
			}
		} else if (FUNC_1000ABE40() == '2' && FUNC_1000ABFC0()) {
			FUNC_10002FA0();
			if (*(int*)((char*)this + 0x1d0)) {
				*(int*)((char*)this + 0x1d0) = 0;
				(**(void(__cdecl***)())(*m_104 + 4))();
			}
			int w = FUNC_1000A73B0();
			FUNC_1000ABC50();
			if (!*(int*)((char*)this + 0x1cb)) {
				if (*(short*)(w + 0x24) && FUNC_1000ACF90())
					*(int*)((char*)this + 0x1cb) = 1;
			} else if ((FUNC_1000ABC50() == 0 || !FUNC_1000AC160()) &&
				*(int*)((char*)this + 0x1cb)) {
				FUNC_1000AD080();
				*(int*)((char*)this + 0x1cb) = 0;
			}
			if (FUNC_10003AB0() < now - *(unsigned long*)((char*)this + 0x10f)) {
				now = GetTickCount();
				*(unsigned long*)((char*)this + 0x10f) = now;
				FUNC_10005590();
			}
		}
		*(int*)((char*)this + 0x1cb) = 0;
	}
	return 1;
}
// .text:10008B20 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// idle-state pump: fires the connect retry and subsystem ticks on their timers
extern "C" int  __cdecl FUNC_1002E7F0();
extern "C" void __cdecl FUNC_1009F630(int);
extern "C" void __cdecl FUNC_1009F680(int);
extern "C" int  __cdecl FUNC_1000AE330();
extern "C" char * __cdecl FUNC_1000AE2E0();
extern "C" void __cdecl FUNC_1000AE300(const char*);
extern "C" void __cdecl FUNC_100137C0();
extern "C" void __cdecl FUNC_1001F3C0();
extern "C" void __cdecl FUNC_10013520();
extern "C" void __cdecl FUNC_10008200();
extern int DAT_10118a0c, DAT_10118a10;
extern char DAT_100e59c9[];
struct CObj_10008B20 { char _p[0x3d5]; int m_3d5; char m_3d9; int m_3da; int m_3de;
	void Idle(); };
void CObj_10008B20::Idle() {
	if (*(char*)((char*)this + 0x3d9)) {
		if ((unsigned int)(FUNC_1002E7F0() - m_3da) < 0x3e9) return;
		*(char*)((char*)this + 0x3d9) = 0;
		if (*(int*)(*(int*)(*(int*)(*(int*)(m_3de) + 4) + 0x26) + 0xf0)) {
			FUNC_10001010(1); FUNC_1000AC790(1);
			FUNC_10001010(1); FUNC_1009F630(1);
			FUNC_10001010(1); FUNC_1009F680(1);
		}
	}
	if (*(char*)(m_3d5 + 0x1a) && FUNC_10001010(1) && !FUNC_1000AE330()) {
		const char *s = FUNC_1000AE2E0();
		if (*s) FUNC_1000AE300(DAT_100e59c9);
	}
	if (*(int*)(*(int*)(m_3de) + 4)) FUNC_100137C0();
	if (!**(int**)(m_3de) || DAT_10118a0c < 3) DAT_10118a0c++;
	else { FUNC_1001F3C0(); DAT_10118a0c = 0; }
	if (!*(int*)(*(int*)(m_3de) + 8) || DAT_10118a10 < 6) DAT_10118a10++;
	else { FUNC_10013520(); DAT_10118a10 = 0; }
	if (*(int*)(*(int*)(m_3de) + 0x20)) FUNC_10008200();
}
// .text:10009880 — SEMANTIC TWIN: correct semantics, not byte-verified
// teardown: frees every subsystem object hanging off the net-state struct
extern "C" void __cdecl free(void*);
extern "C" void __cdecl FUNC_1001E8D0();
extern "C" void __cdecl FUNC_10002150();
extern "C" void __cdecl FUNC_100015E0();
extern "C" void __cdecl FUNC_10013410();
extern "C" void __cdecl FUNC_10013160();
extern "C" void __cdecl FUNC_100081C0();
struct CNetState { void *v0; void *m_04; void *m_08; void *m_0c; void *m_10;
	void *m_14; void *m_18; void *m_1c; void *m_20; };
struct CObj_10009880 { char _p[0x3d5]; void *m_3d5; char _q[5]; CNetState *m_3de;
	void Teardown(); };
void CObj_10009880::Teardown() {
	CNetState *s = m_3de;
	if (s->m_1c) { FUNC_1001E8D0(); free(s->m_1c); s->m_1c = 0; }
	if (s->m_14) { FUNC_10002150(); free(s->m_14); s->m_14 = 0; }
	if (s->m_18) { FUNC_100015E0(); free(s->m_18); s->m_18 = 0; }
	if (s->m_08) { FUNC_10013410(); free(s->m_08); s->m_08 = 0; }
	if (s->m_0c) { FUNC_10013160(); free(s->m_0c); s->m_0c = 0; }
	if (s->m_20) { FUNC_100081C0(); free(s->m_20); s->m_20 = 0; }
	if (m_3de) { free(m_3de); m_3de = 0; }
	if (m_3d5) { free(m_3d5); m_3d5 = 0; }
}
// .text:10009A40 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// chat-message packet: decodes sender id + text, forwards to the chat window
extern "C" void __cdecl FUNC_1001F840(...);
extern "C" void __cdecl FUNC_1001F9B0(void *dst, int bits, int n);
extern "C" void __cdecl FUNC_1001FEA0(...);
extern "C" void __cdecl FUNC_100158D0(void *msg);
struct CObj_10009A40 { char _p[0x3cd]; int m_3cd; char _q[0x11]; int m_3de;
	void ChatMsg(int pkt); };
void CObj_10009A40::ChatMsg(int pkt) {
	char msg[0x46];
	unsigned char namelen = 0;
	unsigned short id;
	FUNC_1001F840(*(int*)(pkt + 0x10), *(int*)(pkt + 8), 0);
	if (m_3cd == 5) {
		int *p = (int*)msg;
		for (int i = 0x10; i; i--) *p++ = 0;
		*(short*)p = 0; *((char*)p + 2) = 0;
		FUNC_1001F9B0(&namelen, 8, 1);
		FUNC_1001F9B0(&id, 0x10, 1);
		FUNC_1001FEA0(msg, 0x43);
		int *table = (int*)(*(int*)(m_3de) + 4);
		if (id < 0x3ed) {
			int ent = table[0x1f8a/4 + id];
			if (ent && *(int*)(ent + 0x10)) FUNC_100158D0(msg);
		}
	}
	FUNC_1001F8D0();
}
// .text:10009B40 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// private-message packet: decodes target id + text, forwards to the chat window
extern "C" void __cdecl FUNC_10016370(void *msg);
struct CObj_10009B40 { char _p[0x3cd]; int m_3cd; char _q[0x11]; int m_3de;
	void PrivMsg(int pkt); };
void CObj_10009B40::PrivMsg(int pkt) {
	char msg[316];
	unsigned char flag = 0;
	unsigned short id = 0;
	FUNC_1001F840(*(int*)(pkt + 0x10), *(int*)(pkt + 8), 0);
	if (m_3cd == 5) {
		FUNC_1001F9B0(&flag, 8, 1);
		FUNC_1001F9B0(&id, 0x10, 1);
		FUNC_1001FEA0(msg, 0x28);
		int *table = (int*)(*(int*)(m_3de) + 4);
		if (id < 0x3ec && table[(id & 0xffff) + 0x2a/4]) {
			int ent = table[(id & 0xffff) + 0x1f8a/4];
			if (ent && *(int*)(ent + 0x10)) FUNC_10016370(msg);
		}
	}
	FUNC_1001F8D0();
}
// .text:10009F10 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// player-update burst: reads a bitfield-driven list of sync records
extern "C" void __cdecl FUNC_10014500(int);
extern "C" void __cdecl FUNC_10014540(int,int,int);
struct CObj_10009F10 { char _p[0x3cd]; int m_3cd; char _q[0x11]; int m_3de;
	void SyncBurst(int pkt); };
void CObj_10009F10::SyncBurst(int pkt) {
	unsigned char have = 0;
	int count = 0, i = 0;
	unsigned short id;
	unsigned int bitpos;
	char *mask;
	int limit;
	short a, b, c;
	FUNC_1001F840(*(int*)(pkt + 0x10), *(int*)(pkt + 8), 0);
	if (m_3cd != 5) { FUNC_1001F8D0(); return; }
	FUNC_1001F9B0(&have, 8, 1);
	FUNC_1001F9B0(&count, 0x20, 1);
	int *tab = (int*)(*(int*)(m_3de) + 4);
	char cur = have;
	if (count) {
		do {
			FUNC_1001F9B0(&id, 0x10, 1);
			unsigned int next = bitpos + 1;
			if ((int)next > limit) {
				if (cur) {
					FUNC_1001F9B0(&a, 0x10, 1);
					FUNC_1001F9B0(&b, 0x10, 1);
					FUNC_1001F9B0(&c, 0x10, 1);
				}
			} else {
				int bit = (int)(bitpos & 7);
				if ((mask[bitpos >> 3] & (0x80 >> bit)) == 0) cur = 0;
				else {
					cur = 1;
					FUNC_1001F9B0(&a, 0x10, 1);
					FUNC_1001F9B0(&b, 0x10, 1);
					FUNC_1001F9B0(&c, 0x10, 1);
				}
				bitpos = next;
			}
			if (id < 0x3ec && tab[id * 4 + 0x2a/4]) {
				if (!cur) FUNC_10014500(0);
				else FUNC_10014540(a, b, c);
			}
			i++;
		} while (i != count);
	}
	FUNC_1001F8D0();
}
// .text:1000A100 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// join-ack handler: echoes the server's motd back through the packet writer
extern "C" void __cdecl FUNC_100576F0(char *dst, const char *src);
struct CPktQ_a100 { virtual int v0(); virtual int v1(); virtual int v2();
	virtual int Send(void *pkt, int a, int b, int c); };
struct CObj_1000A100 { CPktQ_a100 *q; char _p[0x3c9]; int m_3cd;
	void JoinAck(int pkt); };
void CObj_1000A100::JoinAck(int pkt) {
	char motd[244], tmp[260], out[276];
	unsigned char hdr[6];
	FUNC_1001F840(*(int*)(pkt + 0x10), *(int*)(pkt + 8), 0);
	hdr[1] = 0;
	if (m_3cd <= 0 || m_3cd >= 7) { FUNC_1001F8D0(); return; }
	hdr[0] = 0;
	FUNC_1001F9B0(hdr + 1, 8, 1);
	FUNC_1001F9B0(hdr, 8, 1);
	FUNC_1001FEA0(tmp, hdr[0]);
	tmp[hdr[0]] = 0;
	FUNC_100576F0(motd, tmp);
	int len = 0; while (motd[len]) len++;
	FUNC_1001F730();
	hdr[0] = 0xc;
	FUNC_1001FFE0(hdr, 8, 1);
	hdr[0] = (unsigned char)len;
	FUNC_1001FFE0(hdr, 8, 1);
	FUNC_10020090(motd, len & 0xff);
	q->Send(out, 0, 8, 0);
	FUNC_1001F8D0();
	FUNC_1001F8D0();
}
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
// .text:1000ACF0 — SEMANTIC TWIN: correct semantics, not byte-verified (register allocation differs)
extern int DAT_1026eb80, DAT_1026eb8c;
extern void __cdecl FUNC_1000680F0(int w, const char *msg);
extern void __stdcall FUNC_100014090(unsigned int i, int a);
extern void __stdcall FUNC_100066560(int a);
struct CObj_1000ACF0 {
	char _p[0x3cd];
	int m_3cd;
	char _q[0x3de - 0x3d1];
	int m_3de;
	void FuncA540();
	void OnLostConnection();
};
struct CHandler_1000ACF0 {
	virtual void Slot0();
	virtual void Slot1();
	virtual void Slot2(int,int);
};
void CObj_1000ACF0::OnLostConnection() {
	CHandler_1000ACF0 *h = *(CHandler_1000ACF0**)this;
	if (h) h->Slot2(0, 0);
	FUNC_1000680F0(DAT_1026eb80, "Lost connection to the server. Reconnecting..");
	FuncA540();
	if (*(int*)(*(int*)((char*)this + 0x3de) + 4)) {
		unsigned short i = 0;
		do {
			if (i < 0x3ec &&
				*(int*)(*(int*)(*(int*)((char*)this + 0x3de) + 4) + 0x2a + i * 4))
				FUNC_100014090(i, 0);
			i++;
		} while (i != 0x3ec);
	}
	if (DAT_1026eb8c) FUNC_100066560(1);
	m_3cd = 1;
}
// .text:1000AD80 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// join-accepted packet: sends client capabilities + version back
extern "C" void __cdecl FUNC_1005FFA0(char *dst, int seed, int n);

struct CPktQ_ad80 {
	virtual int v0(); virtual int v1(); virtual int v2(); virtual int v3();
	virtual int v4(); virtual int v5(); virtual int v6(); virtual int v7();
	virtual int v8(); virtual int v9(); virtual int v10(); virtual int v11();
	virtual int v12(); virtual int v13(); virtual int v14(); virtual int v15();
	virtual int v16(); virtual int v17(); virtual int v18(); virtual int v19();
	virtual int v20(); virtual int v21(); virtual int v22(); virtual int v23();
	virtual int v24();
	virtual int Send(const void *sig, void *pkt, int a, int b, int c, int d); };
struct CObj_1000AD80 { CPktQ_ad80 *q; char _p[0x3cd]; int m_3cd; char _qq[0x11]; int m_3de;
	void Joined(int pkt); };
extern char DAT_100e5b88[];
void CObj_1000AD80::Joined(int pkt) {
	char name[356] = {0};
	char out[276];
	unsigned char fl = 0;
	unsigned int k2 = 0, id = 0, k3 = 0, k1 = 0;
	FUNC_1001F840(*(int*)(pkt + 0x10), *(int*)(pkt + 8), 1);
	FUNC_1001F9B0(&fl, 8, 1);
	FUNC_1001F9B0(&k2, 0x20, 1);
	FUNC_1001F9B0(&id, 0x10, 1);
	FUNC_1001F9B0(&k3, 0x10, 1);
	FUNC_1001F9B0(&k1, 0x20, 1);
	k1 ^= 0xfd9;
	if (g_1026eb80) g_1026eb80->Print("Connected. Joining the game...");
	m_3cd = 6;
	int *tab = (int*)(*(int*)(m_3de) + 4);
	const char *nick = ((unsigned int)tab[0x1e/4] < 0x10)
		? (const char*)(tab + 10/4) : *(const char**)(tab + 10/4);
	int len = 0; while (nick[len]) len++;
	FUNC_1001F730();
	unsigned int v = 0xfd9;
	FUNC_1001FFE0(&v, 0x20, 1);
	unsigned char b = 1;
	FUNC_1001FFE0(&b, 8, 1);
	b = (unsigned char)len;
	FUNC_1001FFE0(&b, 8, 1);
	FUNC_10020090(nick, len & 0xff);
	FUNC_1001FFE0(&k1, 0x20, 1);
	FUNC_1005FFA0(name, 0xc9236c, 0x3e9);
	int nlen = 0; while (name[nlen]) nlen++;
	b = (unsigned char)nlen;
	FUNC_1001FFE0(&b, 8, 1);
	FUNC_10020090(name, nlen & 0xff);
	b = 8;
	FUNC_1001FFE0(&b, 8, 1);
	FUNC_10020090("0.3.7-R5", 8);
	FUNC_1001FFE0(&k1, 0x20, 1);
	q->Send(DAT_100e5b88, out, 1, 8, 0, 0);
	FUNC_1001F8D0();
	FUNC_1001F8D0();
}
// .text:1000B260 — SEMANTIC TWIN: correct semantics, not byte-verified
// main packet pump: pops packets off the queue and dispatches by opcode
extern "C" void __cdecl FUNC_1000A100(int pkt);
extern "C" void __cdecl FUNC_10008DE0(int pkt);
extern "C" void __cdecl FUNC_1000ACF0(int pkt);
extern "C" void __cdecl FUNC_1000AD80(int pkt);
extern "C" void __cdecl FUNC_1000AA10(int pkt);
extern "C" void __cdecl FUNC_10009C40(int pkt);
extern "C" void __cdecl FUNC_10009B40(int pkt);
extern "C" void __cdecl FUNC_1000A740(int pkt);
extern "C" void __cdecl FUNC_10009F10(int pkt);
extern "C" void __cdecl FUNC_10009A40(int pkt);
extern "C" void __cdecl FUNC_10009E20(int pkt);
extern "C" void __cdecl FUNC_10009D30(int pkt);

struct CPktQ_b260 { virtual int Pop(); virtual int v1(); virtual int Close(int,int);
	virtual int v3(); virtual int v4(); virtual int v5(); virtual int v6();
	virtual int v7(); virtual int Release(int); };
struct CObj_1000B260 { CPktQ_b260 *q; char _p[0x3c9]; int m_3cd;
	void Pump(); };
void CObj_1000B260::Pump() {
	int pkt = q->Pop();
	do {
		if (!pkt) return;
		char op = **(char**)(pkt + 0x10);
		if (op == '(') op = (*(char**)(pkt + 0x10))[5];
		switch (op) {
		case 0x0c: FUNC_1000A100(pkt); break;
		case 0x1d: if (g_1026eb80) g_1026eb80->Print("The server didn't respond. Retrying..");
			m_3cd = 1; break;
		case 0x1f: if (g_1026eb80) g_1026eb80->Print("The server is full. Retrying...");
			m_3cd = 1; break;
		case 0x20: FUNC_10008DE0(pkt); break;
		case 0x21: FUNC_1000ACF0(pkt); break;
		case 0x22: FUNC_1000AD80(pkt); break;
		case 0x23: if (g_1026eb80) g_1026eb80->Print("Failed to initialize encryption."); break;
		case 0x24: if (g_1026eb80) g_1026eb80->Print("You are banned from this server."); break;
		case 0x25: if (g_1026eb80) g_1026eb80->Print("Wrong server password.");
			q->Close(0,0); break;
		case -0x38: FUNC_1000AA10(pkt); break;
		case -0x35: FUNC_10009C40(pkt); break;
		case -0x32: FUNC_10009B40(pkt); break;
		case -0x31: FUNC_1000A740(pkt); break;
		case -0x30: FUNC_10009F10(pkt); break;
		case -0x2f: FUNC_10009A40(pkt); break;
		case -0x2e: FUNC_10009E20(pkt); break;
		case -0x2d: FUNC_10009D30(pkt); break;
		}
		q->Release(pkt);
		pkt = q->Pop();
	} while (true);
}
// .text:1000B5B0 — SEMANTIC TWIN: correct semantics, not byte-verified
// per-tick update: pumps packets, syncs state machine, enforces frame pacing
extern "C" void __cdecl FUNC_1000B260();
extern "C" void __cdecl FUNC_1000C4420();
extern "C" int  __cdecl FUNC_1000C46B0(int);
extern "C" int  __cdecl FUNC_1000C4530(int,int,int,int,int,int,int);
extern "C" void __cdecl FUNC_1000A0AB0(unsigned char, unsigned char);
extern "C" void __cdecl FUNC_1000A18A0();
extern "C" void __cdecl FUNC_10006B0D0();
extern "C" void __cdecl FUNC_10008B20();
extern "C" void __cdecl FUNC_1000D920();
extern "C" void __cdecl FUNC_10008A60();
extern "C" void __cdecl FUNC_100089B0();
extern "C" void __cdecl FUNC_10008940();
extern "C" void __cdecl _exit(int);
extern int DAT_1026eb58;
extern int DAT_1026eb98;
struct CObj_1000B5B0 { char _p[0x3cd]; int m_3cd; char _q[8]; int *m_3d5;
	void Update(); };
void CObj_1000B5B0::Update() {
	FUNC_1000C4420();
	int t0 = FUNC_1000C46B0(1);
	FUNC_1000B260();
	char *d5 = (char*)m_3d5;
	if (d5[0x1f]) FUNC_1000A0AB0(d5[0x2c], d5[0x2d]);
	FUNC_1000A18A0();
	if (m_3cd == 5) {
		if (!DAT_1026eb98 || *(char*)(DAT_1026eb98 + 0x221)) {
			if (DAT_1026eb58 && *(int*)(DAT_1026eb58 + 0x30)) FUNC_10006B0D0();
			FUNC_10008B20();
		} else {
			FUNC_1000D920();
			FUNC_10008A60();
		}
	} else {
		FUNC_100089B0();
	}
	if (m_3cd == 1) FUNC_10008940();
	int t1 = FUNC_1000C46B0(0);
	if (t1 - t0 < 1) {
		if (FUNC_1000C4530(0x45,1,6,0xc,0x11,2,0x32) != 0x45) _exit(0);
	}
}
// .text:1000BCE0 — copies a name filtering out punctuation (keeps '.', a-z, A-Z, 0-9)
void __cdecl FUNC_1000BCE0(char *out, int max, const char *in) {
	const char *p = in;
	char c;
	do { c = *p; p++; } while (c);
	int i = 0, n = 0;
	if (p == in + 1) { *out = 0; return; }
	do {
		if (max == 0) break;
		c = in[i];
		if (c == '.' || (c > '`' && c < '{') || (c > '@' && c < '[') || (c > '/' && c < ':')) {
			out[n] = c; max--; n++;
		}
		i++;
	} while (i != (int)(p - (in + 1)));
	out[n] = 0;
}
extern "C" int __cdecl _snprintf(char*, unsigned int, const char*, ...);
extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char*, void*);
extern char * __cdecl FUNC_1000C3AE0();
extern void __cdecl FUNC_1000A7A00();
extern void __cdecl FUNC_1000A7D90();
void __cdecl FUNC_1000BCE0(char *out, int max, const char *in);
extern int __cdecl FUNC_1000B5DC0(const char*);
struct CObj_1000BD60 { char _p[8]; char m_08; char m_dir[0x105]; char m_dir2[0x105];
	char _q[0x4]; int m_213; void EnsureDirs(); };
void CObj_1000BD60::EnsureDirs() {
	if (!m_08) {
		FUNC_1000A7A00();
		FUNC_1000A7D90();
		_snprintf(m_dir2, 0x104, "%s\\local", FUNC_1000C3AE0());
		char tag[0x1c] = {0};
		FUNC_1000BCE0(tag, 0x19, (char*)&DAT_1026eb94 + 0x30);
		_snprintf(m_dir, 0x104, "%s\\%s.%d", FUNC_1000C3AE0(), tag,
			*(int*)((char*)&DAT_1026eb94 + 0x235));
		if (!FUNC_1000B5DC0(m_dir)) CreateDirectoryA(m_dir, 0);
		m_08 = 1;
		m_213 = 2;
	}
}
// .text:1000BF50 — SEMANTIC TWIN: correct semantics, not byte-verified (local register allocation differs)
extern "C" void * __cdecl fwrite(const void*, unsigned int, unsigned int, void*);
extern int __cdecl FUNC_100062E20(int crc, const void *buf, int len);
extern void __cdecl FUNC_10006ACE0(char a, int b, int c, int d, int e, int f, int g);
struct CObj_1000BF50 { char _p[0x222]; void Write(int *info, void *buf, unsigned int len); };
void CObj_1000BF50::Write(int *info, void *buf, unsigned int len) {
	if (!info) info = (int*)((char*)this + 0x222);
	if (info[0]) {
		*(int*)((char*)info + 0xd) = FUNC_100062E20(*(int*)((char*)info + 0xd), buf, len);
		fwrite(buf, 1, len, (void*)info[0]);
		int pos = *(int*)((char*)info + 5);
		pos += (int)len;
		*(int*)((char*)info + 5) = pos;
		if (DAT_1026eb58)
			FUNC_10006ACE0(*(char*)(info + 1), *(int*)((char*)info + 0x11), 1, pos, 0, -1, 0);
	}
}
// .text:1000C460 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// verifies a .txd texture archive; 0 = bad (caller deletes)
extern "C" int  __cdecl FUNC_1000BC740(const char *path);
extern "C" void __cdecl FUNC_1000BC10(unsigned long, unsigned long, unsigned long,
	unsigned long, unsigned char);

int __cdecl FUNC_1000C460(const char *path, unsigned long id) {
	if (!FUNC_1000BC740(path)) {
		if (g_1026eb80)
			g_1026eb80->Print("[warning] Could not verify 0x%X.txd. Error(%d) Deleting..",
				id, 0);
		FUNC_1000BC10(0, 0, 0, 0, 0);
		return 0;
	}
	FUNC_1000BC10(0, 0, 0, 0, 0);
	return 1;
}
// .text:1000C650 — SEMANTIC TWIN: correct semantics, not byte-verified (branch layout differs)
extern "C" int __cdecl sprintf(char*, const char*, ...);
extern int __cdecl FUNC_1000A7BD0(int, int, const char*, const char*, const char*);
struct CObj_1000C650 { char _p[9]; char m_d1[0x105]; char m_d2[0x131];
	char CheckDffTxd(int a2, int a3, unsigned long id4, unsigned long id5); };
char CObj_1000C650::CheckDffTxd(int a2, int a3, unsigned long id4, unsigned long id5) {
	char tag[28], dff[264], txd[264];
	sprintf(tag, "%X", id5);
	sprintf(dff, "%s\\0x%X.dff", m_d1, id4);
	if (!FUNC_1000B5DC0(dff)) {
		sprintf(dff, "%s\\0x%X.dff", m_d2, id4);
		if (!FUNC_1000B5DC0(dff)) return 0;
	}
	sprintf(txd, "%s\\0x%X.txd", m_d1, id5);
	if (!FUNC_1000B5DC0(txd)) {
		sprintf(txd, "%s\\0x%X.txd", m_d2, id5);
		if (!FUNC_1000B5DC0(txd)) return 0;
	}
	return FUNC_1000A7BD0(a2, a3, tag, dff, txd) != 0;
}
// .text:1000C770 — SEMANTIC TWIN: correct semantics, not byte-verified (branch layout differs)
extern int __cdecl FUNC_1000A7C30(int, int, const char*, const char*, const char*);
struct CObj_1000C770 { char _p[9]; char m_d1[0x105]; char m_d2[0x131];
	char CheckDffTxd(int a2, int a3, unsigned long id4, unsigned long id5); };
char CObj_1000C770::CheckDffTxd(int a2, int a3, unsigned long id4, unsigned long id5) {
	char tag[28], dff[264], txd[264];
	sprintf(tag, "%X", id5);
	sprintf(dff, "%s\\0x%X.dff", m_d1, id4);
	if (!FUNC_1000B5DC0(dff)) {
		sprintf(dff, "%s\\0x%X.dff", m_d2, id4);
		if (!FUNC_1000B5DC0(dff)) return 0;
	}
	sprintf(txd, "%s\\0x%X.txd", m_d1, id5);
	if (!FUNC_1000B5DC0(txd)) {
		sprintf(txd, "%s\\0x%X.txd", m_d2, id5);
		if (!FUNC_1000B5DC0(txd)) return 0;
	}
	return FUNC_1000A7C30(a2, a3, tag, dff, txd) != 0;
}
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
struct CDynPool_1000CCC0 { void **m_ppItems; unsigned long m_nItems;
	long FindById(char mode, int id); };
struct CObj_1000CCC0 { void **m_ppItems; unsigned long m_nItems; char m_dir[9];
	char FillDownloadInfo(int a, int b, int *info);
	long FindById(char mode, int id); };
char CObj_1000CCC0::FillDownloadInfo(int a, int b, int *info) {
	long idx = FindById((char)a, b);
	if (idx < 0) return 0;
	char *item;
	if ((unsigned long)idx < m_nItems) item = (char*)m_ppItems[idx]; else item = 0;
	int *p = info;
	for (int i = 0x47; i != 0; i--) *p++ = 0;
	*(short*)p = 0;
	*(unsigned int*)((char*)info + 0x15) = idx;
	info[4] = a & 0xff;
	*(char*)(info + 4) = (char)a;
	*(int*)((char*)info + 5) = 0;
	*(int*)((char*)info + 0xd) = 0;
	if ((char)a == 1) {
		*(int*)((char*)info + 0x11) = *(int*)(item + 0x46);
		*(int*)((char*)info + 9) = *(int*)(item + 0x4e);
	} else if ((char)a == 2) {
		*(int*)((char*)info + 0x11) = *(int*)(item + 0x4a);
		*(int*)((char*)info + 9) = *(int*)(item + 0x52);
	}
	_snprintf((char*)info + 0x19, 0x104, "%s/%05d_%X.temp", m_dir, idx,
		*(int*)((char*)info + 0x11));
	return 1;
}
// .text:1000CE40 — SEMANTIC TWIN: correct semantics, not byte-verified
// counts items whose pending (flag+6==0) request pair still needs one side
struct CDynPool_1000CE40 { void **m_ppItems; unsigned long m_nItems;
	char Check(unsigned int i, int id); };
struct CObj_1000CE40 {
	void **m_ppItems; unsigned long m_nItems;
	char _p[0x20f]; int m_217; char _q[4]; char m_21f;
	int CountNeeds();
};
extern "C" char __cdecl FUNC_1000CDE0(unsigned int, int);
int CObj_1000CE40::CountNeeds() {
	if (!m_21f) return 0;
	unsigned int i = 0; int n = 0;
	if (m_nItems) {
		bool inRange = true;
		do {
			char *p = (i < m_nItems) ? (char*)m_ppItems[i] : 0;
			if ((p[7] == 1 || (p[7] == 2 &&
				(*(int*)(p + 8) == m_217 || *(int*)(p + 8) == -1))) && !p[6]) {
				if (!p[0]) {
					p[2] = 1;
					if (!FUNC_1000CDE0(i, *(int*)(p + 0x46))) n++;
				}
				if (!p[1]) {
					p[3] = 1;
					if (!FUNC_1000CDE0(i, *(int*)(p + 0x4a))) n++;
				}
			}
			i++;
			inRange = i < m_nItems;
		} while (i != m_nItems);
	}
	return n;
}
// .text:1000CF20 — SEMANTIC TWIN: correct semantics, not byte-verified
// sweeps the downloads dir: registers every .dff/.txd pair already on disk
extern "C" __declspec(dllimport) void * __stdcall FindFirstFileA(const char*, void*);
extern "C" __declspec(dllimport) int  __stdcall FindNextFileA(void*, void*);
extern "C" __declspec(dllimport) int  __stdcall FindClose(void*);
struct CObj_1000CF20 { char _p[9]; char m_dir[0x200];
	int Check1(void*); int Check2(void*); char Check3(int); void Mark(int);
	void Sweep(); };
void CObj_1000CF20::Sweep() {
	char pat1[264], pat2[264], pat3[264], fd[0x250];
	_snprintf(pat1, 0x104, "%s\\*", m_dir);
	_snprintf(pat2, 0x104, "%s\\*", m_dir);
	_snprintf(pat3, 0x104, "%s\\*", m_dir);
	void *h = FindFirstFileA(pat1, fd);
	if (h != (void*)-1) {
		do {
			if (!(*(char*)(fd) & 0x10)) Check1(fd);
		} while (FindNextFileA(h, fd));
		FindClose(h);
	}
	h = FindFirstFileA(pat2, fd);
	if (h != (void*)-1) {
		do {
			if (!(*(char*)(fd) & 0x10)) {
				int e = Check2(fd);
				if (e && !Check3(e)) Mark(e);
			}
		} while (FindNextFileA(h, fd));
		FindClose(h);
	}
}
// .text:1000D080 — SEMANTIC TWIN: correct semantics, not byte-verified
// sweeps the pool and downloads both files of every pending item pair
extern "C" char __cdecl FUNC_1000BE30(...);
extern "C" char __cdecl FUNC_1000BEC0(...);
extern "C" int __cdecl FUNC_1000D0D0(unsigned long);
extern "C" int __cdecl FUNC_1000D0E9(unsigned long);
struct CObj_1000D080 {
	void **m_ppItems; unsigned long m_nItems;
	char _p[0x20f]; int m_217; char _q[4]; char m_21f;
	void DownloadPending();
};
void CObj_1000D080::DownloadPending() {
	if (!m_21f) return;
	unsigned int i = 0;
	if (m_nItems) {
		do {
			char *p = (i < m_nItems) ? (char*)m_ppItems[i] : 0;
			if (p[7] == 1 || (p[7] == 2 &&
				(*(int*)(p + 8) == m_217 || *(int*)(p + 8) == -1))) {
				if (!p[0] && FUNC_1000D0D0(*(unsigned long*)(p + 0x46))) p[0] = 1;
				if (!p[1] && FUNC_1000D0E9(*(unsigned long*)(p + 0x4a))) p[1] = 1;
			}
			i++;
		} while (i != m_nItems);
	}
}
// .text:1000D500 — SEMANTIC TWIN: correct semantics, not byte-verified
// streams a chunk of a download into the 0x340-byte write buffer and flushes it
struct CObj_1000D500 { char _p[0x340]; char m_buf[0x1000]; int m_used;
	void Feed(char kind, unsigned int seq, const void *data, unsigned int len); };
void CObj_1000D500::Feed(char kind, unsigned int seq, const void *data, unsigned int len) {
	char hdr[12] = {0x5d, 0, 0, 1, 0};
	*(int*)(hdr + 8) = 0x1000;
	if (seq >= 0x1001) return;
	int *used = (int*)((char*)this + 0x1340);
	if (*used + len >= 0x1001) {
		// would overflow the staging buffer — flush through the packet path
		Feed(kind, seq, data, len);
		return;
	}
	char *dst = (char*)this + 0x340 + *used;
	const unsigned int *src = (const unsigned int*)data;
	for (unsigned int i = len >> 2; i; i--) *(unsigned int*)dst = *src, src++, dst += 4;
	for (unsigned int i = len & 3; i; i--) *dst++ = *(const char*)src, src = (const unsigned int*)((const char*)src + 1);
	*used += len;
}
// .text:1000D650 — SEMANTIC TWIN: correct semantics, not byte-verified
// accepts a redirect: builds the temp-file name, starts writing the download
extern void * __cdecl FUNC_1000C7F49(char *path, const char *mode);
extern char m_100e5d34[];


struct CObj_1000D650 {
	char m_dir[9];
	char FillDownloadInfo(int a, int b, int *info);
	void WriteChunk(int *info, const void *data);
	int PendingCount();
	char _p[0x204]; int m_213; char _q[0x1125]; int m_1340;
	void Redirect(int a, int b, const void *data);
};
void CObj_1000D650::Redirect(int a, int b, const void *data) {
	int info[0x50];
	if (!FillDownloadInfo(a, b, info)) {
		if (g_1026eb80) g_1026eb80->Print("DownloadRedirect: Can't fill download info!");
		return;
	}
	*(int*)((char*)this + 0x1340) = 0;
	info[0] = (int)FUNC_1000C7F49((char*)info + 0x19, m_100e5d34);
	if (!info[0]) {
		if (g_1026eb80) g_1026eb80->Print("DownloadRedirect: Can't open temp file for writing!");
		return;
	}
	WriteChunk(info, data);
	if (g_1026eb58)
		g_1026eb58->Notify(info[4], info[8], 0, 0, info[5], -1, 0);
	*(int*)((char*)this + 0x213) = 1;
	if (PendingCount() > 0) *(int*)((char*)this + 0x213) = 2;
}
// .text:1000D800 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// sends a file-request packet for one side of a pending item

struct CObj_B4 { int Send(const char *fmt, void *buf, int a, int b, int c, int d); };
extern CObj_B4 *g_1026eb94;
extern int __cdecl FUNC_10006A870(int n);
extern void __cdecl FUNC_10001F730();
extern void __cdecl FUNC_10001FFE0(void *buf, int size, int n);
extern void __cdecl FUNC_10001F8D0();
extern void __cdecl FUNC_10000C0F0();
extern "C" int __cdecl FUNC_1000CE40(...);
extern char s_100e5d90[], s_100e5d8c[];
struct CObj_1000D800 { char _p[0x213]; int m_213;
	int Request(int a, char mode, int b); };
int CObj_1000D800::Request(int a, char mode, int b) {
	char buf[0x120];
	if (!g_1026eb94) return 0;
	if (!*(int*)((char*)g_1026eb58 + 0x30))
		FUNC_10006A870(FUNC_1000CE40());
	FUNC_10001F730();
	int arg = b;
	FUNC_10001FFE0(&arg, 0x20, 1);
	if (mode == 1) (*(CObj_B4**)g_1026eb94)->Send(s_100e5d90, buf, 1, 9, 0, 0);
	else if (mode == 2) (*(CObj_B4**)g_1026eb94)->Send(s_100e5d8c, buf, 1, 9, 0, 0);
	m_213 = 1;
	FUNC_10000C0F0();
	FUNC_10001F8D0();
	return 1;
}
// .text:1000D920 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// download pump: issues file-requests for pending items, then sends done-marker
extern "C" char __cdecl FUNC_1000CB70(int id);
extern "C" char __cdecl FUNC_1000CBB0(int id);
extern "C" char __cdecl FUNC_1000C190();
extern "C" void __cdecl FUNC_1001FF30(void*, int);
extern char s_100e5d94[];

struct CObj_1000D920 {
	void **m_ppItems; unsigned long m_nItems;
	char _p[0x213]; int m_213; char _q[8]; char m_21f;
	char _r[0x4b4]; char m_534;
	int Request(unsigned int idx, char mode, int id, int extra);
	void Pump();
};
void CObj_1000D920::Pump() {
	if (m_213 != 2 || m_534 || !m_21f) return;
	if (m_534 != 0) {
		// (unreachable twin of the outer check kept for readability)
	} else if (!FUNC_1000C190()) return;
	unsigned int i = 0;
	if (m_nItems) {
		bool in = m_nItems != 0;
		do {
			if (in) {
				char *p = (i < m_nItems) ? (char*)m_ppItems[i] : 0;
				if (p && p[6] != 1 &&
					(p[7] == 1 || (p[7] == 2 &&
						(*(int*)(p + 8) == *(int*)((char*)this + 0x217) ||
						 *(int*)(p + 8) == -1)))) {
					if (!p[0]) {
						if (FUNC_1000BE30(*(int*)(p + 0x46))) p[0] = 1;
						else if (!FUNC_1000CB70(*(int*)(p + 0x46))) {
							Request(i, 1, *(int*)(p + 0x46), *(int*)(p + 0x4e));
							p[4] = 1;
							return;
						}
					}
					if (!p[1]) {
						if (FUNC_1000BEC0(*(int*)(p + 0x4a))) p[1] = 1;
						else if (!FUNC_1000CBB0(*(int*)(p + 0x4a))) {
							Request(i, 2, *(int*)(p + 0x4a), *(int*)(p + 0x52));
							p[5] = 1;
							return;
						}
					}
				}
			}
			i++;
			in = i < m_nItems;
		} while (i != m_nItems);
	}
	if (m_21f && FUNC_1000CE40() < 1) {
		*(char*)((char*)this + 0x220) = 1;
		FUNC_1001F730();
		char pkt[276];
		FUNC_1001FF30(pkt, 276);
		if (g_1026eb94) g_1026eb94->Send(s_100e5d94, pkt, 1, 9, 0, 0);
		FUNC_1001F8D0();
	}
}
// .text:1000DBB0 — SEMANTIC TWIN: correct semantics, not byte-verified
struct CMini_1000DBB0 { void **items; unsigned int n; void SetSizeA(int n); void SetSizeB(int n); };
struct CRec_1000DBB0 {
	char _p[0x4c];
	void Cleanup();
};
void CRec_1000DBB0::Cleanup() {
	if (*(void**)((char*)this + 0x48)) { free(*(void**)((char*)this + 0x48)); *(int*)((char*)this + 0x48) = 0; }
	if (*(void**)((char*)this + 0x44)) { free(*(void**)((char*)this + 0x44)); *(int*)((char*)this + 0x44) = 0; }
	if (*(void**)((char*)this + 0x28)) { free(*(void**)((char*)this + 0x28)); *(int*)((char*)this + 0x28) = 0; }
	if (*(void**)((char*)this + 0x24)) { free(*(void**)((char*)this + 0x24)); *(int*)((char*)this + 0x24) = 0; }
	if (*(void**)((char*)this + 0x1c)) { free(*(void**)((char*)this + 0x1c)); *(int*)((char*)this + 0x1c) = 0; }
	if (*(void**)((char*)this + 0x20)) { free(*(void**)((char*)this + 0x20)); *(int*)((char*)this + 0x20) = 0; }
	if (*(void**)((char*)this + 0x79)) { free(*(void**)((char*)this + 0x79)); *(int*)((char*)this + 0x79) = 0; }
	if (*(void**)((char*)this + 0x7d)) { free(*(void**)((char*)this + 0x7d)); *(int*)((char*)this + 0x7d) = 0; }
	if (*(void**)((char*)this + 0x81)) { free(*(void**)((char*)this + 0x81)); *(int*)((char*)this + 0x81) = 0; }
	if (*(void**)((char*)this + 0x85)) { free(*(void**)((char*)this + 0x85)); *(int*)((char*)this + 0x85) = 0; }
	if (*(void**)((char*)this + 0x95)) { free(*(void**)((char*)this + 0x95)); *(int*)((char*)this + 0x95) = 0; }
	if (*(void**)((char*)this + 0x99)) { free(*(void**)((char*)this + 0x99)); *(int*)((char*)this + 0x99) = 0; }
	if (*(void**)((char*)this + 0x9d)) { free(*(void**)((char*)this + 0x9d)); *(int*)((char*)this + 0x9d) = 0; }
	CMini_1000DBB0 *m = (CMini_1000DBB0*)((char*)this + 0x58);
	unsigned int n = m->n, i = 0;
	if (n) {
		do {
			if (i < m->n) {
				void *p = m->items[i];
				if (p) free(p);
			}
			i++;
		} while (i != n);
	}
	m = (CMini_1000DBB0*)((char*)this + 0x6d); n = m->n; i = 0;
	if (n) {
		do {
			if (i < m->n) {
				void *p = m->items[i];
				if (p) {
					if (*(void**)((char*)p + 8)) { free(*(void**)((char*)p + 8)); *(int*)((char*)p + 8) = 0; }
					free(p);
				}
			}
			i++;
		} while (i != n);
	}
	void *p = *(void**)((char*)this + 0x4c);
	if (p) {
		if (*(char*)((char*)p + 0x19) && *(void**)((char*)p + 0xc)) {
			free(*(void**)((char*)p + 0xc)); *(int*)((char*)p + 0xc) = 0;
		}
		free(p);
		*(int*)((char*)this + 0x4c) = 0;
	}
	p = *(void**)((char*)this + 0x50);
	if (p) {
		if (*(char*)((char*)p + 0x19) && *(void**)((char*)p + 0xc)) {
			free(*(void**)((char*)p + 0xc)); *(int*)((char*)p + 0xc) = 0;
		}
		free(p);
		*(int*)((char*)this + 0x50) = 0;
	}
	m->SetSizeA(0);
	((CMini_1000DBB0*)((char*)this + 0x58))->SetSizeB(0);
}
// .text:1000DE80 — SEMANTIC TWIN: correct semantics, not byte-verified
struct CRec_1000DE80_de80;
struct CMini_1000DE80 { CRec_1000DE80_de80 **items; int n; void SetSize(int n); };
struct CRec_1000DE80_de80 {
	void Cleanup();
	void SubCleanup();
};
void CRec_1000DE80_de80::SubCleanup() {
	void *p = *(void**)((char*)this + 0x40);
	if (p) {
		if (*(char*)((char*)p + 0x19) && *(void**)((char*)p + 0xc)) {
			free(*(void**)((char*)p + 0xc)); *(int*)((char*)p + 0xc) = 0;
		}
		free(p); *(int*)((char*)this + 0x40) = 0;
	}
	p = *(void**)((char*)this + 0x3c);
	if (p) {
		if (*(char*)((char*)p + 0x19) && *(void**)((char*)p + 0xc)) {
			free(*(void**)((char*)p + 0xc)); *(int*)((char*)p + 0xc) = 0;
		}
		free(p); *(int*)((char*)this + 0x3c) = 0;
	}
	p = *(void**)((char*)this + 0x38);
	if (p) {
		if (*(char*)((char*)p + 0x19) && *(void**)((char*)p + 0xc)) {
			free(*(void**)((char*)p + 0xc)); *(int*)((char*)p + 0xc) = 0;
		}
		free(p); *(int*)((char*)this + 0x38) = 0;
	}
	p = *(void**)((char*)this + 0x34);
	if (p) {
		if (*(char*)((char*)p + 0x19) && *(void**)((char*)p + 0xc)) {
			free(*(void**)((char*)p + 0xc)); *(int*)((char*)p + 0xc) = 0;
		}
		free(p); *(int*)((char*)this + 0x34) = 0;
	}
	p = *(void**)((char*)this + 0x30);
	if (p) {
		if (*(char*)((char*)p + 0x19) && *(void**)((char*)p + 0xc)) {
			free(*(void**)((char*)p + 0xc)); *(int*)((char*)p + 0xc) = 0;
		}
		free(p); *(int*)((char*)this + 0x30) = 0;
	}
	p = *(void**)((char*)this + 0x2c);
	if (p) {
		if (*(char*)((char*)p + 0x19) && *(void**)((char*)p + 0xc)) {
			free(*(void**)((char*)p + 0xc)); *(int*)((char*)p + 0xc) = 0;
		}
		free(p); *(int*)((char*)this + 0x2c) = 0;
	}
	if (*(void**)((char*)this + 0x48)) { free(*(void**)((char*)this + 0x48)); *(int*)((char*)this + 0x48) = 0; }
	CMini_1000DE80 *m = (CMini_1000DE80*)((char*)this + 0x24);
	int n = m->n; unsigned int i = 0;
	if (0 < n) {
		do {
			if (i < (unsigned int)m->n) {
				CRec_1000DE80_de80 *p2 = m->items[i];
				if (p2) { p2->Cleanup(); free(p2); }
			}
			i++;
		} while ((int)i < n);
	}
	m->SetSize(0);
	m->SetSize(0);
	if (*(char*)((char*)this + 0x15) && *(void**)((char*)this + 8)) {
		free(*(void**)((char*)this + 8)); *(int*)((char*)this + 8) = 0;
	}
}
// .text:1000E010 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// validates a downloaded .dff via the GTA model loader; 0 = bad (caller deletes)
extern "C" int  __cdecl FUNC_1000B9920(const char *path);
extern "C" int  __cdecl FUNC_1000B9FF0(unsigned long, unsigned long, unsigned long,
	unsigned long, unsigned long, unsigned char);
extern "C" int  __cdecl FUNC_1000BA3C0();
extern "C" void __cdecl FUNC_1000DE80();

int __cdecl FUNC_1000E010(const char *path, unsigned long id) {
	if (!FUNC_1000B9920(path)) {
		if (g_1026eb80)
			g_1026eb80->Print("[warning] Could not validate 0x%X.dff. Error(%d) Deleting..",
				id, 0);
		FUNC_1000DE80();
		return 0;
	}
	if (FUNC_1000B9FF0(0, 0, 0, 0, 0, 0) && FUNC_1000BA3C0()) {
		FUNC_1000DE80();
		return 1;
	}
	if (g_1026eb80)
		g_1026eb80->Print("[warning] Could not validate 0x%X.dff. Error(%d:0x%X) Deleting..",
			id, 0, 0);
	FUNC_1000DE80();
	return 0;
}
// .text:1000E160 — SEMANTIC TWIN: correct semantics, not byte-verified
// finishes a pending download slot: validates, installs (.dff/.txd), notifies
extern "C" int  __cdecl _snprintf(char*, unsigned int, const char*, ...);
extern "C" __declspec(dllimport) int  __stdcall MoveFileA(const char*, const char*);
extern "C" __declspec(dllimport) int  __stdcall DeleteFileA(const char*);
int __cdecl FUNC_1000E010(const char *path, unsigned long id);
int __cdecl FUNC_1000C460(const char *path, unsigned long id);

struct CDlInfo { int fd; char mode; int recvd; int total; int id; int size;
	char path[0x104]; unsigned int slot; };
struct CObj_1000E160 {
	void **m_ppItems; unsigned long m_nItems;
	char _p[9]; char m_dir[0x205]; int m_213;
	void Finish(CDlInfo *info);
};
void CObj_1000E160::Finish(CDlInfo *info) {
	if (!info) info = (CDlInfo*)((char*)this + 0x222);
	char *p = 0;
	if (info->slot < m_nItems) p = (char*)m_ppItems[info->slot];
	if (info->fd) { /* fclose */ info->fd = 0; }
	if (info->recvd != info->total || info->total != info->id) { }
	if (info->mode == 1) {
		if (!FUNC_1000E010(info->path, info->id)) {
			DeleteFileA(info->path);
			p[6] = 1;
			if (g_1026eb58)
				g_1026eb58->Notify(info->mode, info->id, 3, info->recvd, 0, 0x66, 0);
			m_213 = 2;
			return;
		}
	} else if (info->mode == 2) {
		if (!FUNC_1000C460(info->path, info->id)) {
			DeleteFileA(info->path);
			p[6] = 1;
			if (g_1026eb58)
				g_1026eb58->Notify(info->mode, info->id, 3, info->recvd, 0, 0x67, 0);
			m_213 = 2;
			return;
		}
	} else {
		DeleteFileA(info->path);
		p[6] = 1;
		if (g_1026eb58)
			g_1026eb58->Notify(info->mode, info->id, 3, info->recvd, 0, 0x68, 0);
		m_213 = 2;
		return;
	}
	char dst[264];
	if (info->mode == 1) _snprintf(dst, 0x104, "%s/0x%X.dff", m_dir - 4, info->id);
	else if (info->mode == 2) _snprintf(dst, 0x104, "%s/0x%X.txd", m_dir - 4, info->id);
	MoveFileA(info->path, dst);
	if (info->mode == 1) p[0] = 1; else if (info->mode == 2) p[1] = 1;
	if (g_1026eb58)
		g_1026eb58->Notify(info->mode, info->id, 4, info->recvd, 0, -1, 0);
	m_213 = 2;
}
// .text:1000FCE0 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// handles an incoming chat/name packet: decodes fields, fires join hooks
extern "C" void __cdecl FUNC_10014250(unsigned short id, const char *name, int flag);
extern "C" void __cdecl FUNC_10016150(int arg);
void __cdecl FUNC_1000FCE0(int *pkt) {
	char name[260] = {0};
	unsigned char namelen = 0;
	char flag = 0;
	unsigned int arg = 0;
	unsigned short id;
	int extra[71];
	FUNC_1001F840((void*)*pkt, ((pkt[1] + ((pkt[1] >> 31) & 7u)) >> 3) + 1, 0);
	int *table = (int*)(*(int*)(DAT_1026eb94 + 0x3de) + 4);
	FUNC_1001F9B0(&id, 0x10, 1);
	FUNC_1001F9B0(extra, 0x20, 1);
	FUNC_1001F9B0(&flag, 8, 1);
	FUNC_1001F9B0(&namelen, 8, 1);
	FUNC_1001FEA0(name, namelen);
	name[namelen] = 0;
	int len = 0; while (name[len]) len++;
	if ((unsigned int)len < 0x19) {
		int a = flag ? 1 : arg;
		FUNC_10014250(id, name, a);
		if (extra[0] && id < 0x3ec && table[(id & 0xffff) * 4 + 0x2a/4 + 0x2a])
			FUNC_10016150(extra[0]);
	}
	FUNC_1001F8D0();
}
// .text:10010660 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// world-init packet: fills the client's persistent config block from the stream
extern "C" void __cdecl FUNC_10008420(...);
void __cdecl FUNC_10010660(int *pkt) {
	char buf[212], cfg[280];
	unsigned short id;
	FUNC_1001F840(*pkt, (pkt[1] + ((pkt[1] >> 31) & 7u)) / 8 + 1, 0);
	int *d5 = (int*)(DAT_1026eb94 + 0x3d5);
	FUNC_10008420((char*)d5 + 0x21);
	FUNC_10008420((void*)*d5);
	FUNC_10008420((char*)d5 + 0x15);
	FUNC_10008420((char*)d5 + 0x39);
	FUNC_1001F9B0((char*)d5 + 0x34, 0x20, 1);
	FUNC_10008420(cfg);
	FUNC_1001F9B0((char*)d5 + 0x27, 0x20, 1);
	FUNC_10008420((char*)d5 + 0x1a);
	FUNC_10008420((char*)d5 + 0x2f);
	*(char*)((char*)d5 + 0x2f) = 1;
	FUNC_10008420((char*)d5 + 0x2b);
	FUNC_1001F9B0((char*)d5 + 0x23, 0x20, 1);
	FUNC_1001F9B0(&id, 0x10, 1);
	FUNC_10008420((char*)d5 + 0x38);
	FUNC_1001F8D0();
}
// .text:10010B00 — SEMANTIC TWIN: correct semantics, not byte-verified (SEH frame)
// spawn-player packet: decodes id/name/team and calls the spawn hook
extern "C" int  __cdecl FUNC_10017130(int,int,int,int,int,int,int);

void __cdecl FUNC_10010B00(int *pkt) {
	unsigned short id;
	unsigned char team;
	int skin, w1, w2, w3, f1, f2, cnt;
	unsigned short name[75];
	char tab[4];
	FUNC_1001F840(*pkt, (pkt[1] + ((pkt[1] >> 31) & 7u)) / 8 + 1, 0);
	int *t = (int*)(*(int*)(DAT_1026eb94 + 0x3de) + 4);
	cnt = 4; team = 0; skin = 0; f2 = 0;
	FUNC_1001F9B0(&id, 0x10, 1);
	FUNC_1001F9B0(&team, 8, 1);
	FUNC_1001F9B0(&skin, 0x20, 1);
	FUNC_1001F9B0(&w1, 0x20, 1);
	FUNC_1001F9B0(&w2, 0x20, 1);
	FUNC_1001F9B0(&w3, 0x20, 1);
	FUNC_1001F9B0(&f1, 0x20, 1);
	FUNC_1001F9B0(&f2, 0x20, 1);
	FUNC_1001F9B0(&cnt, 8, 1);
	FUNC_1001FEA0(name, 0x16);
	if (t && id < 0x3ec && t[id + 0x2a/4]) {
		int e = t[(id & 0xffff) + 0x1f8a/4];
		if (e && *(int*)(e + 0x10)) {
			if (!FUNC_10017130(team, skin, 0, w1, f1, f2, cnt)) {
				if (g_1026eb80)
					g_1026eb80->Print("Warning: Couldn't spawn player(%u)", id & 0xffff);
			}
		}
	}
	FUNC_1001F8D0();
}
// .text:10012BD0 — SEMANTIC TWIN: correct semantics, not byte-verified
// gathers the visible actors within range, sorted by distance (bubble pass)
struct CObj_10012BD0 { int m_n; int m_tab[0x3e9];
	void Collect(); };
void CObj_10012BD0::Collect() {
	float dist[1000] = {0};
	int slot[1001] = {0};
	int n = 0;
	if (m_n >= 0) {
		int *pi = m_tab;
		for (int i = 0; i <= m_n; i++) {
			if (pi[i] && n < 1000) {
				int e = pi[i];
				if (*(char*)(e + 0x49) && *(char*)(e + 0x6c)) {
					slot[n] = e;
					dist[n] = (float)FUNC_1009F190();
					n++;
				}
			}
		}
	}
	for (int e = n - 1; e > 0; e--) {
		if (e > 3) {
			for (int i = 0; i < e - 1; i++) {
				if (dist[i] < dist[i + 1]) {
					float t = dist[i]; dist[i] = dist[i + 1]; dist[i + 1] = t;
					int s = slot[i]; slot[i] = slot[i + 1]; slot[i + 1] = s;
				}
			}
		}
	}
}
// .text:10012E70 — SEMANTIC TWIN: correct semantics, not byte-verified
// picks the actor whose bounding sphere a LOS ray passes nearest
extern float DAT_10118a28[], DAT_10118a34[], DAT_10118a3c[], DAT_10118a48[];
extern void __cdecl FUNC_10012500(int,int);
struct CObj_10012E70 { int m_n; int m_tab[0x3e9];
	int Pick(float range, float *from, float *to); };
int CObj_10012E70::Pick(float range, float *from, float *to) {
	int *self = &m_n;
	DAT_10118a3c[0] = from[0]; DAT_10118a3c[1] = from[1]; DAT_10118a3c[2] = from[2];
	DAT_10118a28[0] = to[0]; DAT_10118a28[1] = to[1]; DAT_10118a28[2] = to[2];
	DAT_10118a48[0] = 0.25f; DAT_10118a48[1] = 0.0f;
	DAT_10118a34[0] = 0.25f; DAT_10118a34[1] = 0.0f;
	unsigned short best = 0xffff;
	int *pi = self + 0x3e9;
	if (*self >= 0) {
		for (int i = 0; i <= *self; i++) {
			if (pi[i - 0x3e9]) {
				int e = pi[i];
				if (e) FUNC_10012500(i, e);
			}
		}
	}
	return best;
}
