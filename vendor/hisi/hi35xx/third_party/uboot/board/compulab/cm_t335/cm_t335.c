#include <common.h>
#include <env.h>
#include <errno.h>
#include <miiphy.h>
#include <status_led.h>
#include <cpsw.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/hardware_am33xx.h>
#include <asm/io.h>
#include <asm/gpio.h>
#include "../common/eeprom.h"
#if defined(CONFIG_LED_STATUS) && defined(CONFIG_LED_STATUS_BOOT_ENABLE)
#endif
#if defined (CONFIG_DRIVER_TI_CPSW) && !defined(CONFIG_SPL_BUILD)
#define GPIO_PHY_RST		GPIO_PIN(3, 7)
#define AR8051_PHY_DEBUG_ADDR_REG	0x1d
#define AR8051_PHY_DEBUG_DATA_REG	0x1e
#define AR8051_DEBUG_RGMII_CLK_DLY_REG	0x5
#define AR8051_RGMII_TX_CLK_DLY		0x100
#endif /* CONFIG_DRIVER_TI_CPSW && !CONFIG_SPL_BUILD */
