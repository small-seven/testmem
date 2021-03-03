#include "curl_setup.h"
#include "urldata.h"
#include <curl/curl.h>
#include <stddef.h>
#ifdef HAVE_ZLIB_H
#include <zlib.h>
#ifdef __SYMBIAN32__
#undef WIN32
#endif
#endif
#ifdef HAVE_BROTLI
#include <brotli/decode.h>
#endif
#include "sendf.h"
#include "http.h"
#include "content_encoding.h"
#include "strdup.h"
#include "strcase.h"
#include "curl_memory.h"
#include "memdebug.h"
#define CONTENT_ENCODING_DEFAULT  "identity"
#ifndef CURL_DISABLE_HTTP
#define DSIZ CURL_MAX_WRITE_SIZE /* buffer size for decompressed data */
#ifdef HAVE_LIBZ
#define OLD_ZLIB_SUPPORT 1
#define GZIP_MAGIC_0 0x1f
#define GZIP_MAGIC_1 0x8b
#define ASCII_FLAG   0x01 /* bit 0 set: file probably ascii text */
#define HEAD_CRC     0x02 /* bit 1 set: header CRC present */
#define EXTRA_FIELD  0x04 /* bit 2 set: extra field present */
#define ORIG_NAME    0x08 /* bit 3 set: original file name present */
#define COMMENT      0x10 /* bit 4 set: file comment present */
#define RESERVED     0xE0 /* bits 5..7: reserved */
typedef enum {
  ZLIB_UNINIT,               /* uninitialized */
  ZLIB_INIT,                 /* initialized */
  ZLIB_INFLATING,            /* inflating started. */
  ZLIB_EXTERNAL_TRAILER,     /* reading external trailer */
  ZLIB_GZIP_HEADER,          /* reading gzip header */
  ZLIB_GZIP_INFLATING,       /* inflating gzip stream */
  ZLIB_INIT_GZIP             /* initialized in transparent gzip mode */
} zlibInitState;
typedef struct {
  zlibInitState zlib_init;   /* zlib init state */
  uInt trailerlen;           /* Remaining trailer byte count. */
  z_stream z;                /* State structure for zlib. */
}  zlib_params;
#ifdef Z_BLOCK
#else
#endif
#ifdef OLD_ZLIB_SUPPORT
#endif
#ifndef OLD_ZLIB_SUPPORT
#else
#endif
#endif /* HAVE_LIBZ */
#ifdef HAVE_BROTLI
typedef struct {
  BrotliDecoderState *br;    /* State structure for brotli. */
}  brotli_params;
#ifdef BROTLI_DECODER_ERROR_COMPOUND_DICTIONARY
#endif
#ifdef BROTLI_DECODER_ERROR_DICTIONARY_NOT_SET
#endif
#endif
#ifdef HAVE_LIBZ
#endif
#ifdef HAVE_BROTLI
#endif
#else
#endif /* CURL_DISABLE_HTTP */
