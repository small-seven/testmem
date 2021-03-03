#include <stdarg.h>
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-symbol-object.h"
#include "jcontext.h"
#include "jrt.h"
#if ENABLED (JERRY_LINE_INFO)
#include "vm.h"
#endif /* ENABLED (JERRY_LINE_INFO) */
typedef struct
{
  ecma_standard_error_t error_type; /**< Native error type */
  ecma_builtin_id_t error_prototype_id; /**< ID of the error prototype */
} ecma_error_mapping_t;
#define ERROR_ELEMENT(TYPE, ID) { TYPE, ID }
#if ENABLED (JERRY_BUILTIN_ERRORS)
#endif /* ENABLED (JERRY_BUILTIN_ERRORS) */
#undef ERROR_ELEMENT
#if ENABLED (JERRY_BUILTIN_ERRORS)
#else
#endif /* ENABLED (JERRY_BUILTIN_ERRORS) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_ERROR_MESSAGES)
#if ENABLED (JERRY_ES2015_BUILTIN_SYMBOL)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_SYMBOL) */
#endif /* ENABLED (JERRY_ERROR_MESSAGES) */
