#include <altera.h>
#include <common.h>
#include <errno.h>
#include <fdtdec.h>
#include <miiphy.h>
#include <netdev.h>
#include <ns16550.h>
#include <watchdog.h>
#include <asm/arch/misc.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/reset_manager.h>
#include <asm/arch/reset_manager_arria10.h>
#include <asm/arch/sdram_arria10.h>
#include <asm/arch/system_manager.h>
#include <asm/arch/nic301.h>
#include <asm/io.h>
#include <asm/pl310.h>
#define PINMUX_UART0_TX_SHARED_IO_OFFSET_Q1_3	0x08
#define PINMUX_UART0_TX_SHARED_IO_OFFSET_Q2_11	0x58
#define PINMUX_UART0_TX_SHARED_IO_OFFSET_Q3_3	0x68
#define PINMUX_UART1_TX_SHARED_IO_OFFSET_Q1_7	0x18
#define PINMUX_UART1_TX_SHARED_IO_OFFSET_Q3_7	0x78
#define PINMUX_UART1_TX_SHARED_IO_OFFSET_Q4_3	0x98
#if defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif
