#include <sys/types.h>
#include <sys/mman.h>
#include <sys/resource.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tst_test.h"
#include "lapi/mmap.h"
#define MAP_SIZE (4 * 1024)
#define TEST_FILE "testfile"
#define STR "abcdefghijklmnopqrstuvwxyz12345\n"
#define KSM_SYS_DIR	"/sys/kernel/mm/ksm"
#if !defined(UCLINUX)
#endif /* if !defined(UCLINUX) */
