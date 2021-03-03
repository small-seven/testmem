#include "ecma-alloc.h"
#include "ecma-array-object.h"
#include "ecma-builtin-helpers.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-function-object.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-iterator-object.h"
#include "ecma-objects.h"
#include "ecma-string-object.h"
#include "ecma-try-catch-macro.h"
#include "jcontext.h"
#include "jrt.h"
#include "jrt-libc-includes.h"
#include "lit-char-helpers.h"
#if ENABLED (JERRY_BUILTIN_REGEXP)
#include "ecma-regexp-object.h"
#endif /* ENABLED (JERRY_BUILTIN_REGEXP) */
#if ENABLED (JERRY_BUILTIN_STRING)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_CUSTOM_DISPATCH
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-string-prototype.inc.h"
#define BUILTIN_UNDERSCORED_ID string_prototype
#include "ecma-builtin-internal-routines-template.inc.h"
#if ENABLED (JERRY_BUILTIN_REGEXP)
typedef struct
{
  /* General part. */
  bool is_regexp; /**< whether we search a regexp or string */
  bool is_global; /**< global search or not */
  bool is_replace_callable; /**< replace part is callable or not */
  ecma_value_t input_string; /**< input string */
  ecma_length_t input_length; /**< input string length */
  ecma_value_t regexp_or_search_string; /**< regular expression or search string
                                         * depending on the value of is_regexp */
  ecma_length_t match_start; /**< starting position of the match */
  ecma_length_t match_end; /**< end position of the match */

  /* Replace value callable part. */
  ecma_object_t *replace_function_p; /**< replace function */

  /* Replace value string part. */
  ecma_string_t *replace_string_p; /**< replace string */
  lit_utf8_byte_t *replace_str_curr_p; /**< replace string iterator */
} ecma_builtin_replace_search_ctx_t;
#endif /* ENABLED (JERRY_BUILTIN_REGEXP) */
#if ENABLED (JERRY_BUILTIN_REGEXP)
#else /* !ENABLED (JERRY_BUILTIN_REGEXP) */
#endif /* ENABLED (JERRY_BUILTIN_REGEXP) */
#if ENABLED (JERRY_BUILTIN_REGEXP)
#else /* !ENABLED (JERRY_BUILTIN_REGEXP) */
#endif /* ENABLED (JERRY_BUILTIN_REGEXP) */
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#if ENABLED (JERRY_BUILTIN_REGEXP)
#endif /* ENABLED (JERRY_BUILTIN_REGEXP) */
#if ENABLED (JERRY_BUILTIN_ANNEXB)
#endif /* ENABLED (JERRY_BUILTIN_ANNEXB) */
#if ENABLED (JERRY_ES2015_BUILTIN)
#endif /* ENABLED (JERRY_ES2015_BUILTIN) */
#if ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#endif /* ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
#endif /* ENABLED (JERRY_BUILTIN_STRING) */
