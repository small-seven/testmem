#include <stdio.h>
#ifdef WINDOWS
#include <windows.h>
#include <winioctl.h>
#include <io.h>
#include <process.h>
#include <sys/stat.h>
#include "getopt.h"
#else
#include <sys/types.h>
#include <unistd.h>
#endif
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
#include "defs.h"
#include "globals.h"
#include "sfunc.h"
#include "threading.h"
#include "stats.h"
