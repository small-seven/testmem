#include <openssl/e_os2.h>
#include "crypto/aria.h"
#include <assert.h>
#include <string.h>
#ifndef OPENSSL_SMALL_FOOTPRINT
#define rotl32(v, r) (((uint32_t)(v) << (r)) | ((uint32_t)(v) >> (32 - r)))
#define rotr32(v, r) (((uint32_t)(v) >> (r)) | ((uint32_t)(v) << (32 - r)))
#define bswap32(v)                                          \
#define GET_U8_BE(X, Y) ((uint8_t)((X) >> ((3 - Y) * 8)))
#define GET_U32_BE(X, Y) (                                  \
#define PUT_U32_BE(DEST, IDX, VAL)                              \
#define MAKE_U32(V0, V1, V2, V3) (      \
#define ARIA_ADD_ROUND_KEY(RK, T0, T1, T2, T3)  \
#define ARIA_SBOX_LAYER1_WITH_PRE_DIFF(T0, T1, T2, T3)  \
#define ARIA_SBOX_LAYER2_WITH_PRE_DIFF(T0, T1, T2, T3)  \
#define ARIA_DIFF_WORD(T0,T1,T2,T3) \
#define ARIA_DIFF_BYTE(T0, T1, T2, T3)                                  \
#define ARIA_SUBST_DIFF_ODD(T0, T1, T2, T3)             \
#define ARIA_SUBST_DIFF_EVEN(T0, T1, T2, T3)            \
#define _ARIA_GSRK(RK, X, Y, Q, R)                  \
#define ARIA_GSRK(RK, X, Y, N) _ARIA_GSRK(RK, X, Y, 4 - ((N) / 32), (N) % 32)
#define ARIA_DEC_DIFF_BYTE(X, Y, TMP, TMP2)         \
#else
#endif
