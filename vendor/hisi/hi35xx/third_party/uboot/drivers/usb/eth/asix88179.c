#include <common.h>
#include <dm.h>
#include <usb.h>
#include <net.h>
#include <linux/mii.h>
#include "usb_ether.h"
#include <malloc.h>
#include <memalign.h>
#include <errno.h>
#define AX88179_PHY_ID				0x03
#define AX_EEPROM_LEN				0x100
#define AX88179_EEPROM_MAGIC			0x17900b95
#define AX_MCAST_FLTSIZE			8
#define AX_MAX_MCAST				64
#define AX_INT_PPLS_LINK			(1 << 16)
#define AX_RXHDR_L4_TYPE_MASK			0x1c
#define AX_RXHDR_L4_TYPE_UDP			4
#define AX_RXHDR_L4_TYPE_TCP			16
#define AX_RXHDR_L3CSUM_ERR			2
#define AX_RXHDR_L4CSUM_ERR			1
#define AX_RXHDR_CRC_ERR			(1 << 29)
#define AX_RXHDR_DROP_ERR			(1 << 31)
#define AX_ENDPOINT_INT				0x01
#define AX_ENDPOINT_IN				0x02
#define AX_ENDPOINT_OUT				0x03
#define AX_ACCESS_MAC				0x01
#define AX_ACCESS_PHY				0x02
#define AX_ACCESS_EEPROM			0x04
#define AX_ACCESS_EFUS				0x05
#define AX_PAUSE_WATERLVL_HIGH			0x54
#define AX_PAUSE_WATERLVL_LOW			0x55
#define PHYSICAL_LINK_STATUS			0x02
#define GENERAL_STATUS				0x03
#define AX_SROM_ADDR				0x07
#define AX_SROM_CMD				0x0a
#define AX_SROM_DATA_LOW			0x08
#define AX_SROM_DATA_HIGH			0x09
#define AX_RX_CTL				0x0b
#define AX_NODE_ID				0x10
#define AX_MULFLTARY				0x16
#define AX_MEDIUM_STATUS_MODE			0x22
#define AX_MONITOR_MOD				0x24
#define AX_GPIO_CTRL				0x25
#define AX_PHYPWR_RSTCTL			0x26
#define AX_RX_BULKIN_QCTRL			0x2e
#define AX_CLK_SELECT				0x33
#define AX_RXCOE_CTL				0x34
#define AX_TXCOE_CTL				0x35
#define AX_LEDCTRL				0x73
#define GMII_PHY_PHYSR				0x11
#define GMII_LED_ACT				0x1a
#define GMII_LED_LINK				0x1c
#define GMII_PHYPAGE				0x1e
#define GMII_PHY_PAGE_SELECT			0x1f
#define ASIX_BASE_NAME "axg"
#define USB_CTRL_SET_TIMEOUT 5000
#define USB_CTRL_GET_TIMEOUT 5000
#define USB_BULK_SEND_TIMEOUT 5000
#define USB_BULK_RECV_TIMEOUT 5000
#define AX_RX_URB_SIZE 1024 * 0x12
#define BLK_FRAME_SIZE 0x200
#define PHY_CONNECT_TIMEOUT 5000
#define TIMEOUT_RESOLUTION 50	/* ms */
#define FLAG_NONE			0
#define FLAG_TYPE_AX88179	(1U << 0)
#define FLAG_TYPE_AX88178a	(1U << 1)
#define FLAG_TYPE_DLINK_DUB1312	(1U << 2)
#define FLAG_TYPE_SITECOM	(1U << 3)
#define FLAG_TYPE_SAMSUNG	(1U << 4)
#define FLAG_TYPE_LENOVO	(1U << 5)
#define FLAG_TYPE_GX3		(1U << 6)
#ifndef CONFIG_DM_ETH
#endif
#ifdef CONFIG_DM_ETH
#endif
#ifndef CONFIG_DM_ETH
#else /* !CONFIG_DM_ETH */
#endif /* !CONFIG_DM_ETH */
