#include <common.h>
#include <asm/immap.h>
#include <netdev.h>
#include <asm/io.h>
#ifdef CONFIG_IDE
#include <ata.h>
#define CALC_TIMING(t) (t + period - 1) / period
#endif				/* CONFIG_IDE */
#ifdef CONFIG_DRIVER_DM9000
#endif
