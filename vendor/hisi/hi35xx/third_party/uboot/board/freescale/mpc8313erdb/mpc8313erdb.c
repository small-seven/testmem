#include <common.h>
#include <init.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#endif
#include <pci.h>
#include <mpc83xx.h>
#include <vsc7385.h>
#include <ns16550.h>
#include <nand.h>
#if defined(CONFIG_MPC83XX_GPIO) && !defined(CONFIG_SPL_BUILD)
#include <asm/gpio.h>
#endif
#ifndef CONFIG_SYS_8313ERDB_BROKEN_PMC
#endif
#if defined(CONFIG_MPC83XX_GPIO) && !defined(CONFIG_SPL_BUILD)
#endif
#if defined(CONFIG_MPC83XX_GPIO) && !defined(CONFIG_SPL_BUILD)
#endif
#ifndef CONFIG_SPL_BUILD
#ifdef CONFIG_VSC7385_IMAGE
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
#else /* CONFIG_SPL_BUILD */
#endif
