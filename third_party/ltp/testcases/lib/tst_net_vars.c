#include <arpa/inet.h>
#include <arpa/nameser.h>
#include <assert.h>
#include <errno.h>
#include <linux/rtnetlink.h>
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "tst_net.h"
#include "tst_private.h"
#define BASE_IPV4_PREFIX 8
#define BASE_IPV6_PREFIX 16
#define MAX_IPV4_PREFIX 32
#define MAX_IPV6_PREFIX 128
#define DEFAULT_IPV4_UNUSED_PART1 10
#define DEFAULT_IPV6_UNUSED_PART1 0xfd
#define DEFAULT_IPV4_UNUSED_PART2 23
#define DEFAULT_IPV6_UNUSED_PART2 0x23
