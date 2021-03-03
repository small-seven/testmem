#include "includes.h"
#include <sys/ioctl.h>
#include <net/if.h>
#include <netlink/genl/genl.h>
#include <netlink/genl/family.h>
#include <netlink/genl/ctrl.h>
#include <fcntl.h>
#include "utils/common.h"
#include "driver_nl80211.h"
#include "android_drv.h"
typedef struct android_wifi_priv_cmd {
	char *buf;
	int used_len;
	int total_len;
} android_wifi_priv_cmd;
#ifdef ANDROID_P2P
#ifdef ANDROID_LIB_STUB
#endif /* ANDROID_LIB_STUB */
#endif /* ANDROID_P2P */
