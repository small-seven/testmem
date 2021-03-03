#include <common.h>
#include <command.h>
#include <env.h>
#include <malloc.h>
#include <jffs2/jffs2.h>
#include <linux/list.h>
#include <linux/ctype.h>
#include <cramfs/cramfs_fs.h>
#if defined(CONFIG_CMD_NAND)
#include <linux/mtd/rawnand.h>
#include <nand.h>
#endif
#if defined(CONFIG_CMD_ONENAND)
#include <linux/mtd/mtd.h>
#include <linux/mtd/onenand.h>
#include <onenand_uboot.h>
#endif
#define	DEBUG_JFFS
#undef	DEBUG_JFFS
#ifdef  DEBUG_JFFS
# define DEBUGF(fmt, args...)	printf(fmt ,##args)
#else
# define DEBUGF(fmt, args...)
#endif
#define SIZE_REMAINING		0xFFFFFFFF
#define OFFSET_NOT_SPECIFIED	0xFFFFFFFF
#define MIN_PART_SIZE		4096
#define MTD_WRITEABLE_CMD		1
#ifdef CONFIG_CMD_MTDPARTS
#else
#endif
#if defined(CONFIG_CMD_CRAMFS)
#else
#define cramfs_check(x)		(0)
#define cramfs_load(x,y,z)	(-1)
#define cramfs_ls(x,y)		(0)
#define cramfs_info(x)		(0)
#endif
#ifndef CONFIG_CMD_MTDPARTS
#if defined(CONFIG_CMD_FLASH)
#else
#endif
#if defined(CONFIG_JFFS2_NAND) && defined(CONFIG_CMD_NAND)
#else
#endif
#if defined(CONFIG_CMD_ONENAND)
#else
#endif
#if defined(CONFIG_JFFS2_NAND) && defined(CONFIG_CMD_NAND)
#else
#endif
#if defined(CONFIG_CMD_FLASH)
#else
#endif
#if defined(CONFIG_CMD_ONENAND)
#else
#endif
#if defined(CONFIG_JFFS2_DEV)
#else
#endif
#if defined(CONFIG_JFFS2_PART_SIZE)
#else
#endif
#if defined(CONFIG_JFFS2_PART_OFFSET)
#else
#endif
#endif /* #ifndef CONFIG_CMD_MTDPARTS */
