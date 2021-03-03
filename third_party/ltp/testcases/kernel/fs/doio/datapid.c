#include <stdio.h>
#include <sys/param.h>
#ifdef UNIT_TEST
#include <unistd.h>
#include <stdlib.h>
#endif
#define LOWER16BITS(X)	(X & 0177777)
#define LOWER32BITS(X)	(X & 0xffffffff)
#define HIGHBITS(WRD, bits) ( (-1 << (64-bits)) & WRD)
#define LOWBITS(WRD, bits) ( (-1 >> (64-bits)) & WRD)
#define NBPBYTE		8	/* number bits per byte */
#ifndef DEBUG
#define DEBUG	0
#endif
#if CRAY
#if DEBUG
#endif
#if DEBUG
#endif
#else
#endif
#if CRAY
#if DEBUG
#endif
#else
#endif
#if UNIT_TEST
#endif
