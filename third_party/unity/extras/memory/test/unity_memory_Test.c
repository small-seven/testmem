#include "unity.h"
#include "unity_memory.h"
#include "unity_output_Spy.h"
#include <stdlib.h>
#include <string.h>
#ifdef UNITY_EXCLUDE_STDLIB_MALLOC
#else
#endif
#define EXPECT_ABORT_BEGIN \
#define EXPECT_ABORT_END \
#ifdef __STDC_VERSION__
#ifdef UNITY_SUPPORT_VARIADIC_MACROS
#define USING_SPY_AS(a)                    EXPAND_AND_USE_2ND(ASSIGN_VALUE(a), 0)
#define ASSIGN_VALUE(a)                    VAL_##a
#define VAL_UnityOutputCharSpy_OutputChar  0, 1
#define EXPAND_AND_USE_2ND(a, b)           SECOND_PARAM(a, b, throwaway)
#define SECOND_PARAM(a, b, ...)            b
#if USING_SPY_AS(UNITY_OUTPUT_CHAR)
#endif
#endif /* UNITY_SUPPORT_VARIADIC_MACROS */
#else  /* __STDC_VERSION__ else */
#define UnityOutputCharSpy_OutputChar 42
#if UNITY_OUTPUT_CHAR == UnityOutputCharSpy_OutputChar /* Works if no -Wundef -Werror */
#endif
#undef UnityOutputCharSpy_OutputChar
#endif /* __STDC_VERSION__ */
#ifdef USING_OUTPUT_SPY
#else
#endif
#ifdef USING_OUTPUT_SPY
#else
#endif
#ifdef USING_OUTPUT_SPY
#else
#endif
#ifdef USING_OUTPUT_SPY
#else
#endif
#ifdef USING_OUTPUT_SPY
#else
#endif
#define TEST_ASSERT_MEMORY_ALL_FREE_LIFO_ORDER(first_mem_ptr, ptr) \
#ifdef UNITY_EXCLUDE_STDLIB_MALLOC
#else
#endif
#ifdef UNITY_EXCLUDE_STDLIB_MALLOC
#else
#endif
#ifdef UNITY_EXCLUDE_STDLIB_MALLOC
#else
#endif
#ifdef UNITY_EXCLUDE_STDLIB_MALLOC
#else
#endif
