#include "e_os.h"
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>
#include <assert.h>
#include <openssl/bio.h>
#include <openssl/dsa.h>         /* For d2i_DSAPrivateKey */
#include <openssl/err.h>
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/pkcs12.h>      /* For the PKCS8 stuff o.O */
#include <openssl/rsa.h>         /* For d2i_RSAPrivateKey */
#include <openssl/safestack.h>
#include <openssl/store.h>
#include <openssl/ui.h>
#include <openssl/x509.h>        /* For the PKCS8 stuff o.O */
#include "crypto/asn1.h"
#include "crypto/ctype.h"
#include "internal/o_dir.h"
#include "internal/cryptlib.h"
#include "crypto/store.h"
#include "store_local.h"
#ifdef _WIN32
# define stat    _stat
#endif
#ifndef S_ISDIR
# define S_ISDIR(a) (((a) & S_IFMT) == S_IFDIR)
#endif
typedef OSSL_STORE_INFO *(*file_try_decode_fn)(const char *pem_name,
                                               const char *pem_header,
                                               const unsigned char *blob,
                                               size_t len, void **handler_ctx,
                                               int *matchcount,
                                               const UI_METHOD *ui_method,
                                               void *ui_data);
/*
 * The eof function should return 1 if there's no more data to be found
 * with the handler_ctx, otherwise 0.  This is only used when the handler is
 * marked repeatable.
 */
typedef int (*file_eof_fn)(void *handler_ctx);
/*
 * The destroy_ctx function is used to destroy the handler_ctx that was
 * initiated by a repeatable try_decode function.  This is only used when
 * the handler is marked repeatable.
 */
typedef void (*file_destroy_ctx_fn)(void **handler_ctx);

typedef struct file_handler_st {
    const char *name;
    file_try_decode_fn try_decode;
    file_eof_fn eof;
    file_destroy_ctx_fn destroy_ctx;

    /* flags */
    int repeatable;
} FILE_HANDLER;
#define FILE_FLAG_SECMEM         (1<<0)
static void OSSL_STORE_LOADER_CTX_free(OSSL_STORE_LOADER_CTX *ctx)
{
    if (ctx->type == is_dir) {
        OPENSSL_free(ctx->_.dir.uri);
    } else {
        if (ctx->_.file.last_handler != NULL) {
            ctx->_.file.last_handler->destroy_ctx(&ctx->_.file.last_handler_ctx);
            ctx->_.file.last_handler_ctx = NULL;
            ctx->_.file.last_handler = NULL;
        }
    }
    OPENSSL_free(ctx);
}
#ifdef _WIN32
#endif
#if defined __VMS
#elif defined _WIN32
#endif
# ifdef __VMS
# endif
