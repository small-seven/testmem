#include "jerryscript-debugger-transport.h"
#include "jerryscript-ext/debugger.h"
#include "jext-common.h"
#if (defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)) && !defined _WIN32
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <stdlib.h>
#define CONFIG_SIZE (255)
typedef struct
{
  jerry_debugger_transport_header_t header; /**< transport header */
  int fd; /**< file descriptor */
} jerryx_debugger_transport_serial_t;
typedef struct
{
  char *device_id;
  uint32_t baud_rate; /**< specify the rate at which bits are transmitted for the serial interface */
  uint32_t data_bits; /**< specify the number of data bits to transmit over the serial interface */
  char parity; /**< specify how you want to check parity bits in the data bits transmitted via the serial port */
  uint32_t stop_bits; /**< specify the number of bits used to indicate the end of a byte. */
} jerryx_debugger_transport_serial_config_t;
#else /* !(defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)) || _WIN32 */
#endif /* (defined (JERRY_DEBUGGER) && (JERRY_DEBUGGER == 1)) && !defined _WIN32 */
