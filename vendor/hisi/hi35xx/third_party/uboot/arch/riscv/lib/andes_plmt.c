#include <common.h>
#include <dm.h>
#include <regmap.h>
#include <syscon.h>
#include <asm/io.h>
#include <asm/syscon.h>
#define MTIME_REG(base)			((ulong)(base))
#define PLMT_BASE_GET(void)						\
