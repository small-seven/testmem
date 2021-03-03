#include <common.h>
#include <adc.h>
#include <asm/io.h>
#include <linux/iopoll.h>
#include "stm32-adc-core.h"
#define STM32H7_ADC_ISR			0x00
#define STM32H7_ADC_CR			0x08
#define STM32H7_ADC_CFGR		0x0C
#define STM32H7_ADC_SMPR1		0x14
#define STM32H7_ADC_SMPR2		0x18
#define STM32H7_ADC_PCSEL		0x1C
#define STM32H7_ADC_SQR1		0x30
#define STM32H7_ADC_DR			0x40
#define STM32H7_ADC_DIFSEL		0xC0
#define STM32MP1_VREGREADY		BIT(12)
#define STM32H7_EOC			BIT(2)
#define STM32H7_ADRDY			BIT(0)
#define STM32H7_DEEPPWD			BIT(29)
#define STM32H7_ADVREGEN		BIT(28)
#define STM32H7_BOOST			BIT(8)
#define STM32H7_ADSTART			BIT(2)
#define STM32H7_ADDIS			BIT(1)
#define STM32H7_ADEN			BIT(0)
#define STM32H7_EXTEN			GENMASK(11, 10)
#define STM32H7_DMNGT			GENMASK(1, 0)
#define STM32H7_SQ1_SHIFT		6
#define STM32H7_BOOST_CLKRATE		20000000UL
#define STM32_ADC_CH_MAX		20	/* max number of channels */
#define STM32_ADC_TIMEOUT_US		100000
