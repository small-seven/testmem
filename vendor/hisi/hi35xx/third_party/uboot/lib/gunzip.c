#include <common.h>
#include <command.h>
#include <console.h>
#include <div64.h>
#include <gzip.h>
#include <image.h>
#include <malloc.h>
#include <memalign.h>
#include <u-boot/crc.h>
#include <watchdog.h>
#include <u-boot/zlib.h>
#define HEADER0			'\x1f'
#define HEADER1			'\x8b'
#define	ZALLOC_ALIGNMENT	16
#define HEAD_CRC		2
#define EXTRA_FIELD		4
#define ORIG_NAME		8
#define COMMENT			0x10
#define RESERVED		0xe0
#define DEFLATED		8
void *gzalloc(void *x, unsigned items, unsigned size)
{
	void *p;

	size *= items;
	size = (size + ZALLOC_ALIGNMENT - 1) & ~(ZALLOC_ALIGNMENT - 1);

	p = malloc (size);

	return (p);
}
void gzfree(void *x, void *addr, unsigned nb)
{
	free (addr);
}
#ifdef CONFIG_CMD_UNZIP
#endif
