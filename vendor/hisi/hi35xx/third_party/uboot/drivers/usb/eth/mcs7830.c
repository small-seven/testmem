#include <common.h>
#include <dm.h>
#include <errno.h>
#include <linux/mii.h>
#include <malloc.h>
#include <memalign.h>
#include <usb.h>
#include "usb_ether.h"
#define MCS7830_BASE_NAME	"mcs"
#define USBCALL_TIMEOUT		1000
#define LINKSTATUS_TIMEOUT	5000	/* link status, connect timeout */
#define LINKSTATUS_TIMEOUT_RES	50	/* link status, resolution in msec */
#define MCS7830_RX_URB_SIZE	2048
#define MCS7830_WR_BREQ		0x0d
#define MCS7830_RD_BREQ		0x0e
#define REG_MULTICAST_HASH	offsetof(struct mcs7830_regs, multicast_hashes)
#define REG_PHY_DATA		offsetof(struct mcs7830_regs, phy_data)
#define REG_PHY_CMD		offsetof(struct mcs7830_regs, phy_command)
#define REG_CONFIG		offsetof(struct mcs7830_regs, configuration)
#define REG_ETHER_ADDR		offsetof(struct mcs7830_regs, ether_address)
#define REG_FRAME_DROP_COUNTER	offsetof(struct mcs7830_regs, frame_drop_count)
#define REG_PAUSE_THRESHOLD	offsetof(struct mcs7830_regs, pause_threshold)
#define PHY_CMD1_READ		0x40
#define PHY_CMD1_WRITE		0x20
#define PHY_CMD1_PHYADDR	0x01
#define PHY_CMD2_PEND		0x80
#define PHY_CMD2_READY		0x40
#define CONF_CFG		0x80
#define CONF_SPEED100		0x40
#define CONF_FDX_ENABLE		0x20
#define CONF_RXENABLE		0x10
#define CONF_TXENABLE		0x08
#define CONF_SLEEPMODE		0x04
#define CONF_ALLMULTICAST	0x02
#define CONF_PROMISCUOUS	0x01
#define PAUSE_THRESHOLD_DEFAULT	0
#define STAT_RX_FRAME_CORRECT	0x20
#define STAT_RX_LARGE_FRAME	0x10
#define STAT_RX_CRC_ERROR	0x08
#define STAT_RX_ALIGNMENT_ERROR	0x04
#define STAT_RX_LENGTH_ERROR	0x02
#define STAT_RX_SHORT_FRAME	0x01
#ifdef CONFIG_DM_ETH
#endif
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_DM_ETH
#endif
