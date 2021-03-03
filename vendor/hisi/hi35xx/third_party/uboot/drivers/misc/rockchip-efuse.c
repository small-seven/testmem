#include <common.h>
#include <asm/io.h>
#include <command.h>
#include <display_options.h>
#include <dm.h>
#include <linux/bitops.h>
#include <linux/delay.h>
#include <misc.h>
#define RK3399_A_SHIFT          16
#define RK3399_A_MASK           0x3ff
#define RK3399_NFUSES           32
#define RK3399_BYTES_PER_FUSE   4
#define RK3399_STROBSFTSEL      BIT(9)
#define RK3399_RSB              BIT(7)
#define RK3399_PD               BIT(5)
#define RK3399_PGENB            BIT(3)
#define RK3399_LOAD             BIT(2)
#define RK3399_STROBE           BIT(1)
#define RK3399_CSB              BIT(0)
#if defined(DEBUG)
#endif
