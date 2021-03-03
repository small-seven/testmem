#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dt-bindings/clock/boston-clock.h>
#include <regmap.h>
#include <syscon.h>
#define BOSTON_PLAT_MMCMDIV		0x30
# define BOSTON_PLAT_MMCMDIV_CLK0DIV	(0xff << 0)
# define BOSTON_PLAT_MMCMDIV_INPUT	(0xff << 8)
# define BOSTON_PLAT_MMCMDIV_MUL	(0xff << 16)
# define BOSTON_PLAT_MMCMDIV_CLK1DIV	(0xff << 24)
