#include <common.h>
#include <clk.h>
#include <dm.h>
#include <nand.h>
#include <reset.h>
#include <linux/iopoll.h>
#include <linux/ioport.h>
#define FMC2_BBM_LEN			2
#define FMC2_ECC_STEP_SIZE		512
#define FMC2_RB_DELAY_US		30
#define FMC2_MAX_CE			2
#define FMC2_THIZ			1
#define FMC2_TIO			8000
#define FMC2_TSYNC			3000
#define FMC2_PCR_TIMING_MASK		0xf
#define FMC2_PMEM_PATT_TIMING_MASK	0xff
#define FMC2_BCR1			0x0
#define FMC2_PCR			0x80
#define FMC2_SR				0x84
#define FMC2_PMEM			0x88
#define FMC2_PATT			0x8c
#define FMC2_HECCR			0x94
#define FMC2_BCHISR			0x254
#define FMC2_BCHICR			0x258
#define FMC2_BCHPBR1			0x260
#define FMC2_BCHPBR2			0x264
#define FMC2_BCHPBR3			0x268
#define FMC2_BCHPBR4			0x26c
#define FMC2_BCHDSR0			0x27c
#define FMC2_BCHDSR1			0x280
#define FMC2_BCHDSR2			0x284
#define FMC2_BCHDSR3			0x288
#define FMC2_BCHDSR4			0x28c
#define FMC2_BCR1_FMC2EN		BIT(31)
#define FMC2_PCR_PWAITEN		BIT(1)
#define FMC2_PCR_PBKEN			BIT(2)
#define FMC2_PCR_PWID_MASK		GENMASK(5, 4)
#define FMC2_PCR_PWID(x)		(((x) & 0x3) << 4)
#define FMC2_PCR_PWID_BUSWIDTH_8	0
#define FMC2_PCR_PWID_BUSWIDTH_16	1
#define FMC2_PCR_ECCEN			BIT(6)
#define FMC2_PCR_ECCALG			BIT(8)
#define FMC2_PCR_TCLR_MASK		GENMASK(12, 9)
#define FMC2_PCR_TCLR(x)		(((x) & 0xf) << 9)
#define FMC2_PCR_TCLR_DEFAULT		0xf
#define FMC2_PCR_TAR_MASK		GENMASK(16, 13)
#define FMC2_PCR_TAR(x)			(((x) & 0xf) << 13)
#define FMC2_PCR_TAR_DEFAULT		0xf
#define FMC2_PCR_ECCSS_MASK		GENMASK(19, 17)
#define FMC2_PCR_ECCSS(x)		(((x) & 0x7) << 17)
#define FMC2_PCR_ECCSS_512		1
#define FMC2_PCR_ECCSS_2048		3
#define FMC2_PCR_BCHECC			BIT(24)
#define FMC2_PCR_WEN			BIT(25)
#define FMC2_SR_NWRF			BIT(6)
#define FMC2_PMEM_MEMSET(x)		(((x) & 0xff) << 0)
#define FMC2_PMEM_MEMWAIT(x)		(((x) & 0xff) << 8)
#define FMC2_PMEM_MEMHOLD(x)		(((x) & 0xff) << 16)
#define FMC2_PMEM_MEMHIZ(x)		(((x) & 0xff) << 24)
#define FMC2_PMEM_DEFAULT		0x0a0a0a0a
#define FMC2_PATT_ATTSET(x)		(((x) & 0xff) << 0)
#define FMC2_PATT_ATTWAIT(x)		(((x) & 0xff) << 8)
#define FMC2_PATT_ATTHOLD(x)		(((x) & 0xff) << 16)
#define FMC2_PATT_ATTHIZ(x)		(((x) & 0xff) << 24)
#define FMC2_PATT_DEFAULT		0x0a0a0a0a
#define FMC2_BCHISR_DERF		BIT(1)
#define FMC2_BCHISR_EPBRF		BIT(4)
#define FMC2_BCHICR_CLEAR_IRQ		GENMASK(4, 0)
#define FMC2_BCHDSR0_DUE		BIT(0)
#define FMC2_BCHDSR0_DEF		BIT(1)
#define FMC2_BCHDSR0_DEN_MASK		GENMASK(7, 4)
#define FMC2_BCHDSR0_DEN_SHIFT		4
#define FMC2_BCHDSR1_EBP1_MASK		GENMASK(12, 0)
#define FMC2_BCHDSR1_EBP2_MASK		GENMASK(28, 16)
#define FMC2_BCHDSR1_EBP2_SHIFT		16
#define FMC2_BCHDSR2_EBP3_MASK		GENMASK(12, 0)
#define FMC2_BCHDSR2_EBP4_MASK		GENMASK(28, 16)
#define FMC2_BCHDSR2_EBP4_SHIFT		16
#define FMC2_BCHDSR3_EBP5_MASK		GENMASK(12, 0)
#define FMC2_BCHDSR3_EBP6_MASK		GENMASK(28, 16)
#define FMC2_BCHDSR3_EBP6_SHIFT		16
#define FMC2_BCHDSR4_EBP7_MASK		GENMASK(12, 0)
#define FMC2_BCHDSR4_EBP8_MASK		GENMASK(28, 16)
#define FMC2_BCHDSR4_EBP8_SHIFT		16
#define FMC2_NSEC_PER_SEC		1000000000L
