#include <math.h>
#include "ecma-arraybuffer-object.h"
#include "ecma-builtin-helpers.h"
#include "ecma-builtin-typedarray-helpers.h"
#include "ecma-builtins.h"
#include "ecma-comparison.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-function-object.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-iterator-object.h"
#include "ecma-number-object.h"
#include "ecma-objects.h"
#include "ecma-try-catch-macro.h"
#include "ecma-typedarray-object.h"
#include "jcontext.h"
#include "jmem.h"
#include "jrt-libc-includes.h"
#include "jrt.h"
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-typedarray-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID typedarray_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
typedef enum
{
  TYPEDARRAY_ROUTINE_EVERY, /**< routine: every ES2015, 22.2.3.7 */
  TYPEDARRAY_ROUTINE_SOME, /**< routine: some ES2015, 22.2.3.9 */
  TYPEDARRAY_ROUTINE_FOREACH, /**< routine: forEach ES2015, 15.4.4.18 */
  TYPEDARRAY_ROUTINE__COUNT /**< count of the modes */
} typedarray_routine_mode;
#if ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */
