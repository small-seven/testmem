#include "debugger-sha1.h"
#include "jext-common.h"
#if defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)
typedef struct
{
  uint32_t total[2]; /**< number of bytes processed */
  uint32_t state[5]; /**< intermediate digest state */
  uint8_t buffer[64]; /**< data block being processed */
} jerryx_sha1_context;
#define JERRYX_SHA1_GET_UINT32_BE(n, b, i) \
#define JERRYX_SHA1_PUT_UINT32_BE(n, b, i) \
#define JERRYX_SHA1_P(a, b, c, d, e, x) \
#define JERRYX_SHA1_SHIFT(x, n) ((x << n) | ((x & 0xFFFFFFFF) >> (32 - n)))
#define JERRYX_SHA1_R(t) \
#define JERRYX_SHA1_F(x, y, z) (z ^ (x & (y ^ z)))
#undef JERRYX_SHA1_F
#define JERRYX_SHA1_F(x, y, z) (x ^ y ^ z)
#undef JERRYX_SHA1_F
#define JERRYX_SHA1_F(x, y, z) ((x & y) | (z & (x | y)))
#undef JERRYX_SHA1_F
#define JERRYX_SHA1_F(x, y, z) (x ^ y ^ z)
#undef JERRYX_SHA1_F
#undef JERRYX_SHA1_SHIFT
#undef JERRYX_SHA1_R
#undef JERRYX_SHA1_P
#undef JERRYX_SHA1_GET_UINT32_BE
#undef JERRYX_SHA1_PUT_UINT32_BE
#endif /* defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1) */
