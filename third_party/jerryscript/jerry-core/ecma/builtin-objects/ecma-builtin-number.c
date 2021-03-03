#include <math.h>
#include "ecma-alloc.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-number-object.h"
#include "ecma-objects.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"
#if ENABLED (JERRY_BUILTIN_NUMBER)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-number.inc.h"
#define BUILTIN_UNDERSCORED_ID number
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#endif /* ENABLED (JERRY_BUILTIN_NUMBER) */
