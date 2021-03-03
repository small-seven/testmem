#include <openssl/ssl.h>
#include <openssl/evp.h>
#ifdef __VMS
# pragma names save
# pragma names as_is,shortened
#endif
#include "../ssl/ssl_local.h"
#include "../ssl/record/record_local.h"
#ifdef __VMS
# pragma names restore
#endif
#include "internal/nelem.h"
#include "testutil.h"
typedef struct {
    /*
     * We split these into 3 chunks in order to work around the 509 character
     * limit that the standard specifies for string literals
     */
    const char *plaintext[3];
    const char *ciphertext[3];
    const char *key;
    const char *iv;
    const char *seq;
} RECORD_DATA;
#define TLS13_AES_128_GCM_SHA256_BYTES  ((const unsigned char *)"\x13\x01")
