#include <common.h>
#include <command.h>
#include <cpu_func.h>
#include <env.h>
#include <errno.h>
#include <linux/bug.h>
#include <asm/io.h>
#include <linux/libfdt.h>
#include <net.h>
#include <fdt_support.h>
#include <fsl-mc/fsl_mc.h>
#include <fsl-mc/fsl_mc_sys.h>
#include <fsl-mc/fsl_mc_private.h>
#include <fsl-mc/fsl_dpmng.h>
#include <fsl-mc/fsl_dprc.h>
#include <fsl-mc/fsl_dpio.h>
#include <fsl-mc/fsl_dpni.h>
#include <fsl-mc/fsl_qbman_portal.h>
#include <fsl-mc/ldpaa_wriop.h>
#define MC_RAM_BASE_ADDR_ALIGNMENT  (512UL * 1024 * 1024)
#define MC_RAM_BASE_ADDR_ALIGNMENT_MASK	(~(MC_RAM_BASE_ADDR_ALIGNMENT - 1))
#define MC_RAM_SIZE_ALIGNMENT	    (256UL * 1024 * 1024)
#define MC_MEM_SIZE_ENV_VAR	"mcmemsize"
#define MC_BOOT_TIMEOUT_ENV_VAR	"mcboottimeout"
#define MC_BOOT_ENV_VAR		"mcinitcmd"
#define MC_DRAM_BLOCK_DEFAULT_SIZE (512UL * 1024 * 1024)
#ifdef CONFIG_SYS_LS_MC_DRAM_AIOP_IMG_OFFSET
#endif
#ifdef DEBUG
#else
#define dump_ram_words(title, addr)
#define dump_mc_ccsr_regs(mc_ccsr_regs)
#endif /* DEBUG */
#ifndef CONFIG_SYS_LS_MC_FW_IN_DDR
#endif
#define MC_DT_INCREASE_SIZE	64
#define is_dpni(s) (s != NULL ? !strncmp(s, "dpni@", 5) : 0)
#ifndef CONFIG_SYS_LS_MC_DPC_IN_DDR
#endif
#ifdef CONFIG_SYS_LS_MC_DRAM_DPC_OFFSET
#else
#error "CONFIG_SYS_LS_MC_DRAM_DPC_OFFSET not defined"
#endif
#ifdef CONFIG_SYS_LS_MC_DPC_IN_DDR
#else
#endif /* not defined CONFIG_SYS_LS_MC_DPC_IN_DDR */
#ifndef CONFIG_SYS_LS_MC_DPL_IN_DDR
#endif
#ifdef CONFIG_SYS_LS_MC_DRAM_DPL_OFFSET
#else
#error "CONFIG_SYS_LS_MC_DRAM_DPL_OFFSET not defined"
#endif
#ifdef CONFIG_SYS_LS_MC_DPL_IN_DDR
#else
#endif /* not defined CONFIG_SYS_LS_MC_DPL_IN_DDR */
#ifdef CONFIG_SYS_LS_MC_DRAM_AIOP_IMG_OFFSET
#ifndef CONFIG_SYS_LS_MC_DPC_IN_DDR
#endif
#ifdef CONFIG_SYS_LS_MC_DPC_IN_DDR
#else
#endif
#endif
#ifndef CONFIG_SYS_LS_MC_FW_IN_DDR
#endif
#ifdef CONFIG_SYS_LS_MC_FW_IN_DDR
#else
#endif
#ifdef CONFIG_SYS_LS_MC_DRAM_AIOP_IMG_OFFSET
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_SYS_LS_MC_DRAM_AIOP_IMG_OFFSET
#endif
#ifdef CONFIG_SYS_LS_MC_DRAM_AIOP_IMG_OFFSET
#endif
#if defined(CONFIG_FSL_MC_ENET)
#endif /* CONFIG_FSL_MC_ENET */
