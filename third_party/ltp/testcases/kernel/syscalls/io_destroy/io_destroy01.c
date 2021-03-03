#include <errno.h>
#include <string.h>
#include "config.h"
#include "tst_test.h"
#ifdef HAVE_LIBAIO
#include <libaio.h>
static void verify_io_destroy(void)
{
	io_context_t ctx;

	memset(&ctx, 0xff, sizeof(ctx));

	TEST(io_destroy(ctx));
	if (TST_RET == 0) {
		tst_res(TFAIL, "io_destroy() succeeded unexpectedly");
		return;
	}

	if (TST_RET == -EINVAL) {
		tst_res(TPASS,
			"io_destroy() failed as expected, returned -EINVAL");
	} else {
		tst_res(TFAIL, "io_destroy() failed unexpectedly, "
			"returned -%s expected -EINVAL",
			tst_strerrno(-TST_RET));
	}
}
#else
#endif
