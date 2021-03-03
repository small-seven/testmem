#include <common.h>
#include <dm.h>
#include <asm/arch-mediatek/reset.h>
#include <asm/io.h>
#include <dt-bindings/clock/mt7623-clk.h>
#include "clk-mtk.h"
#define MT7623_CLKSQ_STB_CON0		0x18
#define MT7623_PLL_ISO_CON0		0x24
#define MT7623_PLL_FMAX			(2000UL * MHZ)
#define MT7623_CON0_RST_BAR		BIT(27)
#define MCU_AXI_DIV			0x60
#define AXI_DIV_MSK			GENMASK(4, 0)
#define AXI_DIV_SEL(x)			(x)
#define PLL(_id, _reg, _pwr_reg, _en_mask, _flags, _pcwbits, _pd_reg,	\
#define FACTOR0(_id, _parent, _mult, _div)			\
#define FACTOR1(_id, _parent, _mult, _div)			\
#define FACTOR2(_id, _parent, _mult, _div)			\
#define GATE_INFRA(_id, _parent, _shift) {			\
#define GATE_PERI0(_id, _parent, _shift) {			\
#define GATE_PERI1(_id, _parent, _shift) {			\
#define GATE_ETH_HIF(_id, _parent, _shift, _flag) {		\
#define GATE_ETH_HIF0(_id, _parent, _shift)				\
#define GATE_ETH_HIF1(_id, _parent, _shift)				\
#if CONFIG_IS_ENABLED(RESET_MEDIATEK)
#endif
