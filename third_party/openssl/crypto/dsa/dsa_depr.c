#define xxxHASH    EVP_sha1()
#include <openssl/opensslconf.h>
#if OPENSSL_API_COMPAT >= 0x00908000L
#else
# include <stdio.h>
# include <time.h>
# include "internal/cryptlib.h"
# include <openssl/evp.h>
# include <openssl/bn.h>
# include <openssl/dsa.h>
# include <openssl/sha.h>
#endif
