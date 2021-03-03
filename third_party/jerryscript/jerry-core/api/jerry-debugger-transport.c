#include "debugger.h"
#include "jcontext.h"
#include "jerryscript.h"
#if ENABLED (JERRY_DEBUGGER)
#define JERRY_DEBUGGER_TRANSPORT_MIN_BUFFER_SIZE 64
#define JERRY_DEBUGGER_TRANSPORT_TIMEOUT 10
#ifdef ACE_DEBUGGER_CUSTOM
#endif
#endif /* ENABLED (JERRY_DEBUGGER) */
