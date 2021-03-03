#include <string.h>
#include <time.h>
#include <openssl/asn1.h>
#include <openssl/x509.h>
#include "testutil.h"
#include "internal/nelem.h"
typedef struct {
    const char *data;
    int type;
    time_t cmp_time;
    /* -1 if asn1_time <= cmp_time, 1 if asn1_time > cmp_time, 0 if error. */
    int expected;
} TESTDATA;
typedef struct {
    const char *data;
    /* 0 for check-only mode, 1 for set-string mode */
    int set_string;
    /* 0 for error, 1 if succeed */
    int expected;
    /*
     * The following 2 fields are ignored if set_string field is set to '0'
     * (in check only mode).
     *
     * But they can still be ignored explicitly in set-string mode by:
     * setting -1 to expected_type and setting NULL to expected_string.
     *
     * It's useful in a case of set-string mode but the expected result
     * is a 'parsing error'.
     */
    int expected_type;
    const char *expected_string;
} TESTDATA_FORMAT;
#define construct_asn1_time(s, t, e) \
