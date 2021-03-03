#define _GNU_SOURCE
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <limits.h>
#include <getopt.h>
#include "config.h"
#include "test.h"
#include "safe_macros.h"
#ifdef HAVE_LIBAIO
#include <libaio.h>
#define NUM_CHILDREN 1000
#include "common_sparse.h"
#else
#endif
