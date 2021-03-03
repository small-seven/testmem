#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ct.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/x509.h>
#include <openssl/x509v3.h>
#include "testutil.h"
#include <openssl/crypto.h>
#ifndef OPENSSL_NO_CT
# define CT_TEST_MAX_FILE_SIZE 8096
typedef struct ct_test_fixture {
    const char *test_case_name;
    /* The current time in milliseconds */
    uint64_t epoch_time_in_ms;
    /* The CT log store to use during tests */
    CTLOG_STORE* ctlog_store;
    /* Set the following to test handling of SCTs in X509 certificates */
    const char *certs_dir;
    char *certificate_file;
    char *issuer_file;
    /* Expected number of SCTs */
    int expected_sct_count;
    /* Expected number of valid SCTS */
    int expected_valid_sct_count;
    /* Set the following to test handling of SCTs in TLS format */
    const unsigned char *tls_sct_list;
    size_t tls_sct_list_len;
    STACK_OF(SCT) *sct_list;
    /*
     * A file to load the expected SCT text from.
     * This text will be compared to the actual text output during the test.
     * A maximum of |CT_TEST_MAX_FILE_SIZE| bytes will be read of this file.
     */
    const char *sct_dir;
    const char *sct_text_file;
    /* Whether to test the validity of the SCT(s) */
    int test_validity;
} CT_TEST_FIXTURE;
# define SETUP_CT_TEST_FIXTURE() SETUP_TEST_FIXTURE(CT_TEST_FIXTURE, set_up)
# define EXECUTE_CT_TEST() EXECUTE_TEST(execute_cert_test, tear_down)
#endif
#ifndef OPENSSL_NO_CT
#else
#endif
