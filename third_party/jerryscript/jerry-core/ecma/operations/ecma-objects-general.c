#include "ecma-array-object.h"
#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-function-object.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-objects-general.h"
#include "ecma-try-catch-macro.h"
#define ECMA_PROPERTY_TYPE_GENERIC ECMA_PROPERTY_TYPE_SPECIAL
#if ENABLED (JERRY_CPOINTER_32_BIT)
#else /* !ENABLED (JERRY_CPOINTER_32_BIT) */
#endif /* ENABLED (JERRY_CPOINTER_32_BIT) */
#if ENABLED (JERRY_CPOINTER_32_BIT)
#endif /* ENABLED (JERRY_CPOINTER_32_BIT) */
#undef ECMA_PROPERTY_TYPE_GENERIC
