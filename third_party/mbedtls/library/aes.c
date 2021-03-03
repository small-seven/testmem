#if !defined(MBEDTLS_CONFIG_FILE)
#include "mbedtls/config.h"
#else
#include MBEDTLS_CONFIG_FILE
#endif
#if defined(MBEDTLS_AES_C)
#include <string.h>
#include "mbedtls/aes.h"
#include "mbedtls/platform.h"
#include "mbedtls/platform_util.h"
#if defined(MBEDTLS_PADLOCK_C)
#include "mbedtls/padlock.h"
#endif
#if defined(MBEDTLS_AESNI_C)
#include "mbedtls/aesni.h"
#endif
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_PLATFORM_C)
#include "mbedtls/platform.h"
#else
#include <stdio.h>
#define mbedtls_printf printf
#endif /* MBEDTLS_PLATFORM_C */
#endif /* MBEDTLS_SELF_TEST */
#if !defined(MBEDTLS_AES_ALT)
#define AES_VALIDATE_RET( cond )    \
#define AES_VALIDATE( cond )        \
#ifndef GET_UINT32_LE
#define GET_UINT32_LE(n,b,i)                            \
#endif
#ifndef PUT_UINT32_LE
#define PUT_UINT32_LE(n,b,i)                                    \
#endif
#if defined(MBEDTLS_PADLOCK_C) &&                      \
#endif
#if defined(MBEDTLS_AES_ROM_TABLES)
#define FT \
#define V(a,b,c,d) 0x##a##b##c##d
#undef V
#if !defined(MBEDTLS_AES_FEWER_TABLES)
#define V(a,b,c,d) 0x##b##c##d##a
#undef V
#define V(a,b,c,d) 0x##c##d##a##b
#undef V
#define V(a,b,c,d) 0x##d##a##b##c
#undef V
#endif /* !MBEDTLS_AES_FEWER_TABLES */
#undef FT
#define RT \
#define V(a,b,c,d) 0x##a##b##c##d
#undef V
#if !defined(MBEDTLS_AES_FEWER_TABLES)
#define V(a,b,c,d) 0x##b##c##d##a
#undef V
#define V(a,b,c,d) 0x##c##d##a##b
#undef V
#define V(a,b,c,d) 0x##d##a##b##c
#undef V
#endif /* !MBEDTLS_AES_FEWER_TABLES */
#undef RT
#else /* MBEDTLS_AES_ROM_TABLES */
#if !defined(MBEDTLS_AES_FEWER_TABLES)
#endif /* !MBEDTLS_AES_FEWER_TABLES */
#if !defined(MBEDTLS_AES_FEWER_TABLES)
#endif /* !MBEDTLS_AES_FEWER_TABLES */
#define ROTL8(x) ( ( (x) << 8 ) & 0xFFFFFFFF ) | ( (x) >> 24 )
#define XTIME(x) ( ( (x) << 1 ) ^ ( ( (x) & 0x80 ) ? 0x1B : 0x00 ) )
#define MUL(x,y) ( ( (x) && (y) ) ? pow[(log[(x)]+log[(y)]) % 255] : 0 )
#if !defined(MBEDTLS_AES_FEWER_TABLES)
#endif /* !MBEDTLS_AES_FEWER_TABLES */
#if !defined(MBEDTLS_AES_FEWER_TABLES)
#endif /* !MBEDTLS_AES_FEWER_TABLES */
#undef ROTL8
#endif /* MBEDTLS_AES_ROM_TABLES */
#if defined(MBEDTLS_AES_FEWER_TABLES)
#define ROTL8(x)  ( (uint32_t)( ( x ) <<  8 ) + (uint32_t)( ( x ) >> 24 ) )
#define ROTL16(x) ( (uint32_t)( ( x ) << 16 ) + (uint32_t)( ( x ) >> 16 ) )
#define ROTL24(x) ( (uint32_t)( ( x ) << 24 ) + (uint32_t)( ( x ) >>  8 ) )
#define AES_RT0(idx) RT0[idx]
#define AES_RT1(idx) ROTL8(  RT0[idx] )
#define AES_RT2(idx) ROTL16( RT0[idx] )
#define AES_RT3(idx) ROTL24( RT0[idx] )
#define AES_FT0(idx) FT0[idx]
#define AES_FT1(idx) ROTL8(  FT0[idx] )
#define AES_FT2(idx) ROTL16( FT0[idx] )
#define AES_FT3(idx) ROTL24( FT0[idx] )
#else /* MBEDTLS_AES_FEWER_TABLES */
#define AES_RT0(idx) RT0[idx]
#define AES_RT1(idx) RT1[idx]
#define AES_RT2(idx) RT2[idx]
#define AES_RT3(idx) RT3[idx]
#define AES_FT0(idx) FT0[idx]
#define AES_FT1(idx) FT1[idx]
#define AES_FT2(idx) FT2[idx]
#define AES_FT3(idx) FT3[idx]
#endif /* MBEDTLS_AES_FEWER_TABLES */
void mbedtls_aes_free( mbedtls_aes_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_platform_zeroize( ctx, sizeof( mbedtls_aes_context ) );
}
#if defined(MBEDTLS_CIPHER_MODE_XTS)
void mbedtls_aes_xts_free( mbedtls_aes_xts_context *ctx )
{
    if( ctx == NULL )
        return;

    mbedtls_aes_free( &ctx->crypt );
    mbedtls_aes_free( &ctx->tweak );
}
#endif /* MBEDTLS_CIPHER_MODE_XTS */
#if !defined(MBEDTLS_AES_SETKEY_ENC_ALT)
#if !defined(MBEDTLS_AES_ROM_TABLES)
#endif
#if defined(MBEDTLS_PADLOCK_C) && defined(MBEDTLS_PADLOCK_ALIGN16)
#endif
#if defined(MBEDTLS_AESNI_C) && defined(MBEDTLS_HAVE_X86_64)
#endif
#endif /* !MBEDTLS_AES_SETKEY_ENC_ALT */
#if !defined(MBEDTLS_AES_SETKEY_DEC_ALT)
#if defined(MBEDTLS_PADLOCK_C) && defined(MBEDTLS_PADLOCK_ALIGN16)
#endif
#if defined(MBEDTLS_AESNI_C) && defined(MBEDTLS_HAVE_X86_64)
#endif
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif /* MBEDTLS_CIPHER_MODE_XTS */
#endif /* !MBEDTLS_AES_SETKEY_DEC_ALT */
#define AES_FROUND(X0,X1,X2,X3,Y0,Y1,Y2,Y3)                     \
#define AES_RROUND(X0,X1,X2,X3,Y0,Y1,Y2,Y3)                 \
#if !defined(MBEDTLS_AES_ENCRYPT_ALT)
#endif /* !MBEDTLS_AES_ENCRYPT_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif /* !MBEDTLS_DEPRECATED_REMOVED */
#if !defined(MBEDTLS_AES_DECRYPT_ALT)
#endif /* !MBEDTLS_AES_DECRYPT_ALT */
#if !defined(MBEDTLS_DEPRECATED_REMOVED)
#endif /* !MBEDTLS_DEPRECATED_REMOVED */
#if defined(MBEDTLS_AESNI_C) && defined(MBEDTLS_HAVE_X86_64)
#endif
#if defined(MBEDTLS_PADLOCK_C) && defined(MBEDTLS_HAVE_X86)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#if defined(MBEDTLS_PADLOCK_C) && defined(MBEDTLS_HAVE_X86)
#endif
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#ifndef GET_UINT64_LE
#define GET_UINT64_LE(n,b,i)                            \
#endif
#ifndef PUT_UINT64_LE
#define PUT_UINT64_LE(n,b,i)                            \
#endif
typedef unsigned char mbedtls_be128[16];

