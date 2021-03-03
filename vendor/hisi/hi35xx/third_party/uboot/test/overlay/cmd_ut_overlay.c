#include <common.h>
#include <command.h>
#include <errno.h>
#include <fdt_support.h>
#include <malloc.h>
#include <linux/sizes.h>
#include <test/ut.h>
#include <test/overlay.h>
#include <test/suites.h>
#define FDT_COPY_SIZE	(4 * SZ_1K)
