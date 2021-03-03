#include <common.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/syscon.h>
#define MSIP_REG(base, hart)		((ulong)(base) + (hart) * 4)
#define MTIMECMP_REG(base, hart)	((ulong)(base) + 0x4000 + (hart) * 8)
#define MTIME_REG(base)			((ulong)(base) + 0xbff8)
#define CLINT_BASE_GET(void)						\
