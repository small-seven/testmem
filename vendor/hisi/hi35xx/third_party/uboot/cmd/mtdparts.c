#include <common.h>
#include <command.h>
#include <env.h>
#include <malloc.h>
#include <jffs2/load_kernel.h>
#include <linux/list.h>
#include <linux/ctype.h>
#include <linux/err.h>
#include <linux/mtd/mtd.h>
#if defined(CONFIG_CMD_NAND)
#include <linux/mtd/rawnand.h>
#include <nand.h>
#endif
#if defined(CONFIG_CMD_ONENAND)
#include <linux/mtd/onenand.h>
#include <onenand_uboot.h>
#endif
#define SIZE_REMAINING		(~0llu)
#define OFFSET_NOT_SPECIFIED	(~0llu)
#define MIN_PART_SIZE		4096
#define MTD_WRITEABLE_CMD		1
#if !defined(MTDIDS_DEFAULT)
#ifdef CONFIG_MTDIDS_DEFAULT
#define MTDIDS_DEFAULT CONFIG_MTDIDS_DEFAULT
#else
#define MTDIDS_DEFAULT NULL
#endif
#endif
#if !defined(MTDPARTS_DEFAULT)
#ifdef CONFIG_MTDPARTS_DEFAULT
#define MTDPARTS_DEFAULT CONFIG_MTDPARTS_DEFAULT
#else
#define MTDPARTS_DEFAULT NULL
#endif
#endif
#if defined(CONFIG_SYS_MTDPARTS_RUNTIME)
#endif
#define MTDIDS_MAXLEN		128
#define MTDPARTS_MAXLEN		512
#define PARTITION_MAXLEN	16
#define SIZE_GB ((u32)1024*1024*1024)
#define SIZE_MB ((u32)1024*1024)
#define SIZE_KB ((u32)1024)
#if defined(CONFIG_CMD_MTDPARTS_SHOW_NET_SIZES)
#endif
#if defined(CONFIG_CMD_MTDPARTS_SHOW_NET_SIZES)
#else /* !defined(CONFIG_CMD_MTDPARTS_SHOW_NET_SIZES) */
#endif /* defined(CONFIG_CMD_MTDPARTS_SHOW_NET_SIZES) */
#if defined(CONFIG_CMD_MTDPARTS_SPREAD)
#endif /* CONFIG_CMD_MTDPARTS_SPREAD */
#if defined(CONFIG_SYS_MTDPARTS_RUNTIME)
#endif
#define PART_ADD_DESC_MAXLEN 64
#if defined(CONFIG_CMD_MTDPARTS_SPREAD)
#endif
#if defined(CONFIG_CMD_MTDPARTS_SPREAD)
#endif
#if defined(CONFIG_CMD_MTDPARTS_SPREAD)
#endif /* CONFIG_CMD_MTDPARTS_SPREAD */
#ifdef CONFIG_SYS_LONGHELP
#if defined(CONFIG_CMD_MTDPARTS_SPREAD)
#endif
#if defined(CONFIG_CMD_MTDPARTS_SPREAD)
#else
#endif /* CONFIG_CMD_MTDPARTS_SPREAD */
#endif
