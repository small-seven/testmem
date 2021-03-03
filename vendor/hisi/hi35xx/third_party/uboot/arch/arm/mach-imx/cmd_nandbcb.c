#include <common.h>
#include <nand.h>
#include <asm/io.h>
#include <jffs2/jffs2.h>
#include <linux/bch.h>
#include <linux/mtd/mtd.h>
#include <asm/arch/sys_proto.h>
#include <asm/mach-imx/imx-nandbcb.h>
#include <asm/mach-imx/imximage.cfg>
#include <mxs_nand.h>
#include <linux/mtd/mtd.h>
#include <nand.h>
#include "../../../cmd/legacy-mtd-utils.h"
#define BF_VAL(v, bf)		(((v) & bf##_MASK) >> bf##_OFFSET)
#define GETBIT(v, n)		(((v) >> (n)) & 0x1)
#if defined(CONFIG_MX6UL) || defined(CONFIG_MX6ULL)
#else
#endif
#if defined(CONFIG_MX6UL) || defined(CONFIG_MX6ULL)
#else
#endif
#ifdef CONFIG_SYS_LONGHELP
#endif
