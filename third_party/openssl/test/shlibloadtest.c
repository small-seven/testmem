#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/opensslv.h>
#include <openssl/ssl.h>
#include <openssl/ossl_typ.h>
#include "crypto/dso_conf.h"
typedef void DSO;

typedef const SSL_METHOD * (*TLS_method_t)(void);
typedef SSL_CTX * (*SSL_CTX_new_t)(const SSL_METHOD *meth);
typedef void (*SSL_CTX_free_t)(SSL_CTX *);
typedef int (*OPENSSL_init_crypto_t)(uint64_t, void *);
typedef int (*OPENSSL_atexit_t)(void (*handler)(void));
typedef unsigned long (*ERR_get_error_t)(void);
typedef unsigned long (*OpenSSL_version_num_t)(void);
typedef DSO * (*DSO_dsobyaddr_t)(void (*addr)(void), int flags);
typedef int (*DSO_free_t)(DSO *dso);

typedef enum test_types_en {
    CRYPTO_FIRST,
    SSL_FIRST,
    JUST_CRYPTO,
    DSO_REFTEST,
    NO_ATEXIT
} TEST_TYPE;
#ifdef DSO_DLFCN
# include <dlfcn.h>
# define SHLIB_INIT NULL
typedef void *SHLIB;
typedef void *SHLIB_SYM;

static int shlib_load(const char *filename, SHLIB *lib)
{
    int dl_flags = (RTLD_GLOBAL|RTLD_LAZY);
#ifdef _AIX
    if (filename[strlen(filename) - 1] == ')')
        dl_flags |= RTLD_MEMBER;
#endif
    *lib = dlopen(filename, dl_flags);
    return *lib == NULL ? 0 : 1;
}
#endif
#ifdef DSO_WIN32
# include <windows.h>
# define SHLIB_INIT 0
typedef HINSTANCE SHLIB;
typedef void *SHLIB_SYM;

static int shlib_load(const char *filename, SHLIB *lib)
{
    *lib = LoadLibraryA(filename);
    return *lib == NULL ? 0 : 1;
}
#endif
#if defined(DSO_DLFCN) || defined(DSO_WIN32)
# ifdef DSO_DLFCN
# endif /* DSO_DLFCN */
# if defined(OPENSSL_NO_PINSHARED) \
#  if __GLIBC_PREREQ(2, 3)
#  endif
# endif
#endif
#if defined(DSO_DLFCN) || defined(DSO_WIN32)
#endif
