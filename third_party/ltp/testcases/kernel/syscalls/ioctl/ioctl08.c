#include "config.h"
#include <stdlib.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "tst_test.h"
#ifdef HAVE_STRUCT_FILE_DEDUPE_RANGE
#include <linux/fs.h>
#define SUCCESS 0
#define MNTPOINT "mnt_point"
#define FILE_SRC_PATH	MNTPOINT"/file_src"
#define FILE_DEST_PATH	MNTPOINT"/file_dest"
#else
#endif
