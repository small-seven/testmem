#include "ecma-alloc.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-string-object.h"
#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#include "ecma-symbol-object.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
#include "ecma-try-catch-macro.h"
#include "jrt.h"
#if ENABLED (JERRY_BUILTIN_STRING)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-string.inc.h"
#define BUILTIN_UNDERSCORED_ID string
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
#endif /* ENABLED (JERRY_BUILTIN_STRING) */
