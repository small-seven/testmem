#include <stdio.h>
#include "internal/cryptlib.h"
#include "internal/numbers.h"
#include <limits.h>
#include <openssl/asn1.h>
#include <openssl/bn.h>
#include "asn1_local.h"
#define ABS_INT64_MIN ((uint64_t)INT64_MAX + (-(INT64_MIN + INT64_MAX)))
