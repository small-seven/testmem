#include <common.h>
#include <i2c.h>
#include <miiphy.h>
#if defined(CONFIG_CMD_NET) && defined(CONFIG_RESET_PHY_R)
#define MII_MARVELL_PHY_PAGE		22
#define MV88E1116_LED_FCTRL_REG		10
#define MV88E1116_CPRSP_CR3_REG		21
#define MV88E1116_MAC_CTRL_REG		21
#define MV88E1116_RGMII_TXTM_CTRL	(1 << 4)
#define MV88E1116_RGMII_RXTM_CTRL	(1 << 5)
#endif /* CONFIG_CMD_NET && CONFIG_RESET_PHY_R */
#if defined(CONFIG_CMD_I2C) && defined(CONFIG_SYS_I2C_EEPROM_ADDR)
#endif /* CONFIG_CMD_I2C && CONFIG_SYS_I2C_EEPROM_ADDR */
