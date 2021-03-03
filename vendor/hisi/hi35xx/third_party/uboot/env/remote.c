#include <common.h>
#include <command.h>
#include <env_internal.h>
#include <linux/stddef.h>
#include <u-boot/crc.h>
#ifdef ENV_IS_EMBEDDED
#else /* ! ENV_IS_EMBEDDED */
#endif /* ENV_IS_EMBEDDED */
#ifdef CONFIG_CMD_SAVEENV
#ifdef CONFIG_SRIO_PCIE_BOOT_SLAVE
#else
#endif
#endif /* CONFIG_CMD_SAVEENV */
#ifndef ENV_IS_EMBEDDED
#endif
