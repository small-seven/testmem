#ifndef __UBOOT__
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/stringify.h>
#include <linux/namei.h>
#include <linux/stat.h>
#include <linux/miscdevice.h>
#include <linux/log2.h>
#include <linux/kthread.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/major.h>
#else
#include <linux/bug.h>
#include <linux/log2.h>
#endif
#include <linux/err.h>
#include <ubi_uboot.h>
#include <linux/mtd/partitions.h>
#include "ubi.h"
#define MTD_PARAM_LEN_MAX 64
#define MTD_PARAM_MAX_COUNT 4
#define MAX_MTD_UBI_BEB_LIMIT 768
#ifdef CONFIG_MTD_UBI_MODULE
#define ubi_is_module() 1
#else
#define ubi_is_module() 0
#endif
#if (CONFIG_SYS_MALLOC_LEN < (512 << 10))
#error Malloc area too small for UBI, increase CONFIG_SYS_MALLOC_LEN to >= 512k
#endif
#ifndef __UBOOT__
#ifdef CONFIG_MTD_UBI_FASTMAP
#endif
#else
#ifdef CONFIG_MTD_UBI_FASTMAP
#if !defined(CONFIG_MTD_UBI_FASTMAP_AUTOCONVERT)
#define CONFIG_MTD_UBI_FASTMAP_AUTOCONVERT 0
#endif
#if !defined(CONFIG_MTD_UBI_FM_DEBUG)
#define CONFIG_MTD_UBI_FM_DEBUG 0
#endif
#endif
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifdef CONFIG_MTD_UBI_FASTMAP
#else
#endif
#ifdef CONFIG_MTD_UBI_FASTMAP
#endif
#ifndef __UBOOT__
#else
#endif
#ifdef CONFIG_MTD_UBI_FASTMAP
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifdef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifdef __UBOOT__
#endif
#ifndef __UBOOT__
#else
#endif
#ifdef CONFIG_MTD_UBI_FASTMAP
#endif
