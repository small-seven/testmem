#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#include "timespec.h"
#if !defined(_POSIX_CPUTIME) || _POSIX_CPUTIME == -1
#else
#endif
