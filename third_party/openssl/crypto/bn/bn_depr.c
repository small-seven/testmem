#include <openssl/opensslconf.h>
#if OPENSSL_API_COMPAT >= 0x00908000L
#else
# include <stdio.h>
# include <time.h>
# include "internal/cryptlib.h"
# include "bn_local.h"
#endif
