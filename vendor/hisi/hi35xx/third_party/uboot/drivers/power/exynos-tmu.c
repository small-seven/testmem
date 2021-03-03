#include <common.h>
#include <errno.h>
#include <fdtdec.h>
#include <tmu.h>
#include <asm/arch/tmu.h>
#include <asm/arch/power.h>
#define TRIMINFO_RELOAD		1
#define CORE_EN			1
#define THERM_TRIP_EN		(1 << 12)
#define INTEN_RISE0		1
#define INTEN_RISE1		(1 << 4)
#define INTEN_RISE2		(1 << 8)
#define INTEN_FALL0		(1 << 16)
#define INTEN_FALL1		(1 << 20)
#define INTEN_FALL2		(1 << 24)
#define TRIM_INFO_MASK		0xff
#define INTCLEAR_RISE0		1
#define INTCLEAR_RISE1		(1 << 4)
#define INTCLEAR_RISE2		(1 << 8)
#define INTCLEAR_FALL0		(1 << 16)
#define INTCLEAR_FALL1		(1 << 20)
#define INTCLEAR_FALL2		(1 << 24)
#define INTCLEARALL		(INTCLEAR_RISE0 | INTCLEAR_RISE1 | \
#if CONFIG_IS_ENABLED(OF_CONTROL)
#else
#endif
