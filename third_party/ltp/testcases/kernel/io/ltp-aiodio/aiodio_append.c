#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "config.h"
#include "test.h"
#ifdef HAVE_LIBAIO
#include <libaio.h>
#define NUM_CHILDREN 8
#include "common_checkzero.h"
#define NUM_AIO 16
#define AIO_SIZE 64*1024
#else
#endif