/*
 * GF(2^128) multiplication function
 *
 * This function multiplies a field element by x in the polynomial field
 * representation. It uses 64-bit word operations to gain speed but compensates
 * for machine endianess and hence works correctly on both big and little
 * endian machines.
 */
static void mbedtls_gf128mul_x_ble( unsigned char r[16],
                                    const unsigned char x[16] )
{
    uint64_t a, b, ra, rb;

    GET_UINT64_LE( a, x, 0 );
    GET_UINT64_LE( b, x, 8 );

    ra = ( a << 1 )  ^ 0x0087 >> ( 8 - ( ( b >> 63 ) << 3 ) );
    rb = ( a >> 63 ) | ( b << 1 );

    PUT_UINT64_LE( ra, r, 0 );
    PUT_UINT64_LE( rb, r, 8 );
}
#endif /* MBEDTLS_CIPHER_MODE_XTS */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif /* MBEDTLS_CIPHER_MODE_OFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#endif /* !MBEDTLS_AES_ALT */
#if defined(MBEDTLS_SELF_TEST)
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif /* MBEDTLS_CIPHER_MODE_OFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif /* MBEDTLS_CIPHER_MODE_XTS */
#if defined(MBEDTLS_CIPHER_MODE_CBC) || defined(MBEDTLS_CIPHER_MODE_CFB)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR) || defined(MBEDTLS_CIPHER_MODE_CFB) || \
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR) || defined(MBEDTLS_CIPHER_MODE_XTS)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif
#if defined(MBEDTLS_CIPHER_MODE_CBC)
#endif /* MBEDTLS_CIPHER_MODE_CBC */
#if defined(MBEDTLS_CIPHER_MODE_CFB)
#endif /* MBEDTLS_CIPHER_MODE_CFB */
#if defined(MBEDTLS_CIPHER_MODE_OFB)
#endif /* MBEDTLS_CIPHER_MODE_OFB */
#if defined(MBEDTLS_CIPHER_MODE_CTR)
#endif /* MBEDTLS_CIPHER_MODE_CTR */
#if defined(MBEDTLS_CIPHER_MODE_XTS)
#endif /* MBEDTLS_CIPHER_MODE_XTS */
#endif /* MBEDTLS_SELF_TEST */
#endif /* MBEDTLS_AES_C */
