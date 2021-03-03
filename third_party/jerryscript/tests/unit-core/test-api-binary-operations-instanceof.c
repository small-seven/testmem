#include "jerryscript.h"
#include "test-common.h"
#define T(lhs, rhs, res) \
typedef struct
{
  jerry_value_t lhs;
  jerry_value_t rhs;
  bool expected;
} test_entry_t;
