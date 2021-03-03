#include "ecma-builtins.h"
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-float64array-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID float64array_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */
