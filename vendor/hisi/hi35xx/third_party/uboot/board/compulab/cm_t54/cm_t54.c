#include <common.h>
#include <env.h>
#include <fdt_support.h>
#include <usb.h>
#include <mmc.h>
#include <palmas.h>
#include <spl.h>
#include <asm/gpio.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/clock.h>
#include <asm/arch/ehci.h>
#include <asm/ehci-omap.h>
#include "../common/eeprom.h"
#define DIE_ID_REG_BASE		(OMAP54XX_L4_CORE_BASE + 0x2000)
#define DIE_ID_REG_OFFSET	0x200
#if !defined(CONFIG_SPL_BUILD)
#endif
#ifdef CONFIG_SYS_MMC_ENV_PART
#endif
#if defined(CONFIG_MMC)
#define SB_T54_CD_GPIO 228
#define SB_T54_WP_GPIO 229
#endif
#ifdef CONFIG_USB_HOST_ETHER
#endif
#ifdef CONFIG_USB_EHCI_HCD
#endif
