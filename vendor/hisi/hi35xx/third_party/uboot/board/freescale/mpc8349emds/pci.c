#include <init.h>
#include <asm/mmu.h>
#include <asm/io.h>
#include <common.h>
#include <mpc83xx.h>
#include <pci.h>
#include <i2c.h>
#include <asm/fsl_i2c.h>
#ifdef CONFIG_MPC83XX_PCI2
#endif
#ifndef CONFIG_PCISLAVE
#if defined(CONFIG_PCI_64BIT)
#elif defined(CONFIG_PCI_ALL_PCI1)
#elif defined(CONFIG_PCI_ONE_PCI1)
#else
#endif
#if defined(CONFIG_PCI_64BIT)
#elif defined(CONFIG_PCI_ALL_PCI1)
#elif defined(CONFIG_PCI_ONE_PCI1)
#else
#endif
#ifndef CONFIG_MPC83XX_PCI2
#else
#endif
#ifndef CONFIG_MPC83XX_PCI2
#else
#endif
#else
#endif /* CONFIG_PCISLAVE */
