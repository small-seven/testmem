#include <linux/input.h>
#include <linux/uinput.h>
#include <stdio.h>
#include <string.h>
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "tst_uinput.h"
#define VIRTUAL_DEVICE "virtual-device-ltp"
#define SYSFS_PREFIX "Sysfs="
#define HANDLERS_PREFIX "Handlers="
