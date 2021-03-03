#include <string.h>
#include "jerryscript.h"
#include "jerryscript-ext/arg.h"
#include "test-common.h"
typedef struct
{
  int x;
} my_type_a_t;
typedef struct
{
  bool x;
} my_type_b_t;
typedef enum
{
  DOUBLE_VALUE,
  BOOL_VALUE
} union_type_t;
typedef struct
{
  union_type_t type_of_value;
  union
  {
    double double_field;
    bool bool_field;
  } value;
#define jerryx_arg_double_or_bool_t(value_ptr, coerce_or_not, optional_or_not, last_parameter) \
