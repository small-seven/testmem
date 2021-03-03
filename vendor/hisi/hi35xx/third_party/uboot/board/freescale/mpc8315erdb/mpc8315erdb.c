#include <common.h>
#include <hwconfig.h>
#include <i2c.h>
#include <init.h>
#include <linux/libfdt.h>
#include <fdt_support.h>
#include <pci.h>
#include <mpc83xx.h>
#include <netdev.h>
#include <asm/io.h>
#include <ns16550.h>
#include <nand.h>
#ifndef CONFIG_NAND_SPL
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
#else /* CONFIG_NAND_SPL */
#endif /* CONFIG_NAND_SPL */
