#include <common.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <linux/sizes.h>
#include <linux/kernel.h>
#include <asm/psci.h>
#ifdef CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT
#include <asm/armv8/sec_firmware.h>
#endif
#if defined(CONFIG_ARMV7_PSCI) || defined(CONFIG_ARMV8_PSCI) || \
#ifdef CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT
#elif defined(CONFIG_ARMV7_PSCI_1_0) || defined(CONFIG_ARMV8_PSCI)
#elif defined(CONFIG_ARMV7_PSCI_0_2)
#endif
#ifndef CONFIG_ARMV8_SEC_FIRMWARE_SUPPORT
#endif
#endif
