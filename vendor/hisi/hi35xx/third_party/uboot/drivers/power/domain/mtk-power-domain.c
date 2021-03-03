#include <clk.h>
#include <common.h>
#include <dm.h>
#include <power-domain-uclass.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/processor.h>
#include <linux/iopoll.h>
#include <dt-bindings/power/mt7623-power.h>
#include <dt-bindings/power/mt7629-power.h>
#define SPM_EN			(0xb16 << 16 | 0x1)
#define SPM_VDE_PWR_CON		0x0210
#define SPM_MFG_PWR_CON		0x0214
#define SPM_ISP_PWR_CON		0x0238
#define SPM_DIS_PWR_CON		0x023c
#define SPM_CONN_PWR_CON	0x0280
#define SPM_BDP_PWR_CON		0x029c
#define SPM_ETH_PWR_CON		0x02a0
#define SPM_HIF_PWR_CON		0x02a4
#define SPM_IFR_MSC_PWR_CON	0x02a8
#define SPM_ETHSYS_PWR_CON	0x2e0
#define SPM_HIF0_PWR_CON	0x2e4
#define SPM_HIF1_PWR_CON	0x2e8
#define SPM_PWR_STATUS		0x60c
#define SPM_PWR_STATUS_2ND	0x610
#define PWR_RST_B_BIT		BIT(0)
#define PWR_ISO_BIT		BIT(1)
#define PWR_ON_BIT		BIT(2)
#define PWR_ON_2ND_BIT		BIT(3)
#define PWR_CLK_DIS_BIT		BIT(4)
#define PWR_STATUS_CONN		BIT(1)
#define PWR_STATUS_DISP		BIT(3)
#define PWR_STATUS_MFG		BIT(4)
#define PWR_STATUS_ISP		BIT(5)
#define PWR_STATUS_VDEC		BIT(7)
#define PWR_STATUS_BDP		BIT(14)
#define PWR_STATUS_ETH		BIT(15)
#define PWR_STATUS_HIF		BIT(16)
#define PWR_STATUS_IFR_MSC	BIT(17)
#define PWR_STATUS_ETHSYS	BIT(24)
#define PWR_STATUS_HIF0		BIT(25)
#define PWR_STATUS_HIF1		BIT(26)
#define INFRA_TOPDCM_CTRL	0x10
#define INFRA_TOPAXI_PROT_EN	0x220
#define INFRA_TOPAXI_PROT_STA1	0x228
#define DCM_TOP_EN		BIT(0)
static int scpsys_power_free(struct power_domain *power_domain)
{
	return 0;
}
