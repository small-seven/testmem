#include <common.h>
#include <malloc.h>
#include <asm/io.h>
#include <linux/errno.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/rawnand.h>
#include <linux/mtd/partitions.h>
#include <linux/mtd/nand_ecc.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#include <nand.h>
#define arasan_nand_base ((struct nand_regs __iomem *)ARASAN_NAND_BASEADDR)
#define ONDIE_ECC_FEATURE_ADDR			0x90
#define ENABLE_ONDIE_ECC			0x08
#define ARASAN_PROG_RD_MASK			0x00000001
#define ARASAN_PROG_BLK_ERS_MASK		0x00000004
#define ARASAN_PROG_RD_ID_MASK			0x00000040
#define ARASAN_PROG_RD_STS_MASK			0x00000008
#define ARASAN_PROG_PG_PROG_MASK		0x00000010
#define ARASAN_PROG_RD_PARAM_PG_MASK		0x00000080
#define ARASAN_PROG_RST_MASK			0x00000100
#define ARASAN_PROG_GET_FTRS_MASK		0x00000200
#define ARASAN_PROG_SET_FTRS_MASK		0x00000400
#define ARASAN_PROG_CHNG_ROWADR_END_MASK	0x00400000
#define ARASAN_NAND_CMD_ECC_ON_MASK		0x80000000
#define ARASAN_NAND_CMD_CMD12_MASK		0xFFFF
#define ARASAN_NAND_CMD_PG_SIZE_MASK		0x3800000
#define ARASAN_NAND_CMD_PG_SIZE_SHIFT		23
#define ARASAN_NAND_CMD_CMD2_SHIFT		8
#define ARASAN_NAND_CMD_ADDR_CYCL_MASK		0x70000000
#define ARASAN_NAND_CMD_ADDR_CYCL_SHIFT		28
#define ARASAN_NAND_MEM_ADDR1_PAGE_MASK		0xFFFF0000
#define ARASAN_NAND_MEM_ADDR1_COL_MASK		0xFFFF
#define ARASAN_NAND_MEM_ADDR1_PAGE_SHIFT	16
#define ARASAN_NAND_MEM_ADDR2_PAGE_MASK		0xFF
#define ARASAN_NAND_MEM_ADDR2_CS_MASK		0xC0000000
#define ARASAN_NAND_MEM_ADDR2_CS0_MASK         (0x3 << 30)
#define ARASAN_NAND_MEM_ADDR2_CS1_MASK         (0x1 << 30)
#define ARASAN_NAND_MEM_ADDR2_BCH_MASK		0xE000000
#define ARASAN_NAND_MEM_ADDR2_BCH_SHIFT		25
#define ARASAN_NAND_INT_STS_ERR_EN_MASK		0x10
#define ARASAN_NAND_INT_STS_MUL_BIT_ERR_MASK	0x08
#define ARASAN_NAND_INT_STS_BUF_RD_RDY_MASK	0x02
#define ARASAN_NAND_INT_STS_BUF_WR_RDY_MASK	0x01
#define ARASAN_NAND_INT_STS_XFR_CMPLT_MASK	0x04
#define ARASAN_NAND_PKT_REG_PKT_CNT_MASK	0xFFF000
#define ARASAN_NAND_PKT_REG_PKT_SIZE_MASK	0x7FF
#define ARASAN_NAND_PKT_REG_PKT_CNT_SHFT	12
#define ARASAN_NAND_ROW_ADDR_CYCL_MASK		0x0F
#define ARASAN_NAND_COL_ADDR_CYCL_MASK		0xF0
#define ARASAN_NAND_COL_ADDR_CYCL_SHIFT		4
#define ARASAN_NAND_ECC_SIZE_SHIFT		16
#define ARASAN_NAND_ECC_BCH_SHIFT		27
#define ARASAN_NAND_PKTSIZE_1K			1024
#define ARASAN_NAND_PKTSIZE_512			512
#define ARASAN_NAND_POLL_TIMEOUT		1000000
#define ARASAN_NAND_INVALID_ADDR_CYCL		0xFF
#define ERR_ADDR_CYCLE				-1
#define READ_BUFF_SIZE				0x4000
#ifdef CONFIG_SYS_NAND_NO_SUBPAGE_WRITE
#endif
