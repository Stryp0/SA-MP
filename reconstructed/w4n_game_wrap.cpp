// w4 scratch batch 13 - float math
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" double __cdecl sqrt(double);
extern "C" double __cdecl _copysign(double, double);
extern "C" double __cdecl cos(double);
extern "C" double __cdecl sin(double);
extern "C" double __cdecl atan2(double, double);
extern "C" float flt_100e5b2c;
extern "C" float flt_100e5940;
extern "C" float flt_100e5814;
extern "C" float flt_100e6400;
extern "C" float flt_100ed4d0;
extern "C" int __stdcall FUNC_100A7A40(int);
extern "C" int __cdecl FUNC_100B41F0(float *);
extern "C" int __cdecl FUNC_100B5500(float *);
extern "C" DWORD DAT_1026dfc0;

// --- @ 0xB4D70 (416): matrix -> quaternion conversion ---
void FUNC_100B4D70(float a, float b, float c, float d, float e,
	float f, float g, float h, float i,
	float *o1, float *o2, float *o3, float *o4)
{
	float t1 = a + e + i + flt_100e5b2c;
	if (t1 < flt_100e5940)
		t1 = flt_100e5940;
	float w = (float)sqrt(t1) * flt_100e5814;
	float t2 = ((a + flt_100e5b2c) - e) - i;
	if (t2 < flt_100e5940)
		t2 = flt_100e5940;
	float fx = flt_100e5b2c - a;
	float t3 = (e + fx) - i;
	if (t3 < flt_100e5940)
		t3 = flt_100e5940;
	float x = (float)sqrt(t3) * flt_100e5814;
	float t4 = (fx - e) + i;
	if (t4 < flt_100e5940)
		t4 = flt_100e5940;
	float y = (float)sqrt(t4) * flt_100e5814;
	if (w < flt_100e5940)
		w = 0.f;
	float sx = (float)sqrt(t2) * flt_100e5814;
	if (sx < flt_100e5940)
		sx = flt_100e5940;
	if (x < flt_100e5940)
		x = 0.f;
	if (y < flt_100e5940)
		y = 0.f;
	*o1 = w;
	*o2 = (float)_copysign((double)sx, (double)(h - f));
	*o3 = (float)_copysign((double)x, (double)(c - g));
	*o4 = (float)_copysign((double)y, (double)(d - b));
}

// --- @ 0xB5560 (192): euler angles -> quaternion ---
void FUNC_100B5560(float *e, float *q)
{
	float cz = (float)cos(e[2] * flt_100e5814);
	float cy = (float)cos(e[1] * flt_100e5814);
	float cx = (float)cos(e[0] * flt_100e5814);
	float sz = (float)sin(e[2] * flt_100e5814);
	float sy = (float)sin(e[1] * flt_100e5814);
	float sx = (float)sin(e[0] * flt_100e5814);
	q[0] = sx * sy * sz + cx * cy * cz;
	q[1] = cy * sx * cz - sy * sz * cx;
	q[2] = sy * cx * cz + sx * sz * cy;
	q[3] = sz * cx * cy - sx * sy * cz;
}

// --- @ 0xB6900 (240): rotate 2d point by atan2 ---
void FUNC_100B6900(float *v, float *o)
{
	float ang = (float)atan2(v[0], v[1]);
	float s = (float)sin(ang - flt_100ed4d0);
	float c = (float)cos(ang - flt_100ed4d0);
	o[0] = v[1] * flt_100e5940 - c * v[2];
	o[1] = s * v[2] - v[0] * flt_100e5940;
	o[2] = c * v[0] - s * v[1];
}
