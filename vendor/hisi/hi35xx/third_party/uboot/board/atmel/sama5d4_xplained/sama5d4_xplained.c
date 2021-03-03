#include <common.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/atmel_mpddrc.h>
#include <asm/arch/gpio.h>
#include <asm/arch/clk.h>
#include <asm/arch/sama5d3_smc.h>
#include <asm/arch/sama5d4.h>
#include <debug_uart.h>
#ifdef CONFIG_NAND_ATMEL
#endif
#ifdef CONFIG_CMD_USB
#endif
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
#define AT24MAC_MAC_OFFSET	0x9a
#ifdef CONFIG_MISC_INIT_R
#ifdef CONFIG_I2C_EEPROM
#endif
#endif
#ifdef CONFIG_NAND_ATMEL
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_SPL_BUILD
#if CONFIG_NAND_BOOT
#endif
void mem_init(void)
{
	struct atmel_mpddrc_config ddr2;

	ddr2_conf(&ddr2);

	/* Enable MPDDR clock */
	at91_periph_clk_enable(ATMEL_ID_MPDDRC);
	at91_system_clk_enable(AT91_PMC_DDR);

	/* DDRAM2 Controller initialize */
	ddr2_init(ATMEL_BASE_MPDDRC, ATMEL_BASE_DDRCS, &ddr2);
}
#endif
