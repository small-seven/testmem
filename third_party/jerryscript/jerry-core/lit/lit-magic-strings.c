#include "jcontext.h"
#include "lit-magic-strings.h"
#include "lit-strings.h"
#define LIT_EXTERNAL_MAGIC_STRING_LIMIT (UINT32_MAX / 2)
#define LIT_MAGIC_STRING_FIRST_STRING_WITH_SIZE(size, id)
#define LIT_MAGIC_STRING_DEF(id, utf8_string) \
#include "lit-magic-strings.inc.h"
#undef LIT_MAGIC_STRING_DEF
#undef LIT_MAGIC_STRING_FIRST_STRING_WITH_SIZE
#define LIT_MAGIC_STRING_FIRST_STRING_WITH_SIZE(size, id)
#define LIT_MAGIC_STRING_DEF(id, utf8_string) \
#include "lit-magic-strings.inc.h"
#undef LIT_MAGIC_STRING_DEF
#undef LIT_MAGIC_STRING_FIRST_STRING_WITH_SIZE
#define LIT_MAGIC_STRING_DEF(id, utf8_string)
#define LIT_MAGIC_STRING_FIRST_STRING_WITH_SIZE(size, id) \
#include "lit-magic-strings.inc.h"
#undef LIT_MAGIC_STRING_DEF
#undef LIT_MAGIC_STRING_FIRST_STRING_WITH_SIZE
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
