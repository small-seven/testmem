#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <signal.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "lapi/mmap.h"
#define MB (1<<20)
#define PAGE_SIZE getpagesize()
#define barrier() __asm__ __volatile__("": : :"memory")
#define TEST_SFILE "ltp_numa_testfile"
#define STR "abcdefghijklmnopqrstuvwxyz12345\n"
