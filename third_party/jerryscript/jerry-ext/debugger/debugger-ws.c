#include "debugger-sha1.h"
#include "jerryscript-ext/debugger.h"
#include "jext-common.h"
#if defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)
#define JERRYX_DEBUGGER_WEBSOCKET_FIN_BIT 0x80
#define JERRYX_DEBUGGER_WEBSOCKET_MASK_BIT 0x80
#define JERRYX_DEBUGGER_WEBSOCKET_OPCODE_MASK 0x0fu
#define JERRYX_DEBUGGER_WEBSOCKET_LENGTH_MASK 0x7fu
#define JERRYX_DEBUGGER_WEBSOCKET_HEADER_SIZE 2
#define JERRYX_DEBUGGER_WEBSOCKET_MASK_SIZE 4
#define JERRYX_DEBUGGER_WEBSOCKET_ONE_BYTE_LEN_MAX 125
typedef enum
{
  JERRYX_DEBUGGER_WEBSOCKET_TEXT_FRAME = 1, /**< text frame */
  JERRYX_DEBUGGER_WEBSOCKET_BINARY_FRAME = 2, /**< binary frame */
  JERRYX_DEBUGGER_WEBSOCKET_CLOSE_CONNECTION = 8, /**< close connection */
  JERRYX_DEBUGGER_WEBSOCKET_PING = 9, /**< ping (keep alive) frame */
  JERRYX_DEBUGGER_WEBSOCKET_PONG = 10, /**< reply to ping frame */
} jerryx_websocket_opcode_type_t;
typedef struct
{
  uint8_t ws_opcode; /**< websocket opcode */
  uint8_t size; /**< size of the message */
  uint8_t mask[4]; /**< mask bytes */
} jerryx_websocket_receive_header_t;
#else /* !(defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)) */
#endif /* defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1) */
