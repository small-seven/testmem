#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../arch/arm/include/asm/arch-sunxi/spl.h"
#define STAMP_VALUE                     0x5F0A6C39
#define ALIGN(x, a) __ALIGN_MASK((x), (typeof(x))(a)-1)
#define __ALIGN_MASK(x, mask) (((x)+(mask))&~(mask))
#define SUNXI_SRAM_SIZE 0x8000	/* SoC with smaller size are limited before */
#define SRAM_LOAD_MAX_SIZE (SUNXI_SRAM_SIZE - sizeof(struct boot_file_head))
#define BLOCK_SIZE 0x2000
