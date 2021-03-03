#include <common.h>
#include <adc.h>
#include <clk.h>
#include <dm.h>
#include <regmap.h>
#include <errno.h>
#include <asm/io.h>
#include <linux/math64.h>
#include <linux/bitfield.h>
#define MESON_SAR_ADC_REG0					0x00
#define MESON_SAR_ADC_CHAN_LIST					0x04
#define MESON_SAR_ADC_AVG_CNTL					0x08
#define MESON_SAR_ADC_REG3					0x0c
#define MESON_SAR_ADC_DELAY					0x10
#define MESON_SAR_ADC_LAST_RD					0x14
#define MESON_SAR_ADC_FIFO_RD					0x18
#define MESON_SAR_ADC_AUX_SW					0x1c
#define MESON_SAR_ADC_CHAN_10_SW				0x20
#define MESON_SAR_ADC_DETECT_IDLE_SW				0x24
#define MESON_SAR_ADC_DELTA_10					0x28
#define MESON_SAR_ADC_REG11					0x2c
#define MESON_SAR_ADC_REG13					0x34
#define MESON_SAR_ADC_MAX_FIFO_SIZE				32
#define MESON_SAR_ADC_TIMEOUT					100 /* ms */
#define NUM_CHANNELS						8
#define MILLION							1000000
#if CONFIG_IS_ENABLED(CLK)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
