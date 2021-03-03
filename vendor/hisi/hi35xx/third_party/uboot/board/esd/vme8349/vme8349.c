#include <common.h>
#include <ioports.h>
#include <mpc83xx.h>
#include <asm/mpc8349_pci.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#endif
#include <asm/io.h>
#include <asm/mmu.h>
#include <spd.h>
#include <spd_sdram.h>
#include <i2c.h>
#include <netdev.h>
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#ifdef CONFIG_TARGET_CADDY2
#else
#endif
#ifdef CONFIG_TARGET_CADDY2
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
#ifdef CONFIG_TARGET_CADDY2
#define SMALL_RAM	0xff
#define LARGE_RAM	0x00
#else
#define SMALL_RAM	0x00
#define LARGE_RAM	0xff
#endif
#define SPD_VAL(a, b)	(((a) & SMALL_RAM) | ((b) & LARGE_RAM))
#ifdef CONFIG_TARGET_CADDY2
#else
#endif
