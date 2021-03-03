#include <common.h>
#include <bootm.h>
#include <command.h>
#include <gzip.h>
#include <lz4.h>
#include <malloc.h>
#include <mapmem.h>
#include <asm/io.h>
#include <u-boot/zlib.h>
#include <bzlib.h>
#include <lzma/LzmaTypes.h>
#include <lzma/LzmaDec.h>
#include <lzma/LzmaTools.h>
#include <linux/lzo.h>
#include <test/compression.h>
#include <test/suites.h>
#include <test/ut.h>
#define TEST_BUFFER_SIZE	512
typedef int (*mutate_func)(struct unit_test_state *uts, void *, unsigned long,
			   void *, unsigned long, unsigned long *);

static int compress_using_gzip(struct unit_test_state *uts,
			       void *in, unsigned long in_size,
			       void *out, unsigned long out_max,
			       unsigned long *out_size)
{
	int ret;
	unsigned long inout_size = out_max;

	ret = gzip(out, &inout_size, in, in_size);
	if (out_size)
		*out_size = inout_size;

	return ret;
}
#define errcheck(statement) if (!(statement)) { \
