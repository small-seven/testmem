#include <stdio.h>
#include "internal/cryptlib.h"
#include "dh_local.h"
#include <openssl/bn.h>
#include "crypto/bn_dh.h"
#define make_dh(x) \
