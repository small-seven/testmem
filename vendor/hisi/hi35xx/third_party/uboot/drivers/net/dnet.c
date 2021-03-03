#include <common.h>
#ifndef CONFIG_DNET_AUTONEG_TIMEOUT
#define CONFIG_DNET_AUTONEG_TIMEOUT	5000000	/* default value */
#endif
#include <net.h>
#include <malloc.h>
#include <linux/mii.h>
#include <miiphy.h>
#include <asm/io.h>
#include <asm/unaligned.h>
#include "dnet.h"
#define to_dnet(_nd) container_of(_nd, struct dnet_device, netdev)
