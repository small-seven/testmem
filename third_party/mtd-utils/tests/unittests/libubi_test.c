#include <stdarg.h>
#include <setjmp.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <cmocka.h>
#include "libubi.h"
#include "test_lib.h"
static void test_ubi_vol_block_remove(void **state)
{
	int mock_fd = 1;
	expect_ioctl_short(UBI_IOCVOLRMBLK, 0);
	int r = ubi_vol_block_remove(mock_fd);
	assert_int_equal(r, 0);

	(void) state;
}
