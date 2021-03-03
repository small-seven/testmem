#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "test.h"
#include "safe_macros.h"
#define PATH_ZRAM	"/sys/block/zram0"
#define OBSOLETE_ZRAM_FILE	"/sys/block/zram0/num_reads"
#define PATH_ZRAM_STAT	"/sys/block/zram0/stat"
#define PATH_ZRAM_MM_STAT	"/sys/block/zram0/mm_stat"
#define SIZE		(512 * 1024 * 1024L)
#define DEVICE		"/dev/zram0"
