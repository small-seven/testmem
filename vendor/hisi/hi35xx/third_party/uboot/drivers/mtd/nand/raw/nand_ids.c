#include <common.h>
#include <linux/mtd/rawnand.h>
#include <linux/sizes.h>
#define LP_OPTIONS NAND_SAMSUNG_LP_OPTIONS
#define LP_OPTIONS16 (LP_OPTIONS | NAND_BUSWIDTH_16)
#define SP_OPTIONS NAND_NEED_READRDY
#define SP_OPTIONS16 (SP_OPTIONS | NAND_BUSWIDTH_16)
#ifdef CONFIG_MTD_NAND_MUSEUM_IDS
#endif
