#include <common.h>
#include <command.h>
#include <env.h>
#include <i2c.h>
#include <linux/ctype.h>
#include <u-boot/crc.h>
#include "eeprom.h"
#ifdef CONFIG_SYS_I2C_EEPROM_NXID_MAC
#define MAX_NUM_PORTS	CONFIG_SYS_I2C_EEPROM_NXID_MAC
#else
#define MAX_NUM_PORTS	8
#endif
#define NXID_VERSION	0
#define is_valid ((e.id[0] == 'N') || (e.id[1] == 'X') || \
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_SYS_I2C_MAC1_CHIP_ADDR
#endif
#ifdef CONFIG_SYS_I2C_MAC2_CHIP_ADDR
#endif
