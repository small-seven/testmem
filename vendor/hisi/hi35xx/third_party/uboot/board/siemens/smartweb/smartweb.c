#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/at91sam9_sdramc.h>
#include <asm/arch/at91sam9260_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/atmel_serial.h>
#include <asm/arch/at91_spi.h>
#include <spi.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <watchdog.h>
# include <net.h>
#ifndef CONFIG_DM_ETH
# include <netdev.h>
#endif
#include <g_dnl.h>
#ifdef CONFIG_USB_GADGET_AT91
#include <linux/usb/at91_udc.h>
#endif
#ifdef CONFIG_USB_GADGET_AT91
#endif
#ifndef CONFIG_DM_ETH
#ifdef CONFIG_MACB
#endif /* CONFIG_MACB */
#endif
#if defined(CONFIG_SPL_BUILD)
#include <spl.h>
#include <nand.h>
#include <spi_flash.h>
#define SDRAM_BASE_CONF	(AT91_SDRAMC_NC_9 | AT91_SDRAMC_NR_13 \
void mem_init(void)
{
	struct at91_matrix *ma = (struct at91_matrix *)ATMEL_BASE_MATRIX;
	struct at91_port *port = (struct at91_port *)ATMEL_BASE_PIOC;
	struct sdramc_reg setting;

	setting.cr = SDRAM_BASE_CONF;
	setting.mdr = AT91_SDRAMC_MD_SDRAM;
	setting.tr = (CONFIG_SYS_MASTER_CLOCK * 7) / 1000000;

	/*
	 * I write here directly in this register, because this
	 * approach is smaller than calling at91_set_a_periph() in a
	 * for loop. This saved me 96 bytes.
	 */
	writel(0xffff0000, &port->pdr);

	writel(readl(&ma->ebicsa) | AT91_MATRIX_CS1A_SDRAMC, &ma->ebicsa);
	sdramc_initialize(ATMEL_BASE_CS1, &setting);
}
#endif
