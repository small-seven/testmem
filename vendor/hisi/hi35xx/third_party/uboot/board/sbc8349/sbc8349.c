#include <common.h>
#include <ioports.h>
#include <mpc83xx.h>
#include <asm/mpc8349_pci.h>
#include <i2c.h>
#include <spd_sdram.h>
#include <miiphy.h>
#if defined(CONFIG_OF_LIBFDT)
#include <linux/libfdt.h>
#endif
#if defined(CONFIG_DDR_ECC) && defined(CONFIG_MPC83xx)
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#endif
#define ns2clk(ns) (ns / (1000000000 / CONFIG_8349_CLKIN) + 1)
#if defined(CONFIG_SPD_EEPROM)
#else
#endif
#if defined(CONFIG_DDR_ECC) && !defined(CONFIG_ECC_INIT_VIA_DDRCONTROLLER)
#endif
#if !defined(CONFIG_SPD_EEPROM)
#if (CONFIG_SYS_DDR_SIZE != 256)
#warning Currently any ddr size other than 256 is not supported
#endif
#if ((CONFIG_SYS_SDRAM_BASE & 0x00FFFFFF) != 0)
#warning Chip select bounds is only configurable in 16MB increments
#endif
#if defined(CONFIG_DDR_2T_TIMING)
#endif
#if defined (CONFIG_DDR_32BIT)
#endif
#endif/*!CONFIG_SYS_SPD_EEPROM*/
#if defined(CONFIG_SYS_BR2_PRELIM)  \
#else
#endif
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
