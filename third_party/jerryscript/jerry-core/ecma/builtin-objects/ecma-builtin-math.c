#include <math.h>
#include "ecma-alloc.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-number-arithmetic.h"
#include "ecma-objects.h"
#include "ecma-objects-general.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"
#include "jrt-libc-includes.h"
#if ENABLED (JERRY_BUILTIN_MATH)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_CUSTOM_DISPATCH
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-math.inc.h"
#define BUILTIN_UNDERSCORED_ID math
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#endif /* ENABLED (JERRY_BUILTIN_MATH) */
