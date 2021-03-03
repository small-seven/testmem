#include <common.h>
#include <clk.h>
#include <malloc.h>
#include <part.h>
#include <mmc.h>
#include <linux/io.h>
#include <linux/errno.h>
#include <asm/byteorder.h>
#include <faraday/ftsdc010.h>
#include "ftsdc010_mci.h"
#include <dm.h>
#include <dt-structs.h>
#include <errno.h>
#include <mapmem.h>
#include <pwrseq.h>
#include <syscon.h>
#include <linux/err.h>
#define CFG_CMD_TIMEOUT (CONFIG_SYS_HZ >> 4) /* 250 ms */
#define CFG_RST_TIMEOUT CONFIG_SYS_HZ /* 1 sec reset timeout */
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#ifdef CONFIG_FTSDC010_SDIO
#endif
#if !CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
#if CONFIG_IS_ENABLED(OF_PLATDATA)
#endif
