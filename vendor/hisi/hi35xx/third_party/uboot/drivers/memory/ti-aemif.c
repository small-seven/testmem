#include <common.h>
#include <asm/ti-common/ti-aemif.h>
#define AEMIF_WAITCYCLE_CONFIG		(CONFIG_AEMIF_CNTRL_BASE + 0x4)
#define AEMIF_NAND_CONTROL		(CONFIG_AEMIF_CNTRL_BASE + 0x60)
#define AEMIF_ONENAND_CONTROL		(CONFIG_AEMIF_CNTRL_BASE + 0x5c)
#define AEMIF_CONFIG(cs)		(CONFIG_AEMIF_CNTRL_BASE + 0x10 \
#define AEMIF_CFG_SELECT_STROBE(v)	((v) ? 1 << 31 : 0)
#define AEMIF_CFG_EXTEND_WAIT(v)	((v) ? 1 << 30 : 0)
#define AEMIF_CFG_WR_SETUP(v)		(((v) & 0x0f) << 26)
#define AEMIF_CFG_WR_STROBE(v)		(((v) & 0x3f) << 20)
#define AEMIF_CFG_WR_HOLD(v)		(((v) & 0x07) << 17)
#define AEMIF_CFG_RD_SETUP(v)		(((v) & 0x0f) << 13)
#define AEMIF_CFG_RD_STROBE(v)		(((v) & 0x3f) << 7)
#define AEMIF_CFG_RD_HOLD(v)		(((v) & 0x07) << 4)
#define AEMIF_CFG_TURN_AROUND(v)	(((v) & 0x03) << 2)
#define AEMIF_CFG_WIDTH(v)		(((v) & 0x03) << 0)
#define set_config_field(reg, field, val)			\
