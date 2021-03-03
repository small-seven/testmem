#include <common.h>
#include <command.h>
#include <dm.h>
#include <i2c.h>
#include <rtc.h>
#define PCF2127_REG_CTRL1	0x00
#define PCF2127_REG_CTRL2	0x01
#define PCF2127_REG_CTRL3	0x02
#define PCF2127_REG_SC		0x03
#define PCF2127_REG_MN		0x04
#define PCF2127_REG_HR		0x05
#define PCF2127_REG_DM		0x06
#define PCF2127_REG_DW		0x07
#define PCF2127_REG_MO		0x08
#define PCF2127_REG_YR		0x09
