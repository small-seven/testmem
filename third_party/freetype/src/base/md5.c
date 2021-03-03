#ifndef HAVE_OPENSSL
#include <string.h>
#include "md5.h"
#define F(x, y, z)			((z) ^ ((x) & ((y) ^ (z))))
#define G(x, y, z)			((y) ^ ((z) & ((x) ^ (y))))
#define H(x, y, z)			(((x) ^ (y)) ^ (z))
#define H2(x, y, z)			((x) ^ ((y) ^ (z)))
#define I(x, y, z)			((y) ^ ((x) | ~(z)))
#define STEP(f, a, b, c, d, x, t, s) \
#if defined(__i386__) || defined(__x86_64__) || defined(__vax__)
#define SET(n) \
#define GET(n) \
#else
#define SET(n) \
#define GET(n) \
#endif
#define OUT(dst, src) \
#endif
