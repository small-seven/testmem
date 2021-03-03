#ifndef _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_DEPRECATE 1
#endif
#ifndef USE_HOSTCC
#include <common.h>
#include <linux/string.h>
#else
#include <string.h>
#endif /* USE_HOSTCC */
#include <watchdog.h>
#include <u-boot/sha1.h>
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i) {				\
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i) {				\
#endif
#define S(x,n)	((x << n) | ((x & 0xFFFFFFFF) >> (32 - n)))
#define R(t) (						\
#define P(a,b,c,d,e,x)	{				\
#define F(x,y,z) (z ^ (x & (y ^ z)))
#define K 0x5A827999
#undef K
#undef F
#define F(x,y,z) (x ^ y ^ z)
#define K 0x6ED9EBA1
#undef K
#undef F
#define F(x,y,z) ((x & y) | (z & (x | y)))
#define K 0x8F1BBCDC
#undef K
#undef F
#define F(x,y,z) (x ^ y ^ z)
#define K 0xCA62C1D6
#undef K
#undef F
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#endif
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#else
#endif
#ifdef SELF_TEST
#else
#endif
