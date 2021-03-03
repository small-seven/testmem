#include <unistd.h>
#include <math.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>
#include "../libcontrollers/libcontrollers.h"
#ifdef VERBOSE
#define verbose(x...) printf(x)
#else
#define verbose(x...) do {} while (0);
#endif
#define NUM_TIMES 200		/* How many intervals you want to check */
#define INTERVALS 1		/* How many milliseconds interval in iterations */
#define USECONDS  1000		/* microseconds to sleep */
#define info	printf("The results FAIL is just intuitive and not exact" \
