#include <sys/cdefs.h>
#include <sys/cdefs.h>
#include <sys/types.h>
#ifdef _KERNEL
#include <sys/systm.h>
#else
#include <string.h>
#include <assert.h>
#define	KASSERT(exp, msg)	assert(exp)
#endif
#include <crypto/rijndael/rijndael.h>
#include <crypto/rijndael/rijndael_local.h>
#define SWAP(x) (_lrotl(x, 8) & 0x00ff00ff | _lrotr(x, 8) & 0xff00ff00)
#define GETU32(pt) (((u32)(pt)[0] << 24) ^ ((u32)(pt)[1] << 16) ^ ((u32)(pt)[2] <<  8) ^ ((u32)(pt)[3]))
#define PUTU32(ct, st) { (ct)[0] = (u8)((st) >> 24); (ct)[1] = (u8)((st) >> 16); (ct)[2] = (u8)((st) >>  8); (ct)[3] = (u8)(st); }
#ifndef FULL_UNROLL
#endif /* ?FULL_UNROLL */
#ifdef FULL_UNROLL
#else  /* !FULL_UNROLL */
#endif /* ?FULL_UNROLL */
#ifndef FULL_UNROLL
#endif /* ?FULL_UNROLL */
#ifdef FULL_UNROLL
#else  /* !FULL_UNROLL */
#endif /* ?FULL_UNROLL */
