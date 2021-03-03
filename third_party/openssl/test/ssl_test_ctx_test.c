#include <stdio.h>
#include <string.h>
#include "internal/nelem.h"
#include "ssl_test_ctx.h"
#include "testutil.h"
#include <openssl/e_os2.h>
#include <openssl/err.h>
#include <openssl/conf.h>
#include <openssl/ssl.h>
typedef struct ssl_test_ctx_test_fixture {
    const char *test_case_name;
    const char *test_section;
    /* Expected parsed configuration. */
    SSL_TEST_CTX *expected_ctx;
} SSL_TEST_CTX_TEST_FIXTURE;
#define SETUP_SSL_TEST_CTX_TEST_FIXTURE() \
#define EXECUTE_SSL_TEST_CTX_TEST() \
