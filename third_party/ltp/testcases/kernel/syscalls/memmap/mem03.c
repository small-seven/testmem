#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include "test.h"
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>		/* definitions for open()                               */
#include <sys/mman.h>		/* definitions for mmap()                               */
#include <fcntl.h>		/* definition of open()                                 */
#include <sys/user.h>
#define FAILED       (-1)	/* return status for all funcs indicating failure   */
#define SUCCESS      0		/* return status for all routines indicating success */
