// w4 scratch batch 11
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" double __cdecl sqrt(double);
extern "C" float flt_100e5b2c;
extern "C" float flt_100ed478;
extern "C" float flt_100e6118;
extern "C" float flt_00859520;
extern "C" float flt_00859524;
extern "C" double dbl_00c17044;
extern "C" double dbl_00c17048;
extern "C" DWORD DAT_1026b568[];
extern "C" void __cdecl FUNC_100B2CA0(int, float *, int);
extern "C" int __cdecl FUNC_100C7444(void);

// --- @ 0xB5020 (352): quaternion from two vectors ---
void FUNC_100B5020(float *q, float *v, float *u)
{
	float x = v[0], y = v[1], z = v[2];
	float a = u[0], b = u[1], c = u[2];
	float w = c * y - b * z;
	float dot = a * x + b * y + c * z +
		(float)sqrt((x * x + y * y + z * z) * (a * a + b * b + c * c));
	float wy = a * z - c * x;
	float wz = b * x - a * y;
	if (dot < flt_100ed478) {
		w = -z;
		dot = 0.f;
		wy = y;
		wz = x;
	}
	float k = flt_100e5b2c /
		(float)sqrt(w * w + wy * wy + wz * wz + dot * dot);
	q[1] = k * w;
	q[2] = k * wy;
	q[3] = k * wz;
	q[0] = k * dot;
}

// --- @ 0xB5300 (288): quaternion -> basis vectors ---
void FUNC_100B5300(float *q, float *m)
{
	float x = q[1], y = q[2], z = q[3];
	float n = flt_100e6118 / (q[0] * q[0] + z * z + y * y + x * x);
	float yy = n * x;
	float zz = n * y;
	float zz2 = n * z;
	float w = q[0];
	m[0] = flt_100e5b2c - (zz2 * z + zz * y);
	m[1] = w * zz2 + zz * x;
	m[2] = yy * z - zz * w;
	m[4] = zz * x - w * zz2;
	m[5] = flt_100e5b2c - (zz2 * z + yy * x);
	m[6] = w * yy + zz2 * y;
	m[8] = zz * w + yy * z;
	m[9] = zz2 * y - w * yy;
	m[10] = flt_100e5b2c - (zz * y + yy * x);
}

// --- @ 0xB3090 (272): thiscall aim/weapon setup ---
struct s3090 {
	char _0[0x9d3];
	void FUNC_100B3090();
};
void s3090::FUNC_100B3090()
{
	float local[4];
	local[0] = *(float *)((char *)this + 0x98b) * (float)dbl_00c17044 * flt_00859520;
	local[3] = (float)dbl_00c17048 * flt_00859524 * *(float *)((char *)this + 0x98f);
	local[2] = (*(float *)((char *)this + 0x98b) + *(float *)((char *)this + 0x972))
		* (float)dbl_00c17044 * flt_00859520;
	local[1] = (*(float *)((char *)this + 0x98f) + *(float *)((char *)this + 0x976))
		* (float)dbl_00c17048 * flt_00859524;
	int p, u;
	if (*(char *)((char *)this + 0x9d1) == 0)
		p = (int)this + 0x96b;
	else
		p = (int)this + 0x9d2;
	u = DAT_1026b568[*(int *)((char *)this + 0x9a3)];
	FUNC_100B2CA0(u, local, p);
	*(int *)((char *)this + 0x9c1) = FUNC_100C7444();
	*(int *)((char *)this + 0x9c9) = FUNC_100C7444();
	*(int *)((char *)this + 0x9c5) = FUNC_100C7444();
	*(int *)((char *)this + 0x9cd) = FUNC_100C7444();
	*(char *)((char *)this + 0x9bf) = 1;
}
