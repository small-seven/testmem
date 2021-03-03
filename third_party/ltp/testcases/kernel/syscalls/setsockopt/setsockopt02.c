#include <errno.h>
#include "tst_test.h"
#include "tst_safe_net.h"
#include "config.h"
#ifdef HAVE_LINUX_IF_PACKET_H
# include <linux/if_packet.h>
#endif
#ifdef HAVE_LINUX_IF_ETHER_H
# include <linux/if_ether.h>
#endif
#ifndef ETH_P_ALL
# define ETH_P_ALL 0x0003
#endif
#ifndef PACKET_RX_RING
# define PACKET_RX_RING 5
#endif
#ifndef PACKET_VERSION
# define PACKET_VERSION 10
#endif
#ifndef HAVE_STRUCT_TPACKET_REQ3
# define TPACKET_V3 2
#endif
