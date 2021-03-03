#include "ecma-alloc.h"
#include "ecma-array-object.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-objects.h"
#include "ecma-try-catch-macro.h"
#include "lit-char-helpers.h"
#if ENABLED (JERRY_BUILTIN_REGEXP)
#include "ecma-regexp-object.h"
#include "re-compiler.h"
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-regexp-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID regexp_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_ES2015)
#endif /* ENABLED (JERRY_ES2015) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#endif /* ENABLED (JERRY_BUILTIN_REGEXP) */
