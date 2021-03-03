#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>		/* for _SC_OPEN_MAX */
#include "test.h"
#include "safe_macros.h"
#define OPEN_MAX (sysconf(_SC_OPEN_MAX))
#ifdef DEBUG
#endif
