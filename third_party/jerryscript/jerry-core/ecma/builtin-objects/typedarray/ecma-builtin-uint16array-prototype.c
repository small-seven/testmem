#include "ecma-builtins.h"
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-uint16array-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID uint16array_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */
