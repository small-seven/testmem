#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jerryscript.h"
#include "jerryscript-ext/debugger.h"
#include "jerryscript-ext/handler.h"
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#include "cli.h"
#define JERRY_BUFFER_SIZE (1048576)
#define JERRY_SNAPSHOT_BUFFER_SIZE (JERRY_BUFFER_SIZE / sizeof (uint32_t))
#define JERRY_STANDALONE_EXIT_CODE_OK   (0)
#define JERRY_STANDALONE_EXIT_CODE_FAIL (1)
#define SYNTAX_ERROR_CONTEXT_SIZE 2
typedef enum
{
  OPT_HELP,
  OPT_VERSION,
  OPT_MEM_STATS,
  OPT_PARSE_ONLY,
  OPT_SHOW_OP,
  OPT_SHOW_RE_OP,
  OPT_DEBUG_SERVER,
  OPT_DEBUG_PORT,
  OPT_DEBUG_CHANNEL,
  OPT_DEBUG_PROTOCOL,
  OPT_DEBUG_SERIAL_CONFIG,
  OPT_DEBUGGER_WAIT_SOURCE,
  OPT_EXEC_SNAP,
  OPT_EXEC_SNAP_FUNC,
  OPT_LOG_LEVEL,
  OPT_NO_PROMPT
} main_opt_id_t;
#if defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1)
#endif /* defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1) */
#if defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1)
#endif /* defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1) */
#if defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1)
#endif /* defined (JERRY_EXTERNAL_CONTEXT) && (JERRY_EXTERNAL_CONTEXT == 1) */
