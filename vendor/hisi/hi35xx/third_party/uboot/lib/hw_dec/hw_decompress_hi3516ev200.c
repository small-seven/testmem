#include <asm/io.h>
#include <config.h>
#define PERI_CRG100 0x190
#define GZIP_OFFSET PERI_CRG100
#define GZIP_CLKEN (0x1<<0)
#ifndef GZIP_REG_BASE
#define GZIP_REG_BASE   0x11310000
#endif
#define HW_DEC_REG_BASE_ADDR  (GZIP_REG_BASE)
