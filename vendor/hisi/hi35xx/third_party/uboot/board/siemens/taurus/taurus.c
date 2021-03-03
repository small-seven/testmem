#include <command.h>
#include <common.h>
#include <dm.h>
#include <env.h>
#include <asm/io.h>
#include <asm/arch/at91sam9260_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/gpio.h>
#include <asm/arch/at91sam9_sdramc.h>
#include <asm/arch/atmel_serial.h>
#include <asm/arch/clk.h>
#include <asm/gpio.h>
#include <linux/mtd/rawnand.h>
#include <atmel_mci.h>
#include <asm/arch/at91_spi.h>
#include <spi.h>
#include <net.h>
#ifndef CONFIG_DM_ETH
#include <netdev.h>
#endif
#if defined(CONFIG_SPL_BUILD)
#include <spl.h>
#include <nand.h>
#include <spi_flash.h>
#if defined(CONFIG_BOARD_AXM)
#elif defined(CONFIG_BOARD_TAURUS)
#endif
#if defined(CONFIG_BOARD_AXM)
#elif defined(CONFIG_BOARD_TAURUS)
#endif
#define SDRAM_BASE_CONF	(AT91_SDRAMC_NR_13 | AT91_SDRAMC_CAS_3 \
void mem_init(void)
{
	unsigned int ram_size = 0;

	/* Configure SDRAM for 128MB */
	sdramc_configure(AT91_SDRAMC_NC_10);

	/* Do memtest for 128MB */
	ram_size = get_ram_size((void *)CONFIG_SYS_SDRAM_BASE,
				CONFIG_SYS_SDRAM_SIZE);

	/*
	 * If 32MB or 16MB should be supported check also for
	 * expected mirroring at A16 and A17
	 * To find mirror addresses depends how the collumns are connected
	 * at RAM (internaly or externaly)
	 * If the collumns are not in inverted order the mirror size effect
	 * behaves like normal SRAM with A0,A1,A2,etc. connected incremantal
	 */

	/* Mirrors at A15 on ATMEL G20 SDRAM Controller with 64MB*/
	if (ram_size == 0x800) {
		printf("\n\r 64MB\n");
		sdramc_configure(AT91_SDRAMC_NC_9);
	} else {
		/* Size already initialized */
		printf("\n\r 128MB\n");
	}
}
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_GENERIC_ATMEL_MCI
#endif
#ifdef CONFIG_USB_GADGET_AT91
#include <linux/usb/at91_udc.h>
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_USB_GADGET_AT91
#endif
#if !defined(CONFIG_SPL_BUILD)
#if defined(CONFIG_BOARD_AXM)
#endif
#endif
