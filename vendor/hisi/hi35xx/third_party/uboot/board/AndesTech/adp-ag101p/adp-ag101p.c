#include <common.h>
#if defined(CONFIG_FTMAC100) && !defined(CONFIG_DM_ETH)
#include <netdev.h>
#endif
#include <linux/io.h>
#include <asm/io.h>
#include <asm/mach-types.h>
#include <faraday/ftsmc020.h>
#if defined(CONFIG_FTMAC100) && !defined(CONFIG_DM_ETH)
#endif
