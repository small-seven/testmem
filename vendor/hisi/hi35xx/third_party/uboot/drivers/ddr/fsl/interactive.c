#include <common.h>
#include <cli.h>
#include <env.h>
#include <linux/ctype.h>
#include <asm/types.h>
#include <asm/io.h>
#include <fsl_ddr_sdram.h>
#include <fsl_ddr.h>
#define COMMON_TIMING(x) {#x, offsetof(common_timing_params_t, x), \
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR1) || defined(CONFIG_SYS_FSL_DDR2)
#endif
#define DIMM_PARM(x) {#x, offsetof(dimm_params_t, x), \
#define DIMM_PARM_HEX(x) {#x, offsetof(dimm_params_t, x), \
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR1) || defined(CONFIG_SYS_FSL_DDR2)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR4) || defined(CONFIG_SYS_FSL_DDR3)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR1) || defined(CONFIG_SYS_FSL_DDR2)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#else
#endif
#if defined(CONFIG_SYS_FSL_DDR1) || defined(CONFIG_SYS_FSL_DDR2)
#endif
#define CTRL_OPTIONS(x) {#x, offsetof(memctl_options_t, x), \
#define CTRL_OPTIONS_CS(x, y) {"cs" #x "_" #y, \
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 1)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 1)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#endif
#define CFG_REGS(x) {#x, offsetof(fsl_ddr_cfg_regs_t, x), \
#define CFG_REGS_CS(x, y) {"cs" #x "_" #y, \
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 1)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 1)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 3)
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#endif
#define CTRL_OPTIONS_HEX(x) {#x, offsetof(memctl_options_t, x), \
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 1)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 3)
#endif
#if defined(CONFIG_SYS_FSL_DDR3) || defined(CONFIG_SYS_FSL_DDR4)
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 1)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 2)
#endif
#if (CONFIG_CHIP_SELECTS_PER_CTRL > 3)
#endif
#endif
#ifdef CONFIG_SYS_FSL_DDR1
#endif
#ifdef CONFIG_SYS_FSL_DDR2
#endif
#ifdef CONFIG_SYS_FSL_DDR3
#define PRINT_NXS(x, y, z...) printf("%-3d    : %02x " z "\n", x, (u8)y);
#define PRINT_NNXXS(n0, n1, x0, x1, s) \
#endif
#ifdef CONFIG_SYS_FSL_DDR4
#define PRINT_NXS(x, y, z...) printf("%-3d    : %02x " z "\n", x, (u8)y);
#define PRINT_NNXXS(n0, n1, x0, x1, s) \
#endif
#if defined(CONFIG_SYS_FSL_DDR1)
#elif defined(CONFIG_SYS_FSL_DDR2)
#elif defined(CONFIG_SYS_FSL_DDR3)
#elif defined(CONFIG_SYS_FSL_DDR4)
#endif
#define DATA_OPTIONS(name, step, dimm) {#name, step, dimm}
