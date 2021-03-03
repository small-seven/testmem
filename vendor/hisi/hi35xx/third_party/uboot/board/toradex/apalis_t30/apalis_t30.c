#include <common.h>
#include <asm/arch/gp_padctrl.h>
#include <asm/arch/pinmux.h>
#include <asm/arch-tegra/ap.h>
#include <asm/arch-tegra/tegra.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <dm.h>
#include <i2c.h>
#include <pci_tegra.h>
#include "../common/tdx-common.h"
#include "pinmux-config-apalis_t30.h"
#define PMU_I2C_ADDRESS		0x2D
#define MAX_I2C_RETRY		3
#ifdef CONFIG_APALIS_T30_PCIE_EVALBOARD_INIT
#define PEX_PERST_N	TEGRA_GPIO(S, 7) /* Apalis GPIO7 */
#define RESET_MOCI_CTRL	TEGRA_GPIO(I, 4)
#endif /* CONFIG_APALIS_T30_PCIE_EVALBOARD_INIT */
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef CONFIG_PCI_TEGRA
#ifdef CONFIG_APALIS_T30_PCIE_EVALBOARD_INIT
#endif /* CONFIG_APALIS_T30_PCIE_EVALBOARD_INIT */
#ifdef CONFIG_APALIS_T30_PCIE_EVALBOARD_INIT
#endif /* CONFIG_APALIS_T30_PCIE_EVALBOARD_INIT */
#endif /* CONFIG_PCI_TEGRA */
