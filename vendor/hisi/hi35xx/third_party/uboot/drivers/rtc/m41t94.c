#include <common.h>
#include <rtc.h>
#include <spi.h>
#define M41T94_REG_SECONDS	0x01
#define M41T94_REG_MINUTES	0x02
#define M41T94_REG_HOURS	0x03
#define M41T94_REG_WDAY		0x04
#define M41T94_REG_DAY		0x05
#define M41T94_REG_MONTH	0x06
#define M41T94_REG_YEAR		0x07
#define M41T94_REG_HT		0x0c
#define M41T94_BIT_HALT		0x40
#define M41T94_BIT_STOP		0x80
#define M41T94_BIT_CB		0x40
#define M41T94_BIT_CEB		0x80
