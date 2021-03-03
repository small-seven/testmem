#include <common.h>
#include <asm/io.h>
#include <asm/unaligned.h>
#include <linux/mtd/rawnand.h>
#include "denali.h"
#define DENALI_MAP01		(1 << 26)	/* read/write pages in PIO */
#define DENALI_MAP10		(2 << 26)	/* high-level control plane */
#define INDEX_CTRL_REG		0x0
#define INDEX_DATA_REG		0x10
#define SPARE_ACCESS		0x41
#define MAIN_ACCESS		0x42
#define PIPELINE_ACCESS		0x2000
#define BANK(x) ((x) << 24)
