// w4 scratch batch 16 - large game funcs (semantic twins)
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" int __cdecl FUNC_1009F3D0(void);
extern "C" void __cdecl FUNC_1009F040(void);
extern "C" void __cdecl FUNC_1009EB10(void *);
extern "C" void __cdecl FUNC_1009EBC0(void);
extern "C" void __cdecl FUNC_1009EC80(void);
extern "C" int __cdecl FUNC_100B4100(int);
extern "C" int __cdecl FUNC_100B4180(int);
extern "C" int __cdecl FUNC_100AEBB0(int);
extern "C" void __cdecl FUNC_100B57E0(int, int, int, int);
extern "C" void __cdecl FUNC_100B58A0(int, int *, float *);
extern "C" int __cdecl FUNC_100B2310(void *, int, ...);
extern "C" int __cdecl FUNC_100B3C30(int);
extern "C" int __cdecl FUNC_100AEEB0(int);
extern "C" void __cdecl FUNC_100AEE50(int);
extern "C" int __cdecl FUNC_1000D110(int);
extern "C" int __cdecl FUNC_1000D150(int);
extern "C" int __cdecl FUNC_1000D190(int);
extern "C" int __cdecl FUNC_1000D2C0(int);
extern "C" int __cdecl FUNC_1000D320(int);
extern "C" int __cdecl FUNC_100B3DD0(int);
extern "C" int __cdecl FUNC_100B3DB0(int);
extern "C" int __cdecl FUNC_100B4570(int);
extern "C" int __cdecl FUNC_1006C9B0(int, int, int, int);
extern "C" int __cdecl FUNC_1006C3C0(int, int, int, int, int, int);
extern "C" int __cdecl FUNC_1006C140(int, int, int, int);
extern "C" long long __cdecl FUNC_100B2B20(void);
extern "C" void *__cdecl FUNC_100A9110(int, int, int, int, int, int, int, int, int, int, int);
extern "C" void __cdecl FUNC_100A8530(int, int, int, int, int);
extern "C" void __cdecl FUNC_1009F630(int);
extern "C" void *__cdecl operator_new(unsigned);
extern "C" void __cdecl _free(void *);
extern "C" void *__cdecl _calloc(unsigned, unsigned);
extern "C" void __cdecl FUNC_100BA7D0(void *, int);
extern "C" int __cdecl FUNC_100B2C60(char *, char *);
extern "C" int __cdecl FUNC_100A7A40(int);
extern "C" int __cdecl FUNC_100B41F0(float *);
extern "C" float flt_100e5b2c;
extern "C" float flt_100e5814;
extern "C" float flt_100e6400;
extern "C" float flt_100ec314;
extern "C" float flt_100ed2b8;
extern "C" float flt_100ed2b4;
extern "C" float flt_100ea16c;
extern "C" float flt_100ed2b0;
extern "C" DWORD DAT_1026eb98;
extern "C" DWORD DAT_1026b568[];
extern "C" DWORD DAT_100ece98;
extern "C" DWORD DAT_100ed12c;
extern "C" DWORD DAT_100ed210;
extern "C" DWORD DAT_101172c4;
extern "C" char DAT_1026dfc0;
extern "C" DWORD DAT_100e6128;
extern "C" DWORD DAT_100e6124;

