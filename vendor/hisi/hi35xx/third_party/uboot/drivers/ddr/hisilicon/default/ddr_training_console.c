#include "ddr_interface.h"
#include "ddr_training_impl.h"
#define __ddr_training_console__
#ifdef DDR_TRAINING_CONSOLE_CONFIG
#define DDR_UART_BASE_REG               0x12090000
#define UART_PL01x_FR                   0x18	 /*  Flag register (Read only). */
#define UART_PL01x_FR_RXFE              0x10
#define UART_PL01x_DR                   0x00	 /*  Data read or written from the interface. */
#define UART_PL01x_ECR                  0x04	 /*  Error clear register (Write). */
#define isprint(c)  ((c) >= ' ' && (c) <= '~')
#define isspace(c)  ((c) == ' ' || ((c) >= '\t' && (c) <= '\r'))
#define isdigit(c)  ((c) >= '0' && (c) <= '9')
#define isxdigit(c)	(isdigit(c) \
#define CMD(_p, _c0, _c1, _do_cmd) \
#ifdef DDR_TRAINING_CMD
#endif
#ifdef DDR_TRAINING_CMD
#endif
#else
#endif /* DDR_TRAINING_CONSOLE_CONFIG */
