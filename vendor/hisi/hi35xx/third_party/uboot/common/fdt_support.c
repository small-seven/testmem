#include <common.h>
#include <env.h>
#include <mapmem.h>
#include <stdio_dev.h>
#include <linux/ctype.h>
#include <linux/types.h>
#include <asm/global_data.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <exports.h>
#include <fdtdec.h>
#if defined(OF_STDOUT_PATH)
#elif defined(CONFIG_OF_STDOUT_VIA_ALIAS) && defined(CONFIG_CONS_INDEX)
#else
#endif
#if defined(DEBUG)
#endif
#if defined(DEBUG)
#endif
#if defined(DEBUG)
#endif
#ifdef CONFIG_ARCH_FIXUP_FDT_MEMORY
#if CONFIG_NR_DRAM_BANKS > 4
#define MEMORY_BANKS_MAX CONFIG_NR_DRAM_BANKS
#else
#define MEMORY_BANKS_MAX 4
#endif
#endif
#ifdef FDT_SEQ_MACADDR_FROM_ENV
#endif
#ifdef FDT_SEQ_MACADDR_FROM_ENV
#endif
#ifndef FDT_SEQ_MACADDR_FROM_ENV
#endif
#ifdef FDT_SEQ_MACADDR_FROM_ENV
#endif
#ifdef CONFIG_PCI
#define CONFIG_SYS_PCI_NR_INBOUND_WIN 4
#define FDT_PCI_PREFETCH	(0x40000000)
#define FDT_PCI_MEM32		(0x02000000)
#define FDT_PCI_IO		(0x01000000)
#define FDT_PCI_MEM64		(0x03000000)
#ifdef CONFIG_SYS_PCI_64BIT
#else
#endif
#endif
#ifdef CONFIG_FDT_FIXUP_PARTITIONS
#include <jffs2/load_kernel.h>
#include <mtd_node.h>
#endif
#define OF_MAX_ADDR_CELLS	4
#define OF_BAD_ADDR	FDT_ADDR_T_NONE
#define OF_CHECK_COUNTS(na, ns)	((na) > 0 && (na) <= OF_MAX_ADDR_CELLS && \
#ifdef DEBUG
#else
#endif
#ifdef CONFIG_OF_ISA_BUS
#endif /* CONFIG_OF_ISA_BUS */
#ifdef CONFIG_OF_ISA_BUS
#endif /* CONFIG_OF_ISA_BUS */
#ifdef DEBUG
#endif
#if defined(CONFIG_VIDEO) || defined(CONFIG_LCD)
#endif
#ifdef CONFIG_OF_LIBFDT_OVERLAY
#endif
