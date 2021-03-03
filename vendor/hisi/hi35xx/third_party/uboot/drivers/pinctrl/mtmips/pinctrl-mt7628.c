#include <common.h>
#include <dm.h>
#include <dm/pinctrl.h>
#include <linux/bitops.h>
#include <linux/io.h>
#include "pinctrl-mtmips-common.h"
#define AGPIO_OFS			0
#define GPIOMODE1_OFS			0x24
#define GPIOMODE2_OFS			0x28
#define EPHY4_1_PAD_SHIFT		17
#define EPHY4_1_PAD_MASK		0x0f
#define EPHY0_SHIFT			16
#define RF_OLT_MODE_SHIFT		12
#define N9_EINT_SRC_SHIFT		9
#define WLED_OD_SHIFT			8
#define REF_CLKO_PAD_SHIFT		4
#define I2S_CLK_PAD_SHIFT		3
#define I2S_WS_PAD_SHIFT		2
#define I2S_SDO_PAD_SHIFT		1
#define I2S_SDI_PAD_SHIFT		0
#define GM4_MASK			3
#define P4LED_K_SHIFT			26
#define P3LED_K_SHIFT			24
#define P2LED_K_SHIFT			22
#define P1LED_K_SHIFT			20
#define P0LED_K_SHIFT			18
#define WLED_K_SHIFT			16
#define P4LED_A_SHIFT			10
#define P3LED_A_SHIFT			8
#define P2LED_A_SHIFT			6
#define P1LED_A_SHIFT			4
#define P0LED_A_SHIFT			2
#define WLED_A_SHIFT			0
#define PWM1_SHIFT			30
#define PWM0_SHIFT			28
#define UART2_SHIFT			26
#define UART1_SHIFT			24
#define I2C_SHIFT			20
#define REFCLK_SHIFT			18
#define PERST_SHIFT			16
#define ESD_SHIFT			15
#define WDT_SHIFT			14
#define SPI_SHIFT			12
#define SDMODE_SHIFT			10
#define UART0_SHIFT			8
#define I2S_SHIFT			6
#define SPI_CS1_SHIFT			4
#define SPIS_SHIFT			2
#define GPIO0_SHIFT			0
#define PAD_PU_G0_REG			0x00
#define PAD_PU_G1_REG			0x04
#define PAD_PD_G0_REG			0x10
#define PAD_PD_G1_REG			0x14
#define PAD_SR_G0_REG			0x20
#define PAD_SR_G1_REG			0x24
#define PAD_SMT_G0_REG			0x30
#define PAD_SMT_G1_REG			0x34
#define PAD_E2_G0_REG			0x40
#define PAD_E2_G1_REG			0x44
#define PAD_E4_G0_REG			0x50
#define PAD_E4_G1_REG			0x54
#define PAD_E8_G0_REG			0x60
#define PAD_E8_G1_REG			0x64
#define PIN_CONFIG_DRIVE_STRENGTH_28	(PIN_CONFIG_END + 1)
#define PIN_CONFIG_DRIVE_STRENGTH_4G	(PIN_CONFIG_END + 2)
#if CONFIG_IS_ENABLED(PINMUX)
#endif /* CONFIG_IS_ENABLED(PINMUX) */
#if CONFIG_IS_ENABLED(PINCONF)
#endif
#if CONFIG_IS_ENABLED(PINMUX)
#endif /* CONFIG_IS_ENABLED(PINMUX) */
#if CONFIG_IS_ENABLED(PINMUX)
#endif /* CONFIG_IS_ENABLED(PINMUX) */
#if CONFIG_IS_ENABLED(PINCONF)
#endif /* CONFIG_IS_ENABLED(PINCONF) */
