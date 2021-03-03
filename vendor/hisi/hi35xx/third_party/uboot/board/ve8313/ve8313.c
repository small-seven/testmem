#include <common.h>
#include <init.h>
#include <linux/libfdt.h>
#include <pci.h>
#include <mpc83xx.h>
#include <ns16550.h>
#include <nand.h>
#include <asm/bitops.h>
#include <asm/io.h>
#ifndef CONFIG_SYS_RAMBOOT
#if ((CONFIG_SYS_SDRAM_BASE & 0x00FFFFFF) != 0)
#warning Chip select bounds is only configurable in 16MB increments
#endif
#endif
#define VE8313_WDT_EN	0x00020000
#define VE8313_WDT_TRIG	0x00040000
#if defined(CONFIG_HW_WATCHDOG)
#else
#endif
#if defined(CONFIG_HW_WATCHDOG)
#endif
#if defined(CONFIG_PCI)
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
