#ifndef __UBOOT__
#include <linux/device.h>
#include <linux/kernel.h>
#endif
#include <linux/mtd/spinand.h>
#define SPINAND_MFR_GIGADEVICE			0xC8
#define GD5FXGQ4XA_STATUS_ECC_1_7_BITFLIPS	(1 << 4)
#define GD5FXGQ4XA_STATUS_ECC_8_BITFLIPS	(3 << 4)
#define GD5FXGQ4XEXXG_REG_STATUS2		0xf0
static int gd5fxgq4xexxg_ooblayout_free(struct mtd_info *mtd, int section,
					struct mtd_oob_region *region)
{
	if (section)
		return -ERANGE;

	/* Reserve 1 bytes for the BBM. */
	region->offset = 1;
	region->length = 63;

	return 0;
}
