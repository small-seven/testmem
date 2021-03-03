#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define CLEANUP_NOTCALLED 0
#define CLEANUP_CALLED 1
#define INTHREAD 0		/* Control going to or is already for Thread */
#define INMAIN 1		/* Control going to or is already for Main */
