#define _GNU_SOURCE
#include <sys/wait.h>
#include <asm/types.h>
#include <sys/socket.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "netns_helper.h"
#include "test.h"
#include "safe_macros.h"
#define MAX_TRIES 1000
#define IP_TUNTAP_MIN_VER 100519
