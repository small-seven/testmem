#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <dt-bindings/clock/mt7628-clk.h>
#include <linux/bitops.h>
#include <linux/io.h>
#define XTAL_40M_SEL			BIT(6)
#define CLKCFG0_REG			0x0
#define PERI_CLK_FROM_XTAL_SEL		BIT(4)
#define CPU_PLL_FROM_BBP		BIT(1)
#define CPU_PLL_FROM_XTAL		BIT(0)
#define CLKCFG1_REG			0x4
#define CLK_SRC_CPU			-1
#define CLK_SRC_CPU_D2			-2
#define CLK_SRC_SYS			-3
#define CLK_SRC_XTAL			-4
#define CLK_SRC_PERI			-5
