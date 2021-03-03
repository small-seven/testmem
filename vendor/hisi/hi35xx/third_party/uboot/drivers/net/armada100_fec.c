#include <common.h>
#include <net.h>
#include <malloc.h>
#include <miiphy.h>
#include <netdev.h>
#include <asm/types.h>
#include <asm/byteorder.h>
#include <linux/err.h>
#include <linux/mii.h>
#include <asm/io.h>
#include <asm/arch/armada100.h>
#include "armada100_fec.h"
#define  PHY_ADR_REQ     0xFF	/* Magic number to read/write PHY address */
#ifdef DEBUG
#endif
#ifdef DEBUG
#endif
#if (defined(CONFIG_MII) || defined(CONFIG_CMD_MII))
#if defined(CONFIG_PHY_BASE_ADR)
#else
#endif
#if defined(CONFIG_SYS_FAULT_ECHO_LINK_DOWN)
#endif
#endif
#if defined(CONFIG_MII) || defined(CONFIG_CMD_MII)
#endif
