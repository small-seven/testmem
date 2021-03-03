#include <common.h>
#include <dm.h>
#include <div64.h>
#include <errno.h>
#include <serial.h>
#include <asm/io.h>
#include <asm/addrspace.h>
#include <asm/types.h>
#include <dm/pinctrl.h>
#include <mach/ar71xx_regs.h>
#define AR933X_UART_DATA_REG            0x00
#define AR933X_UART_CS_REG              0x04
#define AR933X_UART_CLK_REG             0x08
#define AR933X_UART_DATA_TX_RX_MASK     0xff
#define AR933X_UART_DATA_RX_CSR         BIT(8)
#define AR933X_UART_DATA_TX_CSR         BIT(9)
#define AR933X_UART_CS_IF_MODE_S        2
#define AR933X_UART_CS_IF_MODE_M        0x3
#define AR933X_UART_CS_IF_MODE_DTE      1
#define AR933X_UART_CS_IF_MODE_DCE      2
#define AR933X_UART_CS_TX_RDY_ORIDE     BIT(7)
#define AR933X_UART_CS_RX_RDY_ORIDE     BIT(8)
#define AR933X_UART_CLK_STEP_M          0xffff
#define AR933X_UART_CLK_SCALE_M         0xfff
#define AR933X_UART_CLK_SCALE_S         16
#define AR933X_UART_CLK_STEP_S          0
#ifdef CONFIG_DEBUG_UART_AR933X
#include <debug_uart.h>
#endif
