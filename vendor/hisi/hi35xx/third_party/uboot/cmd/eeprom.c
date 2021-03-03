#include <common.h>
#include <config.h>
#include <command.h>
#include <eeprom.h>
#include <i2c.h>
#include <eeprom_layout.h>
#ifndef	CONFIG_SYS_I2C_SPEED
#define	CONFIG_SYS_I2C_SPEED	50000
#endif
#ifndef CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS
#define CONFIG_SYS_EEPROM_PAGE_WRITE_DELAY_MS	0
#endif
#ifndef CONFIG_SYS_EEPROM_PAGE_WRITE_BITS
#define CONFIG_SYS_EEPROM_PAGE_WRITE_BITS	8
#endif
#ifndef	I2C_RXTX_LEN
#define I2C_RXTX_LEN	128
#endif
#define	EEPROM_PAGE_SIZE	(1 << CONFIG_SYS_EEPROM_PAGE_WRITE_BITS)
#define	EEPROM_PAGE_OFFSET(x)	((x) & (EEPROM_PAGE_SIZE - 1))
#if !defined(CONFIG_SPI) || defined(CONFIG_ENV_EEPROM_IS_ON_I2C)
#if !defined(CONFIG_SYS_I2C_EEPROM_ADDR_LEN) || \
#error CONFIG_SYS_I2C_EEPROM_ADDR_LEN must be 1 or 2
#endif
#endif
#if defined(CONFIG_DM_I2C)
#endif
#if defined(CONFIG_DM_I2C)
#elif defined(CONFIG_SYS_I2C)
#endif
#if CONFIG_SYS_I2C_EEPROM_ADDR_LEN == 1
#else
#endif	/* CONFIG_SYS_I2C_EEPROM_ADDR_LEN */
#if !defined(CONFIG_SYS_I2C_FRAM)
#endif
#if defined(CONFIG_DM_I2C)
#else /* Non DM I2C support - will be removed */
#endif /* CONFIG_DM_I2C */
#if defined(CONFIG_SYS_I2C_EEPROM_BUS)
#endif
#ifdef CONFIG_SYS_DEF_EEPROM_ADDR
#endif
#ifdef CONFIG_CMD_EEPROM_LAYOUT
#endif
#ifdef CONFIG_CMD_EEPROM_LAYOUT
#endif
#ifdef CONFIG_CMD_EEPROM_LAYOUT
#endif
#ifdef CONFIG_CMD_EEPROM_LAYOUT
#endif
#define NEXT_PARAM(argc, index)	{ (argc)--; (index)++; }
#ifdef CONFIG_CMD_EEPROM_LAYOUT
#endif
#ifdef CONFIG_CMD_EEPROM_LAYOUT
#endif
#ifdef CONFIG_CMD_EEPROM_LAYOUT
#endif
