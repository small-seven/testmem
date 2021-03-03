#define _GNU_SOURCE
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <syscall.h>
#include <net/if.h>
#include <netinet/in.h>
#include <unsupported_api.h>
#include "netlink.h"
#define IFADDRS_HASH_SIZE 64
