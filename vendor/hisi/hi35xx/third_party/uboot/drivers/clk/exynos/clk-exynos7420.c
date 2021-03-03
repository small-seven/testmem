#include <common.h>
#include <dm.h>
#include <errno.h>
#include <clk-uclass.h>
#include <asm/io.h>
#include <dt-bindings/clock/exynos7420-clk.h>
#include "clk-pll.h"
#define DIVIDER(reg, shift, mask)	\
