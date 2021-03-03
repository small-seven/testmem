#include <common.h>
#include <command.h>
#include <net.h>
#include <net/tftp.h>
#include "nfs.h"
#include "bootp.h"
#include "rarp.h"
#define TIMEOUT 5000UL /* Milliseconds before trying BOOTP again */
#ifndef	CONFIG_NET_RETRY_COUNT
#define TIMEOUT_COUNT 5 /* # of timeouts before giving up  */
#else
#define TIMEOUT_COUNT (CONFIG_NET_RETRY_COUNT)
#endif
