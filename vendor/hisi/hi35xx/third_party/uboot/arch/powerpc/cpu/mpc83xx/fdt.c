#include <common.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <asm/processor.h>
#if defined(CONFIG_BOOTCOUNT_LIMIT) && \
#include <linux/immap_qe.h>
#endif
#if defined(CONFIG_HAS_ETH0) || defined(CONFIG_HAS_ETH1) ||\
#ifdef CONFIG_ARCH_MPC8313
#if defined(CONFIG_HAS_ETH0)
#endif
#if defined(CONFIG_HAS_ETH1)
#endif
#endif
#endif
#ifdef CONFIG_QE
#endif
#ifdef CONFIG_SYS_NS16550
#endif
#if defined(CONFIG_BOOTCOUNT_LIMIT) && \
#endif
