#include <common.h>
#include <mmc.h>
#include <malloc.h>
#define ESDHC_BOOT_IMAGE_SIZE	0x48
#define ESDHC_BOOT_IMAGE_ADDR	0x50
#define ESDHC_DEFAULT_ENVADDR	0x400
#ifdef CONFIG_BLK
#else
#endif
#ifdef CONFIG_ESDHC_HC_BLK_ADDR
#endif
