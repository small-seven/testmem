#ifndef USE_HOSTCC
#include <common.h>
#include <ubi_uboot.h>
#include <linux/bitops.h>
#else
#include <errno.h>
#if defined(__FreeBSD__)
#include <sys/endian.h>
#elif defined(__APPLE__)
#include <machine/endian.h>
#include <libkern/OSByteOrder.h>
#else
#include <endian.h>
#endif
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#undef cpu_to_be32
#if defined(__APPLE__)
#define cpu_to_be32 OSSwapHostToBigInt32
#else
#define cpu_to_be32 htobe32
#endif
#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))
#define kmalloc(size, flags)	malloc(size)
#define kzalloc(size, flags)	calloc(1, size)
#define kfree free
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#endif
#include <asm/byteorder.h>
#include <linux/bch.h>
#if defined(CONFIG_BCH_CONST_PARAMS)
#define GF_M(_p)               (CONFIG_BCH_CONST_M)
#define GF_T(_p)               (CONFIG_BCH_CONST_T)
#define GF_N(_p)               ((1 << (CONFIG_BCH_CONST_M))-1)
#else
#define GF_M(_p)               ((_p)->m)
#define GF_T(_p)               ((_p)->t)
#define GF_N(_p)               ((_p)->n)
#endif
#define BCH_ECC_WORDS(_p)      DIV_ROUND_UP(GF_M(_p)*GF_T(_p), 32)
#define BCH_ECC_BYTES(_p)      DIV_ROUND_UP(GF_M(_p)*GF_T(_p), 8)
#ifndef dbg
#define dbg(_fmt, args...)     do {} while (0)
#endif
#define GF_POLY_SZ(_d) (sizeof(struct gf_poly)+((_d)+1)*sizeof(unsigned int))
#ifdef USE_HOSTCC
#if !defined(__DragonFly__) && !defined(__FreeBSD__) && !defined(__APPLE__)
#endif
#endif
#if defined(USE_CHIEN_SEARCH)
#define find_poly_roots(_p, _k, _elp, _loc) chien_search(_p, len, _elp, _loc)
#endif /* USE_CHIEN_SEARCH */
#if defined(CONFIG_BCH_CONST_PARAMS)
#endif
