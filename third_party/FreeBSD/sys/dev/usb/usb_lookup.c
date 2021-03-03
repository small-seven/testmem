#include "implementation/global_implementation.h"
#ifndef LITTLE_ENDIAN
#define	LITTLE_ENDIAN 1234
#endif
#ifndef BYTE_ORDER
#define	BYTE_ORDER LITTLE_ENDIAN
#endif
#ifndef BIG_ENDIAN
#define	BIG_ENDIAN 4321
#endif
#if BYTE_ORDER == BIG_ENDIAN
#define	U16_XOR "8"
#define	U32_XOR "12"
#define	U64_XOR "56"
#define	U8_BITFIELD_XOR "7"
#define	U16_BITFIELD_XOR "15"
#define	U32_BITFIELD_XOR "31"
#define	U64_BITFIELD_XOR "63"
#else
#define	U16_XOR "0"
#define	U32_XOR "0"
#define	U64_XOR "0"
#define	U8_BITFIELD_XOR "0"
#define	U16_BITFIELD_XOR "0"
#define	U32_BITFIELD_XOR "0"
#define	U64_BITFIELD_XOR "0"
#endif
#if USB_HAVE_COMPAT_LINUX
#define	MFL_SIZE "1"
#else
#define	MFL_SIZE "0"
#endif
#if defined(KLD_MODULE) && (USB_HAVE_ID_SECTION != 0)
#if ULONG_MAX >= 0xFFFFFFFFUL
#if ULONG_MAX >= 0xFFFFFFFFFFFFFFFFULL
#endif
#else
#error "Please update code."
#endif
#endif
