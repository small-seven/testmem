#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/objects.h>
#include "internal/comp.h"
#include <openssl/err.h>
#include "crypto/cryptlib.h"
#include "internal/bio.h"
#include "comp_local.h"
#ifndef ZLIB
# undef ZLIB_SHARED
#else
# include <zlib.h>
static void *zlib_zalloc(void *opaque, unsigned int no, unsigned int size)
{
    void *p;

    p = OPENSSL_zalloc(no * size);
    return p;
}
static void zlib_zfree(void *opaque, void *address)
{
    OPENSSL_free(address);
}
# if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_WIN32)
#  include <windows.h>
# endif                         /* !(OPENSSL_SYS_WINDOWS ||
# ifdef ZLIB_SHARED
#  include "internal/dso.h"
typedef int (*compress_ft) (Bytef *dest, uLongf * destLen,
                            const Bytef *source, uLong sourceLen);
typedef int (*inflateEnd_ft) (z_streamp strm);
typedef int (*inflate_ft) (z_streamp strm, int flush);
typedef int (*inflateInit__ft) (z_streamp strm,
                                const char *version, int stream_size);
typedef int (*deflateEnd_ft) (z_streamp strm);
typedef int (*deflate_ft) (z_streamp strm, int flush);
typedef int (*deflateInit__ft) (z_streamp strm, int level,
                                const char *version, int stream_size);
typedef const char *(*zError__ft) (int err);
static compress_ft p_compress = NULL;
static inflateEnd_ft p_inflateEnd = NULL;
static inflate_ft p_inflate = NULL;
static inflateInit__ft p_inflateInit_ = NULL;
static deflateEnd_ft p_deflateEnd = NULL;
static deflate_ft p_deflate = NULL;
static deflateInit__ft p_deflateInit_ = NULL;
static zError__ft p_zError = NULL;

static int zlib_loaded = 0;     /* only attempt to init func pts once */
static DSO *zlib_dso = NULL;

#  define compress                p_compress
#  define inflateEnd              p_inflateEnd
#  define inflate                 p_inflate
#  define inflateInit_            p_inflateInit_
#  define deflateEnd              p_deflateEnd
#  define deflate                 p_deflate
#  define deflateInit_            p_deflateInit_
#  define zError                  p_zError
# endif                         /* ZLIB_SHARED */

struct zlib_state {
    z_stream istream;
    z_stream ostream;
};
#endif
#ifdef ZLIB_SHARED
# ifndef LIBZ
#  if defined(OPENSSL_SYS_WINDOWS) || defined(OPENSSL_SYS_WIN32)
#   define LIBZ "ZLIB1"
#  elif defined(OPENSSL_SYS_VMS)
#   define LIBZ "LIBZ"
#  else
#   define LIBZ "z"
#  endif
# endif
#endif
#if defined(ZLIB)
#endif
#ifdef ZLIB_SHARED
#endif
#ifdef ZLIB
typedef struct {
    unsigned char *ibuf;        /* Input buffer */
    int ibufsize;               /* Buffer size */
    z_stream zin;               /* Input decompress context */
    unsigned char *obuf;        /* Output buffer */
    int obufsize;               /* Output buffer size */
    unsigned char *optr;        /* Position in output buffer */
    int ocount;                 /* Amount of data in output buffer */
    int odone;                  /* deflate EOF */
    int comp_level;             /* Compression level to use */
    z_stream zout;              /* Output compression context */
} BIO_ZLIB_CTX;
# define ZLIB_DEFAULT_BUFSIZE 1024
# ifdef ZLIB_SHARED
# endif
static int bio_zlib_free(BIO *bi)
{
    BIO_ZLIB_CTX *ctx;
    if (!bi)
        return 0;
    ctx = BIO_get_data(bi);
    if (ctx->ibuf) {
        /* Destroy decompress context */
        inflateEnd(&ctx->zin);
        OPENSSL_free(ctx->ibuf);
    }
    if (ctx->obuf) {
        /* Destroy compress context */
        deflateEnd(&ctx->zout);
        OPENSSL_free(ctx->obuf);
    }
    OPENSSL_free(ctx);
    BIO_set_data(bi, NULL);
    BIO_set_init(bi, 0);

    return 1;
}
#endif
