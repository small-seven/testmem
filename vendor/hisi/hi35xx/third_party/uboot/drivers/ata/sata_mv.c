#include <common.h>
#include <ahci.h>
#include <cpu_func.h>
#include <dm.h>
#include <dm/device-internal.h>
#include <dm/lists.h>
#include <fis.h>
#include <libata.h>
#include <malloc.h>
#include <sata.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <linux/mbus.h>
#include <asm/arch/soc.h>
#if defined(CONFIG_KIRKWOOD)
#define SATAHC_BASE		KW_SATA_BASE
#else
#define SATAHC_BASE		MVEBU_AXP_SATA_BASE
#endif
#define SATA0_BASE		(SATAHC_BASE + 0x2000)
#define SATA1_BASE		(SATAHC_BASE + 0x4000)
#define EDMA_CFG		0x000
#define EDMA_CFG_NCQ		(1 << 5)
#define EDMA_CFG_EQUE		(1 << 9)
#define EDMA_TIMER		0x004
#define EDMA_IECR		0x008
#define EDMA_IEMR		0x00c
#define EDMA_RQBA_HI		0x010
#define EDMA_RQIPR		0x014
#define EDMA_RQIPR_IPMASK	(0x1f << 5)
#define EDMA_RQIPR_IPSHIFT	5
#define EDMA_RQOPR		0x018
#define EDMA_RQOPR_OPMASK	(0x1f << 5)
#define EDMA_RQOPR_OPSHIFT	5
#define EDMA_RSBA_HI		0x01c
#define EDMA_RSIPR		0x020
#define EDMA_RSIPR_IPMASK	(0x1f << 3)
#define EDMA_RSIPR_IPSHIFT	3
#define	EDMA_RSOPR		0x024
#define EDMA_RSOPR_OPMASK	(0x1f << 3)
#define EDMA_RSOPR_OPSHIFT	3
#define EDMA_CMD		0x028
#define EDMA_CMD_ENEDMA		(0x01 << 0)
#define EDMA_CMD_DISEDMA	(0x01 << 1)
#define EDMA_CMD_ATARST		(0x01 << 2)
#define EDMA_CMD_FREEZE		(0x01 << 4)
#define EDMA_TEST_CTL		0x02c
#define EDMA_STATUS		0x030
#define EDMA_IORTO		0x034
#define EDMA_CDTR		0x040
#define EDMA_HLTCND		0x060
#define EDMA_NTSR		0x094
#define BDMA_CMD		0x224
#define BDMA_STATUS		0x228
#define BDMA_DTLB		0x22c
#define BDMA_DTHB		0x230
#define BDMA_DRL		0x234
#define BDMA_DRH		0x238
#define SIR_ICFG		0x050
#define SIR_CFG_GEN2EN		(0x1 << 7)
#define SIR_PLL_CFG		0x054
#define SIR_SSTATUS		0x300
#define SSTATUS_DET_MASK	(0x0f << 0)
#define SIR_SERROR		0x304
#define SIR_SCONTROL		0x308
#define SIR_SCONTROL_DETEN	(0x01 << 0)
#define SIR_LTMODE		0x30c
#define SIR_LTMODE_NELBE	(0x01 << 7)
#define SIR_PHYMODE3		0x310
#define SIR_PHYMODE4		0x314
#define SIR_PHYMODE1		0x32c
#define SIR_PHYMODE2		0x330
#define SIR_BIST_CTRL		0x334
#define SIR_BIST_DW1		0x338
#define SIR_BIST_DW2		0x33c
#define SIR_SERR_IRQ_MASK	0x340
#define SIR_SATA_IFCTRL		0x344
#define SIR_SATA_TESTCTRL	0x348
#define SIR_SATA_IFSTATUS	0x34c
#define SIR_VEND_UNIQ		0x35c
#define SIR_FIS_CFG		0x360
#define SIR_FIS_IRQ_CAUSE	0x364
#define SIR_FIS_IRQ_MASK	0x368
#define SIR_FIS_DWORD0		0x370
#define SIR_FIS_DWORD1		0x374
#define SIR_FIS_DWORD2		0x378
#define SIR_FIS_DWORD3		0x37c
#define SIR_FIS_DWORD4		0x380
#define SIR_FIS_DWORD5		0x384
#define SIR_FIS_DWORD6		0x388
#define SIR_PHYM9_GEN2		0x398
#define SIR_PHYM9_GEN1		0x39c
#define SIR_PHY_CFG		0x3a0
#define SIR_PHYCTL		0x3a4
#define SIR_PHYM10		0x3a8
#define SIR_PHYM12		0x3b0
#define	PIO_DATA		0x100
#define PIO_ERR_FEATURES	0x104
#define PIO_SECTOR_COUNT	0x108
#define PIO_LBA_LOW		0x10c
#define PIO_LBA_MID		0x110
#define PIO_LBA_HI		0x114
#define PIO_DEVICE		0x118
#define PIO_CMD_STATUS		0x11c
#define PIO_STATUS_ERR		(0x01 << 0)
#define PIO_STATUS_DRQ		(0x01 << 3)
#define PIO_STATUS_DF		(0x01 << 5)
#define PIO_STATUS_DRDY		(0x01 << 6)
#define PIO_STATUS_BSY		(0x01 << 7)
#define PIO_CTRL_ALTSTAT	0x120
#define SATAHC_CFG		0x000
#define SATAHC_RQOP		0x004
#define SATAHC_RQIP		0x008
#define SATAHC_ICT		0x00c
#define SATAHC_ITT		0x010
#define SATAHC_ICR		0x014
#define SATAHC_ICR_PORT0	(0x01 << 0)
#define SATAHC_ICR_PORT1	(0x01 << 1)
#define SATAHC_MIC		0x020
#define SATAHC_MIM		0x024
#define SATAHC_LED_CFG		0x02c
#define REQUEST_QUEUE_SIZE	32
#define RESPONSE_QUEUE_SIZE	REQUEST_QUEUE_SIZE
#define CRQB_ALIGN			0x400
#define CRQB_CNTRLFLAGS_DIR		(0x01 << 0)
#define CRQB_CNTRLFLAGS_DQTAGMASK	(0x1f << 1)
#define CRQB_CNTRLFLAGS_DQTAGSHIFT	1
#define CRQB_CNTRLFLAGS_PMPORTMASK	(0x0f << 12)
#define CRQB_CNTRLFLAGS_PMPORTSHIFT	12
#define CRQB_CNTRLFLAGS_PRDMODE		(0x01 << 16)
#define CRQB_CNTRLFLAGS_HQTAGMASK	(0x1f << 17)
#define CRQB_CNTRLFLAGS_HQTAGSHIFT	17
#define CRQB_CMDFEAT_CMDMASK		(0xff << 16)
#define CRQB_CMDFEAT_CMDSHIFT		16
#define CRQB_CMDFEAT_FEATMASK		(0xff << 16)
#define CRQB_CMDFEAT_FEATSHIFT		24
#define CRQB_ADDR_LBA_LOWMASK		(0xff << 0)
#define CRQB_ADDR_LBA_LOWSHIFT		0
#define CRQB_ADDR_LBA_MIDMASK		(0xff << 8)
#define CRQB_ADDR_LBA_MIDSHIFT		8
#define CRQB_ADDR_LBA_HIGHMASK		(0xff << 16)
#define CRQB_ADDR_LBA_HIGHSHIFT		16
#define CRQB_ADDR_DEVICE_MASK		(0xff << 24)
#define CRQB_ADDR_DEVICE_SHIFT		24
#define CRQB_ADDR_LBA_LOW_EXP_MASK	(0xff << 0)
#define CRQB_ADDR_LBA_LOW_EXP_SHIFT	0
#define CRQB_ADDR_LBA_MID_EXP_MASK	(0xff << 8)
#define CRQB_ADDR_LBA_MID_EXP_SHIFT	8
#define CRQB_ADDR_LBA_HIGH_EXP_MASK	(0xff << 16)
#define CRQB_ADDR_LBA_HIGH_EXP_SHIFT	16
#define CRQB_ADDR_FEATURE_EXP_MASK	(0xff << 24)
#define CRQB_ADDR_FEATURE_EXP_SHIFT	24
#define CRQB_SECTCOUNT_COUNT_MASK	(0xff << 0)
#define CRQB_SECTCOUNT_COUNT_SHIFT	0
#define CRQB_SECTCOUNT_COUNT_EXP_MASK	(0xff << 8)
#define CRQB_SECTCOUNT_COUNT_EXP_SHIFT	8
#define MVSATA_WIN_CONTROL(w)	(SATAHC_BASE + 0x30 + ((w) << 4))
#define MVSATA_WIN_BASE(w)	(SATAHC_BASE + 0x34 + ((w) << 4))
#define EPRD_PHYADDR_MASK	0xfffffffe
#define EPRD_BYTECOUNT_MASK	0x0000ffff
#define EPRD_EOT		(0x01 << 31)
#define CRPB_ALIGN		0x100
#define READ_CMD		0
#define WRITE_CMD		1
#define MV_ATA_MAX_SECTORS	(65535 / ATA_SECT_SIZE)
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
