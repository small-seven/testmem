#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/at91_sfr.h>
#include <asm/arch/sama5d3_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_pmc.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/gpio.h>
#include <asm/arch/clk.h>
#include <env.h>
#include <micrel.h>
#include <net.h>
#include <netdev.h>
#include <spl.h>
#include <asm/arch/atmel_mpddrc.h>
#include <asm/arch/at91_wdt.h>
#ifdef CONFIG_BOARD_LATE_INIT
#include <linux/ctype.h>
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#endif
#ifdef CONFIG_SPL_BUILD
void mem_init(void)
{
	struct atmel_mpddrc_config ddr2;

	ddr2_conf(&ddr2);

	configure_ddrcfg_input_buffers(true);

	/* enable MPDDR clock */
	at91_periph_clk_enable(ATMEL_ID_MPDDRC);
	at91_system_clk_enable(AT91_PMC_DDR);

	/* DDRAM2 Controller initialize */
	ddr2_init(ATMEL_BASE_MPDDRC, ATMEL_BASE_DDRCS, &ddr2);
}
#endif
