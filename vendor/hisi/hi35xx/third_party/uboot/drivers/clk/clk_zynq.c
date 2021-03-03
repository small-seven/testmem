#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dm/lists.h>
#include <errno.h>
#include <asm/io.h>
#include <asm/arch/clk.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sys_proto.h>
#define PLLCTRL_FBDIV_MASK	0x7f000
#define PLLCTRL_FBDIV_SHIFT	12
#define PLLCTRL_BPFORCE_MASK	(1 << 4)
#define PLLCTRL_PWRDWN_MASK	2
#define PLLCTRL_PWRDWN_SHIFT	1
#define PLLCTRL_RESET_MASK	1
#define PLLCTRL_RESET_SHIFT	0
#define ZYNQ_CLK_MAXDIV		0x3f
#define CLK_CTRL_DIV1_SHIFT	20
#define CLK_CTRL_DIV1_MASK	(ZYNQ_CLK_MAXDIV << CLK_CTRL_DIV1_SHIFT)
#define CLK_CTRL_DIV0_SHIFT	8
#define CLK_CTRL_DIV0_MASK	(ZYNQ_CLK_MAXDIV << CLK_CTRL_DIV0_SHIFT)
#define CLK_CTRL_SRCSEL_SHIFT	4
#define CLK_CTRL_SRCSEL_MASK	(0x3 << CLK_CTRL_SRCSEL_SHIFT)
#define CLK_CTRL_DIV2X_SHIFT	26
#define CLK_CTRL_DIV2X_MASK	(ZYNQ_CLK_MAXDIV << CLK_CTRL_DIV2X_SHIFT)
#define CLK_CTRL_DIV3X_SHIFT	20
#define CLK_CTRL_DIV3X_MASK	(ZYNQ_CLK_MAXDIV << CLK_CTRL_DIV3X_SHIFT)
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#else
#endif
#ifndef CONFIG_SPL_BUILD
#endif
#ifndef CONFIG_SPL_BUILD
#endif
