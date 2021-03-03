#ifndef USE_HOSTCC
#include <common.h>
#include <linux/string.h>
#else
#include <string.h>
#endif /* USE_HOSTCC */
#include <watchdog.h>
#include <u-boot/sha256.h>
#ifndef GET_UINT32_BE
#define GET_UINT32_BE(n,b,i) {				\
#endif
#ifndef PUT_UINT32_BE
#define PUT_UINT32_BE(n,b,i) {				\
#endif
#define SHR(x,n) ((x & 0xFFFFFFFF) >> n)
#define ROTR(x,n) (SHR(x,n) | (x << (32 - n)))
#define S0(x) (ROTR(x, 7) ^ ROTR(x,18) ^ SHR(x, 3))
#define S1(x) (ROTR(x,17) ^ ROTR(x,19) ^ SHR(x,10))
#define S2(x) (ROTR(x, 2) ^ ROTR(x,13) ^ ROTR(x,22))
#define S3(x) (ROTR(x, 6) ^ ROTR(x,11) ^ ROTR(x,25))
#define F0(x,y,z) ((x & y) | (z & (x | y)))
#define F1(x,y,z) (z ^ (x & (y ^ z)))
#define R(t)					\
#define P(a,b,c,d,e,f,g,h,x,K) {		\
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#endif
#if defined(CONFIG_HW_WATCHDOG) || defined(CONFIG_WATCHDOG)
#else
#endif
