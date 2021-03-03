#include <common.h>
#include <errno.h>
#include <i2c.h>
#include <status_led.h>
#ifndef CONFIG_PCA9551_I2C_ADDR
#error "CONFIG_PCA9551_I2C_ADDR not defined!"
#endif
#define PCA9551_REG_INPUT	0x00	/* Input register (read only) */
#define PCA9551_REG_PSC0	0x01	/* Frequency prescaler 0 */
#define PCA9551_REG_PWM0	0x02	/* PWM0 */
#define PCA9551_REG_PSC1	0x03	/* Frequency prescaler 1 */
#define PCA9551_REG_PWM1	0x04	/* PWM1 */
#define PCA9551_REG_LS0		0x05	/* LED0 to LED3 selector */
#define PCA9551_REG_LS1		0x06	/* LED4 to LED7 selector */
#define PCA9551_CTRL_AI		(1 << 4)	/* Auto-increment flag */
#define PCA9551_LED_STATE_ON		0x00
#define PCA9551_LED_STATE_OFF		0x01
#define PCA9551_LED_STATE_BLINK0	0x02
#define PCA9551_LED_STATE_BLINK1	0x03
