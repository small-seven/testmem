#include <common.h>
#include <asm/io.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_pmc.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/atmel_mpddrc.h>
#include <asm/arch/atmel_usba_udc.h>
#include <asm/arch/gpio.h>
#include <asm/arch/clk.h>
#include <asm/arch/sama5d3_smc.h>
#include <asm/arch/sama5d4.h>
#include <atmel_hlcdc.h>
#include <atmel_mci.h>
#include <lcd.h>
#include <mmc.h>
#include <net.h>
#include <netdev.h>
#include <nand.h>
#include <spi.h>
#include <version.h>
#ifndef CONFIG_DM_SPI
#endif /* CONFIG_ATMEL_SPI */
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_GENERIC_ATMEL_MCI
#endif /* CONFIG_GENERIC_ATMEL_MCI */
#ifdef CONFIG_MACB
#endif
#ifndef CONFIG_DM_SPI
#endif
#ifdef CONFIG_GENERIC_ATMEL_MCI
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_USB_GADGET_ATMEL_USBA
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_USB_GADGET_ATMEL_USBA
#ifdef CONFIG_USB_ETH_RNDIS
#endif
#endif
