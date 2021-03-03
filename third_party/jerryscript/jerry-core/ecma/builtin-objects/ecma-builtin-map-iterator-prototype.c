#include "ecma-builtin-helpers.h"
#include "ecma-builtins.h"
#include "ecma-container-object.h"
#if ENABLED (JERRY_ES2015_BUILTIN_MAP)
#if !ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#error "Map iterator builtin requires ES2015 iterator builtin"
#endif /* !ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-map-iterator-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID map_iterator_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_MAP) */
