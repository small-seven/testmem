#include "byte-code.h"
#include "debugger.h"
#include "ecma-array-object.h"
#include "ecma-builtin-helpers.h"
#include "ecma-conversion.h"
#include "ecma-eval.h"
#include "ecma-function-object.h"
#include "ecma-objects.h"
#include "jcontext.h"
#include "jerryscript-port.h"
#include "lit-char-helpers.h"
#if ENABLED (JERRY_DEBUGGER)
typedef struct
{
  uint8_t type; /**< type of the message */
} jerry_debugger_receive_uint8_data_part_t;
#define JERRY_DEBUGGER_RECEIVE_DATA_MODE \
#define JERRY_DEBUGGER_SEND_BUFFER_AS(type, name_p) \
#define JERRY_DEBUGGER_RECEIVE_BUFFER_AS(type, name_p) \
#ifdef ACE_DEBUGGER_CUSTOM
#endif
#define JERRY_DEBUGGER_CHECK_PACKET_SIZE(type) \
#ifdef ACE_DEBUGGER_CUSTOM
#define ENUM_TYPE_TO_STRING_CASE(x)   case x: return(#x);
#endif
#ifdef ACE_DEBUGGER_CUSTOM
#endif
#if ENABLED (JERRY_MEM_STATS)
#endif /* ENABLED (JERRY_MEM_STATS) */
#undef JERRY_DEBUGGER_CHECK_PACKET_SIZE
#if ENABLED (JERRY_MEM_STATS) /* if memory statistics feature is enabled */
#else /* !ENABLED (JERRY_MEM_STATS) if not, just put zeros */
#endif /* ENABLED (JERRY_MEM_STATS) */
#if ENABLED (JERRY_BUILTIN_ERRORS)
#endif /* ENABLED (JERRY_BUILTIN_ERRORS) */
#endif /* ENABLED (JERRY_DEBUGGER) */
