#include <stdio.h>
#include <string.h>
#include "common.h"
#include "bitmask.h"
#include "cpuset.h"
#include "meminfo.h"
#define LIST_PRESENT_MEM_FILE	"/sys/devices/system/node/possible"
#define LIST_ONLINE_MEM_FILE	"/sys/devices/system/node/online"
