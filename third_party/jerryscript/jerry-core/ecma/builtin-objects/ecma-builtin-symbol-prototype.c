#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-symbol-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID symbol_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
