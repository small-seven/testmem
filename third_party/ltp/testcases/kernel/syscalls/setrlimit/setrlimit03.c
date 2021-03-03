#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <linux/fs.h>
#include "tst_test.h"
#if !defined(NR_OPEN)
# define NR_OPEN (1024*1024)
#endif
#define NR_OPEN_PATH "/proc/sys/fs/nr_open"
