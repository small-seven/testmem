#include "jerryscript.h"
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#include "test-common.h"
typedef struct
{
  jerry_type_t type_info;
  jerry_value_t value;
} test_entry_t;
#define ENTRY(TYPE, VALUE) { TYPE, VALUE }
