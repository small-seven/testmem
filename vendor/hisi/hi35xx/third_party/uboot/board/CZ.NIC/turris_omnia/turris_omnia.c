#include <common.h>
#include <env.h>
#include <i2c.h>
#include <init.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <dm/uclass.h>
#include <fdt_support.h>
#include <time.h>
#include <u-boot/crc.h>
# include <atsha204a-i2c.h>
#include "../drivers/ddr/marvell/a38x/ddr3_init.h"
#include <../serdes/a38x/high_speed_env_spec.h>
#define OMNIA_I2C_BUS_NAME		"i2c@11000->i2cmux@70->i2c@0"
#define OMNIA_I2C_MCU_CHIP_ADDR		0x2a
#define OMNIA_I2C_MCU_CHIP_LEN		1
#define OMNIA_I2C_EEPROM_CHIP_ADDR	0x54
#define OMNIA_I2C_EEPROM_CHIP_LEN	2
#define OMNIA_I2C_EEPROM_MAGIC		0x0341a034
#define OMNIA_ATSHA204_OTP_VERSION	0
#define OMNIA_ATSHA204_OTP_SERIAL	1
#define OMNIA_ATSHA204_OTP_MAC0		3
#define OMNIA_ATSHA204_OTP_MAC1		4
#define OMNIA_GPP_OUT_ENA_LOW					\
#define OMNIA_GPP_OUT_ENA_MID					\
#define OMNIA_GPP_OUT_VAL_LOW	0x0
#define OMNIA_GPP_OUT_VAL_MID	0x0
#define OMNIA_GPP_POL_LOW	0x0
#define OMNIA_GPP_POL_MID	0x0
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#define OMNIA_FACTORY_RESET_BOOTCMD \
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
