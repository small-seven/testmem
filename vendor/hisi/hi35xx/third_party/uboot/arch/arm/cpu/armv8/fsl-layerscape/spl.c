#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <spl.h>
#include <asm/io.h>
#include <fsl_ifc.h>
#include <i2c.h>
#include <fsl_csu.h>
#include <asm/arch/fdt.h>
#include <asm/arch/ppa.h>
#include <asm/arch/soc.h>
#ifdef CONFIG_SPL_MMC_SUPPORT
#endif
#ifdef CONFIG_SPL_NAND_SUPPORT
#endif
#ifdef CONFIG_QSPI_BOOT
#endif
#ifdef CONFIG_SPL_BUILD
#if defined(CONFIG_NXP_ESBC) && defined(CONFIG_FSL_LSCH2)
#endif
#ifdef CONFIG_LAYERSCAPE_NS_ACCESS
#endif
#ifdef CONFIG_SPL_FSL_LS_PPA
#endif
#ifdef CONFIG_ARCH_LS2080A
#endif
#ifdef CONFIG_SPL_I2C_SUPPORT
#endif
#ifdef CONFIG_VID
#endif
#ifdef CONFIG_SPL_FSL_LS_PPA
#ifndef CONFIG_SYS_MEM_RESERVE_SECURE
#error Need secure RAM for PPA
#endif
#endif	/* CONFIG_SPL_FSL_LS_PPA */
#if defined(CONFIG_QSPI_AHB_INIT) && defined(CONFIG_QSPI_BOOT)
#endif
#ifdef CONFIG_SPL_OS_BOOT
#endif	/* CONFIG_SPL_OS_BOOT */
#ifdef CONFIG_SPL_LOAD_FIT
#endif
#endif /* CONFIG_SPL_BUILD */
