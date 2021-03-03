#include <config.h>
#include <common.h>
#include <asm/io.h>
#include <asm/immap.h>
#if defined(CONFIG_CMD_NAND)
#include <nand.h>
#include <linux/mtd/mtd.h>
#define SET_CLE		0x10
#define SET_ALE		0x08
#endif
