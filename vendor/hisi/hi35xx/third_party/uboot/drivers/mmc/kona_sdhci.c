#include <common.h>
#include <malloc.h>
#include <sdhci.h>
#include <linux/errno.h>
#include <asm/kona-common/clk.h>
#define SDHCI_CORECTRL_OFFSET		0x00008000
#define SDHCI_CORECTRL_EN		0x01
#define SDHCI_CORECTRL_RESET		0x02
#define SDHCI_CORESTAT_OFFSET		0x00008004
#define SDHCI_CORESTAT_CD_SW		0x01
#define SDHCI_COREIMR_OFFSET		0x00008008
#define SDHCI_COREIMR_IP		0x01
