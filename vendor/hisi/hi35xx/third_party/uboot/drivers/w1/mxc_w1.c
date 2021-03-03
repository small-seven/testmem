#include <asm/arch/clock.h>
#include <common.h>
#include <dm.h>
#include <linux/io.h>
#include <w1.h>
#define MXC_W1_CONTROL_RPP	BIT(7)
#define MXC_W1_CONTROL_PST	BIT(6)
#define MXC_W1_CONTROL_WR(x)	BIT(5 - (x))
#define MXC_W1_CONTROL_RDST	BIT(3)
#define MXC_W1_INTERRUPT_TBE	BIT(2)
#define MXC_W1_INTERRUPT_TSRE	BIT(3)
#define MXC_W1_INTERRUPT_RBF	BIT(4)
#define MXC_W1_INTERRUPT_RSRF	BIT(5)
