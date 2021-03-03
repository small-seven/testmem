#include <common.h>
#include <errno.h>
#include <wait_bit.h>
#include <dm.h>
#include <reset-uclass.h>
#include <regmap.h>
#include <syscon.h>
#include <dt-bindings/reset/stih407-resets.h>
#define _SYSCFG_RST_CH(_c, _rr, _rb, _ar, _ab)		\
#define _SYSCFG_RST_CH_NO_ACK(_c, _rr, _rb)		\
#define STIH407_SRST_CORE(_reg, _bit) \
#define STIH407_SRST_SBC(_reg, _bit) \
#define STIH407_SRST_LPM(_reg, _bit) \
#define STIH407_PDN_0(_bit) \
#define STIH407_PDN_1(_bit) \
#define STIH407_PDN_ETH(_bit, _stat) \
#define SYSCFG_5000	0x0
#define SYSSTAT_5500	0x7d0
#define SYSCFG_5001	0x4
#define SYSSTAT_5501	0x7d4
#define SYSCFG_4032	0x80
#define SYSSTAT_4520	0x820
#define SYSCFG_4002	0x8
#define SYSCFG_5128	0x200
#define SYSCFG_5131	0x20c
#define SYSCFG_5132	0x210
#define LPM_SYSCFG_1	0x4	/* Softreset IRB & SBC UART */
#define SYSCFG_5061	0x0f4
static int sti_reset_free(struct reset_ctl *reset_ctl)
{
	return 0;
}
