#include <string.h>
#include "ssltestlib.h"
#include "testutil.h"
#define TEST_PLAINTEXT_OVERFLOW_OK      0
#define TEST_PLAINTEXT_OVERFLOW_NOT_OK  1
#define TEST_ENCRYPTED_OVERFLOW_TLS1_3_OK       2
#define TEST_ENCRYPTED_OVERFLOW_TLS1_3_NOT_OK   3
#define TEST_ENCRYPTED_OVERFLOW_TLS1_2_OK       4
#define TEST_ENCRYPTED_OVERFLOW_TLS1_2_NOT_OK   5
#define TOTAL_RECORD_OVERFLOW_TESTS 6
#ifdef OPENSSL_NO_TLS1_2
#endif
#ifdef OPENSSL_NO_TLS1_3
#endif
#ifndef OPENSSL_NO_COMP
#endif
