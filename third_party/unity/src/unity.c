#include "unity.h"
#include <stddef.h>
#ifdef AVR
#include <avr/pgmspace.h>
#else
#define PROGMEM
#endif
#ifdef UNITY_OMIT_OUTPUT_CHAR_HEADER_DECLARATION
#endif
#define UNITY_FAIL_AND_BAIL   { Unity.CurrentTestFailed  = 1; UNITY_OUTPUT_FLUSH(); TEST_ABORT(); }
#define UNITY_IGNORE_AND_BAIL { Unity.CurrentTestIgnored = 1; UNITY_OUTPUT_FLUSH(); TEST_ABORT(); }
#define RETURN_IF_FAIL_OR_IGNORE if (Unity.CurrentTestFailed || Unity.CurrentTestIgnored) return
#ifdef UNITY_OUTPUT_COLOR
#else
#endif
#ifndef UNITY_EXCLUDE_FLOAT
#endif
#ifdef UNITY_OUTPUT_COLOR
#endif
#ifdef UNITY_OUTPUT_COLOR
#endif
#ifdef UNITY_INCLUDE_PRINT_FORMATTED
#ifndef UNITY_EXCLUDE_FLOAT_PRINT
#endif
#ifdef UNITY_OUTPUT_COLOR
#endif
#endif /* ! UNITY_INCLUDE_PRINT_FORMATTED */
#ifndef UNITY_EXCLUDE_FLOAT_PRINT
#ifdef UNITY_INCLUDE_DOUBLE
#else
#endif
#ifndef UNITY_ROUND_TIES_AWAY_FROM_ZERO
#endif
#endif /* ! UNITY_EXCLUDE_FLOAT_PRINT */
#ifdef UNITY_OUTPUT_FOR_ECLIPSE
#else
#ifdef UNITY_OUTPUT_FOR_IAR_WORKBENCH
#else
#ifdef UNITY_OUTPUT_FOR_QT_CREATOR
#else
#endif
#endif
#endif
#ifndef UNITY_EXCLUDE_DETAILS
#endif
#define UnityPrintPointlessAndBail()       \
#ifdef UNITY_SUPPORT_64
#endif
#ifndef UNITY_EXCLUDE_FLOAT
#define UNITY_FLOAT_OR_DOUBLE_WITHIN(delta, expected, actual, diff)                           \
#ifndef UNITY_NAN_NOT_EQUAL_NAN
#else
#endif
#ifndef UNITY_EXCLUDE_FLOAT_PRINT
#else
#endif /* UNITY_EXCLUDE_FLOAT_PRINT */
#ifndef UNITY_EXCLUDE_FLOAT_PRINT
#else
#endif
#endif /* not UNITY_EXCLUDE_FLOAT */
#ifndef UNITY_EXCLUDE_DOUBLE
#ifndef UNITY_EXCLUDE_FLOAT_PRINT
#else
#endif
#endif /* not UNITY_EXCLUDE_DOUBLE */
#ifdef UNITY_SUPPORT_64
#endif
#ifdef UNITY_SUPPORT_64
#endif
#ifndef UNITY_EXCLUDE_FLOAT
#endif
#ifndef UNITY_EXCLUDE_DOUBLE
#endif
#ifdef UNITY_SUPPORT_64
#endif
#ifndef UNITY_EXCLUDE_FLOAT
#endif
#ifndef UNITY_EXCLUDE_DOUBLE
#endif
#ifndef UNITY_EXCLUDE_DETAILS
#endif
#ifdef UNITY_DIFFERENTIATE_FINAL_FAIL
#endif
#ifdef UNITY_USE_COMMAND_LINE_ARGS
#endif /* UNITY_USE_COMMAND_LINE_ARGS */
