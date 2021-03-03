#include <linux/input.h>
#include <linux/uinput.h>
#include <fnmatch.h>
#include <errno.h>
#include <poll.h>
#include "test.h"
#include "safe_macros.h"
#include "input_helper.h"
#define VIRTUAL_DEVICE "virtual-device-ltp"
#define VIRTUAL_DEVICE_REGEX "*virtual-device-ltp*"
