#include <asm/io.h>
#include <config.h>
#define PERI_CRG82 0x148
#define GZIP_CLKEN (1<<1)
#ifndef GZIP_REG_BASE
#define GZIP_REG_BASE           0x11330000
#endif
#define HW_DEC_REG_BASE_ADDR  (GZIP_REG_BASE)
