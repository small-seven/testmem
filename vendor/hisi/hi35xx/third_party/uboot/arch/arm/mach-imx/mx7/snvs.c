#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <linux/bitops.h>
#define SNVS_HPCOMR		0x04
#define SNVS_HPCOMR_NPSWA_EN	BIT(31)
