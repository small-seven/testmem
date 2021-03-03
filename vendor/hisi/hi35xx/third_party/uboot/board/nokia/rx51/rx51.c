#include <common.h>
#include <env.h>
#include <watchdog.h>
#include <malloc.h>
#include <twl4030.h>
#include <i2c.h>
#include <video_fb.h>
#include <asm/io.h>
#include <asm/setup.h>
#include <asm/bitops.h>
#include <asm/mach-types.h>
#include <asm/arch/mux.h>
#include <asm/arch/sys_proto.h>
#include <asm/arch/mmc_host_def.h>
#include "rx51.h"
#include "tag_omap.h"
#define KEYBUF_SIZE 32
