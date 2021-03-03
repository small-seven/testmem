#include <common.h>
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
#include <atmel_mci.h>
#if defined(CONFIG_RESET_PHY_R) && defined(CONFIG_MACB)
#include <net.h>
#endif
#include <netdev.h>
#include <asm/mach-types.h>
#if defined(CONFIG_SPL_BUILD)
#include <spl.h>
#ifdef CONFIG_SYS_USE_MMC
#endif
#include <asm/arch/atmel_mpddrc.h>
void mem_init(void)
{
	struct at91_matrix *mat = (struct at91_matrix *)ATMEL_BASE_MATRIX;
	struct atmel_mpddrc_config ddr2;
	unsigned long csa;

	ddr2_conf(&ddr2);

	at91_system_clk_enable(AT91_PMC_DDR);

	/* Chip select 1 is for DDR2/SDRAM */
	csa = readl(&mat->ebicsa);
	csa |= AT91_MATRIX_EBI_CS1A_SDRAMC;
	csa &= ~AT91_MATRIX_EBI_VDDIOMSEL_3_3V;
	writel(csa, &mat->ebicsa);

	/* DDRAM2 Controller initialize */
	ddr2_init(ATMEL_BASE_DDRSDRC0, ATMEL_BASE_CS6, &ddr2);
	ddr2_init(ATMEL_BASE_DDRSDRC1, ATMEL_BASE_CS1, &ddr2);
}
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_LCD
#ifdef CONFIG_LCD_INFO
#include <nand.h>
#include <version.h>
#endif /* CONFIG_LCD_INFO */
#endif
#ifdef CONFIG_GENERIC_ATMEL_MCI
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_ATMEL_SPI
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_LCD
#endif
#ifdef CONFIG_RESET_PHY_R
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_ATMEL_SPI
#include <spi.h>
#endif /* CONFIG_ATMEL_SPI */
