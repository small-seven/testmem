#include "includes.h"
#include <sys/ioctl.h>
#include <linux/sockios.h>
#include <linux/if_ether.h>
#include <linux/mii.h>
#include <net/if.h>
#include "common.h"
#include "driver.h"
#include "l2_packet/l2_packet.h"
#define ROBO_PHY_ADDR		0x1e	/* RoboSwitch PHY address */
#define ROBO_MII_PAGE		0x10	/* MII page register */
#define ROBO_MII_ADDR		0x11	/* MII address register */
#define ROBO_MII_DATA_OFFSET	0x18	/* Start of MII data registers */
#define ROBO_MII_PAGE_ENABLE	0x01	/* MII page op code */
#define ROBO_MII_ADDR_WRITE	0x01	/* MII address write op code */
#define ROBO_MII_ADDR_READ	0x02	/* MII address read op code */
#define ROBO_MII_DATA_MAX	   4	/* Consecutive MII data registers */
#define ROBO_MII_RETRY_MAX	  10	/* Read attempts before giving up */
#define ROBO_ARLCTRL_PAGE	0x04	/* ARL control page */
#define ROBO_VLAN_PAGE		0x34	/* VLAN page */
#define ROBO_ARLCTRL_CONF	0x00	/* ARL configuration register */
#define ROBO_ARLCTRL_ADDR_1	0x10	/* Multiport address 1 */
#define ROBO_ARLCTRL_VEC_1	0x16	/* Multiport vector 1 */
#define ROBO_ARLCTRL_ADDR_2	0x20	/* Multiport address 2 */
#define ROBO_ARLCTRL_VEC_2	0x26	/* Multiport vector 2 */
#define ROBO_VLAN_ACCESS	0x08	/* VLAN table access register */
#define ROBO_VLAN_ACCESS_5350	0x06	/* VLAN table access register (5350) */
#define ROBO_VLAN_READ		0x0c	/* VLAN read register */
#define ROBO_VLAN_MAX		0xff	/* Maximum number of VLANs */
