#include "imagetool.h"
#include <compiler.h>
#include <image.h>
#ifndef LPC32XX_BOOT_ICR
#define LPC32XX_BOOT_ICR 0x00000096
#endif
#ifndef LPC32XX_BOOT_NAND_PAGESIZE
#define LPC32XX_BOOT_NAND_PAGESIZE 2048
#endif
#ifndef LPC32XX_BOOT_NAND_PAGES_PER_SECTOR
#define LPC32XX_BOOT_NAND_PAGES_PER_SECTOR 64
#endif
#ifndef LPC32XX_BOOT_CODESIZE
#define LPC32XX_BOOT_CODESIZE (56*1024)
#endif
#define LPC32XX_BOOT_BLOCK_OK 0xaa
