#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "log.h"
#define HILOG_LOGBUFFER 2048
#define HILOG_MAX_FILELEN 2048
#ifdef __LINUX__
#define HILOG_PATH1 "/data/log/hilog1.txt"
#define HILOG_PATH2 "/data/log/hilog2.txt"
#else
#define HILOG_PATH1 "/storage/data/log/hilog1.txt"
#define HILOG_PATH2 "/storage/data/log/hilog2.txt"
#endif
#define HILOG_PERMMISION 0700
#define HILOG_TEST_ARGC 2
#ifdef OHOS_RELEASE
#endif
