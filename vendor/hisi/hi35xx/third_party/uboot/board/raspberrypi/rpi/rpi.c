#include <common.h>
#include <config.h>
#include <dm.h>
#include <env.h>
#include <efi_loader.h>
#include <fdt_support.h>
#include <fdt_simplefb.h>
#include <init.h>
#include <lcd.h>
#include <memalign.h>
#include <mmc.h>
#include <asm/gpio.h>
#include <asm/arch/mbox.h>
#include <asm/arch/msg.h>
#include <asm/arch/sdhci.h>
#include <asm/global_data.h>
#include <dm/platform_data/serial_bcm283x_mu.h>
#ifdef CONFIG_ARM64
#include <asm/armv8/mmu.h>
#endif
#include <watchdog.h>
#include <dm/pinctrl.h>
#ifdef CONFIG_ARM64
#define DTB_DIR "broadcom/"
#else
#define DTB_DIR ""
#endif
#ifdef CONFIG_OF_BOARD
#endif
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif /* CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG */
#ifdef CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG
#endif
#ifdef CONFIG_HW_WATCHDOG
#endif
#ifdef CONFIG_EFI_LOADER
#endif
