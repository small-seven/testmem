#include <common.h>
#include <asm/io.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/at91_sfr.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <debug_uart.h>
#include <asm/mach-types.h>
#ifdef CONFIG_CMD_NAND
#ifdef CONFIG_SYS_NAND_DBW_16
#else /* CONFIG_SYS_NAND_DBW_8 */
#endif
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#ifdef CONFIG_DEBUG_UART
#endif
#endif
#define MAC24AA_MAC_OFFSET     0xfa
#ifdef CONFIG_MISC_INIT_R
#ifdef CONFIG_I2C_EEPROM
#endif
#endif
#ifdef CONFIG_CMD_NAND
#endif
