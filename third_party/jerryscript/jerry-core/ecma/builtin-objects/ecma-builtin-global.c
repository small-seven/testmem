#include "ecma-alloc.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-eval.h"
#include "ecma-exceptions.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-try-catch-macro.h"
#include "jrt.h"
#include "lit-char-helpers.h"
#include "lit-magic-strings.h"
#include "lit-strings.h"
#include "vm.h"
#include "jcontext.h"
#include "jrt-libc-includes.h"
#include "jrt-bit-fields.h"
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_CUSTOM_DISPATCH
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-global.inc.h"
#define BUILTIN_UNDERSCORED_ID global
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#define URI_ENCODED_BYTE_SIZE (3)
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#define ECMA_ESCAPE_MAXIMUM_BYTE_VALUE (255)
#define ECMA_ESCAPE_ENCODED_UNICODE_CHARACTER_SIZE (6)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
