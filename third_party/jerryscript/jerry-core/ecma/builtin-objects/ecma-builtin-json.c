#include "ecma-alloc.h"
#include "ecma-array-object.h"
#include "ecma-builtins.h"
#include "ecma-conversion.h"
#include "ecma-exceptions.h"
#include "ecma-function-object.h"
#include "ecma-gc.h"
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "ecma-builtin-helpers.h"
#include "ecma-objects.h"
#include "ecma-objects-general.h"
#include "jrt.h"
#include "jrt-libc-includes.h"
#include "lit-char-helpers.h"
#include "lit-globals.h"
#if ENABLED (JERRY_BUILTIN_JSON)
#define ECMA_BUILTINS_INTERNAL
#include "ecma-builtins-internal.h"
#define BUILTIN_INC_HEADER_NAME "ecma-builtin-json.inc.h"
#define BUILTIN_UNDERSCORED_ID json
#include "ecma-builtin-internal-routines-template.inc.h"
#define ECMA_JSON_HEX_ESCAPE_SEQUENCE_LENGTH (4)
typedef enum
{
  TOKEN_INVALID, /**< error token */
  TOKEN_END, /**< end of stream reached */
  TOKEN_NUMBER, /**< JSON number */
  TOKEN_STRING, /**< JSON string */
  TOKEN_NULL, /**< JSON null primitive value */
  TOKEN_TRUE, /**< JSON true primitive value */
  TOKEN_FALSE, /**< JSON false primitive value */
  TOKEN_LEFT_BRACE, /**< JSON left brace */
  TOKEN_RIGHT_BRACE, /**< JSON right brace */
  TOKEN_LEFT_SQUARE, /**< JSON left square bracket */
  TOKEN_RIGHT_SQUARE, /**< JSON right square bracket */
  TOKEN_COMMA, /**< JSON comma */
  TOKEN_COLON /**< JSON colon */
} ecma_json_token_type_t;
typedef struct
{
  ecma_json_token_type_t type; /**< type of the current token */
  const lit_utf8_byte_t *current_p; /**< current position of the string processed by the parser */
  const lit_utf8_byte_t *end_p; /**< end of the string processed by the parser */

  /**
   * Fields depending on type.
   */
  union
  {
    ecma_string_t *string_p; /**< when type is string_token it contains the string */
    ecma_number_t number; /**< when type is number_token, it contains the value of the number */
  } u;
#endif /* ENABLED (JERRY_BUILTIN_JSON) */
