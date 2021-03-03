#include <common.h>
#include <asm/arch/clock-axg.h>
#include <asm/io.h>
#include <clk-uclass.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <div64.h>
#include <dt-bindings/clock/axg-clkc.h>
#include "clk_meson.h"
#define XTAL_RATE 24000000
