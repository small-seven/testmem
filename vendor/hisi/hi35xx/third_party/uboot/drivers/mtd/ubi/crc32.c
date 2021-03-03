#ifndef __UBOOT__
#include <linux/crc32.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/compiler.h>
#include <u-boot/crc.h>
#endif
#include <linux/types.h>
#include <asm/byteorder.h>
#ifndef __UBOOT__
#include <linux/slab.h>
#include <linux/init.h>
#include <asm/atomic.h>
#endif
#include "crc32defs.h"
#define CRC_LE_BITS 8
#if CRC_LE_BITS == 8
#define tole(x) cpu_to_le32(x)
#define tobe(x) cpu_to_be32(x)
#else
#define tole(x) (x)
#define tobe(x) (x)
#endif
#include "crc32table.h"
#ifndef __UBOOT__
#endif
#if CRC_LE_BITS == 1
#else				/* Table-based approach */
# if CRC_LE_BITS == 8
# ifdef __LITTLE_ENDIAN
#  define DO_CRC(x) crc = tab[ (crc ^ (x)) & 255 ] ^ (crc>>8)
# else
#  define DO_CRC(x) crc = tab[ ((crc >> 24) ^ (x)) & 255] ^ (crc<<8)
# endif
#undef ENDIAN_SHIFT
#undef DO_CRC
# elif CRC_LE_BITS == 4
# elif CRC_LE_BITS == 2
# endif
#endif
#ifndef __UBOOT__
#if CRC_BE_BITS == 1
#else				/* Table-based approach */
# if CRC_BE_BITS == 8
# ifdef __LITTLE_ENDIAN
#  define DO_CRC(x) crc = tab[ (crc ^ (x)) & 255 ] ^ (crc>>8)
# else
#  define DO_CRC(x) crc = tab[ ((crc >> 24) ^ (x)) & 255] ^ (crc<<8)
# endif
#undef ENDIAN_SHIFT
#undef DO_CRC
# elif CRC_BE_BITS == 4
# elif CRC_BE_BITS == 2
# endif
#endif
#endif
#ifdef UNITTEST
#include <stdlib.h>
#include <stdio.h>
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#define SIZE 64
#define INIT1 0
#define INIT2 0
#endif				/* UNITTEST */
