#include <common.h>
#include <debug_uart.h>
#include <vsprintf.h>
#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/at91sam9g45_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/gpio.h>
#include <asm/arch/clk.h>
#include <lcd.h>
#include <linux/mtd/rawnand.h>
#include <atmel_lcdc.h>
#include <asm/mach-types.h>
#ifdef CONFIG_CMD_NAND
#ifdef CONFIG_SYS_NAND_DBW_16
#else /* CONFIG_SYS_NAND_DBW_8 */
#endif
#endif
#if defined(CONFIG_SPL_BUILD)
#include <spl.h>
#include <nand.h>
#ifdef CONFIG_SD_BOOT
#elif CONFIG_NAND_BOOT
#endif
#include <asm/arch/atmel_mpddrc.h>
void mem_init(void)
{
	struct atmel_mpddrc_config ddr2;

	ddr2_conf(&ddr2);

	at91_system_clk_enable(AT91_PMC_DDR);

	/* DDRAM2 Controller initialize */
	ddr2_init(ATMEL_BASE_DDRSDRC0, ATMEL_BASE_CS6, &ddr2);
}
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_LCD
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
#ifdef CONFIG_AT91SAM9M10G45EK
#elif defined CONFIG_AT91SAM9G45EKES
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_LCD
#endif
#ifdef CONFIG_RESET_PHY_R
#endif
