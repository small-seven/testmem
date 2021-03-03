#include <common.h>
#if defined(CONFIG_AT91FAMILY)
#include <asm/io.h>
#include <asm/arch/hardware.h>
#include <asm/arch/at91_pio.h>
#ifdef CONFIG_ATMEL_LEGACY
#include <asm/arch/gpio.h>
#endif
#endif
#include <i2c.h>
#if defined(CONFIG_SOFT_I2C_GPIO_SCL)
# include <asm/gpio.h>
# ifndef I2C_GPIO_SYNC
#  define I2C_GPIO_SYNC
# endif
# ifndef I2C_INIT
#  define I2C_INIT \
# endif
# ifndef I2C_ACTIVE
#  define I2C_ACTIVE do { } while (0)
# endif
# ifndef I2C_TRISTATE
#  define I2C_TRISTATE do { } while (0)
# endif
# ifndef I2C_READ
#  define I2C_READ gpio_get_value(CONFIG_SOFT_I2C_GPIO_SDA)
# endif
# ifndef I2C_SDA
#  define I2C_SDA(bit) \
# endif
# ifndef I2C_SCL
#  define I2C_SCL(bit) \
# endif
# ifndef I2C_DELAY
#  define I2C_DELAY udelay(5)	/* 1/4 I2C clock duration */
# endif
#endif
#ifndef	I2C_SOFT_DECLARATIONS
#  define I2C_SOFT_DECLARATIONS
#endif
#if !defined(CONFIG_SYS_I2C_SOFT_SPEED)
#define CONFIG_SYS_I2C_SOFT_SPEED CONFIG_SYS_I2C_SPEED
#endif
#if !defined(CONFIG_SYS_I2C_SOFT_SLAVE)
#define CONFIG_SYS_I2C_SOFT_SLAVE CONFIG_SYS_I2C_SLAVE
#endif
#define RETRIES		0
#define I2C_ACK		0		/* PD_SDA level to ack a byte */
#define I2C_NOACK	1		/* PD_SDA level to noack a byte */
#ifdef DEBUG_I2C
#define PRINTD(fmt,args...)	do {	\
#else
#define PRINTD(fmt,args...)
#endif
#if !defined(CONFIG_SYS_I2C_INIT_BOARD)
#endif
#if !defined(CONFIG_SYS_I2C_INIT_BOARD)
#ifdef	I2C_INIT
#endif
#endif
#if defined(CONFIG_SYS_I2C_INIT_BOARD)
#else
#endif
#ifdef CONFIG_SYS_I2C_EEPROM_ADDR_OVERFLOW
#endif
#ifdef CONFIG_SOFT_I2C_READ_REPEATED_START
#else
#endif
#if defined(I2C_SOFT_DECLARATIONS2)
#endif
#if defined(I2C_SOFT_DECLARATIONS3)
#endif
#if defined(I2C_SOFT_DECLARATIONS4)
#endif
#if defined(I2C_SOFT_DECLARATIONS5)
#endif
#if defined(I2C_SOFT_DECLARATIONS6)
#endif
#if defined(I2C_SOFT_DECLARATIONS7)
#endif
#if defined(I2C_SOFT_DECLARATIONS8)
#endif
#if defined(I2C_SOFT_DECLARATIONS9)
#endif
#if defined(I2C_SOFT_DECLARATIONS10)
#endif
#if defined(I2C_SOFT_DECLARATIONS11)
#endif
#if defined(I2C_SOFT_DECLARATIONS12)
#endif
