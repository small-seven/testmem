#include <openssl/opensslconf.h>
#if OPENSSL_API_COMPAT >= 0x00908000L
#else
# include <stdio.h>
# include "internal/cryptlib.h"
# include <openssl/bn.h>
# include <openssl/dh.h>
#endif
