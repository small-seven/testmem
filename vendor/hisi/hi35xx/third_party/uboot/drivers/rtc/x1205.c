#include <common.h>
#include <command.h>
#include <rtc.h>
#include <i2c.h>
#define CCR_SEC			0
#define CCR_MIN			1
#define CCR_HOUR		2
#define CCR_MDAY		3
#define CCR_MONTH		4
#define CCR_YEAR		5
#define CCR_WDAY		6
#define CCR_Y2K			7
#define X1205_REG_SR		0x3F	/* status register */
#define X1205_REG_Y2K		0x37
#define X1205_REG_DW		0x36
#define X1205_REG_YR		0x35
#define X1205_REG_MO		0x34
#define X1205_REG_DT		0x33
#define X1205_REG_HR		0x32
#define X1205_REG_MN		0x31
#define X1205_REG_SC		0x30
#define X1205_REG_DTR		0x13
#define X1205_REG_ATR		0x12
#define X1205_REG_INT		0x11
#define X1205_REG_0		0x10
#define X1205_REG_Y2K1		0x0F
#define X1205_REG_DWA1		0x0E
#define X1205_REG_YRA1		0x0D
#define X1205_REG_MOA1		0x0C
#define X1205_REG_DTA1		0x0B
#define X1205_REG_HRA1		0x0A
#define X1205_REG_MNA1		0x09
#define X1205_REG_SCA1		0x08
#define X1205_REG_Y2K0		0x07
#define X1205_REG_DWA0		0x06
#define X1205_REG_YRA0		0x05
#define X1205_REG_MOA0		0x04
#define X1205_REG_DTA0		0x03
#define X1205_REG_HRA0		0x02
#define X1205_REG_MNA0		0x01
#define X1205_REG_SCA0		0x00
#define X1205_CCR_BASE		0x30	/* Base address of CCR */
#define X1205_ALM0_BASE		0x00	/* Base address of ALARM0 */
#define X1205_SR_RTCF		0x01	/* Clock failure */
#define X1205_SR_WEL		0x02	/* Write Enable Latch */
#define X1205_SR_RWEL		0x04	/* Register Write Enable */
#define X1205_DTR_DTR0		0x01
#define X1205_DTR_DTR1		0x02
#define X1205_DTR_DTR2		0x04
#define X1205_HR_MIL		0x80	/* Set in ccr.hour for 24 hr mode */
