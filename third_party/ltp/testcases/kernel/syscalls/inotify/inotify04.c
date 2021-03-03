#include "config.h"
#if defined(HAVE_SYS_INOTIFY_H)
# include <sys/inotify.h>
#endif
#include <errno.h>
#include <string.h>
#include "tst_test.h"
#include "inotify.h"
#if defined(HAVE_SYS_INOTIFY_H)
#define EVENT_MAX 1024
#define EVENT_SIZE  (sizeof(struct inotify_event))
#define EVENT_BUF_LEN        (EVENT_MAX * (EVENT_SIZE + 16))
#define BUF_SIZE 256
#define	TEST_DIR	"test_dir"
#define	TEST_FILE	"test_file"
#else
#endif /* defined(HAVE_SYS_INOTIFY_H) */
