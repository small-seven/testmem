#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-typedarray-object.h"
#include "jrt.h"
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-int8array.inc.h"
#define BUILTIN_UNDERSCORED_ID int8array
#include "ecma-builtin-internal-routines-template.inc.h"
#include "ecma-builtin-typedarray-helpers.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */
