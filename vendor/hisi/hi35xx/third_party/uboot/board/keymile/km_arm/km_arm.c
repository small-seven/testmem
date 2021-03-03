#include <common.h>
#include <env.h>
#include <i2c.h>
#include <init.h>
#include <nand.h>
#include <netdev.h>
#include <miiphy.h>
#include <spi.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <asm/arch/mpp.h>
#include "../common/common.h"
#define BOCO		0x10
#define REG_CTRL_H		0x02
#define MASK_WRL_UNITRUN	0x01
#define MASK_RBX_PGY_PRESENT	0x40
#define REG_IRQ_CIRQ2		0x2d
#define MASK_RBI_DEFECT_16	0x01
#define PHY_MARVELL_OUI					0x5043
#define PHY_MARVELL_88E1118_MODEL			0x0022
#define PHY_MARVELL_88E1118R_MODEL			0x0024
#define PHY_MARVELL_PAGE_REG				0x0016
#define PHY_MARVELL_DEFAULT_PAGE			0x0000
#define PHY_MARVELL_88E1118R_LED_CTRL_PAGE		0x0003
#define PHY_MARVELL_88E1118R_LED_CTRL_REG		0x0010
#define PHY_MARVELL_88E1118R_LED_CTRL_RESERVED		0x1000
#define PHY_MARVELL_88E1118R_LED_CTRL_LED0_1000MB	(0x7<<0)
#define PHY_MARVELL_88E1118R_LED_CTRL_LED1_ACT		(0x3<<4)
#define PHY_MARVELL_88E1118R_LED_CTRL_LED2_LINK		(0x0<<8)
#define KM_FLASH_ERASE_ENABLE	43
#if defined(KM_PCIE_RESET_MPP7)
#else
#endif
#if defined(CONFIG_SYS_I2C_SOFT)
#endif
#if defined(CONFIG_KM_MGCOGE3UN)
#endif
#if (defined(CONFIG_KM_PIGGY4_88E6061)|defined(CONFIG_KM_PIGGY4_88E6352))
#else
#endif
#if defined(CONFIG_KM_MGCOGE3UN)
#endif
#if defined(CONFIG_SYS_I2C_SOFT)
#endif
#if defined(CONFIG_SYS_I2C_SOFT)
#endif
#if defined(CONFIG_SYS_EEPROM_WREN)
#endif
#if defined(CONFIG_KM_FPGA_CONFIG)
#endif
#if (defined(CONFIG_KM_COGE5UN) | defined(CONFIG_KM_MGCOGE3UN))
#endif
#if defined(CONFIG_KM_FPGA_CONFIG)
#endif
#if (defined(CONFIG_KM_PIGGY4_88E6061))
#define	PHY_LED_SEL_REG		0x18
#define PHY_LED0_LINK		(0x5)
#define PHY_LED1_ACT		(0x8<<4)
#define PHY_LED2_INT		(0xe<<8)
#define	PHY_SPEC_CTRL_REG	0x1c
#define PHY_RGMII_CLK_STABLE	(0x1<<10)
#define PHY_CLSA		(0x1<<1)
#elif defined(CONFIG_KM_PIGGY4_88E6352)
#include <mv88e6352.h>
#if defined(CONFIG_KM_NUSA)
#else
#endif
#if defined(CONFIG_KM_MVEXTSW_ADDR)
#endif
#else
#endif
#if defined(CONFIG_HUSH_INIT_VAR)
#endif
#if defined(CONFIG_SYS_I2C_SOFT)
#endif
#if defined(CONFIG_POST)
#define KM_POST_EN_L	44
#define POST_WORD_OFF	8
#if defined(CONFIG_KM_COGE5UN)
#else
#endif
#endif
#if defined(CONFIG_SYS_EEPROM_WREN)
#endif
