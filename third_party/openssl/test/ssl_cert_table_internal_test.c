#include <stdio.h>
#include <string.h>
#include <openssl/ssl.h>
#include "testutil.h"
#include "internal/nelem.h"
#ifdef __VMS
# pragma names save
# pragma names as_is,shortened
#endif
#include "../ssl/ssl_local.h"
#include "../ssl/ssl_cert_table.h"
#ifdef __VMS
# pragma names restore
#endif
#define test_cert_table(nid, amask, idx) \
