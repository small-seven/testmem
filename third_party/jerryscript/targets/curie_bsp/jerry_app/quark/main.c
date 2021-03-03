#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "infra/bsp.h"
#include "infra/reboot.h"
#include "infra/log.h"
#include "infra/time.h"
#include "infra/system_events.h"
#include "infra/tcmd/handler.h"
#include "cfw/cfw.h"
#include "infra/wdt_helper.h"
#include "jerryscript.h"
#include "jerryscript-port.h"
#include "string.h"
#include "zephyr.h"
#include "microkernel/task.h"
#include "os/os.h"
#include "misc/printk.h"
