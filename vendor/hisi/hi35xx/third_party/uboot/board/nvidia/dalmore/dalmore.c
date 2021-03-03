#include <common.h>
#include <dm.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/gp_padctrl.h>
#include "pinmux-config-dalmore.h"
#include <i2c.h>
#define BAT_I2C_ADDRESS		0x48	/* TPS65090 charger */
#define PMU_I2C_ADDRESS		0x58	/* TPS65913 PMU */
#if defined(CONFIG_MMC_SDHCI_TEGRA)
#endif /* MMC */