// --- @ 0xB0760 (842): ped-bone drive / land-animation controller ---
struct s0760 {
	char _0[0x2a4];
	int f_2A4;
	char _2A8[0x20];
	void FUNC_100B0760();
};
static int BoneEnt(s0760 *s)
{
	int *p = *(int **)&s->f_2A4;
	if (!p || *p == 0x863c40 || !p[6])
		return 0;
	return p[6];
}
void s0760::FUNC_100B0760()
{
	float ang = 0.f;
	for (DWORD *b = &DAT_101172c4; (int)b < 0x10117378; b += 5) {
		int e = BoneEnt(this);
		if (!e)
			continue;
		int skel = ((int(__cdecl *)(int))0x734a40)(e);
		DWORD *bone = (DWORD *)(*(int *)(*(int *)(skel + 0x20) + 0x24) * b[-1]
			+ 0x4c + *(int *)(skel + 0x20));
		if (bone) {
			bone[0] = b[0];
			bone[1] = b[1];
			bone[2] = b[2];
			bone[3] = b[3];
		}
	}
	if (BoneEnt(this)) {
		int e = BoneEnt(this);
		int skel = ((int(__cdecl *)(int))0x734a40)(e);
		int b = *(int *)(skel + 0x20) + 0x4c;
		if (b) {
			DWORD p2[2] = {0, 0};
			float out;
			FUNC_100B58A0(b, (int *)p2, &out);
			ang = flt_100e5b2c - out;
		}
	}
	int f2a4 = f_2A4;
	int mdl = 0;
	if (f2a4) {
		mdl = FUNC_100B4100(*(unsigned short *)(f2a4 + 0x22));
		if (mdl == 5 || mdl == 0x16) {
			int e = BoneEnt(this);
			if (e) {
				int skel = ((int(__cdecl *)(int))0x734a40)(e);
				int b = *(int *)(*(int *)(skel + 0x20) + 0x24) * 9 + 0x4c
					+ *(int *)(skel + 0x20);
				if (b) {
					FUNC_100B57E0(b, 1, 0xc0c80000, 1);
					FUNC_100B57E0(b, 0, 0x41480000, 1);
				}
				int b2 = *(int *)(*(int *)(skel + 0x20) + 0x24) * 0xf + 0x4c
					+ *(int *)(skel + 0x20);
				if (b2) {
					FUNC_100B57E0(b2, 1, 0x40c80000, 1);
					FUNC_100B57E0(b2, 0, 0xc1480000, 1);
				}
			}
			goto done;
		}
	}
	if (f2a4 && FUNC_100B4180(*(unsigned short *)(f2a4 + 0x22)) == 0x7c) {
		int h = FUNC_100AEBB0(9);
		if (h) {
			FUNC_100B57E0(h, 1, 0x41200000, 1);
			FUNC_100B57E0(h, 0, 0x41c80000, 1);
		}
		h = FUNC_100AEBB0(0xf);
		if (h) {
			FUNC_100B57E0(h, 1, 0xc1200000, 1);
			FUNC_100B57E0(h, 0, 0xc1c80000, 1);
		}
	} else {
		ang = ang + flt_100ec314;
		int h = FUNC_100AEBB0(9);
		if (h) {
			FUNC_100B57E0(h, 1, (int)(ang * flt_100ed2b8), 1);
			FUNC_100B57E0(h, 0, (int)(ang * flt_100ed2b4), 1);
		}
		h = FUNC_100AEBB0(0xf);
		if (h) {
			FUNC_100B57E0(h, 1, (int)(ang * flt_100ea16c), 1);
			FUNC_100B57E0(h, 0, (int)(ang * flt_100ed2b0), 1);
		}
	}
done:
	if (f_2A4)
		((void(__cdecl *)())0x532b20)();
}

// --- @ 0xB0B10 (464): per-slot object spawn (SEH-wrapped operator_new) ---
struct s0B10 {
	char _0[0x4c];
	int f_4C[10];
	char _74[0x34 * 10];
	int f_27C[10];
	int f_2A4;
	void FUNC_100B0B10(int, int *);
};
void s0B10::FUNC_100B0B10(int slot, int *rec)
{
	int *root = (int *)f_2A4;
	if (!root || *root == 0x863c40 || !root[6])
		return;
	if (slot < 0 || slot >= 10)
		return;
	if (rec[1] <= 0 || rec[1] >= 0x13)
		return;
	int a = FUNC_100AEEB0(slot);
	if (a)
		FUNC_100AEE50(slot);
	char m[48];
	FUNC_1009EB10(m);
	int *entry = (int *)((char *)this + 0x74 + slot * 0x34);
	for (int i = 0; i < 0xd; i++)
		entry[i] = rec[i];
	if (entry[0] < 0 && DAT_1026eb98) {
		if (!FUNC_1000D150(entry[0]) && !FUNC_1000D190(entry[0])
			&& !FUNC_1000D320(entry[0]))
			entry[0] = 0x48c7;
	}
	void *nv = operator_new(0x119c);
	if (nv) {
		DWORD ex[3];
		FUNC_100A9110(entry[0], ex[0], ex[1], ex[2],
			*(int *)((char *)entry + 0x14), *(int *)((char *)entry + 0x18),
			*(int *)((char *)entry + 0x1c), 0x43480000, 1, 0, 0);
		f_27C[slot] = (int)nv;
	}
	if (rec[0xb])
		FUNC_100A8530(-1, 0, 0, 0, rec[0xb]);
	if (rec[0xc])
		FUNC_100A8530(-1, 1, 0, 0, rec[0xc]);
	FUNC_1009F630(0);
	f_4C[slot] = 1;
}

