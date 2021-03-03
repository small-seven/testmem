#include "jerryscript.h"
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#include "test-common.h"
#include <stdio.h>
typedef struct
{
  jerry_typedarray_type_t typedarray_type; /**< what kind of TypedArray */
  char *constructor_name; /**< JS constructor name for TypedArray */
  uint32_t element_count; /**< number of elements for the TypedArray */
  uint32_t bytes_per_element; /**< bytes per elment of the given typedarray_type */
} test_entry_t;
#define TEST_VALUE_AT(TYPE, BUFFER, OFFSET, VALUE) TEST_ASSERT (((TYPE *) BUFFER)[OFFSET] == (TYPE) (VALUE))
#undef TEST_VALUE_AT
#define TEST_ENTRY(TYPE, CONSTRUCTOR, COUNT, BYTES_PER_ELEMENT) \
#undef TEST_ENTRY
