#include <common.h>
#include <dm.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <errno.h>
#include <clk.h>
#define MSCC_SGPIOS_PER_BANK	32
#define MSCC_SGPIO_BANK_DEPTH	4
#define __M(bf)		GENMASK((bf).end, (bf).beg)
#define __F(bf, x)	(__M(bf) & ((x) << (bf).beg))
#define __X(bf, x)	(((x) >> (bf).beg) & GENMASK(((bf).end - (bf).beg), 0))
#define MSCC_M_CFG_SIO_AUTO_REPEAT(p)		BIT(p->props->auto_repeat.beg)
#define MSCC_F_CFG_SIO_PORT_WIDTH(p, x)		__F(p->props->port_width, x)
#define MSCC_M_CFG_SIO_PORT_WIDTH(p)		__M(p->props->port_width)
#define MSCC_F_CLOCK_SIO_CLK_FREQ(p, x)		__F(p->props->clk_freq, x)
#define MSCC_M_CLOCK_SIO_CLK_FREQ(p)		__M(p->props->clk_freq)
#define MSCC_F_PORT_CFG_BIT_SOURCE(p, x)	__F(p->props->bit_source, x)
#define MSCC_X_PORT_CFG_BIT_SOURCE(p, x)	__X(p->props->bit_source, x)
