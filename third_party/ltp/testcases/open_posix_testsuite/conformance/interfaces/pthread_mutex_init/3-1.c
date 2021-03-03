#include <pthread.h>
#include <stdio.h>
#include <errno.h>
#include "posixtest.h"
typedef struct my_data {
	pthread_mutex_t mutex;	/* Protects access to value */
	int value;		/* Access protected by mutex */
} my_data_t;
