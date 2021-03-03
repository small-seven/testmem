#include <common.h>
#include <debug_uart.h>
#include <asm/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/atmel_pio4.h>
#include <asm/arch/atmel_mpddrc.h>
#include <asm/arch/atmel_sdhci.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <asm/arch/sama5d2.h>
#ifdef CONFIG_BOARD_LATE_INIT
#ifdef CONFIG_DM_VIDEO
#endif
#endif
#ifdef CONFIG_DEBUG_UART_BOARD_INIT
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#ifdef CONFIG_DEBUG_UART
#endif
#endif
#ifdef CONFIG_MISC_INIT_R
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_SD_BOOT
#endif
#ifdef CONFIG_QSPI_BOOT
#endif
#ifdef CONFIG_SD_BOOT
#endif
#ifdef CONFIG_QSPI_BOOT
#endif
void mem_init(void)
{
	struct at91_pmc *pmc = (struct at91_pmc *)ATMEL_BASE_PMC;
	struct atmel_mpddr *mpddrc = (struct atmel_mpddr *)ATMEL_BASE_MPDDRC;
	struct atmel_mpddrc_config ddrc_config;
	u32 reg;

	at91_periph_clk_enable(ATMEL_ID_MPDDRC);
	writel(AT91_PMC_DDR, &pmc->scer);

	ddrc_conf(&ddrc_config);

	reg = readl(&mpddrc->io_calibr);
	reg &= ~ATMEL_MPDDRC_IO_CALIBR_RDIV;
	reg |= ATMEL_MPDDRC_IO_CALIBR_LPDDR2_RZQ_48;
	reg &= ~ATMEL_MPDDRC_IO_CALIBR_TZQIO;
	reg |= ATMEL_MPDDRC_IO_CALIBR_TZQIO_(100);
	writel(reg, &mpddrc->io_calibr);

	writel(ATMEL_MPDDRC_RD_DATA_PATH_SHIFT_ONE_CYCLE,
	       &mpddrc->rd_data_path);

	lpddr2_init(ATMEL_BASE_MPDDRC, ATMEL_BASE_DDRCS, &ddrc_config);
}
#endif
