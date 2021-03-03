#include <common.h>
#include <dm.h>
#include <i2c.h>
#include <phy.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#define I2C_IO_EXP_ADDR		0x22
#define I2C_IO_CFG_REG_0	0x6
#define I2C_IO_DATA_OUT_REG_0	0x2
#define I2C_IO_REG_0_SATA_OFF	2
#define I2C_IO_REG_0_USB_H_OFF	1
#define PINCTRL_NB_REG_VALUE	0x000173fa
#define PINCTRL_SB_REG_VALUE	0x00007a23
#define MVEBU_PORT_CTRL_SMI_ADDR(p)	(16 + (p))
#define MVEBU_SW_G2_SMI_ADDR		(28)
#define MVEBU_SW_SMI_DATA_REG		(1)
#define MVEBU_SW_SMI_CMD_REG		(0)
#define MVEBU_SW_LINK_CTRL_REG		(1)
#define MVEBU_SW_PORT_CTRL_REG		(4)
#define MVEBU_G2_SMI_PHY_CMD_REG	(24)
#define MVEBU_G2_SMI_PHY_DATA_REG	(25)
