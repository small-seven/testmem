#include <common.h>
#include <malloc.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <nand.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/partitions.h>
#include <linux/mtd/nand_ecc.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#define ZYNQ_NAND_CMD_PHASE		1
#define ZYNQ_NAND_DATA_PHASE		2
#define ZYNQ_NAND_ECC_SIZE		512
#define ZYNQ_NAND_SET_OPMODE_8BIT	(0 << 0)
#define ZYNQ_NAND_SET_OPMODE_16BIT	(1 << 0)
#define ZYNQ_NAND_ECC_STATUS		(1 << 6)
#define ZYNQ_MEMC_CLRCR_INT_CLR1	(1 << 4)
#define ZYNQ_MEMC_SR_RAW_INT_ST1	(1 << 6)
#define ZYNQ_MEMC_SR_INT_ST1		(1 << 4)
#define ZYNQ_MEMC_NAND_ECC_MODE_MASK	0xC
#define ZYNQ_NAND_CLR_CONFIG	((0x1 << 1)  |	/* Disable interrupt */ \
#ifndef CONFIG_NAND_ZYNQ_USE_BOOTLOADER1_TIMINGS
#define ZYNQ_NAND_SET_CYCLES	((0x2 << 20) |	/* t_rr from nand_cycles */ \
#endif
#define ZYNQ_NAND_DIRECT_CMD	((0x4 << 23) |	/* Chip 0 from interface 1 */ \
#define ZYNQ_NAND_ECC_CONFIG	((0x1 << 2)  |	/* ECC available on APB */ \
#define ZYNQ_NAND_ECC_CMD1	((0x80)      |	/* Write command */ \
#define ZYNQ_NAND_ECC_CMD2	((0x85)      |	/* Write col change cmd */ \
#define START_CMD_SHIFT			3
#define END_CMD_SHIFT			11
#define END_CMD_VALID_SHIFT		20
#define ADDR_CYCLES_SHIFT		21
#define CLEAR_CS_SHIFT			21
#define ECC_LAST_SHIFT			10
#define COMMAND_PHASE			(0 << 19)
#define DATA_PHASE			(1 << 19)
#define ONDIE_ECC_FEATURE_ADDR		0x90
#define ONDIE_ECC_FEATURE_ENABLE	0x08
#define ZYNQ_NAND_ECC_LAST	(1 << ECC_LAST_SHIFT)	/* Set ECC_Last */
#define ZYNQ_NAND_CLEAR_CS	(1 << CLEAR_CS_SHIFT)	/* Clear chip select */
#define ZYNQ_NAND_ECC_BUSY	(1 << 6)	/* ECC block is busy */
#define ZYNQ_NAND_ECC_MASK	0x00FFFFFF	/* ECC value mask */
#define ZYNQ_NAND_ROW_ADDR_CYCL_MASK	0x0F
#define ZYNQ_NAND_COL_ADDR_CYCL_MASK	0xF0
#define ZYNQ_NAND_MIO_NUM_NAND_8BIT	13
#define ZYNQ_NAND_MIO_NUM_NAND_16BIT	8
#ifndef NAND_CMD_LOCK_TIGHT
#define NAND_CMD_LOCK_TIGHT 0x2c
#endif
#ifndef NAND_CMD_LOCK_STATUS
#define NAND_CMD_LOCK_STATUS 0x7a
#endif
#define zynq_nand_smc_base	((struct zynq_nand_smc_regs __iomem *)\
#ifndef CONFIG_NAND_ZYNQ_USE_BOOTLOADER1_TIMINGS
#endif
