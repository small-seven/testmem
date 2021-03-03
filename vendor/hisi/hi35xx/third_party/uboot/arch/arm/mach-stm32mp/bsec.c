#include <common.h>
#include <dm.h>
#include <misc.h>
#include <asm/io.h>
#include <asm/arch/stm32mp1_smc.h>
#include <linux/arm-smccc.h>
#include <linux/iopoll.h>
#define BSEC_OTP_MAX_VALUE		95
#ifndef CONFIG_STM32MP1_TRUSTED
#define BSEC_TIMEOUT_US			10000
#define BSEC_OTP_CONF_OFF		0x000
#define BSEC_OTP_CTRL_OFF		0x004
#define BSEC_OTP_WRDATA_OFF		0x008
#define BSEC_OTP_STATUS_OFF		0x00C
#define BSEC_OTP_LOCK_OFF		0x010
#define BSEC_DISTURBED_OFF		0x01C
#define BSEC_ERROR_OFF			0x034
#define BSEC_SPLOCK_OFF			0x064 /* Program safmem sticky lock */
#define BSEC_SWLOCK_OFF			0x07C /* write in OTP sticky lock */
#define BSEC_SRLOCK_OFF			0x094 /* shadowing sticky lock */
#define BSEC_OTP_DATA_OFF		0x200
#define BSEC_CONF_POWER_UP		0x001
#define BSEC_READ			0x000
#define BSEC_WRITE			0x100
#define OTP_LOCK_MASK			0x1F
#define OTP_LOCK_BANK_SHIFT		0x05
#define OTP_LOCK_BIT_MASK		0x01
#define BSEC_MODE_BUSY_MASK		0x08
#define BSEC_MODE_PROGFAIL_MASK		0x10
#define BSEC_MODE_PWR_MASK		0x20
#define BSEC_LOCK_PROGRAM		0x04
#endif /* CONFIG_STM32MP1_TRUSTED */
#ifdef CONFIG_STM32MP1_TRUSTED
#else
#endif
#ifdef CONFIG_STM32MP1_TRUSTED
#else
#endif
#ifdef CONFIG_STM32MP1_TRUSTED
#else
#endif
#ifdef CONFIG_STM32MP1_TRUSTED
#else
#endif
#ifndef CONFIG_STM32MP1_TRUSTED
#endif
#ifndef CONFIG_STM32MP1_TRUSTED
#endif
