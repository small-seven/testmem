#include <openssl/ssl.h>
#include <openssl/evp.h>
#ifdef __VMS
# pragma names save
# pragma names as_is,shortened
#endif
#include "../ssl/ssl_local.h"
#ifdef __VMS
# pragma names restore
#endif
#include "testutil.h"
#define IVLEN   12
#define KEYLEN  16
