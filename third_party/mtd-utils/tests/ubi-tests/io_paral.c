#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libubi.h"
#define PROGRAM_NAME "io_paral"
#include "common.h"
#include "helpers.h"
#define THREADS_NUM 4
#define ITERATIONS  (1024 * 1)
#define VOL_LEBS    10
