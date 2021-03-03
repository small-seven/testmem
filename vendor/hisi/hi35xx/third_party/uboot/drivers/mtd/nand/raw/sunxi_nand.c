#include <common.h>
#include <fdtdec.h>
#include <memalign.h>
#include <nand.h>
#include <linux/kernel.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/partitions.h>
#include <linux/io.h>
#include <asm/gpio.h>
#include <asm/arch/clock.h>
#define NFC_REG_CTL		0x0000
#define NFC_REG_ST		0x0004
#define NFC_REG_INT		0x0008
#define NFC_REG_TIMING_CTL	0x000C
#define NFC_REG_TIMING_CFG	0x0010
#define NFC_REG_ADDR_LOW	0x0014
#define NFC_REG_ADDR_HIGH	0x0018
#define NFC_REG_SECTOR_NUM	0x001C
#define NFC_REG_CNT		0x0020
#define NFC_REG_CMD		0x0024
#define NFC_REG_RCMD_SET	0x0028
#define NFC_REG_WCMD_SET	0x002C
#define NFC_REG_IO_DATA		0x0030
#define NFC_REG_ECC_CTL		0x0034
#define NFC_REG_ECC_ST		0x0038
#define NFC_REG_DEBUG		0x003C
#define NFC_REG_ECC_ERR_CNT(x)	((0x0040 + (x)) & ~0x3)
#define NFC_REG_USER_DATA(x)	(0x0050 + ((x) * 4))
#define NFC_REG_SPARE_AREA	0x00A0
#define NFC_REG_PAT_ID		0x00A4
#define NFC_RAM0_BASE		0x0400
#define NFC_RAM1_BASE		0x0800
#define NFC_EN			BIT(0)
#define NFC_RESET		BIT(1)
#define NFC_BUS_WIDTH_MSK	BIT(2)
#define NFC_BUS_WIDTH_8		(0 << 2)
#define NFC_BUS_WIDTH_16	(1 << 2)
#define NFC_RB_SEL_MSK		BIT(3)
#define NFC_RB_SEL(x)		((x) << 3)
#define NFC_CE_SEL_MSK		(0x7 << 24)
#define NFC_CE_SEL(x)		((x) << 24)
#define NFC_CE_CTL		BIT(6)
#define NFC_PAGE_SHIFT_MSK	(0xf << 8)
#define NFC_PAGE_SHIFT(x)	(((x) < 10 ? 0 : (x) - 10) << 8)
#define NFC_SAM			BIT(12)
#define NFC_RAM_METHOD		BIT(14)
#define NFC_DEBUG_CTL		BIT(31)
#define NFC_RB_B2R		BIT(0)
#define NFC_CMD_INT_FLAG	BIT(1)
#define NFC_DMA_INT_FLAG	BIT(2)
#define NFC_CMD_FIFO_STATUS	BIT(3)
#define NFC_STA			BIT(4)
#define NFC_NATCH_INT_FLAG	BIT(5)
#define NFC_RB_STATE(x)		BIT(x + 8)
#define NFC_B2R_INT_ENABLE	BIT(0)
#define NFC_CMD_INT_ENABLE	BIT(1)
#define NFC_DMA_INT_ENABLE	BIT(2)
#define NFC_INT_MASK		(NFC_B2R_INT_ENABLE | \
#define NFC_TIMING_CTL_EDO	BIT(8)
#define NFC_TIMING_CFG(tWB, tADL, tWHR, tRHW, tCAD)		\
#define NFC_CMD_LOW_BYTE_MSK	0xff
#define NFC_CMD_HIGH_BYTE_MSK	(0xff << 8)
#define NFC_CMD(x)		(x)
#define NFC_ADR_NUM_MSK		(0x7 << 16)
#define NFC_ADR_NUM(x)		(((x) - 1) << 16)
#define NFC_SEND_ADR		BIT(19)
#define NFC_ACCESS_DIR		BIT(20)
#define NFC_DATA_TRANS		BIT(21)
#define NFC_SEND_CMD1		BIT(22)
#define NFC_WAIT_FLAG		BIT(23)
#define NFC_SEND_CMD2		BIT(24)
#define NFC_SEQ			BIT(25)
#define NFC_DATA_SWAP_METHOD	BIT(26)
#define NFC_ROW_AUTO_INC	BIT(27)
#define NFC_SEND_CMD3		BIT(28)
#define NFC_SEND_CMD4		BIT(29)
#define NFC_CMD_TYPE_MSK	(0x3 << 30)
#define NFC_NORMAL_OP		(0 << 30)
#define NFC_ECC_OP		(1 << 30)
#define NFC_PAGE_OP		(2 << 30)
#define NFC_READ_CMD_MSK	0xff
#define NFC_RND_READ_CMD0_MSK	(0xff << 8)
#define NFC_RND_READ_CMD1_MSK	(0xff << 16)
#define NFC_PROGRAM_CMD_MSK	0xff
#define NFC_RND_WRITE_CMD_MSK	(0xff << 8)
#define NFC_READ_CMD0_MSK	(0xff << 16)
#define NFC_READ_CMD1_MSK	(0xff << 24)
#define NFC_ECC_EN		BIT(0)
#define NFC_ECC_PIPELINE	BIT(3)
#define NFC_ECC_EXCEPTION	BIT(4)
#define NFC_ECC_BLOCK_SIZE_MSK	BIT(5)
#define NFC_ECC_BLOCK_512	(1 << 5)
#define NFC_RANDOM_EN		BIT(9)
#define NFC_RANDOM_DIRECTION	BIT(10)
#define NFC_ECC_MODE_MSK	(0xf << 12)
#define NFC_ECC_MODE(x)		((x) << 12)
#define NFC_RANDOM_SEED_MSK	(0x7fff << 16)
#define NFC_RANDOM_SEED(x)	((x) << 16)
#define NFC_ECC_ERR(x)		BIT(x)
#define NFC_ECC_PAT_FOUND(x)	BIT(x + 16)
#define NFC_ECC_ERR_CNT(b, x)	(((x) >> ((b) * 8)) & 0xff)
#define NFC_DEFAULT_TIMEOUT_MS	1000
#define NFC_SRAM_SIZE		1024
#define NFC_MAX_CS		7
#ifdef CONFIG_MACH_SUN9I
#else
#endif
#define sunxi_nand_lookup_timing(l, p, c) \
#ifndef __UBOOT__
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif /* __UBOOT__ */
#ifndef __UBOOT__
#endif /* __UBOOT__ */
