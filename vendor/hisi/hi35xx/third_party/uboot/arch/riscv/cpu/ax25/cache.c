#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <dm/uclass-internal.h>
#include <cache.h>
#include <asm/csr.h>
#ifdef CONFIG_RISCV_NDS_CACHE
#if CONFIG_IS_ENABLED(RISCV_MMODE) || CONFIG_IS_ENABLED(SPL_RISCV_MMODE)
#define CCTL_REG_MCCTLCOMMAND_NUM	0x7cc
#define CCTL_L1D_WBINVAL_ALL	6
#endif
#endif
#ifdef CONFIG_V5L2_CACHE
#endif
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
#ifdef CONFIG_RISCV_NDS_CACHE
#if CONFIG_IS_ENABLED(RISCV_MMODE) || CONFIG_IS_ENABLED(SPL_RISCV_MMODE)
#endif
#endif
#endif
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
#ifdef CONFIG_RISCV_NDS_CACHE
#if CONFIG_IS_ENABLED(RISCV_MMODE) || CONFIG_IS_ENABLED(SPL_RISCV_MMODE)
#endif
#endif
#endif
#if !CONFIG_IS_ENABLED(SYS_ICACHE_OFF)
#ifdef CONFIG_RISCV_NDS_CACHE
#if CONFIG_IS_ENABLED(RISCV_MMODE) || CONFIG_IS_ENABLED(SPL_RISCV_MMODE)
#endif
#endif
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#ifdef CONFIG_RISCV_NDS_CACHE
#if CONFIG_IS_ENABLED(RISCV_MMODE) || CONFIG_IS_ENABLED(SPL_RISCV_MMODE)
#endif
#ifdef CONFIG_V5L2_CACHE
#endif
#endif
#endif
#if !CONFIG_IS_ENABLED(SYS_DCACHE_OFF)
#ifdef CONFIG_RISCV_NDS_CACHE
#if CONFIG_IS_ENABLED(RISCV_MMODE) || CONFIG_IS_ENABLED(SPL_RISCV_MMODE)
#endif
#ifdef CONFIG_V5L2_CACHE
#endif
#endif
#endif
#ifdef CONFIG_RISCV_NDS_CACHE
#if CONFIG_IS_ENABLED(RISCV_MMODE) || CONFIG_IS_ENABLED(SPL_RISCV_MMODE)
#endif
#endif
#ifdef CONFIG_RISCV_NDS_CACHE
#if CONFIG_IS_ENABLED(RISCV_MMODE) || CONFIG_IS_ENABLED(SPL_RISCV_MMODE)
#endif
#endif
