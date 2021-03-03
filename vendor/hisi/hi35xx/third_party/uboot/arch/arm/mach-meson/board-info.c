#include <common.h>
#include <asm/io.h>
#include <dm.h>
#include <linux/bitfield.h>
#include <regmap.h>
#include <syscon.h>
#define AO_SEC_SD_CFG8		0xe0
#define AO_SEC_SOCINFO_OFFSET	AO_SEC_SD_CFG8
#define SOCINFO_MAJOR	GENMASK(31, 24)
#define SOCINFO_PACK	GENMASK(23, 16)
#define SOCINFO_MINOR	GENMASK(15, 8)
#define SOCINFO_MISC	GENMASK(7, 0)
