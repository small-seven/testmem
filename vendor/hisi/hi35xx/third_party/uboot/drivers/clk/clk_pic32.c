#include <common.h>
#include <clk-uclass.h>
#include <dm.h>
#include <div64.h>
#include <wait_bit.h>
#include <dm/lists.h>
#include <asm/io.h>
#include <mach/pic32.h>
#include <dt-bindings/clock/microchip,clock.h>
#define SYS_POSC_CLK_HZ	24000000
#define SYS_FRC_CLK_HZ	8000000
#define OSCCON		0x0000
#define OSCTUNE		0x0010
#define SPLLCON		0x0020
#define REFO1CON	0x0080
#define REFO1TRIM	0x0090
#define PB1DIV		0x0140
#define ICLK_MASK	0x00000080
#define PLLIDIV_MASK	0x00000007
#define PLLODIV_MASK	0x00000007
#define CUROSC_MASK	0x00000007
#define PLLMUL_MASK	0x0000007F
#define FRCDIV_MASK	0x00000007
#define PBDIV_MASK	0x00000007
#define SCLK_SRC_FRC1	0
#define SCLK_SRC_SPLL	1
#define SCLK_SRC_POSC	2
#define SCLK_SRC_FRC2	7
#define REFO_SEL_MASK	0x0f
#define REFO_SEL_SHIFT	0
#define REFO_ACTIVE	BIT(8)
#define REFO_DIVSW_EN	BIT(9)
#define REFO_OE		BIT(12)
#define REFO_ON		BIT(15)
#define REFO_DIV_SHIFT	16
#define REFO_DIV_MASK	0x7fff
#define REFO_TRIM_REG	0x10
#define REFO_TRIM_MASK	0x1ff
#define REFO_TRIM_SHIFT	23
#define REFO_TRIM_MAX	511
#define ROCLK_SRC_SCLK		0x0
#define ROCLK_SRC_SPLL		0x7
#define ROCLK_SRC_ROCLKI	0x8
#define MPLL_IDIV		0x3f
#define MPLL_MULT		0xff
#define MPLL_ODIV1		0x7
#define MPLL_ODIV2		0x7
#define MPLL_VREG_RDY		BIT(23)
#define MPLL_RDY		BIT(31)
#define MPLL_IDIV_SHIFT		0
#define MPLL_MULT_SHIFT		8
#define MPLL_ODIV1_SHIFT	24
#define MPLL_ODIV2_SHIFT	27
#define MPLL_IDIV_INIT		0x03
#define MPLL_MULT_INIT		0x32
#define MPLL_ODIV1_INIT		0x02
#define MPLL_ODIV2_INIT		0x01
