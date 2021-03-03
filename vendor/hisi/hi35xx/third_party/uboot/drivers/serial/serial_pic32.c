#include <common.h>
#include <clk.h>
#include <dm.h>
#include <serial.h>
#include <wait_bit.h>
#include <mach/pic32.h>
#include <dt-bindings/clock/microchip,clock.h>
#define U_MOD		0x00
#define U_MODCLR	(U_MOD + _CLR_OFFSET)
#define U_MODSET	(U_MOD + _SET_OFFSET)
#define U_STA		0x10
#define U_STACLR	(U_STA + _CLR_OFFSET)
#define U_STASET	(U_STA + _SET_OFFSET)
#define U_TXR		0x20
#define U_RXR		0x30
#define U_BRG		0x40
#define UART_ENABLE		BIT(15)
#define UART_RX_ENABLE		BIT(12)
#define UART_TX_BRK		BIT(11)
#define UART_TX_ENABLE		BIT(10)
#define UART_TX_FULL		BIT(9)
#define UART_TX_EMPTY		BIT(8)
#define UART_RX_OVER		BIT(1)
#define UART_RX_DATA_AVAIL	BIT(0)
#ifdef CONFIG_DEBUG_UART_PIC32
#include <debug_uart.h>
#endif
