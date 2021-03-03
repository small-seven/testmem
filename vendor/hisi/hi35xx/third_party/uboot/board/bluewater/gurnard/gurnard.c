#include <common.h>
#include <atmel_lcd.h>
#include <atmel_lcdc.h>
#include <atmel_mci.h>
#include <dm.h>
#include <env.h>
#include <init.h>
#include <lcd.h>
#include <net.h>
#ifndef CONFIG_DM_ETH
#include <netdev.h>
#endif
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <asm/arch/at91sam9g45_matrix.h>
#include <asm/arch/at91sam9_smc.h>
#include <asm/arch/at91_common.h>
#include <asm/arch/at91_emac.h>
#include <asm/arch/at91_rstc.h>
#include <asm/arch/at91_rtc.h>
#include <asm/arch/at91_sck.h>
#include <asm/arch/atmel_serial.h>
#include <asm/arch/clk.h>
#include <asm/arch/gpio.h>
#include <dm/uclass-internal.h>
#ifdef CONFIG_GURNARD_SPLASH
#include "splash_logo.h"
#endif
#define IO_EXP_ETH_RESET	(0 << 1)
#define IO_EXP_ETH_POWER	(1 << 1)
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_CMD_NAND
#ifdef CONFIG_SYS_NAND_DBW_16
#else
#endif
#endif
#ifdef CONFIG_GURNARD_SPLASH
#endif
#ifdef CONFIG_DM_VIDEO
#endif
#ifdef CONFIG_GURNARD_FPGA
#endif
#ifdef CONFIG_CMD_USB
#define USB0_ENABLE_PIN		AT91_PIN_PB22
#define USB1_ENABLE_PIN		AT91_PIN_PB23
#endif
#ifdef CONFIG_GENERIC_ATMEL_MCI
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_CMD_NAND
#endif
#ifdef CONFIG_ATMEL_SPI
#endif
#ifdef CONFIG_MACB
#endif
#ifdef CONFIG_GURNARD_FPGA
#endif
#ifdef CONFIG_CMD_USB
#endif
#ifdef CONFIG_CMD_MMC
#endif
#ifdef CONFIG_DM_VIDEO
#endif
#ifdef CONFIG_GURNARD_SPLASH
#endif
#ifndef CONFIG_DM_ETH
#endif
