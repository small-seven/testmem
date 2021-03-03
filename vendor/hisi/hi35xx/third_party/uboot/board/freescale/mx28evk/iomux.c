#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/iomux-mx28.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#define	MUX_CONFIG_SSP0	(MXS_PAD_3V3 | MXS_PAD_8MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_GPMI	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_NOPULL)
#define	MUX_CONFIG_ENET	(MXS_PAD_3V3 | MXS_PAD_8MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_EMI	(MXS_PAD_3V3 | MXS_PAD_12MA | MXS_PAD_NOPULL)
#define	MUX_CONFIG_SSP2	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_LCD	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_NOPULL)
#ifdef CONFIG_NAND_MXS
#endif
#define HW_DRAM_CTL29	(0x74 >> 2)
#define CS_MAP		0xf
#define COLUMN_SIZE	0x2
#define ADDR_PINS	0x1
#define APREBIT		0xa
#define HW_DRAM_CTL29_CONFIG	(CS_MAP << 24 | COLUMN_SIZE << 16 | \