// --- @ 0xB34A0 (528): model-id validation + spawn dispatch ---
struct s34A0 {
	char _0[0x97f];
	int f_97F;
	char _983[4];
	int f_987;
	char _98B[0x18];
	int f_9A3;
	char _9A7[1];
	short f_9A8;
	short f_9AA;
	char _9AC[0xa];
	int f_9B6;
	short f_9BA;
	short f_9BC;
	void FUNC_100B34A0();
};
void s34A0::FUNC_100B34A0()
{
	if (f_987 != 5 || f_9A3 != -1)
		return;
	if (DAT_1026eb98) {
		if (!FUNC_1000D110(f_9A8)) {
			if (FUNC_1000D150(f_9A8) && !FUNC_1000D190(f_9A8)
				&& !FUNC_1000D320(f_9A8))
				f_9A8 = 0x48c7;
		} else if (!FUNC_100B3DD0(f_9A8) && !FUNC_1000D2C0(f_9A8)) {
			f_9A8 = 0;
		}
	}
	int r;
	if (!FUNC_100B3DD0(f_9A8)) {
		short s = f_9A8;
		if (s < 400 || s > 0x263) {
			if ((s < 0x141 || s > 0x175) && s < 0x267) {
				if (s < 0)
					return;
				if (!FUNC_100B4570(s))
					f_9A8 = 0x48c7;
				s = f_9A8;
			} else {
				if (!FUNC_100B3DB0(s))
					f_9A8 = 0x48c7;
				s = f_9A8;
			}
			r = FUNC_1006C9B0(s, f_97F, (int)&f_9AA, f_9B6);
		} else {
			r = FUNC_1006C3C0(s, f_97F, (int)&f_9AA, f_9B6, f_9BA, f_9BC);
		}
	} else {
		if (!FUNC_100B3DB0(f_9A8))
			f_9A8 = 0;
		r = FUNC_1006C140(f_9A8, f_97F, (int)&f_9AA, f_9B6);
	}
	if (r) {
		long long v = FUNC_100B2B20();
		f_9A3 = (int)v;
		DAT_1026b568[(int)v] = (DWORD)(v >> 32);
	}
}

// --- @ 0xB65D0 (336): entity ray/proximity probe ---
struct s65D0 {
	char _0[0x14];
	int f_14;
	char _18[0xc];
	int f_24;
};
long long __fastcall FUNC_100B65D0(int a1, int a2, float *p3, float *p4,
	int p5, float *p6, float p7, char p8)
{
	if (p5 && *(int *)(p5 + 0x14)) {
		float l50[7] = {0};
		float l38[2] = {0};
		int ent = FUNC_100A7A40(*(unsigned short *)(p5 + 0x22));
		int i1 = *(int *)(ent + 0x14);
		int r1 = 0, r2 = 0;
		if (i1) {
			if (p8) {
				float loc[4];
				loc[0] = p6[1];
				loc[1] = p6[0];
				loc[2] = p6[2];
				loc[3] = *(float *)(i1 + 0x24);
				long long v = FUNC_100B41F0(loc);
				r2 = (int)(v >> 32);
				if (!(int)v)
					goto out;
			}
			float d30[3] = {p3[0] - p6[0], p3[1] - p6[1], p3[2] - p6[2]};
			float d40[3] = {p4[0] - p6[0], p4[1] - p6[1], p4[2] - p6[2]};
			float l24 = *(float *)(i1 + 0x24);
			if (l24 < flt_100e5814 || l24 < flt_100e5b2c)
				l24 = (l24 < flt_100e5814 ? flt_100e5814 : l24) * flt_100e6400;
			l24 = l24 * p7;
			int u3 = ((int(__cdecl *)(float *))0x417470)(d30);
			DAT_1026dfc0 = (char)u3;
			return ((long long)(int)d30 << 32) | (unsigned)u3;
		}
	out:
		return ((long long)r2 << 32) | (unsigned)r1 & 0xffffffffffffff00LL;
	}
	return 0;
}

