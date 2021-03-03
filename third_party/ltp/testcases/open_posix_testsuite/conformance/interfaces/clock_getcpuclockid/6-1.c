#include <sys/types.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#if !defined(_POSIX_CPUTIME) || _POSIX_CPUTIME == -1
#else
#endif
