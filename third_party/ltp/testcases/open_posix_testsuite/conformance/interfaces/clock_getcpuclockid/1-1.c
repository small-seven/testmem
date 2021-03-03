#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "posixtest.h"
#define LARGENUMBER 900000
#if !defined(_POSIX_CPUTIME) || _POSIX_CPUTIME == -1
#else
#endif
