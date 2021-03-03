#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include "posixtest.h"
#define RETURN_CODE ((void *)100)
#define INTHREAD 0		/* Control going to or is already for Thread */
#define INMAIN 1		/* Control going to or is already for Main */
