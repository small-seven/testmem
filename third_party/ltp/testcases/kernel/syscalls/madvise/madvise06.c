#include <errno.h>
#include <stdio.h>
#include <sys/mount.h>
#include <sys/sysinfo.h>
#include "tst_test.h"
#define CHUNK_SZ (400*1024*1024L)
#define CHUNK_PAGES (CHUNK_SZ / pg_sz)
#define PASS_THRESHOLD (CHUNK_SZ / 4)
#define MNT_NAME "memory"
#define GROUP_NAME "madvise06"
