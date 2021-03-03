#include <common.h>
#include <debug_uart.h>
#include <vsprintf.h>
#include <linux/sizes.h>
#include <asm/arch/at91sam9263.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_matrix.h>
#include <asm/arch/at91_pio.h>
#include <asm/arch/clk.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>
#include <asm/arch/hardware.h>
#include <lcd.h>
#include <atmel_lcdc.h>
#include <asm/mach-types.h>
#ifdef CONFIG_CMD_NAND
#ifdef CONFIG_SYS_NAND_DBW_16
#else /* CONFIG_SYS_NAND_DBW_8 */
#endif
#endif
#ifdef CONFIG_LCD
#ifdef CONFIG_LCD_INFO
#include <nand.h>
#include <version.h>
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#ifdef CONFIG_MTD_NOR_FLASH
#endif
#endif /* CONFIG_LCD_INFO */
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#ifdef CONFIG_DEBUG_UART
#endif
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_USB_OHCI_NEW
#endif
#ifdef CONFIG_LCD
#endif
#ifdef CONFIG_RESET_PHY_R
#endif
