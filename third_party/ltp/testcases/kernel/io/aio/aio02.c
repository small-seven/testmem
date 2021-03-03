#include "config.h"
#include "tst_test.h"
#ifdef HAVE_LIBAIO
#include <errno.h>
#include <stdlib.h>
#include <libaio.h>
#define AIO_MAXIO 32
#define AIO_BLKSIZE (64*1024)
#define DESC_FLAGS_OPR(x, y) .desc = (x == IO_CMD_PWRITE ? "WRITE: " #y: "READ : " #y), \
#else
#endif
