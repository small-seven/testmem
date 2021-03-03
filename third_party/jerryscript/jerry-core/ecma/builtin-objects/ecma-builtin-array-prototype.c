#include "ecma-alloc.h"
#include "ecma-array-object.h"
#include "ecma-builtin-helpers.h"
#include "ecma-builtins.h"
#include "ecma-comparison.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-function-object.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-iterator-object.h"
#include "ecma-objects.h"
#include "ecma-string-object.h"
#include "lit-char-helpers.h"
#include "jrt.h"
#if ENABLED (JERRY_BUILTIN_ARRAY)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_CUSTOM_DISPATCH
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-array-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID array_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_ES2015_CLASS)
#else /* !ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#else /* !ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#else /* !ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
typedef enum
{
  ARRAY_ROUTINE_EVERY, /**< Array.every: ECMA-262 v5, 15.4.4.16 */
  ARRAY_ROUTINE_SOME, /**< Array.some: ECMA-262 v5, 15.4.4.17 */
  ARRAY_ROUTINE_FOREACH, /**< Array.forEach: ECMA-262 v5, 15.4.4.18 */
  ARRAY_ROUTINE__COUNT /**< count of the modes */
} array_routine_mode;
#if ENABLED (JERRY_ES2015_CLASS)
#else /* !ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#else /* !ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#if ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
#if ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#endif /* ENABLED (JERRY_BUILTIN_ARRAY) */
