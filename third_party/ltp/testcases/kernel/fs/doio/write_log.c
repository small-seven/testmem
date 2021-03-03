#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <sys/param.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "write_log.h"
#ifndef BSIZE
#ifdef DEV_BSIZE
#define BSIZE DEV_BSIZE
#else
#warning DEV_BSIZE is not defined, defaulting to 512
#define BSIZE 512
#endif
#endif
#ifndef PATH_MAX
#define PATH_MAX          255
#endif
#if __STDC__
#else
#endif
