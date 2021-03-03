####ECOSGPLCOPYRIGHTBEGIN####
####ECOSGPLCOPYRIGHTEND####
####BSDCOPYRIGHTBEGIN####
####BSDCOPYRIGHTEND####
#####DESCRIPTIONBEGIN####
####DESCRIPTIONEND####
#include <common.h>
#include <command.h>
#include "ne2000_base.h"
#include "8390.h"
typedef struct hw_info_t {
	u_int	offset;
	u_char	a0, a1, a2;
	u_int	flags;
} hw_info_t;
#define DELAY_OUTPUT	0x01
#define HAS_MISC_REG	0x02
#define USE_BIG_BUF	0x04
#define HAS_IBM_MISC	0x08
#define IS_DL10019	0x10
#define IS_DL10022	0x20
#define HAS_MII		0x40
#define USE_SHMEM	0x80	/* autodetected */
#define AM79C9XX_HOME_PHY	0x00006B90	/* HomePNA PHY */
#define AM79C9XX_ETH_PHY	0x00006B70	/* 10baseT PHY */
#define MII_PHYID_REV_MASK	0xfffffff0
#define MII_PHYID_REG1		0x02
#define MII_PHYID_REG2		0x03
#define NR_INFO		(sizeof(hw_info)/sizeof(hw_info_t))
#define PCNET_CMD	0x00
#define PCNET_DATAPORT	0x10	/* NatSemi-defined port window offset. */
#define PCNET_RESET	0x1f	/* Issue a read to reset, a write to clear. */
#define PCNET_MISC	0x18	/* For IBM CCAE and Socket EA cards */
