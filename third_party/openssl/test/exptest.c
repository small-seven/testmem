#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "internal/nelem.h"
#include <openssl/bio.h>
#include <openssl/bn.h>
#include <openssl/rand.h>
#include <openssl/err.h>
#include "testutil.h"
#define NUM_BITS        (BN_BITS2 * 4)
#define BN_print_var(v) test_output_bignum(#v, v)