// --- @ 0xB6AD0 (1469): RAKNI record-stream parser ---
struct sMem {
	int f0;
	int f4;
	int f8;
	char fC;
	char fD;
	char fE;
	char fF;
	char f10;
	char f11;
	int f12;
	char f16;
};
void FUNC_100B6AD0(int a1, int a2, int a3)
{
	sMem *mem = (sMem *)operator_new(0x17);
	if (mem) {
		mem->f0 = a1;
		mem->f8 = a2;
		mem->f4 = 0;
		mem->fC = 0;
		mem->fD = 0;
		mem->f16 = 0;
		mem->f12 = 0;
		mem->fE = 0;
	}
	int nrec = 0;
	int hdr = 0;
	FUNC_100BA7D0(&hdr, 4);
	if (hdr && hdr <= 0x80) {
		int n = hdr;
		do {
			if (mem->fC)
				break;
			int buf[3], len = 0, typ = 0;
			FUNC_100BA7D0(buf, 0xc);
			FUNC_100BA7D0(&len, 4);
			FUNC_100BA7D0(&typ, 4);
			if (!len) {
				if (typ == 0x50 || typ == 0x4c)
					nrec++;
			} else if (len == 10 && typ == 0x28) {
				nrec++;
			}
			if ((unsigned)(mem->f4 + typ) < (unsigned)mem->f8)
				mem->f4 += typ;
			else {
				mem->f4 = mem->f8;
				mem->fC = 1;
			}
		} while (--n);
	}
	if (!nrec) {
		if (mem) {
			if (mem->fD && mem->f0) {
				_free((void *)mem->f0);
				mem->f0 = 0;
			}
			_free(mem);
		}
		return;
	}
	DWORD *arr = (DWORD *)_calloc(1, nrec * 0x40 + 4);
	*arr = nrec;
	int i = 0;
	mem->f4 = 0;
	mem->fC = 0;
	hdr = 0;
	FUNC_100BA7D0(&hdr, 4);
	DWORD *out = arr + 1;
	do {
		if (mem->fC)
			break;
		int buf[3], ln = 0, typ = 0;
		FUNC_100BA7D0(buf, 0xc);
		FUNC_100BA7D0(&ln, 4);
		FUNC_100BA7D0(&typ, 4);
		if (!ln) {
			if (typ != 0x50 && typ != 0x4c)
				continue;
			DWORD rec[0x12];
			for (int j = 0; j < 0xe; j++)
				rec[j] = 0;
			rec[0] = buf[0];
			rec[1] = buf[1];
			rec[2] = buf[2];
			rec[3] = 0;
			FUNC_100BA7D0(&typ, 4);
			rec[4] = typ;
			for (int j = 5; j <= 8; j++) {
				FUNC_100BA7D0(&typ, 4);
				rec[j] = typ;
			}
			BYTE b[5] = {0};
			for (int j = 0; j < 4; j++)
				FUNC_100BA7D0(&b[j], 1);
			char s1[66] = {0}, s2[66] = {0};
			FUNC_100BA7D0(s1, 0x18);
			FUNC_100BA7D0(s2, 0x18);
			FUNC_100BA7D0(&b[4], 1);
			FUNC_100BA7D0(&b[0], 1);
			short x = (short)(b[4] * 0x100 + b[0]);
			if (typ == 0x50) {
				for (int j = 0; j < 3; j++)
					FUNC_100BA7D0(&b[0], 1);
			}
			FUNC_100BA7D0(&b[0], 1);
			if (s1[0])
				(void)FUNC_100B2C60("particle", s1);
			if (s2[0])
				(void)FUNC_100B2C60("particle", s2);
			for (int j = 0; j < 0xe; j++)
				out[j] = rec[j];
			i++;
			out += 0x10;
		} else {
			if (ln == 10 && typ == 0x28) {
				DWORD rec[0x10];
				for (int j = 0; j < 0xd; j++)
					rec[j] = 0;
				*(BYTE *)rec = 0;
				rec[0] = buf[0];
				rec[1] = buf[1];
				rec[2] = buf[2];
				rec[3] = 10;
				for (int j = 4; j < 0x10; j++) {
					FUNC_100BA7D0(&typ, 4);
					rec[j] = typ;
				}
				for (int j = 0; j < 0x10; j++)
					out[j] = rec[j];
				i++;
				out += 0x10;
			}
		}
	} while (i < nrec);
}
