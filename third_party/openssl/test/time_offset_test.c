#include <stdio.h>
#include <string.h>
#include <time.h>
#include <openssl/asn1.h>
#include <openssl/x509.h>
#include "testutil.h"
#include "internal/nelem.h"
typedef struct {
    const char *data;
    int time_result;
    int type;
} TESTDATA;
