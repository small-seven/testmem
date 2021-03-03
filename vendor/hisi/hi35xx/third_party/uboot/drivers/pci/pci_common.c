#include <common.h>
#include <dm.h>
#include <env.h>
#include <errno.h>
#include <pci.h>
#include <asm/io.h>
#if defined(CONFIG_PCI_CONFIG_HOST_BRIDGE) /* don't skip host bridge */
#ifndef CONFIG_PCIE_BVT
#endif
#else
#endif
#if !defined(CONFIG_DM_PCI) || defined(CONFIG_DM_PCI_COMPAT)
#endif /* !CONFIG_DM_PCI || CONFIG_DM_PCI_COMPAT */
