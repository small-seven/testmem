#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/opensslconf.h> /* To see if OPENSSL_NO_CAST is defined */
#include "internal/nelem.h"
#include "testutil.h"
#ifndef OPENSSL_NO_CAST
# include <openssl/cast.h>
#endif
#ifndef OPENSSL_NO_CAST
#endif
