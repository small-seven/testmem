#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <pwd.h>
#include <time.h>
#include <limits.h>
#include "sched.h"
#define MAXPROCS   100
#define PRIINC     2
#define MAX_PRI    55		/* was 50 */
#define MIN_PRI    75		/* was 64 */
#define DEFAULT_STRESS_PERCENTAGE	0.5
#define DEFAULT_PROCESS_SLOTS		16
#define DEFAULT_TIME			1.00
#define USAGE "Usage:  %s  [-s n] [-p n] [-t n] [-d] [-v]              \n" \
#if defined(_IA64) && !defined(__64BIT__)
#else
#endif
#if defined(_IA64) && !defined(__64BIT__)
#else
#endif
#if defined(_IA64) && !defined(__64BIT__)
#else
#endif
#if 0
#endif
