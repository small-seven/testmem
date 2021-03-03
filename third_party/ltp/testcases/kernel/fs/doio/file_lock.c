#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <sys/param.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/sysmacros.h>
#include <string.h>		/* memset, strerror */
#include "file_lock.h"
#ifndef EFSEXCLWR
#define EFSEXCLWR	503
#endif
#ifdef EFILESH
#endif
#ifdef EFILESH
#endif
