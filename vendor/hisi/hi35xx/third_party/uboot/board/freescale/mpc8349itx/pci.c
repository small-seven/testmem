#include <common.h>
#include <init.h>
#include <asm/mmu.h>
#include <asm/io.h>
#include <mpc83xx.h>
#include <pci.h>
#include <i2c.h>
#include <asm/fsl_i2c.h>
#ifdef CONFIG_MPC83XX_PCI2
#endif
#ifndef CONFIG_MPC83XX_PCI2
#else
#endif
#if defined(CONFIG_SYS_I2C)
#else
#endif
#ifndef CONFIG_MPC83XX_PCI2
#else
#endif
