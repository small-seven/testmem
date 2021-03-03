#include <common.h>
#include <clk.h>
#include <dm.h>
#include <i2c.h>
#include <reset.h>
#include <dm/device.h>
#include <linux/io.h>
#define STM32_I2C_CR1				0x00
#define STM32_I2C_CR2				0x04
#define STM32_I2C_TIMINGR			0x10
#define STM32_I2C_ISR				0x18
#define STM32_I2C_ICR				0x1C
#define STM32_I2C_RXDR				0x24
#define STM32_I2C_TXDR				0x28
#define STM32_I2C_CR1_ANFOFF			BIT(12)
#define STM32_I2C_CR1_ERRIE			BIT(7)
#define STM32_I2C_CR1_TCIE			BIT(6)
#define STM32_I2C_CR1_STOPIE			BIT(5)
#define STM32_I2C_CR1_NACKIE			BIT(4)
#define STM32_I2C_CR1_ADDRIE			BIT(3)
#define STM32_I2C_CR1_RXIE			BIT(2)
#define STM32_I2C_CR1_TXIE			BIT(1)
#define STM32_I2C_CR1_PE			BIT(0)
#define STM32_I2C_CR2_AUTOEND			BIT(25)
#define STM32_I2C_CR2_RELOAD			BIT(24)
#define STM32_I2C_CR2_NBYTES_MASK		GENMASK(23, 16)
#define STM32_I2C_CR2_NBYTES(n)			((n & 0xff) << 16)
#define STM32_I2C_CR2_NACK			BIT(15)
#define STM32_I2C_CR2_STOP			BIT(14)
#define STM32_I2C_CR2_START			BIT(13)
#define STM32_I2C_CR2_HEAD10R			BIT(12)
#define STM32_I2C_CR2_ADD10			BIT(11)
#define STM32_I2C_CR2_RD_WRN			BIT(10)
#define STM32_I2C_CR2_SADD10_MASK		GENMASK(9, 0)
#define STM32_I2C_CR2_SADD10(n)			(n & STM32_I2C_CR2_SADD10_MASK)
#define STM32_I2C_CR2_SADD7_MASK		GENMASK(7, 1)
#define STM32_I2C_CR2_SADD7(n)			((n & 0x7f) << 1)
#define STM32_I2C_CR2_RESET_MASK		(STM32_I2C_CR2_HEAD10R \
#define STM32_I2C_ISR_BUSY			BIT(15)
#define STM32_I2C_ISR_ARLO			BIT(9)
#define STM32_I2C_ISR_BERR			BIT(8)
#define STM32_I2C_ISR_TCR			BIT(7)
#define STM32_I2C_ISR_TC			BIT(6)
#define STM32_I2C_ISR_STOPF			BIT(5)
#define STM32_I2C_ISR_NACKF			BIT(4)
#define STM32_I2C_ISR_ADDR			BIT(3)
#define STM32_I2C_ISR_RXNE			BIT(2)
#define STM32_I2C_ISR_TXIS			BIT(1)
#define STM32_I2C_ISR_TXE			BIT(0)
#define STM32_I2C_ISR_ERRORS			(STM32_I2C_ISR_BERR \
#define STM32_I2C_ICR_ARLOCF			BIT(9)
#define STM32_I2C_ICR_BERRCF			BIT(8)
#define STM32_I2C_ICR_STOPCF			BIT(5)
#define STM32_I2C_ICR_NACKCF			BIT(4)
#define STM32_I2C_TIMINGR_PRESC(n)		((n & 0xf) << 28)
#define STM32_I2C_TIMINGR_SCLDEL(n)		((n & 0xf) << 20)
#define STM32_I2C_TIMINGR_SDADEL(n)		((n & 0xf) << 16)
#define STM32_I2C_TIMINGR_SCLH(n)		((n & 0xff) << 8)
#define STM32_I2C_TIMINGR_SCLL(n)		(n & 0xff)
#define STM32_I2C_MAX_LEN			0xff
#define STM32_I2C_DNF_DEFAULT			0
#define STM32_I2C_DNF_MAX			16
#define STM32_I2C_ANALOG_FILTER_ENABLE	1
#define STM32_I2C_ANALOG_FILTER_DELAY_MIN	50	/* ns */
#define STM32_I2C_ANALOG_FILTER_DELAY_MAX	260	/* ns */
#define STM32_I2C_RISE_TIME_DEFAULT		25	/* ns */
#define STM32_I2C_FALL_TIME_DEFAULT		10	/* ns */
#define STM32_PRESC_MAX				BIT(4)
#define STM32_SCLDEL_MAX			BIT(4)
#define STM32_SDADEL_MAX			BIT(4)
#define STM32_SCLH_MAX				BIT(8)
#define STM32_SCLL_MAX				BIT(8)
#define STM32_NSEC_PER_SEC			1000000000L
#define STANDARD_RATE				100000
#define FAST_RATE				400000
#define FAST_PLUS_RATE				1000000
