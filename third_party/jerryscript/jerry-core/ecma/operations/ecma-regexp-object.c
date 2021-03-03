#include "ecma-alloc.h"
#include "ecma-array-object.h"
#include "ecma-builtin-helpers.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-objects.h"
#include "ecma-regexp-object.h"
#include "ecma-try-catch-macro.h"
#include "jcontext.h"
#include "jrt-libc-includes.h"
#include "lit-char-helpers.h"
#include "re-compiler.h"
#if ENABLED (JERRY_BUILTIN_REGEXP)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define RE_GLOBAL_CAPTURE 0
#define RE_IS_CAPTURE_GROUP(x) (((x) < RE_OP_NON_CAPTURE_GROUP_START) ? 1 : 0)
#if !ENABLED (JERRY_ES2015)
#endif /* !ENABLED (JERRY_ES2015) */
#if !ENABLED (JERRY_ES2015)
#else /* ENABLED (JERRY_ES2015) */
#endif /* !ENABLED (JERRY_ES2015) */
#if (JERRY_STACK_LIMIT != 0)
#endif /* JERRY_STACK_LIMIT != 0 */
#if ENABLED (JERRY_ES2015)
#else /* !ENABLED (JERRY_ES2015) */
#endif /* ENABLED (JERRY_ES2015) */
#if ENABLED (JERRY_ES2015)
#else /* !ENABLED (JERRY_ES2015) */
#endif /* ENABLED (JERRY_ES2015) */
#endif /* ENABLED (JERRY_BUILTIN_REGEXP) */
