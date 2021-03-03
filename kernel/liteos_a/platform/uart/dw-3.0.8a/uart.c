#include "los_event.h"
#include "hisoc/uart.h"
#ifdef LOSCFG_PLATFORM_UART_WITHOUT_VFS
#ifdef LOSCFG_SHELL
#define UART_BUF    128
#endif
#endif
#if defined(LOSCFG_COREDUMP) || defined(LOSCFG_LLTSER)
#endif
#ifdef LOSCFG_PLATFORM_UART_WITHOUT_VFS
#ifdef LOSCFG_SHELL
#endif
#endif
