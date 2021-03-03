#include <common.h>
#include <console.h>
#include <i2c.h>
#include <init.h>
#include <pci.h>
#if !defined(CONFIG_SPL_BUILD)
#include <bootcount.h>
#endif
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <linux/mbus.h>
#ifdef CONFIG_NET
#include <netdev.h>
#endif
#include <u-boot/crc.h>
#include "theadorable.h"
#include "../drivers/ddr/marvell/axp/ddr3_hw_training.h"
#include "../arch/arm/mach-mvebu/serdes/axp/high_speed_env_spec.h"
#define MV_USB_PHY_BASE			(MVEBU_AXP_USB_BASE + 0x800)
#define PHY_CHANNEL_RX_CTRL0_REG(port, chan) \
#define THEADORABLE_GPP_OUT_ENA_LOW	0x00336780
#define THEADORABLE_GPP_OUT_ENA_MID	0x00003cf0
#define THEADORABLE_GPP_OUT_ENA_HIGH	(~(0x0))
#define THEADORABLE_GPP_OUT_VAL_LOW	0x2c0c983f
#define THEADORABLE_GPP_OUT_VAL_MID	0x0007000c
#define THEADORABLE_GPP_OUT_VAL_HIGH	0x00000000
#define GPIO_USB0_PWR_ON		18
#define GPIO_USB1_PWR_ON		19
#define PEX_SWITCH_NOT_FOUNT_LIMIT	3
#define STM_I2C_BUS	1
#define STM_I2C_ADDR	0x27
#define REBOOT_DELAY	1000		/* reboot-delay in ms */
#define ABORT_TIMEOUT	3000		/* 3 seconds reboot abort timeout */
#ifdef CONFIG_NET
#endif
#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_BOARD_LATE_INIT)
#endif
#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_PCI)
#endif
