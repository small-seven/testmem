#include <common.h>
#include <command.h>
#include <env.h>
#include <i2c.h>
#include <linux/ctype.h>
#include <u-boot/crc.h>
#ifdef CONFIG_SYS_I2C_EEPROM_CCID
#include "../common/eeprom.h"
#define MAX_NUM_PORTS	8
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#ifndef MAX_NUM_PORTS
#define MAX_NUM_PORTS	16
#endif
#define NXID_VERSION	1
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_CCID
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#define is_valid ((e.id[0] == 'N') || (e.id[1] == 'X') || \
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_CCID
#define is_valid ((e.id[0] == 'C') || (e.id[1] == 'C') || \
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#else
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#else
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#ifndef CONFIG_DM_I2C
#endif
#endif
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#ifndef CONFIG_DM_I2C
#endif
#endif
#ifndef CONFIG_DM_I2C
#else
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#else
#endif
#endif
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#ifndef CONFIG_DM_I2C
#endif
#endif
#ifdef DEBUG
#endif
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#ifndef CONFIG_DM_I2C
#endif
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#else
#endif
#ifndef CONFIG_DM_I2C
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#endif
#endif
#ifndef CONFIG_DM_I2C
#else
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#else
#endif
#endif
#ifndef CONFIG_DM_I2C
#else
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#else
#endif
#endif
#ifndef CONFIG_DM_I2C
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#endif
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#else
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#else
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#else
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_NXID
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_CCID
#ifndef CONFIG_DM_I2C
#else
#ifdef CONFIG_SYS_EEPROM_BUS_NUM
#else
#endif
#endif
#endif
