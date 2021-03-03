#include <common.h>
#include <dm.h>
#include <errno.h>
#include <malloc.h>
#include <memalign.h>
#include <usb.h>
#include <asm/unaligned.h>
#include <linux/mii.h>
#include "usb_ether.h"
#define LED_GPIO_CFG			(0x24)
#define LED_GPIO_CFG_SPD_LED		(0x01000000)
#define LED_GPIO_CFG_LNK_LED		(0x00100000)
#define LED_GPIO_CFG_FDX_LED		(0x00010000)
#define TX_CMD_A_FIRST_SEG_		0x00002000
#define TX_CMD_A_LAST_SEG_		0x00001000
#define RX_STS_FL_			0x3FFF0000	/* Frame Length */
#define RX_STS_ES_			0x00008000	/* Error Summary */
#define ID_REV				0x00
#define INT_STS				0x08
#define TX_CFG				0x10
#define TX_CFG_ON_			0x00000004
#define HW_CFG				0x14
#define HW_CFG_BIR_			0x00001000
#define HW_CFG_RXDOFF_			0x00000600
#define HW_CFG_MEF_			0x00000020
#define HW_CFG_BCE_			0x00000002
#define HW_CFG_LRST_			0x00000008
#define PM_CTRL				0x20
#define PM_CTL_PHY_RST_			0x00000010
#define AFC_CFG				0x2C
#define AFC_CFG_DEFAULT			0x00F830A1
#define E2P_CMD				0x30
#define E2P_CMD_BUSY_			0x80000000
#define E2P_CMD_READ_			0x00000000
#define E2P_CMD_TIMEOUT_		0x00000400
#define E2P_CMD_LOADED_			0x00000200
#define E2P_CMD_ADDR_			0x000001FF
#define E2P_DATA			0x34
#define BURST_CAP			0x38
#define INT_EP_CTL			0x68
#define INT_EP_CTL_PHY_INT_		0x00008000
#define BULK_IN_DLY			0x6C
#define MAC_CR				0x100
#define MAC_CR_MCPAS_			0x00080000
#define MAC_CR_PRMS_			0x00040000
#define MAC_CR_HPFILT_			0x00002000
#define MAC_CR_TXEN_			0x00000008
#define MAC_CR_RXEN_			0x00000004
#define ADDRH				0x104
#define ADDRL				0x108
#define MII_ADDR			0x114
#define MII_WRITE_			0x02
#define MII_BUSY_			0x01
#define MII_READ_			0x00 /* ~of MII Write bit */
#define MII_DATA			0x118
#define FLOW				0x11C
#define VLAN1				0x120
#define COE_CR				0x130
#define Tx_COE_EN_			0x00010000
#define Rx_COE_EN_			0x00000001
#define PHY_INT_SRC			29
#define PHY_INT_MASK			30
#define PHY_INT_MASK_ANEG_COMP_		((u16)0x0040)
#define PHY_INT_MASK_LINK_DOWN_		((u16)0x0010)
#define PHY_INT_MASK_DEFAULT_		(PHY_INT_MASK_ANEG_COMP_ | \
#define USB_VENDOR_REQUEST_WRITE_REGISTER	0xA0
#define USB_VENDOR_REQUEST_READ_REGISTER	0xA1
#define HS_USB_PKT_SIZE			512
#define FS_USB_PKT_SIZE			64
#define DEFAULT_HS_BURST_CAP_SIZE	(5 * HS_USB_PKT_SIZE)
#define DEFAULT_FS_BURST_CAP_SIZE	(33 * FS_USB_PKT_SIZE)
#define DEFAULT_BULK_IN_DELAY		0x00002000
#define MAX_SINGLE_PACKET_SIZE		2048
#define EEPROM_MAC_OFFSET		0x01
#define SMSC95XX_INTERNAL_PHY_ID	1
#define ETH_P_8021Q	0x8100          /* 802.1Q VLAN Extended Header  */
#define SMSC95XX_BASE_NAME "sms"
#define USB_CTRL_SET_TIMEOUT 5000
#define USB_CTRL_GET_TIMEOUT 5000
#define USB_BULK_SEND_TIMEOUT 5000
#define USB_BULK_RECV_TIMEOUT 5000
#define RX_URB_SIZE DEFAULT_HS_BURST_CAP_SIZE
#define PHY_CONNECT_TIMEOUT 5000
#define TURBO_MODE
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_DM_ETH
#endif
#define TIMEOUT_RESOLUTION 50	/* ms */
#ifndef CONFIG_DM_ETH
#endif
#ifdef TURBO_MODE
#else
#endif
#ifdef TURBO_MODE
#endif
#define NET_IP_ALIGN 0
#ifndef CONFIG_DM_ETH
#endif /* !CONFIG_DM_ETH */
#ifdef CONFIG_DM_ETH
#endif
