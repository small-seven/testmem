#include <common.h>
#include <dm.h>
#include <asm/arch/pinmux.h>
#include <asm/arch/gp_padctrl.h>
#include <asm/arch/gpio.h>
#include <asm/gpio.h>
#include "pinmux-config-cardhu.h"
#include <i2c.h>
#define PMU_I2C_ADDRESS		0x2D
#define MAX_I2C_RETRY		3
#if defined(CONFIG_MMC_SDHCI_TEGRA)
#endif	/* MMC */
#ifdef CONFIG_PCI_TEGRA
#endif /* PCI */
