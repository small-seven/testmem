#include <cpu_func.h>
#include <dm.h>
#include <nand.h>
#include <linux/bitfield.h>
#include <linux/dma-direction.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include "denali.h"
#define DENALI_NAND_NAME    "denali-nand"
#define DENALI_INDEXED_CTRL	0x00
#define DENALI_INDEXED_DATA	0x10
#define DENALI_MAP00		(0 << 26)	/* direct access to buffer */
#define DENALI_MAP01		(1 << 26)	/* read/write pages in PIO */
#define DENALI_MAP10		(2 << 26)	/* high-level control plane */
#define DENALI_MAP11		(3 << 26)	/* direct controller access */
#define DENALI_MAP11_CMD	((DENALI_MAP11) | 0)	/* command cycle */
#define DENALI_MAP11_ADDR	((DENALI_MAP11) | 1)	/* address cycle */
#define DENALI_MAP11_DATA	((DENALI_MAP11) | 2)	/* data cycle */
#define DENALI_ERASE		0x01
#define DENALI_BANK(denali)	((denali)->active_bank << 24)
#define DENALI_INVALID_BANK	-1
#define DENALI_NR_BANKS		4
static int denali_ooblayout_free(struct mtd_info *mtd, int section,
				 struct mtd_oob_region *oobregion)
{
	struct denali_nand_info *denali = mtd_to_denali(mtd);
	struct nand_chip *chip = mtd_to_nand(mtd);

	if (section)
		return -ERANGE;

	oobregion->offset = chip->ecc.total + denali->oob_skip_bytes;
	oobregion->length = mtd->oobsize - oobregion->offset;

	return 0;
}
