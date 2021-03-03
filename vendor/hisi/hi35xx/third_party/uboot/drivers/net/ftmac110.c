#include <common.h>
#include <command.h>
#include <malloc.h>
#include <net.h>
#include <linux/errno.h>
#include <asm/io.h>
#include <asm/dma-mapping.h>
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#include <miiphy.h>
#endif
#include "ftmac110.h"
#define CFG_RXDES_NUM   8
#define CFG_TXDES_NUM   2
#define CFG_XBUF_SIZE   1536
#define CFG_MDIORD_TIMEOUT  (CONFIG_SYS_HZ >> 1) /* 500 ms */
#define CFG_MDIOWR_TIMEOUT  (CONFIG_SYS_HZ >> 1) /* 500 ms */
#define CFG_LINKUP_TIMEOUT  (CONFIG_SYS_HZ << 2) /* 4 sec */
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif    /* #if defined(CONFIG_MII) || defined(CONFIG_CMD_MII) */
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
