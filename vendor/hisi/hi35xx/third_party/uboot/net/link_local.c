#include <common.h>
#include <env.h>
#include <net.h>
#include <rand.h>
#include "arp.h"
#include "net_rand.h"
#define MONOTONIC_MS() ((unsigned)get_timer(0) * (1000 / CONFIG_SYS_HZ))
#if 0
#endif
