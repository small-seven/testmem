#include <ctype.h>
#include <errno.h>
#include <libgen.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#define dbg if (global_debug >= 3) \
#define out if (global_debug >= 2) \
#define wrn if (global_debug >= 1) \
#define err if (global_debug >= 0) \
#define assert_arg(A) \
