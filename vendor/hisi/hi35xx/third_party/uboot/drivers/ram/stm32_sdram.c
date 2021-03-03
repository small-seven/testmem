#include <common.h>
#include <clk.h>
#include <dm.h>
#include <ram.h>
#include <asm/io.h>
#define MEM_MODE_MASK	GENMASK(2, 0)
#define SWP_FMC_OFFSET 10
#define SWP_FMC_MASK	GENMASK(SWP_FMC_OFFSET+1, SWP_FMC_OFFSET)
#define NOT_FOUND	0xff
#define FMC_BCR1_FMCEN		BIT(31)
#define FMC_SDCR_RPIPE_SHIFT	13	/* RPIPE bit shift */
#define FMC_SDCR_RBURST_SHIFT	12	/* RBURST bit shift */
#define FMC_SDCR_SDCLK_SHIFT	10	/* SDRAM clock divisor shift */
#define FMC_SDCR_WP_SHIFT	9	/* Write protection shift */
#define FMC_SDCR_CAS_SHIFT	7	/* CAS latency shift */
#define FMC_SDCR_NB_SHIFT	6	/* Number of banks shift */
#define FMC_SDCR_MWID_SHIFT	4	/* Memory width shift */
#define FMC_SDCR_NR_SHIFT	2	/* Number of row address bits shift */
#define FMC_SDCR_NC_SHIFT	0	/* Number of col address bits shift */
#define FMC_SDTR_TMRD_SHIFT	0	/* Load mode register to active */
#define FMC_SDTR_TXSR_SHIFT	4	/* Exit self-refresh time */
#define FMC_SDTR_TRAS_SHIFT	8	/* Self-refresh time */
#define FMC_SDTR_TRC_SHIFT	12	/* Row cycle delay */
#define FMC_SDTR_TWR_SHIFT	16	/* Recovery delay */
#define FMC_SDTR_TRP_SHIFT	20	/* Row precharge delay */
#define FMC_SDTR_TRCD_SHIFT	24	/* Row-to-column delay */
#define FMC_SDCMR_NRFS_SHIFT	5
#define FMC_SDCMR_MODE_NORMAL		0
#define FMC_SDCMR_MODE_START_CLOCK	1
#define FMC_SDCMR_MODE_PRECHARGE	2
#define FMC_SDCMR_MODE_AUTOREFRESH	3
#define FMC_SDCMR_MODE_WRITE_MODE	4
#define FMC_SDCMR_MODE_SELFREFRESH	5
#define FMC_SDCMR_MODE_POWERDOWN	6
#define FMC_SDCMR_BANK_1		BIT(4)
#define FMC_SDCMR_BANK_2		BIT(3)
#define FMC_SDCMR_MODE_REGISTER_SHIFT	9
#define FMC_SDSR_BUSY			BIT(5)
#define FMC_BUSY_WAIT(regs)	do { \
#define SDRAM_MODE_BL_SHIFT	0
#define SDRAM_MODE_CAS_SHIFT	4
#define SDRAM_MODE_BL		0
#ifdef CONFIG_CLK
#endif
