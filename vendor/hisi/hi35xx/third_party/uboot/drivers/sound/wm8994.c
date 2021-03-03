#include <common.h>
#include <audio_codec.h>
#include <dm.h>
#include <div64.h>
#include <fdtdec.h>
#include <i2c.h>
#include <i2s.h>
#include <sound.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/cpu.h>
#include <asm/arch/sound.h>
#include "wm8994.h"
#include "wm8994_registers.h"
#define SEL_MCLK1	0x00
#define SEL_MCLK2	0x08
#define SEL_FLL1	0x10
#define SEL_FLL2	0x18
