#include "ecma-builtin-helpers.h"
#include "ecma-builtins.h"
#include "ecma-iterator-object.h"
#include "ecma-typedarray-object.h"
#if ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#if !ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#error "Iterator builtin requires ES2015 symbol builtin"
#endif /* !ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-array-iterator-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID array_iterator_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */
#if ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_TYPEDARRAY) */
#endif /* ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
