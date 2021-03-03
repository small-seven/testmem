#include <init.h>
#include <asm/mmu.h>
#include <asm/io.h>
#include <common.h>
#include <mpc83xx.h>
#include <pci.h>
#include <i2c.h>
#include <asm/fsl_i2c.h>
#include "../common/pq-mds-pib.h"
#ifdef CONFIG_MPC83XX_PCI2
#endif
#ifdef CONFIG_PCISLAVE
#else
#ifndef CONFIG_MPC83XX_PCI2
#else
#endif
#if defined(CONFIG_PCI_66M)
#elif defined(CONFIG_PCI_33M)
#else
#endif
#ifndef CONFIG_MPC83XX_PCI2
#else
#endif
#endif				/* CONFIG_PCISLAVE */
