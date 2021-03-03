#define _GNU_SOURCE
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <asm/types.h>
#include <sys/socket.h>
#include <linux/rtnetlink.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include "test.h"
#include "config.h"
#if HAVE_DECL_IFLA_NET_NS_PID
#else
#endif
