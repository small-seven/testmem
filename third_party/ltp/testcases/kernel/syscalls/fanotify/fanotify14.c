#define _GNU_SOURCE
#include "tst_test.h"
#include "fanotify.h"
#include <errno.h>
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define MNTPOINT "mntpoint"
#define FILE1 MNTPOINT"/file1"
#define INODE_EVENTS (FAN_ATTRIB | FAN_CREATE | FAN_DELETE | FAN_MOVE | \
#else
#endif
