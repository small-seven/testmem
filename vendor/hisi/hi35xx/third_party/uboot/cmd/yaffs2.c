#include <common.h>
#include <config.h>
#include <command.h>
#ifdef YAFFS2_DEBUG
#define PRINTF(fmt, args...) printf(fmt, ##args)
#else
#define PRINTF(fmt, args...) do { } while (0)
#endif
