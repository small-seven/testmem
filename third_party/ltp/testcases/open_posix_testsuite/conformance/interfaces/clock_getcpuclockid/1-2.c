#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#if !defined(_POSIX_CPUTIME) || _POSIX_CPUTIME == -1
#else
#endif
