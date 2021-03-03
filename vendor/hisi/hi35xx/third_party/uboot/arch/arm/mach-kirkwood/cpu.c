#include <common.h>
#include <command.h>
#include <env.h>
#include <netdev.h>
#include <asm/cache.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <mvebu_mmc.h>
#if defined(CONFIG_DISPLAY_CPUINFO)
#endif /* CONFIG_DISPLAY_CPUINFO */
#ifdef CONFIG_ARCH_CPU_INIT
#ifdef CONFIG_KIRKWOOD_RGMII_PAD_1V8
#endif
#ifdef CONFIG_KIRKWOOD_EGIGA_INIT
#endif
#ifdef CONFIG_KIRKWOOD_PCIE_INIT
#endif
#endif /* CONFIG_ARCH_CPU_INIT */
#if defined(CONFIG_ARCH_MISC_INIT)
#endif /* CONFIG_ARCH_MISC_INIT */
#ifdef CONFIG_MVGBE
#endif
#ifdef CONFIG_MVEBU_MMC
#endif /* CONFIG_MVEBU_MMC */
