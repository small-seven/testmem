#include <common.h>
#include <dm.h>
#include <serial.h>
#if defined(CONFIG_CPU_V6) || defined(CONFIG_CPU_V7A) || defined(CONFIG_CPU_V7R)
#define DCC_RBIT	(1 << 30)
#define DCC_WBIT	(1 << 29)
#define write_dcc(x)	\
#define read_dcc(x)	\
#define status_dcc(x)	\
#elif defined(CONFIG_CPU_XSCALE)
#define DCC_RBIT	(1 << 31)
#define DCC_WBIT	(1 << 28)
#define write_dcc(x)	\
#define read_dcc(x)	\
#define status_dcc(x)	\
#elif defined(CONFIG_CPU_ARMV8)
#define DCC_RBIT	(1 << 30)
#define DCC_WBIT	(1 << 29)
#define write_dcc(x)   \
#define read_dcc(x)    \
#define status_dcc(x)  \
#else
#define DCC_RBIT	(1 << 0)
#define DCC_WBIT	(1 << 1)
#define write_dcc(x)	\
#define read_dcc(x)	\
#define status_dcc(x)	\
#endif
#define can_read_dcc(x)	do {	\
#define can_write_dcc(x) do {	\
#define TIMEOUT_COUNT 0x4000000
#ifdef CONFIG_DEBUG_UART_ARM_DCC
#include <debug_uart.h>
#endif
