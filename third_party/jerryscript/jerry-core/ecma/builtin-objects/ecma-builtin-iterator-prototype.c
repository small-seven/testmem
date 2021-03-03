#include "ecma-builtin-helpers.h"
#include "ecma-builtins.h"
#include "ecma-iterator-object.h"
#if ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-iterator-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID iterator_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#endif /* ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
