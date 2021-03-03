#include "config.h"
#include <stdarg.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <utime.h>
#include "test.h"
#include "safe_file_ops_fn.h"
#ifndef HAVE_UTIMENSAT
#endif
#ifdef HAVE_UTIMENSAT
#else
#endif
