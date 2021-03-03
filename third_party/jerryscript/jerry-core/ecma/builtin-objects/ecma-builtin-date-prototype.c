#include <math.h>
#include "ecma-alloc.h"
#include "ecma-builtin-helpers.h"
#include "ecma-exceptions.h"
#include "ecma-function-object.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-try-catch-macro.h"
#if ENABLED (JERRY_BUILTIN_DATE)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_CUSTOM_DISPATCH
#define BUILTIN_DATE_FUNCTION_IS_UTC(builtin_routine_id) \
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-date-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID date_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#define ECMA_DATE_PROTOTYPE_IS_SET_YEAR_ROUTINE(builtin_routine_id) \
#else /* !ENABLED (JERRY_BUILTIN_ANNEXB) */
#define ECMA_DATE_PROTOTYPE_IS_SET_YEAR_ROUTINE(builtin_routine_id) \
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#undef ECMA_DATE_PROTOTYPE_IS_SET_YEAR_ROUTINE
#endif /* ENABLED (JERRY_BUILTIN_DATE) */
