#ifdef MAKECRCH
#  include <stdio.h>
#  ifndef DYNAMIC_CRC_TABLE
#    define DYNAMIC_CRC_TABLE
#  endif /* !DYNAMIC_CRC_TABLE */
#endif /* MAKECRCH */
#include "zutil.h"      /* for STDC and FAR definitions */
#if !defined(NOBYFOUR) && defined(Z_U4)
#  define BYFOUR
#endif
#ifdef BYFOUR
#  define TBLS 8
#else
#  define TBLS 1
#endif /* BYFOUR */
#ifdef DYNAMIC_CRC_TABLE
#ifdef MAKECRCH
#endif /* MAKECRCH */
#ifdef BYFOUR
#endif /* BYFOUR */
#ifdef MAKECRCH
#  ifdef BYFOUR
#  endif /* BYFOUR */
#endif /* MAKECRCH */
#ifdef MAKECRCH
#endif /* MAKECRCH */
#else /* !DYNAMIC_CRC_TABLE */
#include "crc32.h"
#endif /* DYNAMIC_CRC_TABLE */
#ifdef DYNAMIC_CRC_TABLE
#endif /* DYNAMIC_CRC_TABLE */
#define DO1 crc = crc_table[0][((int)crc ^ (*buf++)) & 0xff] ^ (crc >> 8)
#define DO8 DO1; DO1; DO1; DO1; DO1; DO1; DO1; DO1
#ifdef DYNAMIC_CRC_TABLE
#endif /* DYNAMIC_CRC_TABLE */
#ifdef BYFOUR
#endif /* BYFOUR */
#ifdef BYFOUR
#define DOLIT4 c ^= *buf4++; \
#define DOLIT32 DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4; DOLIT4
#define DOBIG4 c ^= *buf4++; \
#define DOBIG32 DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4; DOBIG4
#endif /* BYFOUR */
#define GF2_DIM 32      /* dimension of GF(2) vectors (length of CRC) */
