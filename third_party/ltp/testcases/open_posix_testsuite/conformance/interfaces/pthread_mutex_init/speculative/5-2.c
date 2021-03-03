#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdarg.h>
#include <sys/utsname.h>
#include <string.h>
#include "../../testfrmw/testfrmw.h"
#include "../../testfrmw/testfrmw.c"
#ifndef VERBOSE
#define VERBOSE 1
#endif
#ifndef PTS_UNSUPPORTED
#define PTS_UNSUPPORTED 4
#endif
#ifndef PTS_UNTESTED
#define PTS_UNTESTED 5
#endif
#if VERBOSE > 0
#endif
