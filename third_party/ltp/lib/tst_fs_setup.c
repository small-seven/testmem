#include <dirent.h>
#include <errno.h>
#include <sys/mount.h>
#define TST_NO_DEFAULT_MAIN
#include "tst_test.h"
#include "tst_fs.h"
#define TST_FS_SETUP_OVERLAYFS_MSG "overlayfs is not configured in this kernel"
#define TST_FS_SETUP_OVERLAYFS_CONFIG "lowerdir="OVL_LOWER",upperdir="OVL_UPPER",workdir="OVL_WORK
