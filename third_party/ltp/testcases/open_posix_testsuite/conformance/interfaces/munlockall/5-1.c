#include <unistd.h>
#include <sys/mman.h>
#include <stdio.h>
#include <errno.h>
#include "posixtest.h"
#if !defined(_POSIX_MEMLOCK) || _POSIX_MEMLOCK == -1
#else
#if _POSIX_MEMLOCK != 0
#else
#endif
#endif
