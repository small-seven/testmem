#include <common.h>
#include <clk.h>
#include <dm.h>
#include <i2c.h>
#include <asm/io.h>
#define RCAR_IIC_ICDR		0x00
#define RCAR_IIC_ICCR		0x04
#define RCAR_IIC_ICSR		0x08
#define RCAR_IIC_ICIC		0x0c
#define RCAR_IIC_ICCL		0x10
#define RCAR_IIC_ICCH		0x14
#define RCAR_IIC_ICCR_ICE	BIT(7)
#define RCAR_IIC_ICCR_RACK	BIT(6)
#define RCAR_IIC_ICCR_RTS	BIT(4)
#define RCAR_IIC_ICCR_BUSY	BIT(2)
#define RCAR_IIC_ICCR_SCP	BIT(0)
#define RCAR_IC_BUSY		BIT(4)
#define RCAR_IC_TACK		BIT(2)
#define RCAR_IC_DTE		BIT(0)
#define IRQ_WAIT 1000
