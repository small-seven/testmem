#include <common.h>
#include <errno.h>
#include <malloc.h>
#include <part.h>
#include <mmc.h>
#include <asm/io.h>
#include <asm/arch/cpu.h>
#include <asm/arch/soc.h>
#include <mvebu_mmc.h>
#define DRIVER_NAME "MVEBU_MMC"
#define MVEBU_TARGET_DRAM 0
#define TIMEOUT_DELAY	5*CONFIG_SYS_HZ		/* wait 5 seconds */
