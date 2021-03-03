#include "ecma-alloc.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-eval.h"
#include "ecma-gc.h"
#include "ecma-function-object.h"
#include "ecma-lex-env.h"
#include "ecma-try-catch-macro.h"
#include "js-parser.h"
#include "lit-magic-strings.h"
#if ENABLED (JERRY_LINE_INFO) || ENABLED (JERRY_ERROR_MESSAGES) || ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#include "jcontext.h"
#endif /* ENABLED (JERRY_LINE_INFO) || ENABLED (JERRY_ERROR_MESSAGES) || ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-function.inc.h"
#define BUILTIN_UNDERSCORED_ID function
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_LINE_INFO) || ENABLED (JERRY_ERROR_MESSAGES) || ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif /* ENABLED (JERRY_LINE_INFO) || ENABLED (JERRY_ERROR_MESSAGES) || ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
