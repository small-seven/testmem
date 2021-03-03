#include "jerryscript.h"
#include "test-common.h"
#define T(op, lhs, rhs, res) \
typedef struct
{
  jerry_binary_operation_t op;
  jerry_value_t lhs;
  jerry_value_t rhs;
  bool expected;
} test_entry_t;
