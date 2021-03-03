#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#include "jerryscript-debugger.h"
#ifndef DISABLE_EXTRA_API
#define JERRY_PORT_DEFAULT_LOG_LEVEL jerry_port_default_log_level
#else /* DISABLE_EXTRA_API */
#define JERRY_PORT_DEFAULT_LOG_LEVEL JERRY_LOG_LEVEL_ERROR
#endif /* !DISABLE_EXTRA_API */
#if defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)
#else /* If jerry-debugger isn't defined, libc is turned on */
#endif /* defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1) */
#if defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)
#define DEBUG_BUFFER_SIZE (256)
#endif /* defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1) */
#if defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)
#endif /* defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1) */
