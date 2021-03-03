#include "ecma-alloc.h"
#include "ecma-array-object.h"
#include "ecma-builtin-helpers.h"
#include "ecma-builtins.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-property-hashmap.h"
#include "ecma-helpers.h"
#include "ecma-number-arithmetic.h"
#include "ecma-objects.h"
#include "ecma-objects-general.h"
#include "ecma-function-object.h"
#if ENABLED (JERRY_BUILTIN_ARRAY)
#else /* !ENABLED (JERRY_BUILTIN_ARRAY) */
#endif /* (ENABLED (JERRY_BUILTIN_ARRAY)) */
#define ECMA_FAST_ARRAY_UINT32_DIRECT_STRING_PROP_TYPE 0x80
#if ENABLED (JERRY_SYSTEM_ALLOCATOR)
#define ECMA_FAST_ARRAY_MAX_INITIAL_LENGTH (1 << 17)
#else
#define ECMA_FAST_ARRAY_MAX_INITIAL_LENGTH (1 << 13)
#endif
#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_PROPRETY_HASHMAP)
#endif /* ENABLED (JERRY_PROPRETY_HASHMAP) */
#if ENABLED (JERRY_PROPRETY_HASHMAP)
#endif /* ENABLED (JERRY_PROPRETY_HASHMAP) */
#if ENABLED (JERRY_PROPRETY_HASHMAP)
#endif /* ENABLED (JERRY_PROPRETY_HASHMAP) */
#if ENABLED (JERRY_PROPRETY_HASHMAP)
#endif /* ENABLED (JERRY_PROPRETY_HASHMAP) */
#define ECMA_FAST_ARRAY_DATA_PROP_FLAGS (ECMA_PROP_IS_VALUE_DEFINED \
