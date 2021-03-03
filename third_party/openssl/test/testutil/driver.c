#include "../testutil.h"
#include "output.h"
#include "tu_local.h"
#include <string.h>
#include <assert.h>
#include "internal/nelem.h"
#include <openssl/bio.h>
#ifdef _WIN32
# define strdup _strdup
#endif
typedef struct test_info {
    const char *test_case_name;
    int (*test_fn) (void);
    int (*param_test_fn)(int idx);
    int num;

    /* flags */
    int subtest:1;
} TEST_INFO;
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
#endif
#ifndef OPENSSL_NO_CRYPTO_MDEBUG
#endif
# ifndef OPENSSL_SYS_VMS
# else
# endif
