#include <linux/input.h>
#include <linux/uinput.h>
#include "test.h"
#include "safe_macros.h"
#include "lapi/fcntl.h"
#include "input_helper.h"
#define NB_TEST 10
#define PS2_RIGHT_BTN 0x02
