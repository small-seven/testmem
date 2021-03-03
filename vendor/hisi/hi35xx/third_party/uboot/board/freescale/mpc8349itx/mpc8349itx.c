#include <common.h>
#include <ioports.h>
#include <mpc83xx.h>
#include <i2c.h>
#include <miiphy.h>
#include <vsc7385.h>
#ifdef CONFIG_PCI
#include <asm/mpc8349_pci.h>
#include <pci.h>
#endif
#include <spd_sdram.h>
#include <asm/mmu.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#endif
#include "../../../arch/powerpc/cpu/mpc83xx/hrcw/hrcw.h"
#include "../../../arch/powerpc/cpu/mpc83xx/elbc/elbc.h"
#ifndef CONFIG_SPD_EEPROM
#if ((CONFIG_SYS_SDRAM_BASE & 0x00FFFFFF) != 0)
#warning Chip select bounds is only configurable in 16MB increments
#endif
#endif
#ifdef CONFIG_PCI
#ifndef CONFIG_PCI_PNP
#endif
#ifndef CONFIG_PCI_PNP
#endif
#ifndef CONFIG_PCI_PNP
#endif
#endif				/* CONFIG_PCI */
#ifdef CONFIG_DDR_ECC
#endif
#ifdef CONFIG_SPD_EEPROM
#else
#endif
#ifdef CONFIG_DDR_ECC
#endif
#ifdef CONFIG_TARGET_MPC8349ITX
#else
#endif
#ifdef CONFIG_VSC7385_ENET
#endif
#ifdef CONFIG_COMPACT_FLASH
#endif
#if defined(CONFIG_SYS_I2C)
#ifdef CONFIG_SYS_I2C_RTC_ADDR
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_ADDR
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_ADDR
#endif
#ifdef CONFIG_SYS_I2C_RTC_ADDR
#endif
#endif
#ifdef CONFIG_VSC7385_IMAGE
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
