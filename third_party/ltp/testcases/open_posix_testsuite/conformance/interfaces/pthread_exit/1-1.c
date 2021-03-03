#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "posixtest.h"
#define RETURN_CODE 100		/* Set a random return code number. This shall be the return code of the
#define INTHREAD 0		/* Control going to or is already for Thread */
#define INMAIN 1		/* Control going to or is already for Main */
