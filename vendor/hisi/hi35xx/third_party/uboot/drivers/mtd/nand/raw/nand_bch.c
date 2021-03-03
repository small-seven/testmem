#include <common.h>
#include <linux/types.h>
#include <linux/bitops.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/nand_bch.h>
#include <linux/bch.h>
#include <malloc.h>
void nand_bch_free(struct nand_bch_control *nbc)
{
	if (nbc) {
		free_bch(nbc->bch);
		kfree(nbc->errloc);
		kfree(nbc->eccmask);
		kfree(nbc);
	}
}
