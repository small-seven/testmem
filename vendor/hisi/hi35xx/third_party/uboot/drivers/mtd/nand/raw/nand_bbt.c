#include <common.h>
#include <malloc.h>
#include <linux/compat.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/bbm.h>
#include <linux/mtd/rawnand.h>
#include <linux/bitops.h>
#include <linux/string.h>
#define BBT_BLOCK_GOOD		0x00
#define BBT_BLOCK_WORN		0x01
#define BBT_BLOCK_RESERVED	0x02
#define BBT_BLOCK_FACTORY_BAD	0x03
#define BBT_ENTRY_MASK		0x03
#define BBT_ENTRY_SHIFT		2
#define BADBLOCK_SCAN_MASK (~NAND_BBT_NO_OOB)
