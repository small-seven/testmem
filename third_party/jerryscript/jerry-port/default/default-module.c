#if !defined (_WIN32) && !defined(JERRY_FOR_IAR_CONFIG)
#include <libgen.h>
#endif /* !defined (_WIN32) */
#include <limits.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include "jerryscript-port.h"
#include "jerryscript-port-default.h"
#if defined (_WIN32)
#elif defined (__unix__) || defined (__APPLE__)
#define MAX_JERRY_PATH_SIZE 256
#undef MAX_JERRY_PATH_SIZE
#else
#endif
