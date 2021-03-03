#ifdef _WIN32
# ifndef _WIN32_WINNT
#  define _WIN32_WINNT 0x0400
# endif
# include <windows.h>
# include <wincrypt.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <malloc.h>
# ifndef alloca
#  define alloca _alloca
# endif
# include <openssl/crypto.h>
# ifndef OPENSSL_NO_CAPIENG
#  include <openssl/buffer.h>
#  include <openssl/bn.h>
#  include <openssl/rsa.h>
#  include <openssl/dsa.h>
#  if defined(CERT_KEY_PROV_INFO_PROP_ID) && \
#   define __COMPILE_CAPIENG
#  endif                        /* CERT_KEY_PROV_INFO_PROP_ID */
# endif                         /* OPENSSL_NO_CAPIENG */
#endif                          /* _WIN32 */
#ifdef __COMPILE_CAPIENG
# undef X509_EXTENSIONS
# ifndef CERT_STORE_OPEN_EXISTING_FLAG
#  define CERT_STORE_OPEN_EXISTING_FLAG                   0x00004000
# endif
# ifndef CERT_STORE_CREATE_NEW_FLAG
#  define CERT_STORE_CREATE_NEW_FLAG                      0x00002000
# endif
# ifndef CERT_SYSTEM_STORE_CURRENT_USER
#  define CERT_SYSTEM_STORE_CURRENT_USER                  0x00010000
# endif
# ifndef ALG_SID_SHA_256
#  define ALG_SID_SHA_256   12
# endif
# ifndef ALG_SID_SHA_384
#  define ALG_SID_SHA_384   13
# endif
# ifndef ALG_SID_SHA_512
#  define ALG_SID_SHA_512   14
# endif
# ifndef CALG_SHA_256
#  define CALG_SHA_256      (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_256)
# endif
# ifndef CALG_SHA_384
#  define CALG_SHA_384      (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_384)
# endif
# ifndef CALG_SHA_512
#  define CALG_SHA_512      (ALG_CLASS_HASH | ALG_TYPE_ANY | ALG_SID_SHA_512)
# endif
# ifndef PROV_RSA_AES
#  define PROV_RSA_AES 24
# endif
# include <openssl/engine.h>
# include <openssl/pem.h>
# include <openssl/x509v3.h>
# include "e_capi_err.h"
# include "e_capi_err.c"
typedef struct CAPI_CTX_st CAPI_CTX;
typedef struct CAPI_KEY_st CAPI_KEY;

static void capi_addlasterror(void);
static void capi_adderror(DWORD err);

static void CAPI_trace(CAPI_CTX *ctx, char *format, ...);

static int capi_list_providers(CAPI_CTX *ctx, BIO *out);
static int capi_list_containers(CAPI_CTX *ctx, BIO *out);
int capi_list_certs(CAPI_CTX *ctx, BIO *out, char *storename);
void capi_free_key(CAPI_KEY *key);

static PCCERT_CONTEXT capi_find_cert(CAPI_CTX *ctx, const char *id,
                                     HCERTSTORE hstore);

CAPI_KEY *capi_find_key(CAPI_CTX *ctx, const char *id);

static EVP_PKEY *capi_load_privkey(ENGINE *eng, const char *key_id,
                                   UI_METHOD *ui_method, void *callback_data);
static int capi_rsa_sign(int dtype, const unsigned char *m,
                         unsigned int m_len, unsigned char *sigret,
                         unsigned int *siglen, const RSA *rsa);
static int capi_rsa_priv_enc(int flen, const unsigned char *from,
                             unsigned char *to, RSA *rsa, int padding);
static int capi_rsa_priv_dec(int flen, const unsigned char *from,
                             unsigned char *to, RSA *rsa, int padding);
static int capi_rsa_free(RSA *rsa);

# ifndef OPENSSL_NO_DSA
static DSA_SIG *capi_dsa_do_sign(const unsigned char *digest, int dlen,
                                 DSA *dsa);
static int capi_dsa_free(DSA *dsa);
# endif

static int capi_load_ssl_client_cert(ENGINE *e, SSL *ssl,
                                     STACK_OF(X509_NAME) *ca_dn, X509 **pcert,
                                     EVP_PKEY **pkey, STACK_OF(X509) **pother,
                                     UI_METHOD *ui_method,
                                     void *callback_data);

static int cert_select_simple(ENGINE *e, SSL *ssl, STACK_OF(X509) *certs);
# ifdef OPENSSL_CAPIENG_DIALOG
static int cert_select_dialog(ENGINE *e, SSL *ssl, STACK_OF(X509) *certs);
# endif

void engine_load_capi_int(void);

typedef PCCERT_CONTEXT(WINAPI *CERTDLG)(HCERTSTORE, HWND, LPCWSTR,
                                        LPCWSTR, DWORD, DWORD, void *);
typedef HWND(WINAPI *GETCONSWIN)(void);

/*
 * This structure contains CAPI ENGINE specific data: it contains various
 * global options and affects how other functions behave.
 */

# define CAPI_DBG_TRACE  2
# define CAPI_DBG_ERROR  1

