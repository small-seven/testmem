#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <pwd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <mqueue.h>
#include "include_j_h.h"
#include "test.h"
#define barrier() __asm__ __volatile__("": : :"memory")
#define WITH_SIGNALS_BLOCKED(code) {					\
#define MIN_SWAPFILE_SIZE	(64 * 1024)
#if 0
#endif
