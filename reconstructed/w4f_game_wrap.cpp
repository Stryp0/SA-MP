// w4 scratch batch 6
typedef unsigned long DWORD;
typedef unsigned short WORD;
typedef unsigned char BYTE;

extern "C" float flt_100e5814;
extern "C" float flt_100e5b2c;
extern "C" void __cdecl FUNC_100B5500(float *);

// --- @ 0xB4F10 (205): quaternion -> 3x3 basis columns ---
void FUNC_100B4F10(float x, float y, float z, float w,
	float *o5, float *o6, float *o7, float *o8, float *o9,
	float *o10, float *o11, float *o12, float *o13)
{
	float xx, yy, zz, ww, t;
	xx = x * x;
	yy = y * y;
	zz = z * z;
	ww = w * w;
	*o5 = ((yy - zz) - ww) + xx;
	*o9 = ((zz - yy) - ww) + xx;
	*o13 = (ww - (zz + yy)) + xx;
	t = x * w + y * z;
	*o8 = t + t;
	t = y * z - x * w;
	*o6 = t + t;
	t = y * w - x * z;
	*o11 = t + t;
	t = x * z + y * w;
	*o7 = t + t;
	t = x * y + z * w;
	*o12 = t + t;
	t = z * w - x * y;
	*o10 = t + t;
}

// --- @ 0xB69F0 (144): quaternion from axis/angle-ish vectors ---
void FUNC_100B69F0(float *q, float *v, float *u)
{
	float t;
	q[1] = (u[2] * v[1] - u[1] * v[2]) * flt_100e5814;
	q[2] = (u[0] * v[2] - u[2] * v[0]) * flt_100e5814;
	q[3] = (u[1] * v[0] - u[0] * v[1]) * flt_100e5814;
	*q = (u[1] * v[1] + u[2] * v[2] + v[0] * u[0] + flt_100e5b2c) * flt_100e5814;
	FUNC_100B5500(q);
}
