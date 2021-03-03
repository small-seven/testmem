#ifndef OPENSSL_NO_SRP
# include "internal/cryptlib.h"
# include <openssl/sha.h>
# include <openssl/srp.h>
# include <openssl/evp.h>
# include "crypto/bn_srp.h"
# define KNOWN_GN_NUMBER sizeof(knowngN) / sizeof(SRP_gN)
#endif
