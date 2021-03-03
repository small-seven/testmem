#define fabs(x) __builtin_fabs(x)
#define isless(x, y) __builtin_isless(x, y)
#define inf() __builtin_inf()
#define unlikely(x) __builtin_expect((x), 0)
#define nonfinite(a) unlikely(!isless(fabs(a), inf()))
typedef union {
	long double ldval;
	double dval[2];
} longDblUnion;
#ifndef __NO_FPRS__
#else
#endif
