#include <common.h>
#include <dm.h>
#include <asm/io.h>
#include <dt-bindings/clock/mt8518-clk.h>
#include "clk-mtk.h"
#define MT8518_PLL_FMAX		(3000UL * MHZ)
#define MT8518_CON0_RST_BAR	BIT(27)
#define PLL(_id, _reg, _pwr_reg, _en_mask, _flags, _pcwbits, _pd_reg,	\
#define FACTOR0(_id, _parent, _mult, _div)	\
#define FACTOR1(_id, _parent, _mult, _div)	\
#define FACTOR2(_id, _parent, _mult, _div)	\
#define GATE_TOP0(_id, _parent, _shift) {			\
#define GATE_TOP1(_id, _parent, _shift) {			\
#define GATE_TOP2(_id, _parent, _shift) {			\
#define GATE_TOP2_I(_id, _parent, _shift) {				\
#define GATE_TOP3(_id, _parent, _shift) {			\
#define GATE_TOP4(_id, _parent, _shift) {				\
#define GATE_TOP5(_id, _parent, _shift) {				\
#define GATE_TOP5_I(_id, _parent, _shift) {				\
#define GATE_TOP6(_id, _parent, _shift) {				\
#define GATE_TOP7(_id, _parent, _shift) {				\
