#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include "tst_test.h"
#include "lapi/mmap.h"
#define MEMCG_PATH "/sys/fs/cgroup/memory/"
#define PAGES 128
#define TOUCHED_PAGE1 0
#define TOUCHED_PAGE2 10
