#include <math.h>
#include "ecma-globals.h"
#include "ecma-helpers.h"
#include "jrt-libc-includes.h"
#include "lit-char-helpers.h"
#include "lit-magic-strings.h"
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
typedef struct
{
  uint64_t lo; /**< low 64 bits */
  uint64_t hi; /**< high 64 bits */
} ecma_uint128_t;
#define ECMA_UINT128_IS_ZERO(name) \
#define ECMA_UINT128_LEFT_SHIFT_MAX63(name, shift) \
#define ECMA_UINT128_RIGHT_SHIFT_MAX63(name, shift) \
#define ECMA_UINT128_ADD(name_add_to, name_to_add) \
#define ECMA_UINT128_MUL10(name) \
#define ECMA_UINT128_DIV10(name) \
#if defined (__GNUC__) || defined (__clang__)
#define ECMA_UINT128_CLZ_MAX63(name) \
#define ECMA_UINT128_CLZ_MAX4(name) \
#else /* !__GNUC__ && !__clang__ */
#define ECMA_UINT128_CLZ_MAX63(name) \
#define ECMA_UINT128_CLZ_MAX4(name) \
#endif /* __GNUC__ || __clang__ */
#define NUMBER_MAX_DECIMAL_EXPONENT 308
#define NUMBER_MIN_DECIMAL_EXPONENT -324
#elif !ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#define NUMBER_MAX_DECIMAL_EXPONENT 38
#define NUMBER_MIN_DECIMAL_EXPONENT -45
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#define EPSILON 0.0000001
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#elif !ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
