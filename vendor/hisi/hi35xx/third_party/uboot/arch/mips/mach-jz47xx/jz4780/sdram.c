#include <common.h>
#include <asm/io.h>
#include <mach/jz4780.h>
#include <mach/jz4780_dram.h>
#define JZBIT(bit) ((bit % 4) * 8)
#define JZMASK(bit) (0x1f << JZBIT(bit))
