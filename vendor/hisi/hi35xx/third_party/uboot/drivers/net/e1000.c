#include <common.h>
#include <cpu_func.h>
#include <dm.h>
#include <errno.h>
#include <memalign.h>
#include <pci.h>
#include "e1000.h"
#define TOUT_LOOP   100000
#ifdef CONFIG_DM_ETH
#define virt_to_bus(devno, v)	dm_pci_virt_to_mem(devno, (void *) (v))
#define bus_to_phys(devno, a)	dm_pci_mem_to_phys(devno, a)
#else
#define virt_to_bus(devno, v)	pci_virt_to_mem(devno, (void *) (v))
#define bus_to_phys(devno, a)	pci_mem_to_phys(devno, a)
#endif
#define E1000_DEFAULT_PCI_PBA	0x00000030
#define E1000_DEFAULT_PCIE_PBA	0x000a0026
#define E1000_BUFFER_ALIGN	128
#ifdef CONFIG_DM_ETH
#endif
#ifndef CONFIG_E1000_NO_NVM
#ifndef CONFIG_DM_ETH
#endif
#endif /* CONFIG_E1000_NO_NVM */
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#define MAX_INTS_PER_SEC	8000
#define DEFAULT_ITR		1000000000/(MAX_INTS_PER_SEC * 256)
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifndef CONFIG_E1000_NO_NVM
#endif
#ifndef CONFIG_E1000_NO_NVM
#else
#endif
#ifndef CONFIG_DM_ETH
#ifndef CONFIG_E1000_NO_NVM
#else
#endif
#endif /* !CONFIG_DM_ETH */
#ifdef CONFIG_CMD_E1000
#ifdef CONFIG_DM_ETH
#endif
#if !defined(CONFIG_DM_ETH) || defined(CONFIG_E1000_SPI)
#endif
#ifdef CONFIG_DM_ETH
#else
#endif
#ifdef CONFIG_E1000_SPI
#ifdef CONFIG_DM_ETH
#endif
#endif
#ifdef CONFIG_E1000_SPI
#endif
#endif /* not CONFIG_CMD_E1000 */
#ifdef CONFIG_DM_ETH
#endif
