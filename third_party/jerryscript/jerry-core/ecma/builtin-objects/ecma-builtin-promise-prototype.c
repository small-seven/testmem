#include "ecma-globals.h"
#include "ecma-promise-object.h"
#if ENABLED (JERRY_ES2015_BUILTIN_PROMISE)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-promise-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID promise_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_PROMISE) */
