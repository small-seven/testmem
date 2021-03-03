#include <linux/string.h>
#include <linux/types.h>
#include <linux/errno.h>
#include "jffs2.h"
#include "compr.h"
#define RUBIN_REG_SIZE   16
#define UPPER_BIT_RUBIN    (((long) 1)<<(RUBIN_REG_SIZE-1))
#define LOWER_BITS_RUBIN   ((((long) 1)<<(RUBIN_REG_SIZE-1))-1)
#define BIT_DIVIDER_MIPS 1043
#if 0
#endif
#ifdef JFFS2_RUBINMIPS_DISABLED
#else
#endif
#ifdef JFFS2_DYNRUBIN_DISABLED
#else
#endif
