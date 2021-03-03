#include <common.h>
#include <dm.h>
#include <asm/arch-tegra/ap.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/gpio.h>
#include <asm/arch/pinmux.h>
#include <env_internal.h>
#include <pci_tegra.h>
#include <power/as3722.h>
#include <power/pmic.h>
#include "../common/tdx-common.h"
#include "pinmux-config-apalis-tk1.h"
#define LAN_DEV_OFF_N	TEGRA_GPIO(O, 6)
#define LAN_RESET_N	TEGRA_GPIO(S, 2)
#define FAN_EN		TEGRA_GPIO(DD, 2)
#define LAN_WAKE_N	TEGRA_GPIO(O, 5)
#ifdef CONFIG_APALIS_TK1_PCIE_EVALBOARD_INIT
#define PEX_PERST_N	TEGRA_GPIO(DD, 1) /* Apalis GPIO7 */
#define RESET_MOCI_CTRL	TEGRA_GPIO(U, 4)
#endif /* CONFIG_APALIS_TK1_PCIE_EVALBOARD_INIT */
#define VCC_USBH	TEGRA_GPIO(T, 6)
#define VCC_USBH_V1_0	TEGRA_GPIO(N, 5)
#define VCC_USBO1	TEGRA_GPIO(T, 5)
#define VCC_USBO1_V1_0	TEGRA_GPIO(N, 4)
#ifndef CONFIG_ENV_IS_NOWHERE
#endif
#if defined(CONFIG_OF_LIBFDT) && defined(CONFIG_OF_BOARD_SETUP)
#endif
#ifdef CONFIG_PCI_TEGRA
#ifdef CONFIG_APALIS_TK1_PCIE_EVALBOARD_INIT
#endif /* CONFIG_APALIS_TK1_PCIE_EVALBOARD_INIT */
#ifdef CONFIG_APALIS_TK1_PCIE_EVALBOARD_INIT
#endif /* CONFIG_APALIS_TK1_PCIE_EVALBOARD_INIT */
#endif /* CONFIG_PCI_TEGRA */
