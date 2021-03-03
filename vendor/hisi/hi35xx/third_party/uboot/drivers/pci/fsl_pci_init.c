#include <common.h>
#include <env.h>
#include <malloc.h>
#include <asm/fsl_serdes.h>
#include <pci.h>
#include <asm/io.h>
#include <asm/fsl_pci.h>
#ifndef CONFIG_SYS_PCI_MEMORY_BUS
#define CONFIG_SYS_PCI_MEMORY_BUS 0
#endif
#ifndef CONFIG_SYS_PCI_MEMORY_PHYS
#define CONFIG_SYS_PCI_MEMORY_PHYS 0
#endif
#if defined(CONFIG_SYS_PCI_64BIT) && !defined(CONFIG_SYS_PCI64_MEMORY_BUS)
#define CONFIG_SYS_PCI64_MEMORY_BUS (64ull*1024*1024*1024)
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A005434
#else
#endif
#ifdef CONFIG_SYS_PCI_64BIT
#else
#endif
#if defined(CONFIG_PHYS_64BIT) && defined(CONFIG_SYS_PCI_64BIT)
#else
#endif
#ifdef CONFIG_PHYS_64BIT
#endif
#ifdef CONFIG_SRIO_PCIE_BOOT_MASTER
#ifdef CONFIG_SYS_PCIE2_MEM_VIRT
#endif
#ifdef CONFIG_SYS_PCIE3_MEM_VIRT
#endif
#endif
#if defined(CONFIG_FSL_PCIE_DISABLE_ASPM)
#endif
#ifdef PEX_CCB_DIV
#endif
#ifdef CONFIG_SYS_PCI_64BIT
#else
#endif
#ifdef CONFIG_SRIO_PCIE_BOOT_MASTER
#else
#endif
#if defined(CONFIG_FSL_PCIE_DISABLE_ASPM)
#endif
#define PEX_CSR0_LTSSM_MASK	0xFC
#define PEX_CSR0_LTSSM_SHIFT	2
#ifdef CONFIG_FSL_PCIE_RESET
#endif
#ifdef CONFIG_FSL_PCIE_RESET
#endif
#ifdef CONFIG_SYS_P4080_ERRATUM_PCIE_A003
#endif
#ifdef CONFIG_SYS_FSL_ERRATUM_A007815
#endif
#ifndef CONFIG_PCI_NOSCAN
#else
#endif
#ifdef CONFIG_SRIO_PCIE_BOOT_MASTER
#endif
#if defined(CONFIG_PCIE1) || defined(CONFIG_PCIE2) || \
#if defined(CONFIG_FSL_CORENET)
#ifdef CONFIG_SYS_FSL_QORIQ_CHASSIS2
#else
#endif
#elif defined(CONFIG_MPC85xx)
#elif defined(CONFIG_MPC86xx)
#else
#error "No defines for DEVDISR_PCIE"
#endif
#ifdef CONFIG_SYS_PCIE1_NAME
#endif
#ifdef CONFIG_SYS_PCIE2_NAME
#endif
#ifdef CONFIG_SYS_PCIE3_NAME
#endif
#ifdef CONFIG_SYS_PCIE4_NAME
#endif
#ifdef CONFIG_SYS_FSL_QORIQ_CHASSIS2
#else
#endif
#ifdef CONFIG_PCIE1
#else
#endif
#ifdef CONFIG_PCIE2
#else
#endif
#ifdef CONFIG_PCIE3
#else
#endif
#ifdef CONFIG_PCIE4
#else
#endif
#else
#endif
#ifdef CONFIG_OF_BOARD_SETUP
#include <linux/libfdt.h>
#include <fdt_support.h>
#endif
