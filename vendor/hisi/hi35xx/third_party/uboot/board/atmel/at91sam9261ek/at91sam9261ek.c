#include <common.h>
#include <debug_uart.h>
#include <vsprintf.h>
#include <asm/io.h>
#include <asm/arch/at91sam9261.h>
#include <asm/arch/at91sam9261_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <lcd.h>
#include <atmel_lcdc.h>
#if defined(CONFIG_RESET_PHY_R) && defined(CONFIG_DRIVER_DM9000)
#include <net.h>
#include <netdev.h>
#endif
#include <asm/mach-types.h>
#ifdef CONFIG_CMD_NAND
#ifdef CONFIG_AT91SAM9G10EK
#else
#endif
#ifdef CONFIG_SYS_NAND_DBW_16
#else /* CONFIG_SYS_NAND_DBW_8 */
#endif
#endif
#ifdef CONFIG_DRIVER_DM9000
#ifdef CONFIG_AT91SAM9G10EK
#else
#endif
#endif
#ifdef CONFIG_LCD
#ifdef CONFIG_AT91SAM9261EK
#endif
#ifdef CONFIG_LCD_INFO
#include <nand.h>
#include <version.h>
#endif /* CONFIG_LCD_INFO */
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#ifdef CONFIG_DEBUG_UART
#endif
#endif
#ifdef CONFIG_AT91SAM9G10EK
#else
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_DRIVER_DM9000
#endif
#ifdef CONFIG_LCD
#endif
#ifdef CONFIG_DRIVER_DM9000
#endif
#ifdef CONFIG_RESET_PHY_R
#ifdef CONFIG_DRIVER_DM9000
#endif
#endif
