#include <common.h>
#include <eeprom.h>
#include <i2c.h>
#include <eeprom_layout.h>
#include <eeprom_field.h>
#include <asm/setup.h>
#include <linux/kernel.h>
#include "eeprom.h"
#ifndef CONFIG_SYS_I2C_EEPROM_ADDR
# define CONFIG_SYS_I2C_EEPROM_ADDR	0x50
# define CONFIG_SYS_I2C_EEPROM_ADDR_LEN	1
#endif
#ifndef CONFIG_SYS_I2C_EEPROM_BUS
#define CONFIG_SYS_I2C_EEPROM_BUS	0
#endif
#define EEPROM_LAYOUT_VER_OFFSET	44
#define BOARD_SERIAL_OFFSET		20
#define BOARD_SERIAL_OFFSET_LEGACY	8
#define BOARD_REV_OFFSET		0
#define BOARD_REV_OFFSET_LEGACY		6
#define BOARD_REV_SIZE			2
#define PRODUCT_NAME_OFFSET		128
#define PRODUCT_NAME_SIZE		16
#define MAC_ADDR_OFFSET			4
#define MAC_ADDR_OFFSET_LEGACY		0
#define LAYOUT_INVALID	0
#define LAYOUT_LEGACY	0xff
#ifdef CONFIG_CMD_EEPROM_LAYOUT
#define	LAYOUT_VERSION_LEGACY 1
#define	LAYOUT_VERSION_VER1 2
#define	LAYOUT_VERSION_VER2 3
#define	LAYOUT_VERSION_VER3 4
#define DEFINE_PRINT_UPDATE(x) eeprom_field_print_##x, eeprom_field_update_##x
#ifdef CONFIG_CM_T3X
#else
#define layout_legacy layout_unknown
#endif
#if defined(CONFIG_CM_T3X)
#else
#define layout_v1 layout_unknown
#endif
#endif
