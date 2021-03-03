#include <linux/io.h>
#include "../init.h"
#include "bcu-regs.h"
#define ch(x) ((x) >= 32 ? 0 : (x) < 0 ? 0x11111111 : 0x11111111 << (x))
