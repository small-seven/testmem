#include <common.h>
#include <ioports.h>
#include <mpc83xx.h>
#include <asm/mpc8349_pci.h>
#include <i2c.h>
#include <spi.h>
#include <miiphy.h>
#ifdef CONFIG_SYS_FSL_DDR2
#include <fsl_ddr_sdram.h>
#else
#include <spd_sdram.h>
#endif
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#endif
#if defined(CONFIG_DDR_ECC) && defined(CONFIG_MPC83xx)
#endif
#ifdef CONFIG_SYS_USE_MPC834XSYS_USB_PHY
#endif
#define ns2clk(ns) (ns / (1000000000 / CONFIG_8349_CLKIN) + 1)
#if defined(CONFIG_SPD_EEPROM)
#ifndef CONFIG_SYS_FSL_DDR2
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#else
#endif
#else
#endif
#if !defined(CONFIG_SPD_EEPROM)
#if (CONFIG_SYS_DDR_SIZE != 256)
#warning Currenly any ddr size other than 256 is not supported
#endif
#ifdef CONFIG_DDR_II
#else
#if ((CONFIG_SYS_SDRAM_BASE & 0x00FFFFFF) != 0)
#warning Chip select bounds is only configurable in 16MB increments
#endif
#if defined(CONFIG_DDR_2T_TIMING)
#endif
#if defined (CONFIG_DDR_32BIT)
#endif
#endif
#endif/*!CONFIG_SYS_SPD_EEPROM*/
#if defined(CONFIG_SYS_BR2_PRELIM)  \
#else
#endif
#ifdef CONFIG_MPC8XXX_SPI
#define SPI_CS_MASK	0x80000000
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
