#include "jerryscript-ext/debugger.h"
#include "jext-common.h"
#if defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)
#define JERRYX_DEBUGGER_RAWPACKET_HEADER_SIZE 1
#define JERRYX_DEBUGGER_RAWPACKET_ONE_BYTE_LEN_MAX 255
typedef struct
{
  uint8_t size; /**< size of the message */
} jerryx_rawpacket_receive_header_t;
#else /* !(defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)) */
#endif /* defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1) */
