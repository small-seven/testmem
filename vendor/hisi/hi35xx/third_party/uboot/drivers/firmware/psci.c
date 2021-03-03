#include <common.h>
#include <dm.h>
#include <irq_func.h>
#include <dm/lists.h>
#include <efi_loader.h>
#include <linux/libfdt.h>
#include <linux/arm-smccc.h>
#include <linux/errno.h>
#include <linux/printk.h>
#include <linux/psci.h>
#define DRIVER_NAME "psci"
#define PSCI_METHOD_HVC 1
#define PSCI_METHOD_SMC 2
#if IS_ENABLED(CONFIG_EFI_LOADER) && IS_ENABLED(CONFIG_PSCI_RESET)
#endif /* IS_ENABLED(CONFIG_EFI_LOADER) && IS_ENABLED(CONFIG_PSCI_RESET) */
#ifdef CONFIG_PSCI_RESET
#endif /* CONFIG_PSCI_RESET */
#ifdef CONFIG_CMD_POWEROFF
#endif
