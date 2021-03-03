#include "avb_property_descriptor.h"
#include "avb_util.h"
typedef struct {
  const char* key;
  size_t key_size;
  const char* ret_value;
  size_t ret_value_size;
} PropertyIteratorData;
