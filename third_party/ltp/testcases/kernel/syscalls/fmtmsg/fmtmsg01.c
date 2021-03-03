#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#if !defined(__UCLIBC__)
#include <fmtmsg.h>		/* interface definition */
#endif
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "test.h"
#define FAILED 0
#define PASSED 1
#if !defined(__UCLIBC__)
#else
#endif /* if !defined(__UCLIBC__) */
