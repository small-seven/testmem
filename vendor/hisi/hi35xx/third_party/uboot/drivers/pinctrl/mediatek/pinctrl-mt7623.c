#include <dm.h>
#include "pinctrl-mtk-common.h"
#define PIN_BOND_REG0		0xb10
#define PIN_BOND_REG1		0xf20
#define PIN_BOND_REG2		0xef0
#define BOND_PCIE_CLR		(0x77 << 3)
#define BOND_I2S_CLR		0x3
#define BOND_MSDC0E_CLR		0x1
#define PIN_FIELD15(_s_pin, _e_pin, _s_addr, _x_addrs, _s_bit, _x_bits)	\
#define PIN_FIELD16(_s_pin, _e_pin, _s_addr, _x_addrs, _s_bit, _x_bits)	\
#define PINS_FIELD16(_s_pin, _e_pin, _s_addr, _x_addrs, _s_bit, _x_bits)\
