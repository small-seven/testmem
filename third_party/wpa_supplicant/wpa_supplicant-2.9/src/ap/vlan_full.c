#include "utils/includes.h"
#include <net/if.h>
#undef if_type
#include <sys/ioctl.h>
#include "utils/common.h"
#include "drivers/priv_netlink.h"
#include "drivers/linux_ioctl.h"
#include "common/linux_bridge.h"
#include "common/linux_vlan.h"
#include "utils/eloop.h"
#include "hostapd.h"
#include "ap_config.h"
#include "ap_drv_ops.h"
#include "wpa_auth.h"
#include "vlan_init.h"
#include "vlan_util.h"
#define DVLAN_CLEAN_BR         0x1
#define DVLAN_CLEAN_VLAN       0x2
#define DVLAN_CLEAN_VLAN_PORT  0x4
#define MAX_BR_PORTS      		256
