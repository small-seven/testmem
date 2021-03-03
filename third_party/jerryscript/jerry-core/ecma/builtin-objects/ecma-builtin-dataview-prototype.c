#include "ecma-dataview-object.h"
#include "ecma-gc.h"
#if ENABLED (JERRY_ES2015_BUILTIN_DATAVIEW)
#ifdef CONFIG_DISABLE_ES2015_TYPEDARRAY_BUILTIN
#error "DataView builtin requires ES2015 TypedArray builtin"
#endif /* !CONFIG_DISABLE_ES2015_TYPEDARRAY_BUILTIN */
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_CUSTOM_DISPATCH
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-dataview-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID dataview_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#endif /* ENABLED (JERRY_ES2015_BUILTIN_DATAVIEW */
