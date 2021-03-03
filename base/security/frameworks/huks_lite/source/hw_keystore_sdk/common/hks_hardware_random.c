#if defined(_STD_LIB_SOUTH_) & defined(_HILINK_PRODUCT_)
#include "hks_hardware_random.h"
#include <stdint.h>
#include <mbedtls/entropy.h>
#include "securec.h"
#include "base/security_random.h"
#include "hks_errno.h"
#include "hks_types.h"
#define ITERATION_NUM_PADDING 3
#endif
