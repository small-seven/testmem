#include <math.h>
#include "ecma-alloc.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-string-object.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"
#include "jrt-libc-includes.h"
#if ENABLED (JERRY_BUILTIN_NUMBER)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_CUSTOM_DISPATCH
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-number-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID number_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
typedef enum
{
  NUMBER_ROUTINE_TO_FIXED,       /**< Number.prototype.toFixed: ECMA-262 v5, 15.7.4.4 */
  NUMBER_ROUTINE_TO_EXPONENTIAL, /**< Number.prototype.toExponential: ECMA-262 v5, 15.7.4.5 */
  NUMBER_ROUTINE_TO_PRECISION,   /**< Number.prototype.toPrecision: ECMA-262 v5, 15.7.4.6 */
  NUMBER_ROUTINE__COUNT,         /**< count of the modes */
} number_routine_mode_t;
#endif /* ENABLED (JERRY_BUILTIN_NUMBER) */
