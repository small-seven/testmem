#include "includes.h"
#ifdef __linux__
#include <fcntl.h>
#endif /* __linux__ */
#include <sys/un.h>
#include <sys/stat.h>
#include "common.h"
#include "eloop.h"
#include "common/version.h"
#include "drivers/driver.h"
#include "l2_packet/l2_packet.h"
#include "common/privsep_commands.h"
#include "common/ieee802_11_defs.h"
#define WPA_PRIV_MAX_L2 3
#ifdef __linux__
#endif /* __linux__ */
