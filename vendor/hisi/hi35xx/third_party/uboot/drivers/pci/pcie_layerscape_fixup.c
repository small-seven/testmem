#include <common.h>
#include <pci.h>
#include <asm/arch/fsl_serdes.h>
#include <asm/io.h>
#include <errno.h>
#ifdef CONFIG_OF_BOARD_SETUP
#include <linux/libfdt.h>
#include <fdt_support.h>
#ifdef CONFIG_ARM
#include <asm/arch/clock.h>
#endif
#include "pcie_layerscape.h"
#if defined(CONFIG_FSL_LSCH3) || defined(CONFIG_FSL_LSCH2)
#ifdef CONFIG_FSL_PCIE_COMPAT /* Compatible with older version of dts node */
#endif
#ifdef CONFIG_FSL_PCIE_COMPAT /* Compatible with older version of dts node */
#endif
#endif
#ifdef CONFIG_FSL_PCIE_COMPAT /* Compatible with older version of dts node */
#endif
#if defined(CONFIG_FSL_LSCH3) || defined(CONFIG_FSL_LSCH2)
#endif
#else /* !CONFIG_OF_BOARD_SETUP */
#endif
