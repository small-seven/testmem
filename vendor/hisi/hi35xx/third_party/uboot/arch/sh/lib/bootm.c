#include <common.h>
#include <command.h>
#include <asm/byteorder.h>
#include <asm/zimage.h>
#ifdef CONFIG_SYS_DEBUG
#endif
#ifdef CONFIG_SH_SDRAM_OFFSET
#define GET_INITRD_START(initrd, linux) (initrd - linux + CONFIG_SH_SDRAM_OFFSET)
#else
#define GET_INITRD_START(initrd, linux) (initrd - linux)
#endif
