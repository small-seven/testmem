#include <common.h>
#include <debug_uart.h>
#include <dm.h>
#include <i2c.h>
#include <init.h>
#include <nand.h>
#include <version.h>
#include <asm/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/atmel_pio4.h>
#include <asm/arch/atmel_mpddrc.h>
#include <asm/arch/atmel_sdhci.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <asm/arch/sama5d2.h>
#include <asm/arch/sama5d2_smc.h>
#ifdef CONFIG_NAND_ATMEL
#endif
#ifdef CONFIG_BOARD_LATE_INIT
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#ifdef CONFIG_DEBUG_UART
#endif
#endif
#ifdef CONFIG_NAND_ATMEL
#endif
#ifdef CONFIG_CMD_USB
#endif
#define AT24MAC_MAC_OFFSET	0xfa
#ifdef CONFIG_MISC_INIT_R
#ifdef CONFIG_I2C_EEPROM
#endif
#endif
