#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <init.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#define I2C_IO_EXP_ADDR		0x21
#define I2C_IO_CFG_REG_0	0x6
#define I2C_IO_DATA_OUT_REG_0	0x2
#define I2C_IO_REG_0_USB_H0_OFF	0
#define I2C_IO_REG_0_USB_H1_OFF	1
#define I2C_IO_REG_VBUS		((1 << I2C_IO_REG_0_USB_H0_OFF) | \
#define I2C_IO_REG_0_USB_H0_CL	4
#define I2C_IO_REG_0_USB_H1_CL	5
#define I2C_IO_REG_CL		((1 << I2C_IO_REG_0_USB_H0_CL) | \
