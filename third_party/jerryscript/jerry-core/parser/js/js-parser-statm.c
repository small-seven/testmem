#include "js-parser-internal.h"
#if ENABLED (JERRY_PARSER)
#include "jcontext.h"
#include "ecma-helpers.h"
#include "lit-char-helpers.h"
#if ENABLED (JERRY_ES2015_FOR_OF)
#if !ENABLED (JERRY_ES2015_BUILTIN_ITERATOR)
#error "For of support requires ES2015 iterator support"
#endif /* !ENABLED (JERRY_ES2015_BUILTIN_ITERATOR) */
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#define PARSER_USE_STRICT_LITERAL  "use strict"
#define PARSER_USE_STRICT_LENGTH   10
typedef enum
{
  PARSER_STATEMENT_START,
  PARSER_STATEMENT_BLOCK,
  PARSER_STATEMENT_LABEL,
  PARSER_STATEMENT_IF,
  PARSER_STATEMENT_ELSE,
  /* From switch -> for-in : break target statements */
  PARSER_STATEMENT_SWITCH,
  PARSER_STATEMENT_SWITCH_NO_DEFAULT,
  /* From do-while -> for->in : continue target statements */
  PARSER_STATEMENT_DO_WHILE,
  PARSER_STATEMENT_WHILE,
  PARSER_STATEMENT_FOR,
  /* From for->in -> try : instructions with context
   * Break and continue uses another instruction form
   * when crosses their borders. */
  PARSER_STATEMENT_FOR_IN,
#if ENABLED (JERRY_ES2015_FOR_OF)
  PARSER_STATEMENT_FOR_OF,
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
  PARSER_STATEMENT_WITH,
  PARSER_STATEMENT_TRY,
} parser_statement_type_t;
typedef struct
{
  parser_branch_node_t *branch_list_p;    /**< list of breaks and continues targeting this statement */
} parser_loop_statement_t;
typedef struct
{
  lexer_lit_location_t label_ident;       /**< name of the label */
  parser_branch_node_t *break_list_p;     /**< list of breaks targeting this label */
} parser_label_statement_t;
typedef struct
{
  parser_branch_t branch;                 /**< branch to the end */
} parser_if_else_statement_t;
typedef struct
{
  parser_branch_t default_branch;         /**< branch to the default case */
  parser_branch_node_t *branch_list_p;    /**< branches of case statements */
} parser_switch_statement_t;
typedef struct
{
  uint32_t start_offset;                  /**< start byte code offset */
} parser_do_while_statement_t;
typedef struct
{
  parser_branch_t branch;                 /**< branch to the end */
  scanner_location_t condition_location;  /**< condition part */
  uint32_t start_offset;                  /**< start byte code offset */
} parser_while_statement_t;
typedef struct
{
  parser_branch_t branch;                 /**< branch to the end */
  scanner_location_t condition_location;  /**< condition part */
  scanner_location_t expression_location; /**< expression part */
  uint32_t start_offset;                  /**< start byte code offset */
} parser_for_statement_t;
typedef struct
{
  parser_branch_t branch;                 /**< branch to the end */
  uint32_t start_offset;                  /**< start byte code offset */
} parser_for_in_of_statement_t;
typedef struct
{
  parser_branch_t branch;                 /**< branch to the end */
} parser_with_statement_t;
typedef enum
{
  parser_try_block,                       /**< try block */
  parser_catch_block,                     /**< catch block */
  parser_finally_block,                   /**< finally block */
} parser_try_block_type_t;
typedef struct
{
  parser_try_block_type_t type;           /**< current block type */
  parser_branch_t branch;                 /**< branch to the end of the current block */
} parser_try_statement_t;
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_DEBUGGER) || ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_DEBUGGER) || ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif /* ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif /* ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_ES2015_CLASS)
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#else /* !ENABLED (JERRY_ES2015_FOR_OF) */
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_ES2015_FOR_OF)
#else /* !ENABLED (JERRY_ES2015_FOR_OF) */
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#else /* !ENABLED (JERRY_ES2015_FOR_OF) */
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#else /* !ENABLED (JERRY_ES2015_FOR_OF) */
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif /* ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_PARSER_DUMP_BYTE_CODE)
#endif /* ENABLED (JERRY_PARSER_DUMP_BYTE_CODE) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#if ENABLED (JERRY_LINE_INFO)
#endif /* ENABLED (JERRY_LINE_INFO) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_MODULE_SYSTEM)
#endif /* ENABLED (JERRY_ES2015_MODULE_SYSTEM) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_DEBUGGER)
#endif /* ENABLED (JERRY_DEBUGGER) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_ES2015_CLASS)
#endif /* ENABLED (JERRY_ES2015_CLASS) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#if ENABLED (JERRY_ES2015_FOR_OF)
#else
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#ifndef JERRY_NDEBUG
#endif /* !JERRY_NDEBUG */
#if ENABLED (JERRY_ES2015_FOR_OF)
#endif /* ENABLED (JERRY_ES2015_FOR_OF) */
#endif /* ENABLED (JERRY_PARSER) */
