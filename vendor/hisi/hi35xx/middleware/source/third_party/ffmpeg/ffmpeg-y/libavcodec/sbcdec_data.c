#include <stdint.h>
#include "sbcdec_data.h"
#include "sbc.h"
#define SS4(val)  ((int32_t)val >> 12)
#define SS8(val)  ((int32_t)val >> 14)
#define SN4(val)  ((int32_t)val >> 11 + 1 + SBCDEC_FIXED_EXTRA_BITS)
#define SN8(val)  ((int32_t)val >> 11 + 1 + SBCDEC_FIXED_EXTRA_BITS)
