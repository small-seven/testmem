#include <common.h>
#include <command.h>
#include <dm.h>
#include <eeprom.h>
#include <i2c.h>
#include <rtc.h>
#define RTC_RV3029_PAGE_LEN             7
#define RV3029_ONOFF_CTRL		0x00
#define RV3029_ONOFF_CTRL_WE		BIT(0)
#define RV3029_ONOFF_CTRL_TE		BIT(1)
#define RV3029_ONOFF_CTRL_TAR		BIT(2)
#define RV3029_ONOFF_CTRL_EERE		BIT(3)
#define RV3029_ONOFF_CTRL_SRON		BIT(4)
#define RV3029_ONOFF_CTRL_TD0		BIT(5)
#define RV3029_ONOFF_CTRL_TD1		BIT(6)
#define RV3029_ONOFF_CTRL_CLKINT	BIT(7)
#define RV3029_IRQ_CTRL			0x01
#define RV3029_IRQ_CTRL_AIE		BIT(0)
#define RV3029_IRQ_CTRL_TIE		BIT(1)
#define RV3029_IRQ_CTRL_V1IE		BIT(2)
#define RV3029_IRQ_CTRL_V2IE		BIT(3)
#define RV3029_IRQ_CTRL_SRIE		BIT(4)
#define RV3029_IRQ_FLAGS		0x02
#define RV3029_IRQ_FLAGS_AF		BIT(0)
#define RV3029_IRQ_FLAGS_TF		BIT(1)
#define RV3029_IRQ_FLAGS_V1IF		BIT(2)
#define RV3029_IRQ_FLAGS_V2IF		BIT(3)
#define RV3029_IRQ_FLAGS_SRF		BIT(4)
#define RV3029_STATUS			0x03
#define RV3029_STATUS_VLOW1		BIT(2)
#define RV3029_STATUS_VLOW2		BIT(3)
#define RV3029_STATUS_SR		BIT(4)
#define RV3029_STATUS_PON		BIT(5)
#define RV3029_STATUS_EEBUSY		BIT(7)
#define RV3029_RST_CTRL			0x04
#define RV3029_RST_CTRL_SYSR		BIT(4)
#define RV3029_CONTROL_SECTION_LEN	0x05
#define RV3029_W_SEC			0x08
#define RV3029_W_MINUTES		0x09
#define RV3029_W_HOURS			0x0A
#define RV3029_REG_HR_12_24		BIT(6) /* 24h/12h mode */
#define RV3029_REG_HR_PM		BIT(5) /* PM/AM bit in 12h mode */
#define RV3029_W_DATE			0x0B
#define RV3029_W_DAYS			0x0C
#define RV3029_W_MONTHS			0x0D
#define RV3029_W_YEARS			0x0E
#define RV3029_CONTROL_E2P_EECTRL	0x30
#define RV3029_TRICKLE_1K		BIT(4) /* 1.5K resistance */
#define RV3029_TRICKLE_5K		BIT(5) /* 5K   resistance */
#define RV3029_TRICKLE_20K		BIT(6) /* 20K  resistance */
#define RV3029_TRICKLE_80K		BIT(7) /* 80K  resistance */
#define RV3029_TRICKLE_MASK		(RV3029_TRICKLE_1K |\
#define RV3029_TRICKLE_SHIFT		4
#if defined(OF_CONTROL)
#else
#endif
