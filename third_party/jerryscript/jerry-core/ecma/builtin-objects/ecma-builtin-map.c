#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-container-object.h"
#if ENABLED (JERRY_ES2015_BUILTIN_MAP)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-map.inc.h"
#define BUILTIN_UNDERSCORED_ID map
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_MAP) */
