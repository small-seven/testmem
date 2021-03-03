#define _XOPEN_SOURCE 600
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/resource.h>
#include "test.h"
#include "config.h"
#ifdef HAVE_LIBAIO
#include <libaio.h>
#define mapsize (1 << 14)
#else
#endif
