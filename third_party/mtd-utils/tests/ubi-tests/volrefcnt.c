#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include "libubi.h"
#define PROGRAM_NAME "rmvol"
#include "common.h"
#include "helpers.h"
#define SYSFS_FILE "/sys/class/ubi/ubi%d_%d/usable_eb_size"
