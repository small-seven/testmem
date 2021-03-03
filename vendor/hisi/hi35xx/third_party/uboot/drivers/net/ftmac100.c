#include <config.h>
#include <common.h>
#include <cpu_func.h>
#include <env.h>
#include <malloc.h>
#include <net.h>
#include <linux/io.h>
#include "ftmac100.h"
#ifdef CONFIG_DM_ETH
#include <dm.h>
#endif
#define ETH_ZLEN	60
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_DM_ETH
#endif
