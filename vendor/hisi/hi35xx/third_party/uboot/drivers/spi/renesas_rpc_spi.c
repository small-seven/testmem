#include <common.h>
#include <asm/io.h>
#include <clk.h>
#include <dm.h>
#include <dm/of_access.h>
#include <dt-structs.h>
#include <errno.h>
#include <linux/errno.h>
#include <spi.h>
#include <wait_bit.h>
#define RPC_CMNCR		0x0000	/* R/W */
#define RPC_CMNCR_MD		BIT(31)
#define RPC_CMNCR_SFDE		BIT(24)
#define RPC_CMNCR_MOIIO3(val)	(((val) & 0x3) << 22)
#define RPC_CMNCR_MOIIO2(val)	(((val) & 0x3) << 20)
#define RPC_CMNCR_MOIIO1(val)	(((val) & 0x3) << 18)
#define RPC_CMNCR_MOIIO0(val)	(((val) & 0x3) << 16)
#define RPC_CMNCR_MOIIO_HIZ	(RPC_CMNCR_MOIIO0(3) | RPC_CMNCR_MOIIO1(3) | \
#define RPC_CMNCR_IO3FV(val)	(((val) & 0x3) << 14)
#define RPC_CMNCR_IO2FV(val)	(((val) & 0x3) << 12)
#define RPC_CMNCR_IO0FV(val)	(((val) & 0x3) << 8)
#define RPC_CMNCR_IOFV_HIZ	(RPC_CMNCR_IO0FV(3) | RPC_CMNCR_IO2FV(3) | \
#define RPC_CMNCR_CPHAT		BIT(6)
#define RPC_CMNCR_CPHAR		BIT(5)
#define RPC_CMNCR_SSLP		BIT(4)
#define RPC_CMNCR_CPOL		BIT(3)
#define RPC_CMNCR_BSZ(val)	(((val) & 0x3) << 0)
#define RPC_SSLDR		0x0004	/* R/W */
#define RPC_SSLDR_SPNDL(d)	(((d) & 0x7) << 16)
#define RPC_SSLDR_SLNDL(d)	(((d) & 0x7) << 8)
#define RPC_SSLDR_SCKDL(d)	(((d) & 0x7) << 0)
#define RPC_DRCR		0x000C	/* R/W */
#define RPC_DRCR_SSLN		BIT(24)
#define RPC_DRCR_RBURST(v)	(((v) & 0x1F) << 16)
#define RPC_DRCR_RCF		BIT(9)
#define RPC_DRCR_RBE		BIT(8)
#define RPC_DRCR_SSLE		BIT(0)
#define RPC_DRCMR		0x0010	/* R/W */
#define RPC_DRCMR_CMD(c)	(((c) & 0xFF) << 16)
#define RPC_DRCMR_OCMD(c)	(((c) & 0xFF) << 0)
#define RPC_DREAR		0x0014	/* R/W */
#define RPC_DREAR_EAV(v)	(((v) & 0xFF) << 16)
#define RPC_DREAR_EAC(v)	(((v) & 0x7) << 0)
#define RPC_DROPR		0x0018	/* R/W */
#define RPC_DROPR_OPD3(o)	(((o) & 0xFF) << 24)
#define RPC_DROPR_OPD2(o)	(((o) & 0xFF) << 16)
#define RPC_DROPR_OPD1(o)	(((o) & 0xFF) << 8)
#define RPC_DROPR_OPD0(o)	(((o) & 0xFF) << 0)
#define RPC_DRENR		0x001C	/* R/W */
#define RPC_DRENR_CDB(o)	(u32)((((o) & 0x3) << 30))
#define RPC_DRENR_OCDB(o)	(((o) & 0x3) << 28)
#define RPC_DRENR_ADB(o)	(((o) & 0x3) << 24)
#define RPC_DRENR_OPDB(o)	(((o) & 0x3) << 20)
#define RPC_DRENR_SPIDB(o)	(((o) & 0x3) << 16)
#define RPC_DRENR_DME		BIT(15)
#define RPC_DRENR_CDE		BIT(14)
#define RPC_DRENR_OCDE		BIT(12)
#define RPC_DRENR_ADE(v)	(((v) & 0xF) << 8)
#define RPC_DRENR_OPDE(v)	(((v) & 0xF) << 4)
#define RPC_SMCR		0x0020	/* R/W */
#define RPC_SMCR_SSLKP		BIT(8)
#define RPC_SMCR_SPIRE		BIT(2)
#define RPC_SMCR_SPIWE		BIT(1)
#define RPC_SMCR_SPIE		BIT(0)
#define RPC_SMCMR		0x0024	/* R/W */
#define RPC_SMCMR_CMD(c)	(((c) & 0xFF) << 16)
#define RPC_SMCMR_OCMD(c)	(((c) & 0xFF) << 0)
#define RPC_SMADR		0x0028	/* R/W */
#define RPC_SMOPR		0x002C	/* R/W */
#define RPC_SMOPR_OPD0(o)	(((o) & 0xFF) << 0)
#define RPC_SMOPR_OPD1(o)	(((o) & 0xFF) << 8)
#define RPC_SMOPR_OPD2(o)	(((o) & 0xFF) << 16)
#define RPC_SMOPR_OPD3(o)	(((o) & 0xFF) << 24)
#define RPC_SMENR		0x0030	/* R/W */
#define RPC_SMENR_CDB(o)	(((o) & 0x3) << 30)
#define RPC_SMENR_OCDB(o)	(((o) & 0x3) << 28)
#define RPC_SMENR_ADB(o)	(((o) & 0x3) << 24)
#define RPC_SMENR_OPDB(o)	(((o) & 0x3) << 20)
#define RPC_SMENR_SPIDB(o)	(((o) & 0x3) << 16)
#define RPC_SMENR_DME		BIT(15)
#define RPC_SMENR_CDE		BIT(14)
#define RPC_SMENR_OCDE		BIT(12)
#define RPC_SMENR_ADE(v)	(((v) & 0xF) << 8)
#define RPC_SMENR_OPDE(v)	(((v) & 0xF) << 4)
#define RPC_SMENR_SPIDE(v)	(((v) & 0xF) << 0)
#define RPC_SMRDR0		0x0038	/* R */
#define RPC_SMRDR1		0x003C	/* R */
#define RPC_SMWDR0		0x0040	/* R/W */
#define RPC_SMWDR1		0x0044	/* R/W */
#define RPC_CMNSR		0x0048	/* R */
#define RPC_CMNSR_SSLF		BIT(1)
#define	RPC_CMNSR_TEND		BIT(0)
#define RPC_DRDMCR		0x0058	/* R/W */
#define RPC_DRDMCR_DMCYC(v)	(((v) & 0xF) << 0)
#define RPC_DRDRENR		0x005C	/* R/W */
#define RPC_DRDRENR_HYPE	(0x5 << 12)
#define RPC_DRDRENR_ADDRE	BIT(8)
#define RPC_DRDRENR_OPDRE	BIT(4)
#define RPC_DRDRENR_DRDRE	BIT(0)
#define RPC_SMDMCR		0x0060	/* R/W */
#define RPC_SMDMCR_DMCYC(v)	(((v) & 0xF) << 0)
#define RPC_SMDRENR		0x0064	/* R/W */
#define RPC_SMDRENR_HYPE	(0x5 << 12)
#define RPC_SMDRENR_ADDRE	BIT(8)
#define RPC_SMDRENR_OPDRE	BIT(4)
#define RPC_SMDRENR_SPIDRE	BIT(0)
#define RPC_PHYCNT		0x007C	/* R/W */
#define RPC_PHYCNT_CAL		BIT(31)
#define PRC_PHYCNT_OCTA_AA	BIT(22)
#define PRC_PHYCNT_OCTA_SA	BIT(23)
#define PRC_PHYCNT_EXDS		BIT(21)
#define RPC_PHYCNT_OCT		BIT(20)
#define RPC_PHYCNT_STRTIM(v)	(((v) & 0x7) << 15)
#define RPC_PHYCNT_WBUF2	BIT(4)
#define RPC_PHYCNT_WBUF		BIT(2)
#define RPC_PHYCNT_MEM(v)	(((v) & 0x3) << 0)
#define RPC_PHYINT		0x0088	/* R/W */
#define RPC_PHYINT_RSTEN	BIT(18)
#define RPC_PHYINT_WPEN		BIT(17)
#define RPC_PHYINT_INTEN	BIT(16)
#define RPC_PHYINT_RST		BIT(2)
#define RPC_PHYINT_WP		BIT(1)
#define RPC_PHYINT_INT		BIT(0)
#define RPC_WBUF		0x8000	/* R/W size=4/8/16/32/64Bytes */
#define RPC_WBUF_SIZE		0x100
#if CONFIG_IS_ENABLED(CLK)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
