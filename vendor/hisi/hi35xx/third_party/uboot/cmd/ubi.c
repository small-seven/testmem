#include <common.h>
#include <command.h>
#include <env.h>
#include <exports.h>
#include <memalign.h>
#include <mtd.h>
#include <nand.h>
#include <onenand_uboot.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/err.h>
#include <ubi_uboot.h>
#include <linux/errno.h>
#include <jffs2/load_kernel.h>
#undef ubi_msg
#define ubi_msg(fmt, ...) printf("UBI: " fmt "\n", ##__VA_ARGS__)
#ifdef CONFIG_CMD_UBIFS
#include <ubifs_uboot.h>
#endif
#ifdef CONFIG_CMD_UBIFS
#endif
