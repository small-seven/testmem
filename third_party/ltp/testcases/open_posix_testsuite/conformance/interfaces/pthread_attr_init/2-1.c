#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "posixtest.h"
#define TIMEOUT 5		/* Timeout value of 5 seconds. */
#define INTHREAD 0		/* Control going to or is already for Thread */
#define INMAIN 1		/* Control going to or is already for Main */
