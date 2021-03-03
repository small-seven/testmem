#include <common.h>
#include <clk-uclass.h>
#include <div64.h>
#include <dm.h>
#include <asm/io.h>
#include "clk-mtk.h"
#define REG_CON0			0
#define REG_CON1			4
#define CON0_BASE_EN			BIT(0)
#define CON0_PWR_ON			BIT(0)
#define CON0_ISO_EN			BIT(1)
#define CON1_PCW_CHG			BIT(31)
#define POSTDIV_MASK			0x7
#define INTEGER_BITS			7
#define CLK_SCP_CFG0			0x200
#define CLK_SCP_CFG1			0x204
#define SCP_ARMCK_OFF_EN		GENMASK(9, 0)
#define SCP_AXICK_DCM_DIS_EN		BIT(0)
#define SCP_AXICK_26M_SEL_EN		BIT(4)
