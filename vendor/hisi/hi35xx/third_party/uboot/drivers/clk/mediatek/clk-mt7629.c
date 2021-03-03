#include <common.h>
#include <dm.h>
#include <asm/arch-mediatek/reset.h>
#include <asm/io.h>
#include <dt-bindings/clock/mt7629-clk.h>
#include "clk-mtk.h"
#define MT7629_CLKSQ_STB_CON0		0x20
#define MT7629_PLL_ISO_CON0		0x2c
#define MT7629_PLL_FMAX			(2500UL * MHZ)
#define MT7629_CON0_RST_BAR		BIT(24)
#define MCU_AXI_DIV			0x640
#define AXI_DIV_MSK			GENMASK(4, 0)
#define AXI_DIV_SEL(x)			(x)
#define MCU_BUS_MUX			0x7c0
#define MCU_BUS_MSK			GENMASK(10, 9)
#define MCU_BUS_SEL(x)			((x) << 9)
#define PLL(_id, _reg, _pwr_reg, _en_mask, _flags, _pcwbits, _pd_reg,	\
#define FACTOR0(_id, _parent, _mult, _div)			\
#define FACTOR1(_id, _parent, _mult, _div)			\
#define FACTOR2(_id, _parent, _mult, _div)			\
#define GATE_INFRA(_id, _parent, _shift) {			\
#define GATE_PERI0(_id, _parent, _shift) {			\
#define GATE_PERI1(_id, _parent, _shift) {			\
#define GATE_ETH(_id, _parent, _shift, _flag) {			\
#define GATE_ETH0(_id, _parent, _shift)				\
#define GATE_ETH1(_id, _parent, _shift)				\
#define GATE_SGMII(_id, _parent, _shift) {			\
#if CONFIG_IS_ENABLED(RESET_MEDIATEK)
#endif
