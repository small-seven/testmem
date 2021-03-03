#include "ecma-globals.h"
#include "ecma-helpers.h"
#define ECMA_NUMBER_SIGN_POS (ECMA_NUMBER_FRACTION_WIDTH + \
#if !ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#elif ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#else /* !ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#if ENABLED (JERRY_NUMBER_TYPE_FLOAT64)
#else /* !ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#endif /* ENABLED (JERRY_NUMBER_TYPE_FLOAT64) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if defined (__GNUC__) || defined (__clang__)
#endif /* defined (__GNUC__) || defined (__clang__) */
