#include <common.h>
#include <config.h>
#include <asm/io.h>
#include <asm/arch/iomux-mx28.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/sys_proto.h>
#define	MUX_CONFIG_SSP0	(MXS_PAD_3V3 | MXS_PAD_8MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_EMI	(MXS_PAD_3V3 | MXS_PAD_12MA | MXS_PAD_NOPULL)
#define HW_DRAM_CTL29	(0x74 >> 2)
#define CS_MAP		0xf
#define COLUMN_SIZE	0x2
#define ADDR_PINS	0x1
#define APREBIT		0xa
#define HW_DRAM_CTL29_CONFIG	(CS_MAP << 24 | COLUMN_SIZE << 16 | \
#define HW_DRAM_CTL39	(0x9c >> 2)
#define TFAW		0xb
#define TDLL		0xc8
#define HW_DRAM_CTL39_CONFIG	(TFAW << 24 | TDLL)
#define HW_DRAM_CTL41	(0xa4 >> 2)
#define TPDEX		0x2
#define TRCD_INT	0x4
#define TRC		0xd
#define HW_DRAM_CTL41_CONFIG	(TPDEX << 24 | TRCD_INT << 8 | TRC)
#define HW_DRAM_CTL42	(0xa8 >> 2)
#define TRAS_MAX	0x36a6
#define TRAS_MIN	0xa
#define HW_DRAM_CTL42_CONFIG  (TRAS_MAX << 8 | TRAS_MIN)
#define HW_DRAM_CTL43	(0xac >> 2)
#define TRP		0x4
#define TRFC		0x27
#define TREF		0x2a0
#define HW_DRAM_CTL43_CONFIG (TRP << 24 | TRFC << 16 | TREF)
