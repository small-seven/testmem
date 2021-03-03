#include <common.h>
#include <config.h>
#include <malloc.h>
#include <div64.h>
#include <linux/compiler.h>
#include <linux/stat.h>
#include <linux/time.h>
#include <u-boot/crc.h>
#include <watchdog.h>
#include <jffs2/jffs2.h>
#include <jffs2/jffs2_1pass.h>
#include <linux/compat.h>
#include <linux/errno.h>
#include "jffs2_private.h"
#define	NODE_CHUNK	1024	/* size of memory allocation chunk in b_nodes */
#define	SPIN_BLKSIZE	18	/* spin after having scanned 1<<BLKSIZE bytes */
#undef	DEBUG_DIRENTS		/* print directory entry list after scan */
#undef	DEBUG_FRAGMENTS		/* print fragment list after scan */
#undef	DEBUG			/* enable debugging messages */
#ifdef  DEBUG
# define DEBUGF(fmt,args...)	printf(fmt ,##args)
#else
# define DEBUGF(fmt,args...)
#endif
#include "summary.h"
#if (defined(CONFIG_JFFS2_NAND) && \
#include <nand.h>
#define NAND_PAGE_SIZE 512
#define NAND_PAGE_SHIFT 9
#define NAND_PAGE_MASK (~(NAND_PAGE_SIZE-1))
#ifndef NAND_CACHE_PAGES
#define NAND_CACHE_PAGES 16
#endif
#define NAND_CACHE_SIZE (NAND_CACHE_PAGES*NAND_PAGE_SIZE)
#endif
#if defined(CONFIG_CMD_ONENAND)
#include <linux/mtd/mtd.h>
#include <linux/mtd/onenand.h>
#include <onenand_uboot.h>
#define ONENAND_PAGE_SIZE 2048
#define ONENAND_PAGE_SHIFT 11
#define ONENAND_PAGE_MASK (~(ONENAND_PAGE_SIZE-1))
#ifndef ONENAND_CACHE_PAGES
#define ONENAND_CACHE_PAGES 4
#endif
#define ONENAND_CACHE_SIZE (ONENAND_CACHE_PAGES*ONENAND_PAGE_SIZE)
#endif
#if defined(CONFIG_CMD_FLASH)
#endif
#if defined(CONFIG_CMD_FLASH)
#endif
#if defined(CONFIG_JFFS2_NAND) && defined(CONFIG_CMD_NAND)
#endif
#if defined(CONFIG_CMD_ONENAND)
#endif
#if defined(CONFIG_CMD_FLASH)
#endif
#if defined(CONFIG_JFFS2_NAND) && \
#endif
#if defined(CONFIG_CMD_ONENAND)
#endif
#if defined(CONFIG_JFFS2_NAND) && defined(CONFIG_CMD_NAND)
#endif
#if defined(CONFIG_CMD_ONENAND)
#endif
#if defined(CONFIG_JFFS2_LZO)
#endif
#if 0
#endif
#if 0
#endif
#ifdef CONFIG_SYS_JFFS2_SORT_FRAGMENTS
#endif
#ifdef CONFIG_SYS_JFFS2_SORT_FRAGMENTS
#endif
#ifdef CONFIG_SYS_JFFS2_SORT_FRAGMENTS
#endif
#if 0
#endif
#ifndef CONFIG_SYS_JFFS2_SORT_FRAGMENTS
#endif
#if 0
#endif
#if defined(CONFIG_JFFS2_LZO)
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#ifdef CONFIG_SYS_JFFS2_SORT_FRAGMENTS
#endif
#if 0
#endif
#if 0
#endif
#if 0
#endif
#ifdef CONFIG_JFFS2_SUMMARY
#define dbg_summary(...) do {} while (0);
#endif /* CONFIG_JFFS2_SUMMARY */
#ifdef DEBUG_FRAGMENTS
#endif
#ifdef DEBUG_DIRENTS
#endif
#define DEFAULT_EMPTY_SCAN_SIZE	256
#ifdef CONFIG_JFFS2_SUMMARY
#endif
#ifdef CONFIG_JFFS2_SUMMARY
#endif /* CONFIG_JFFS2_SUMMARY */
#if defined(CONFIG_SYS_JFFS2_SORT_FRAGMENTS)
#endif
#if 0
#endif
#ifdef DEBUG_DIRENTS
#endif
#ifdef DEBUG_FRAGMENTS
#endif
#if 0
#endif
