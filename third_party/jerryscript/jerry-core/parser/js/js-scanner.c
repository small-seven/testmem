#include "js-parser-internal.h"
#include "js-scanner-internal.h"
#include "lit-char-helpers.h"
#if ENABLED (JERRY_PARSER)
typedef enum
{
  SCAN_MODE_PRIMARY_EXPRESSION,            /**< scanning primary expression */
  SCAN_MODE_PRIMARY_EXPRESSION_AFTER_NEW,  /**< scanning primary expression after new */
  SCAN_MODE_POST_PRIMARY_EXPRESSION,       /**< scanning post primary expression */
  SCAN_MODE_PRIMARY_EXPRESSION_END,        /**< scanning primary expression end */
  SCAN_MODE_STATEMENT,                     /**< scanning statement */
  SCAN_MODE_STATEMENT_OR_TERMINATOR,       /**< scanning statement or statement end */
  SCAN_MODE_STATEMENT_END,                 /**< scanning statement end */
  SCAN_MODE_VAR_STATEMENT,                 /**< scanning var statement */
  SCAN_MODE_FUNCTION_ARGUMENTS,            /**< scanning function arguments */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
  SCAN_MODE_CONTINUE_FUNCTION_ARGUMENTS,   /**< continue scanning function arguments */
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
  SCAN_MODE_PROPERTY_NAME,                 /**< scanning property name */
#if ENABLED (JERRY_ES2015_CLASS)
  SCAN_MODE_CLASS_DECLARATION,             /**< scanning class declaration */
  SCAN_MODE_CLASS_METHOD,                  /**< scanning class method */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
} scan_modes_t;
typedef enum
{
  SCAN_STACK_SCRIPT,                       /**< script */
  SCAN_STACK_EVAL_FUNCTION,                /**< evaluated function */
  SCAN_STACK_BLOCK_STATEMENT,              /**< block statement group */
  SCAN_STACK_FUNCTION_STATEMENT,           /**< function statement */
  SCAN_STACK_FUNCTION_EXPRESSION,          /**< function expression */
  SCAN_STACK_FUNCTION_PROPERTY,            /**< function expression in an object literal or class */
  SCAN_STACK_SWITCH_BLOCK,                 /**< block part of "switch" statement */
  SCAN_STACK_IF_STATEMENT,                 /**< statement part of "if" statements */
  SCAN_STACK_DO_STATEMENT,                 /**< statement part of "do" statements */
  SCAN_STACK_DO_EXPRESSION,                /**< expression part of "do" statements */
  SCAN_STACK_WHILE_EXPRESSION,             /**< expression part of "while" iterator */
  SCAN_STACK_PAREN_EXPRESSION,             /**< expression in brackets */
  SCAN_STACK_STATEMENT_WITH_EXPR,          /**< statement which starts with expression enclosed in brackets */
  /* The SCANNER_IS_FOR_START macro needs to be updated when the following constants are reordered. */
  SCAN_STACK_VAR,                          /**< var statement */
  SCAN_STACK_FOR_VAR_START,                /**< start of "for" iterator with var statement */
  SCAN_STACK_FOR_START,                    /**< start of "for" iterator */
  SCAN_STACK_FOR_CONDITION,                /**< condition part of "for" iterator */
  SCAN_STACK_FOR_EXPRESSION,               /**< expression part of "for" iterator */
  SCAN_STACK_SWITCH_EXPRESSION,            /**< expression part of "switch" statement */
  SCAN_STACK_CASE_STATEMENT,               /**< case statement inside a switch statement */
  SCAN_STACK_COLON_EXPRESSION,             /**< expression between a question mark and colon */
  SCAN_STACK_TRY_STATEMENT,                /**< try statement */
  SCAN_STACK_CATCH_STATEMENT,              /**< catch statement */
  SCAN_STACK_SQUARE_BRACKETED_EXPRESSION,  /**< square bracketed expression group */
  SCAN_STACK_OBJECT_LITERAL,               /**< object literal group */
#if ENABLED (JERRY_ES2015_OBJECT_INITIALIZER)
  SCAN_STACK_COMPUTED_PROPERTY,            /**< computed property name */
#endif /* ENABLED (JERRY_ES2015_OBJECT_INITIALIZER) */
#if ENABLED (JERRY_ES2015_TEMPLATE_STRINGS)
  SCAN_STACK_TEMPLATE_STRING,              /**< template string */
#endif /* ENABLED (JERRY_ES2015_TEMPLATE_STRINGS) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
  SCAN_STACK_ARROW_ARGUMENTS,              /**< might be arguments of an arrow function */
  SCAN_STACK_ARROW_EXPRESSION,             /**< expression body of an arrow function */
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_CLASS)
  SCAN_STACK_CLASS_STATEMENT,              /**< class statement */
  SCAN_STACK_CLASS_EXPRESSION,             /**< class expression */
  SCAN_STACK_CLASS_EXTENDS,                /**< class extends expression */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
  SCAN_STACK_FUNCTION_PARAMETERS,          /**< function parameter initializer */
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
} scan_stack_modes_t;
#define SCANNER_IS_FOR_START(stack_top) \
typedef enum
{
  SCAN_NEXT_TOKEN, /**< get next token after return */
  SCAN_KEEP_TOKEN, /**< keep the current token after return */
} scan_return_types_t;
#if ENABLED (JERRY_ES2015_FOR_OF)
#define SCANNER_IDENTIFIER_IS_OF() (lexer_compare_literal_to_identifier (context_p, "of", 2))
#else
#define SCANNER_IDENTIFIER_IS_OF() (false)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#else
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_TEMPLATE_STRINGS)
#endif /* ENABLED (JERRY_ES2015_TEMPLATE_STRINGS) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#else /* !ENABLED (JERRY_ES2015_FOR_OF) */
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_OBJECT_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_OBJECT_INITIALIZER) */
#if ENABLED (JERRY_ES2015_TEMPLATE_STRINGS)
#endif /* ENABLED (JERRY_ES2015_TEMPLATE_STRINGS) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#endif /* ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if defined(JERRY_FOR_IAR_CONFIG)
#pragma optimize=none
#endif
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#if ENABLED (JERRY_ES2015_CLASS)
#if ENABLED (JERRY_ES2015_OBJECT_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_OBJECT_INITIALIZER) */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
#if ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_REST_PARAMETER) */
#if ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_FUNCTION_PARAMETER_INITIALIZER) */
#if ENABLED (JERRY_ES2015_OBJECT_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_OBJECT_INITIALIZER) */
#if ENABLED (JERRY_ES2015_OBJECT_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_OBJECT_INITIALIZER) */
#if ENABLED (JERRY_ES2015_OBJECT_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_OBJECT_INITIALIZER) */
#if ENABLED (JERRY_ES2015_OBJECT_INITIALIZER)
#endif /* ENABLED (JERRY_ES2015_OBJECT_INITIALIZER) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_ARROW_FUNCTION)
#endif /* ENABLED (JERRY_ES2015_ARROW_FUNCTION) */
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#endif /* ENABLED (JERRY_PARSER) */
