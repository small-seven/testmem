#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <asm/arch/at91sam9g45_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/atmel_serial.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include <asm/arch/clk.h>
#if defined(CONFIG_RESET_PHY_R) && defined(CONFIG_MACB)
#include <net.h>
#endif
#ifndef CONFIG_DM_ETH
#include <netdev.h>
#endif
#include <spi.h>
#ifdef CONFIG_USB_GADGET_ATMEL_USBA
#include <asm/arch/atmel_usba_udc.h>
#endif
#ifdef CONFIG_SYS_NAND_DBW_16
#else /* CONFIG_SYS_NAND_DBW_8 */
#endif
#if defined(CONFIG_SPL_BUILD)
#include <spl.h>
#include <nand.h>
#ifdef CONFIG_SPL_NAND_SUPPORT
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
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_USB_GADGET_ATMEL_USBA
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_ATMEL_SPI
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_USB_GADGET_ATMEL_USBA
#endif
#ifndef CONFIG_DM_ETH
#ifdef CONFIG_MACB
#endif
#endif
