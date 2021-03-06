#include "debugger.h"
#include "ecma-exceptions.h"
#include "ecma-helpers.h"
#include "ecma-literal-storage.h"
#include "ecma-module.h"
#include "jcontext.h"
#include "js-parser-internal.h"
#if ENABLED (JERRY_PARSER)
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if !ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* !ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if !ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* !ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#else /* !ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#define PARSER_READ_IDENTIFIER_INDEX(name) \
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#undef PARSER_READ_IDENTIFIER_INDEX
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#define PARSER_NEXT_BYTE(page_p, offset) \
#define PARSER_NEXT_BYTE_UPDATE(page_p, offset, real_offset) \
#if ENABLED (JERRY_SNAPSHOT_SAVE)
#endif /* ENABLED (JERRY_SNAPSHOT_SAVE) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if PARSER_MAXIMUM_CODE_SIZE <= 65535
#else /* PARSER_MAXIMUM_CODE_SIZE > 65535 */
#endif /* PARSER_MAXIMUM_CODE_SIZE <= 65535 */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_SNAPSHOT_SAVE)
#endif /* ENABLED (JERRY_SNAPSHOT_SAVE) */
#if ENABLED (JERRY_SNAPSHOT_SAVE)
#endif /* ENABLED (JERRY_SNAPSHOT_SAVE) */
#if ENABLED (JERRY_MEM_STATS)
#endif /* ENABLED (JERRY_MEM_STATS) */
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#if PARSER_MAXIMUM_CODE_SIZE <= 65535
#else /* PARSER_MAXIMUM_CODE_SIZE > 65535 */
#endif /* PARSER_MAXIMUM_CODE_SIZE <= 65535 */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#else /* !ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#undef PARSER_NEXT_BYTE
#undef PARSER_NEXT_BYTE_UPDATE
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif /* ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#if ENABLED (JERRY_ES2015_CLASS)
#else /* !ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#if ENABLED (JERRY_ES2015_CLASS)
#else /* !ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#endif /* ENABLED (JERRY_PARSER) */
#if ENABLED (JERRY_PARSER)
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_ERROR_MESSAGES)
#else /* !ENABLED (JERRY_ERROR_MESSAGES) */
#endif /* ENABLED (JERRY_ERROR_MESSAGES) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif /* ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#else /* !ENABLED (JERRY_PARSER) */
#endif /* ENABLED (JERRY_PARSER) */
