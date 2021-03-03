#include <stdio.h>
#include "internal/cryptlib.h"
#include <openssl/objects.h>
#include <openssl/ts.h>
#include <openssl/pkcs7.h>
#include "ts_local.h"
#define TS_STATUS_BUF_SIZE      256
#define TS_STATUS_TEXT_SIZE     OSSL_NELEM(ts_status_text)
