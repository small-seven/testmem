#include <stdio.h>
#include <string.h>
#include <openssl/opensslconf.h>
#include <openssl/err.h>
#include <openssl/e_os2.h>
#include <openssl/ssl.h>
#include <openssl/ssl3.h>
#include <openssl/tls1.h>
#include "internal/nelem.h"
#include "testutil.h"
typedef struct cipherlist_test_fixture {
    const char *test_case_name;
    SSL_CTX *server;
    SSL_CTX *client;
} CIPHERLIST_TEST_FIXTURE;
#ifndef OPENSSL_NO_TLS1_3
# if !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305)
# endif
#endif
#ifndef OPENSSL_NO_TLS1_2
# ifndef OPENSSL_NO_EC
# endif
# ifndef OPENSSL_NO_DH
# endif
# if !defined(OPENSSL_NO_CHACHA) && !defined(OPENSSL_NO_POLY1305)
#  ifndef OPENSSL_NO_EC
#  endif
#  ifndef OPENSSL_NO_DH
#  endif
# endif  /* !OPENSSL_NO_CHACHA && !OPENSSL_NO_POLY1305 */
# ifndef OPENSSL_NO_EC
# endif
# ifndef OPENSSL_NO_DH
# endif
# ifndef OPENSSL_NO_EC
# endif
# ifndef OPENSSL_NO_DH
# endif
# ifndef OPENSSL_NO_EC
# endif
# ifndef OPENSSL_NO_DH
# endif
#endif  /* !OPENSSL_NO_TLS1_2 */
#if !defined(OPENSSL_NO_TLS1_2) || defined(OPENSSL_NO_TLS1_3)
# ifndef OPENSSL_NO_EC
# endif
# endif
# ifndef OPENSSL_NO_EC
# endif
# ifndef OPENSSL_NO_DH
# endif
#endif /* !defined(OPENSSL_NO_TLS1_2) || defined(OPENSSL_NO_TLS1_3) */
#ifndef OPENSSL_NO_TLS1_2
#endif
#ifndef OPENSSL_NO_TLS1_2
#endif
#if !defined(OPENSSL_NO_TLS1_2) || defined(OPENSSL_NO_TLS1_3)
#endif
#define SETUP_CIPHERLIST_TEST_FIXTURE() \
#define EXECUTE_CIPHERLIST_TEST() \
