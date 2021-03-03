#include <common.h>
#include <command.h>
#include <asm/io.h>
#include <net.h>
#include <malloc.h>
#include "cs8900.h"
#undef DEBUG
#ifdef CONFIG_CS8900_BUS32
#define REG_WRITE(v, a) writel((v),(a))
#define REG_READ(a) readl((a))
#define get_reg_init_bus(r,d) get_reg((r),(d))
#else
#define REG_WRITE(v, a) writew((v),(a))
#define REG_READ(a) readw((a))
#endif
