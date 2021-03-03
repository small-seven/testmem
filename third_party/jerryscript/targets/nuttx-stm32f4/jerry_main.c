#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "jerryscript.h"
#include "jerryscript-ext/debugger.h"
#include "jerryscript-ext/handler.h"
#include "jerryscript-port.h"
#include "setjmp.h"
#define JERRY_MAX_COMMAND_LINE_ARGS (16)
#define JERRY_STANDALONE_EXIT_CODE_OK   (0)
#define JERRY_STANDALONE_EXIT_CODE_FAIL (1)
#define SYNTAX_ERROR_CONTEXT_SIZE 2
#ifdef CONFIG_BUILD_KERNEL
#else
#endif
