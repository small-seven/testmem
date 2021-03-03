#include <string.h>
#include <openssl/ec.h>
#include <openssl/evp.h>
#include "ec_local.h"
#define ECDH_KDF_MAX    (1 << 30)
