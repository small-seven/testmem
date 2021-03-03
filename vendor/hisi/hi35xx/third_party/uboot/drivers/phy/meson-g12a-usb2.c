#include <common.h>
#include <asm/io.h>
#include <bitfield.h>
#include <dm.h>
#include <errno.h>
#include <generic-phy.h>
#include <regmap.h>
#include <power/regulator.h>
#include <reset.h>
#include <clk.h>
#include <linux/bitops.h>
#include <linux/compat.h>
#define PHY_CTRL_R0						0x0
#define PHY_CTRL_R1						0x4
#define PHY_CTRL_R2						0x8
#define PHY_CTRL_R3						0xc
#define PHY_CTRL_R4						0x10
#define PHY_CTRL_R5						0x14
#define PHY_CTRL_R6						0x18
#define PHY_CTRL_R7						0x1c
#define PHY_CTRL_R8						0x20
#define PHY_CTRL_R9						0x24
#define PHY_CTRL_R10						0x28
#define PHY_CTRL_R11						0x2c
#define PHY_CTRL_R12						0x30
#define PHY_CTRL_R13						0x34
#define PHY_CTRL_R14						0x38
#define PHY_CTRL_R15						0x3c
#define PHY_CTRL_R16						0x40
#define PHY_CTRL_R17						0x44
#define PHY_CTRL_R18						0x48
#define PHY_CTRL_R19						0x4c
#define PHY_CTRL_R20						0x50
#define PHY_CTRL_R21						0x54
#define PHY_CTRL_R22						0x58
#define PHY_CTRL_R23						0x5c
#define RESET_COMPLETE_TIME					1000
#define PLL_RESET_COMPLETE_TIME					100
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
#if CONFIG_IS_ENABLED(CLK)
#endif
#if CONFIG_IS_ENABLED(DM_REGULATOR)
#endif
