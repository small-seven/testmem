#include <common.h>
#include <env.h>
#include <status_led.h>
#include <netdev.h>
#include <net.h>
#include <i2c.h>
#include <usb.h>
#include <mmc.h>
#include <splash.h>
#include <twl4030.h>
#include <linux/compiler.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <asm/arch/mem.h>
#include <asm/arch/mux.h>
#include <asm/arch/mmc_host_def.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-types.h>
#include <asm/ehci-omap.h>
#include <asm/gpio.h>
#include "../common/common.h"
#include "../common/eeprom.h"
#ifdef CONFIG_SPL_BUILD
#endif
#if defined(CONFIG_LED_STATUS) && defined(CONFIG_LED_STATUS_BOOT_ENABLE)
#endif
#if defined(CONFIG_MMC)
#define SB_T35_WP_GPIO 59
#endif
#if defined(CONFIG_MMC)
#endif
#ifdef CONFIG_SYS_I2C_OMAP24XX
#else
#endif
#ifdef CONFIG_SMC911X
#define SB_T35_SMC911X_BASE	(CONFIG_SMC911X_BASE + SZ_16M)
#endif
#ifdef CONFIG_USB_EHCI_OMAP
#define SB_T35_USB_HUB_RESET_GPIO	167
#endif /* CONFIG_USB_EHCI_OMAP */
