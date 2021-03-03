#include <common.h>
#include <asm/arch/clock.h>
#include <asm/arch/funcmux.h>
#include <asm/arch/pinmux.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/board.h>
#include <asm/arch-tegra/tegra.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <i2c.h>
#include <nand.h>
#include "../common/tdx-common.h"
#define PMU_I2C_ADDRESS		0x34
#define MAX_I2C_RETRY		3
#define PMU_SUPPLYENE		0x14
#define PMU_SUPPLYENE_SYSINEN	(1<<5)
#define PMU_SUPPLYENE_EXITSLREQ	(1<<1)
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef CONFIG_MMC_SDHCI_TEGRA
#endif
#ifdef CONFIG_TEGRA_NAND
#endif
#ifdef CONFIG_USB_EHCI_TEGRA
#endif
#ifdef CONFIG_VIDEO_TEGRA20
#endif
