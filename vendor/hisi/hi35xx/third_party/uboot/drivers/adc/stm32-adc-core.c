#include <common.h>
#include <asm/io.h>
#include <power/regulator.h>
#include "stm32-adc-core.h"
#define STM32H7_ADC_CCR			(STM32_ADCX_COMN_OFFSET + 0x08)
#define STM32H7_PRESC_SHIFT		18
#define STM32H7_PRESC_MASK		GENMASK(21, 18)
#define STM32H7_CKMODE_SHIFT		16
#define STM32H7_CKMODE_MASK		GENMASK(17, 16)
#define STM32H7_ADC_MAX_CLK_RATE	36000000
