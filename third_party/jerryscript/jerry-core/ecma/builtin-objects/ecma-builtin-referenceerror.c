#include "ecma-alloc.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-builtin-helpers.h"
#include "ecma-objects.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"
#if ENABLED (JERRY_BUILTIN_ERRORS)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-referenceerror.inc.h"
#define BUILTIN_UNDERSCORED_ID reference_error
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_BUILTIN_ERRORS) */
