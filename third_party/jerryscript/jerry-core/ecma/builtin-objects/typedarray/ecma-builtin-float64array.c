#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-typedarray-object.h"
#include "jrt.h"
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-float64array.inc.h"
#define BUILTIN_UNDERSCORED_ID float64array
#include "ecma-builtin-internal-routines-template.inc.h"
#include "ecma-builtin-typedarray-helpers.h"
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */
