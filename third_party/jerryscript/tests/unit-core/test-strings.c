#include "ecma-helpers.h"
#include "lit-strings.h"
#include "ecma-init-finalize.h"
#include "test-common.h"
#define test_iters (1024)
#define test_subiters (128)
#define max_bytes_in_string (65 * 1024)
#define max_code_units_in_string (max_bytes_in_string)
typedef enum
{
  CESU8_ANY_SIZE,
  CESU8_ONE_BYTE,
  CESU8_TWO_BYTES,
  CESU8_THREE_BYTES,
} utf8_char_size;
