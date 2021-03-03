#include <common.h>
#if defined(CONFIG_FTMAC100) && !defined(CONFIG_DM_ETH)
#include <netdev.h>
#endif
#include <linux/io.h>
#include <faraday/ftsmc020.h>
#include <fdtdec.h>
#include <dm.h>
#include <spl.h>
#if defined(CONFIG_FTMAC100) && !defined(CONFIG_DM_ETH)
#endif
#ifdef CONFIG_BOARD_EARLY_INIT_F
#endif
#ifdef CONFIG_SPL
#ifdef CONFIG_SPL_RAM_SUPPORT
#endif
#ifdef CONFIG_SPL_MMC_SUPPORT
#endif
#endif
#ifdef CONFIG_SPL_LOAD_FIT
#endif
