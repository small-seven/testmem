#include <stdio.h>
#include <time.h>
#include "internal/cryptlib.h"
#include "bn_local.h"
#include <openssl/rand.h>
#include <openssl/sha.h>
typedef enum bnrand_flag_e {
    NORMAL, TESTING, PRIVATE
} BNRAND_FLAG;
