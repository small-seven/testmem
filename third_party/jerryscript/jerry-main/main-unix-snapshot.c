#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "jerryscript.h"
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#include "cli.h"
#define JERRY_BUFFER_SIZE (1048576)
#define JERRY_LITERAL_LENGTH (4096)
#define JERRY_STANDALONE_EXIT_CODE_OK   (0)
#define JERRY_STANDALONE_EXIT_CODE_FAIL (1)
#ifdef _WIN32
#  ifdef _WIN64
#    define PRI_SIZET "lu"
#    define SIZE_T_TYPE unsigned long
#  else
#    define PRI_SIZET "zu"
#    define SIZE_T_TYPE size_t
#  endif
#else
#  define PRI_SIZET "zu"
#  define SIZE_T_TYPE size_t
#endif
#if defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1)
#endif /* defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1) */
typedef enum
{
  OPT_GENERATE_HELP,
  OPT_GENERATE_STATIC,
  OPT_GENERATE_SHOW_OP,
  OPT_GENERATE_FUNCTION,
  OPT_GENERATE_OUT,
  OPT_IMPORT_LITERAL_LIST
} generate_opt_id_t;
#if defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1)
#endif /* defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1) */
typedef enum
{
  OPT_LITERAL_DUMP_HELP,
  OPT_LITERAL_DUMP_FORMAT,
  OPT_LITERAL_DUMP_OUT,
} literal_dump_opt_id_t;
#if defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1)
#endif /* defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1) */
typedef enum
{
  OPT_MERGE_HELP,
  OPT_MERGE_OUT,
} merge_opt_id_t;
#if defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1)
#endif /* defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1) */
typedef enum
{
  OPT_HELP,
} main_opt_id_t;
