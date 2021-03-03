#include <string.h>
#include <openssl/opensslconf.h>
#include <openssl/bio.h>
#include <openssl/crypto.h>
#include <openssl/evp.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <time.h>
#include "../ssl/packet_local.h"
#include "testutil.h"
#define CLIENT_VERSION_LEN      2
#define TOTAL_NUM_TESTS                         4
#define TEST_SET_SESSION_TICK_DATA_VER_NEG      0
#define TEST_ADD_PADDING                        1
#define TEST_PADDING_NOT_NEEDED                 2
#define TEST_ADD_PADDING_AND_PSK                3
#define F5_WORKAROUND_MIN_MSG_LEN   0x7f
#define F5_WORKAROUND_MAX_MSG_LEN   0x200
#ifdef OPENSSL_NO_TLS1_3
#endif
#if !defined(OPENSSL_NO_TLS1_3) && defined(OPENSSL_NO_TLS1_2)
#else
#endif
