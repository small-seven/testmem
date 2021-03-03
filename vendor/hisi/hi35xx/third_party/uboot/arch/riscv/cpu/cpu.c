#include <common.h>
#include <cpu.h>
#include <dm.h>
#include <log.h>
#include <asm/encoding.h>
#include <dm/uclass-internal.h>
#ifdef CONFIG_OF_PRIOR_STAGE
#endif
#ifndef CONFIG_XIP
#endif
#ifdef CONFIG_CPU
#else  /* !CONFIG_CPU */
#if CONFIG_IS_ENABLED(RISCV_MMODE)
#else  /* !CONFIG_IS_ENABLED(RISCV_MMODE) */
#warning "There is no way to determine the available extensions in S-mode."
#warning "Please convert your board to use the RISC-V CPU driver."
#endif /* CONFIG_IS_ENABLED(RISCV_MMODE) */
#endif /* CONFIG_CPU */
#ifdef CONFIG_CPU
#endif
