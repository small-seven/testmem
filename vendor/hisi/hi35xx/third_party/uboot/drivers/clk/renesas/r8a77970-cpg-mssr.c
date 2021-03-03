#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dt-bindings/clock/r8a77970-cpg-mssr.h>
#include "renesas-cpg-mssr.h"
#include "rcar-gen3-cpg.h"
#define CPG_PLL_CONFIG_INDEX(md)	((((md) & BIT(14)) >> 12) | \
