#define _GNU_SOURCE
#include <net/if.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unsupported_api.h>
#include "netlink.h"
#define IFADDRS_HASH_SIZE 64
