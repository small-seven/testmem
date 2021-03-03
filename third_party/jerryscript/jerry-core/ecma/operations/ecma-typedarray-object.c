#include <math.h>
#include "ecma-typedarray-object.h"
#include "ecma-arraybuffer-object.h"
#include "ecma-function-object.h"
#include "ecma-builtin-helpers.h"
#include "ecma-try-catch-macro.h"
#include "ecma-objects.h"
#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "jcontext.h"
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#define ECMA_FIRST_TYPEDARRAY_BUILTIN_ROUTINE_ID ECMA_BUILTIN_ID_INT8ARRAY
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#define ECMA_LAST_TYPEDARRAY_BUILTIN_ROUTINE_ID ECMA_BUILTIN_ID_FLOAT64ARRAY
#else /* !ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#define ECMA_LAST_TYPEDARRAY_BUILTIN_ROUTINE_ID ECMA_BUILTIN_ID_FLOAT32ARRAY
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#define ECMA_FIRST_TYPEDARRAY_BUILTIN_PROTOTYPE_ID ECMA_BUILTIN_ID_INT8ARRAY_PROTOTYPE
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */