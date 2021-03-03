#include <common.h>
#include <fdt_support.h>
#ifdef CONFIG_ARMV7_NONSEC
#include <asm/armv7.h>
#endif
#include <asm/psci.h>
#include <asm/spin_table.h>
#ifdef CONFIG_FMAN_ENET
#endif
#if defined(CONFIG_ARMV7_NONSEC) || defined(CONFIG_OF_LIBFDT)
#ifdef CONFIG_ARMV7_NONSEC
#endif
#ifdef CONFIG_OF_LIBFDT
#endif
#ifdef CONFIG_ARMV8_SPIN_TABLE
#endif
#if defined(CONFIG_ARMV7_NONSEC) || defined(CONFIG_ARMV8_PSCI) || \
#endif
#endif
#ifdef CONFIG_FMAN_ENET
#endif
