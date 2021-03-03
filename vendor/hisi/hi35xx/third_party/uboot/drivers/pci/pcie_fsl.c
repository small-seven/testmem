#include <common.h>
#include <dm.h>
#include <malloc.h>
#include <mapmem.h>
#include <pci.h>
#include <asm/fsl_pci.h>
#include <asm/fsl_serdes.h>
#include <asm/io.h>
#include "pcie_fsl.h"
#ifdef CONFIG_SYS_PCI_64BIT
#else
#endif
#ifdef CONFIG_SYS_PCI_64BIT
#else
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A005434
#endif
#if defined(CONFIG_PHYS_64BIT) && defined(CONFIG_SYS_PCI_64BIT)
#endif
#ifdef CONFIG_FSL_PCIE_DISABLE_ASPM
#endif
#ifdef CONFIG_FSL_PCIE_RESET
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_PCIE_A003
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A007815
#endif
