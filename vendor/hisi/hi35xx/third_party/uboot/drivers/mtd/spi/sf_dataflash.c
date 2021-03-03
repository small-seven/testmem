#include <common.h>
#include <dm.h>
#include <errno.h>
#include <fdtdec.h>
#include <spi.h>
#include <spi_flash.h>
#include <div64.h>
#include <linux/err.h>
#include <linux/math64.h>
#include "sf_internal.h"
#define CMD_READ_ID		0x9f
#define OP_READ_CONTINUOUS	0xE8
#define OP_READ_PAGE		0xD2
#define OP_READ_STATUS		0xD7	/* group B */
#define OP_READ_BUFFER1		0xD4	/* group B */
#define OP_READ_BUFFER2		0xD6	/* group B */
#define OP_WRITE_BUFFER1	0x84	/* group B */
#define OP_WRITE_BUFFER2	0x87	/* group B */
#define OP_ERASE_PAGE		0x81
#define OP_ERASE_BLOCK		0x50
#define OP_TRANSFER_BUF1	0x53
#define OP_TRANSFER_BUF2	0x55
#define OP_MREAD_BUFFER1	0xD4
#define OP_MREAD_BUFFER2	0xD6
#define OP_MWERASE_BUFFER1	0x83
#define OP_MWERASE_BUFFER2	0x86
#define OP_MWRITE_BUFFER1	0x88	/* sector must be pre-erased */
#define OP_MWRITE_BUFFER2	0x89	/* sector must be pre-erased */
#define OP_PROGRAM_VIA_BUF1	0x82
#define OP_PROGRAM_VIA_BUF2	0x85
#define OP_COMPARE_BUF1		0x60
#define OP_COMPARE_BUF2		0x61
#define OP_REWRITE_VIA_BUF1	0x58
#define OP_REWRITE_VIA_BUF2	0x59
#define OP_READ_ID		0x9F
#define OP_READ_SECURITY	0x77
#define OP_WRITE_SECURITY_REVC	0x9A
#define OP_WRITE_SECURITY	0x9B	/* revision D */
#ifdef CONFIG_SPI_DATAFLASH_WRITE_VERIFY
#endif	/* CONFIG_SPI_DATAFLASH_WRITE_VERIFY */
#ifndef CONFIG_SPL_BUILD
#endif
#define SUP_POW2PS	0x0002		/* supports 2^N byte pages */
#define IS_POW2PS	0x0001		/* uses 2^N byte pages */
