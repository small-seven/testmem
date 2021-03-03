#define _GNU_SOURCE
#include "config.h"
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/statfs.h>
#include <sys/types.h>
#include "tst_test.h"
#include "fanotify.h"
#if defined(HAVE_SYS_FANOTIFY_H)
#include <sys/fanotify.h>
#define EVENT_MAX 10
#define EVENT_SIZE (sizeof(struct fanotify_event_metadata) + \
#define EVENT_BUF_LEN (EVENT_MAX * EVENT_SIZE * 2)
#define MOUNT_POINT "mntpoint"
#define TEST_DIR MOUNT_POINT"/test_dir"
#define DIR1 TEST_DIR"/dir1"
#define DIR2 TEST_DIR"/dir2"
#define FILE1 TEST_DIR"/file1"
#define FILE2 TEST_DIR"/file2"
#if defined(HAVE_NAME_TO_HANDLE_AT)
#else
#endif
#else
#endif
