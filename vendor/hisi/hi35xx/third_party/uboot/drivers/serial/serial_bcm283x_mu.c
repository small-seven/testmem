#include <common.h>
#include <dm.h>
#include <errno.h>
#include <watchdog.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <serial.h>
#include <dm/platform_data/serial_bcm283x_mu.h>
#include <dm/pinctrl.h>
#include <linux/compiler.h>
#define BCM283X_MU_LCR_DATA_SIZE_8	3
#define BCM283X_MU_LSR_TX_IDLE		BIT(6)
#define BCM283X_MU_LSR_TX_EMPTY		BIT(5)
#define BCM283X_MU_LSR_RX_READY		BIT(0)
#if CONFIG_IS_ENABLED(OF_CONTROL)
#endif
#if !CONFIG_IS_ENABLED(OF_CONTROL) || CONFIG_IS_ENABLED(OF_BOARD)
#endif
