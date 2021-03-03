#include <common.h>
#include <asm/io.h>
#include <dm.h>
#include <mailbox-uclass.h>
#include <dt-bindings/mailbox/tegra186-hsp.h>
#define TEGRA_HSP_INT_DIMENSIONING		0x380
#define TEGRA_HSP_INT_DIMENSIONING_NSI_SHIFT	16
#define TEGRA_HSP_INT_DIMENSIONING_NSI_MASK	0xf
#define TEGRA_HSP_INT_DIMENSIONING_NDB_SHIFT	12
#define TEGRA_HSP_INT_DIMENSIONING_NDB_MASK	0xf
#define TEGRA_HSP_INT_DIMENSIONING_NAS_SHIFT	8
#define TEGRA_HSP_INT_DIMENSIONING_NAS_MASK	0xf
#define TEGRA_HSP_INT_DIMENSIONING_NSS_SHIFT	4
#define TEGRA_HSP_INT_DIMENSIONING_NSS_MASK	0xf
#define TEGRA_HSP_INT_DIMENSIONING_NSM_SHIFT	0
#define TEGRA_HSP_INT_DIMENSIONING_NSM_MASK	0xf
#define TEGRA_HSP_DB_REG_TRIGGER	0x0
#define TEGRA_HSP_DB_REG_ENABLE		0x4
#define TEGRA_HSP_DB_REG_RAW		0x8
#define TEGRA_HSP_DB_REG_PENDING	0xc
#define TEGRA_HSP_DB_ID_CCPLEX		1
#define TEGRA_HSP_DB_ID_BPMP		3
#define TEGRA_HSP_DB_ID_NUM		7
static int tegra_hsp_free(struct mbox_chan *chan)
{
	debug("%s(chan=%p)\n", __func__, chan);

	return 0;
}
