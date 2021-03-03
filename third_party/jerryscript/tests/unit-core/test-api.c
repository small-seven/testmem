#include "config.h"
#include "jerryscript.h"
#include "test-common.h"
#define JERRY_NATIVE_HANDLE_INFO_FOR_CTYPE(c_type) _jerry_object_native_info_##c_type
#define JERRY_DEFINE_NATIVE_HANDLE_INFO(c_type, native_free_cb) \
#define JERRY_MAGIC_STRING_ITEMS \
#define JERRY_MAGIC_STRING_DEF(NAME, STRING) \
#undef JERRY_MAGIC_STRING_DEF
#define JERRY_MAGIC_STRING_DEF(NAME, STRING) \
#undef JERRY_MAGIC_STRING_DEF
#define JERRY_MAGIC_STRING_DEF(NAME, STRING) \
#undef JERRY_MAGIC_STRING_DEF
