#include <common.h>
#include <vsprintf.h>
#include <asm/io.h>
#include <asm/arch/at91sam9x5_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/at91_pio.h>
#include <asm/arch/clk.h>
#include <debug_uart.h>
#include <lcd.h>
#include <atmel_hlcdc.h>
#include <netdev.h>
#ifdef CONFIG_LCD_INFO
#include <nand.h>
#include <version.h>
#endif
#ifdef CONFIG_NAND_ATMEL
#ifdef CONFIG_SYS_NAND_DBW_16
#else /* CONFIG_SYS_NAND_DBW_8 */
#endif
#endif
#ifdef CONFIG_LCD
#ifdef CONFIG_LCD_INFO
#endif /* CONFIG_LCD_INFO */
#endif /* CONFIG_LCD */
#ifdef CONFIG_KS8851_MLL
#endif
#ifdef CONFIG_USB_ATMEL
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#ifdef CONFIG_DEBUG_UART
#endif
#endif
#ifdef CONFIG_NAND_ATMEL
#endif
#ifdef CONFIG_LCD
#endif
#ifdef CONFIG_KS8851_MLL
#endif
#ifdef CONFIG_USB_ATMEL
#endif
#ifdef CONFIG_KS8851_MLL
#endif
#if defined(CONFIG_SPL_BUILD)
#include <spl.h>
#include <nand.h>
#ifdef CONFIG_SD_BOOT
#elif CONFIG_NAND_BOOT
#elif CONFIG_SPI_BOOT
#endif
#include <asm/arch/atmel_mpddrc.h>
void mem_init(void)
{
	struct at91_pmc *pmc = (struct at91_pmc *)ATMEL_BASE_PMC;
	struct at91_matrix *matrix = (struct at91_matrix *)ATMEL_BASE_MATRIX;
	struct atmel_mpddrc_config ddr2;
	unsigned long csa;

	ddr2_conf(&ddr2);

	/* enable DDR2 clock */
	writel(AT91_PMC_DDR, &pmc->scer);

	/* Chip select 1 is for DDR2/SDRAM */
	csa = readl(&matrix->ebicsa);
	csa |= AT91_MATRIX_EBI_CS1A_SDRAMC;
	csa &= ~AT91_MATRIX_EBI_DBPU_OFF;
	csa |= AT91_MATRIX_EBI_DBPD_OFF;
	csa |= AT91_MATRIX_EBI_EBI_IOSR_NORMAL;
	writel(csa, &matrix->ebicsa);

	/* DDRAM2 Controller initialize */
	ddr2_init(ATMEL_BASE_DDRSDRC, ATMEL_BASE_CS1, &ddr2);
}
#endif