struct CAPI_CTX_st {
    int debug_level;
    char *debug_file;
    /* Parameters to use for container lookup */
    DWORD keytype;
    LPSTR cspname;
    DWORD csptype;
    /* Certificate store name to use */
    LPSTR storename;
    LPSTR ssl_client_store;
    /* System store flags */
    DWORD store_flags;
/* Lookup string meanings in load_private_key */
# define CAPI_LU_SUBSTR          1  /* Substring of subject: uses "storename" */
# define CAPI_LU_FNAME           2  /* Friendly name: uses storename */
# define CAPI_LU_CONTNAME        3  /* Container name: uses cspname, keytype */
    int lookup_method;
/* Info to dump with dumpcerts option */
# define CAPI_DMP_SUMMARY        0x1    /* Issuer and serial name strings */
# define CAPI_DMP_FNAME          0x2    /* Friendly name */
# define CAPI_DMP_FULL           0x4    /* Full X509_print dump */
# define CAPI_DMP_PEM            0x8    /* Dump PEM format certificate */
# define CAPI_DMP_PSKEY          0x10   /* Dump pseudo key (if possible) */
# define CAPI_DMP_PKEYINFO       0x20   /* Dump key info (if possible) */
    DWORD dump_flags;
    int (*client_cert_select) (ENGINE *e, SSL *ssl, STACK_OF(X509) *certs);
    CERTDLG certselectdlg;
    GETCONSWIN getconswindow;
};
# define CAPI_CMD_LIST_CERTS             ENGINE_CMD_BASE
# define CAPI_CMD_LOOKUP_CERT            (ENGINE_CMD_BASE + 1)
# define CAPI_CMD_DEBUG_LEVEL            (ENGINE_CMD_BASE + 2)
# define CAPI_CMD_DEBUG_FILE             (ENGINE_CMD_BASE + 3)
# define CAPI_CMD_KEYTYPE                (ENGINE_CMD_BASE + 4)
# define CAPI_CMD_LIST_CSPS              (ENGINE_CMD_BASE + 5)
# define CAPI_CMD_SET_CSP_IDX            (ENGINE_CMD_BASE + 6)
# define CAPI_CMD_SET_CSP_NAME           (ENGINE_CMD_BASE + 7)
# define CAPI_CMD_SET_CSP_TYPE           (ENGINE_CMD_BASE + 8)
# define CAPI_CMD_LIST_CONTAINERS        (ENGINE_CMD_BASE + 9)
# define CAPI_CMD_LIST_OPTIONS           (ENGINE_CMD_BASE + 10)
# define CAPI_CMD_LOOKUP_METHOD          (ENGINE_CMD_BASE + 11)
# define CAPI_CMD_STORE_NAME             (ENGINE_CMD_BASE + 12)
# define CAPI_CMD_STORE_FLAGS            (ENGINE_CMD_BASE + 13)
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
# ifdef OPENSSL_CAPIENG_DIALOG
# endif
static int capi_destroy(ENGINE *e)
{
    RSA_meth_free(capi_rsa_method);
    capi_rsa_method = NULL;
# ifndef OPENSSL_NO_DSA
    DSA_meth_free(capi_dsa_method);
    capi_dsa_method = NULL;
# endif
    ERR_unload_CAPI_strings();
    return 1;
}
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DYNAMIC_ENGINE
# else
# endif
# ifndef OPENSSL_NO_DSA
# endif
# ifndef OPENSSL_NO_DSA
# endif
#ifdef CRYPT_DECRYPT_RSA_NO_PADDING_CHECK
#endif
static int capi_rsa_free(RSA *rsa)
{
    CAPI_KEY *capi_key;
    capi_key = RSA_get_ex_data(rsa, rsa_capi_idx);
    capi_free_key(capi_key);
    RSA_set_ex_data(rsa, rsa_capi_idx, 0);
    return 1;
}
# ifndef OPENSSL_NO_DSA
static int capi_dsa_free(DSA *dsa)
{
    CAPI_KEY *capi_key;
    capi_key = DSA_get_ex_data(dsa, dsa_capi_idx);
    capi_free_key(capi_key);
    DSA_set_ex_data(dsa, dsa_capi_idx, 0);
    return 1;
}
# endif
static void capi_ctx_free(CAPI_CTX *ctx)
{
    CAPI_trace(ctx, "Calling capi_ctx_free with %lx\n", ctx);
    if (!ctx)
        return;
    OPENSSL_free(ctx->cspname);
    OPENSSL_free(ctx->debug_file);
    OPENSSL_free(ctx->storename);
    OPENSSL_free(ctx->ssl_client_store);
    OPENSSL_free(ctx);
}
# ifdef OPENSSL_CAPIENG_DIALOG
#  ifndef CRYPTUI_SELECT_LOCATION_COLUMN
#   define CRYPTUI_SELECT_LOCATION_COLUMN                   0x000000010
#   define CRYPTUI_SELECT_INTENDEDUSE_COLUMN                0x000000004
#  endif
#  define dlg_title L"OpenSSL Application SSL Client Certificate Selection"
#  define dlg_prompt L"Select a certificate to use for authentication"
#  define dlg_columns      CRYPTUI_SELECT_LOCATION_COLUMN \
# endif
#else                           /* !__COMPILE_CAPIENG */
# include <openssl/engine.h>
# ifndef OPENSSL_NO_DYNAMIC_ENGINE
# else
# endif
#endif
