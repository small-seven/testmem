#include <common.h>
#include <asm/io.h>
#include <asm/arch/at91sam9x5_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <net.h>
#include <netdev.h>
#if defined(CONFIG_SPL_BUILD)
#include <spl.h>
#include <nand.h>
#include <asm/arch/atmel_mpddrc.h>
void mem_init(void)
{
	struct at91_matrix *matrix = (struct at91_matrix *)ATMEL_BASE_MATRIX;
	struct atmel_mpddrc_config ddr2;
	unsigned long csa;

	ddr2_conf(&ddr2);

	/* enable DDR2 clock */
	at91_system_clk_enable(AT91_PMC_DDR);

	/* Chip select 1 is for DDR2/SDRAM */
	csa = readl(&matrix->ebicsa);
	csa |= AT91_MATRIX_EBI_CS1A_SDRAMC;
	writel(csa, &matrix->ebicsa);

	/* DDRAM2 Controller initialize */
	ddr2_init(ATMEL_BASE_DDRSDRC, ATMEL_BASE_CS1, &ddr2);
}
#endif
