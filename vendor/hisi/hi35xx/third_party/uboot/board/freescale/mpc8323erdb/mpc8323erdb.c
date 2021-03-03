#include <common.h>
#include <eeprom.h>
#include <env.h>
#include <init.h>
#include <ioports.h>
#include <mpc83xx.h>
#include <i2c.h>
#include <miiphy.h>
#include <command.h>
#include <linux/libfdt.h>
#include <u-boot/crc.h>
#if defined(CONFIG_PCI)
#include <pci.h>
#endif
#include <asm/mmu.h>
#if defined(CONFIG_OF_BOARD_SETUP)
#ifdef CONFIG_PCI
#endif
#endif
#if defined(CONFIG_SYS_I2C_MAC_OFFSET)
#endif				/* CONFIG_I2C_MAC_OFFSET */
