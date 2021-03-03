#include <common.h>
#include <nand.h>
#include <errno.h>
#include <linux/mtd/concat.h>
#ifndef CONFIG_SYS_NAND_BASE_LIST
#define CONFIG_SYS_NAND_BASE_LIST { CONFIG_SYS_NAND_BASE }
#endif
#ifndef CONFIG_SYS_NAND_SELF_INIT
#endif
#ifdef CONFIG_MTD
#endif
#ifndef CONFIG_SYS_NAND_SELF_INIT
#endif
#ifdef CONFIG_MTD_CONCAT
#else
#endif
#ifdef CONFIG_SYS_NAND_SELF_INIT
#else
#endif
#ifdef CONFIG_SYS_NAND_SELECT_DEVICE
#endif
