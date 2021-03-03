#include "includes.h"
#include <netpacket/packet.h>
#include <linux/filter.h>
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "linux_ioctl.h"
#include "radiotap_iter.h"
#include "driver_nl80211.h"
#define PASS	0xFF
#define FAIL	0xFE
#if 0
#endif
