#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <librttest.h>
#if HAS_PTHREAD_MUTEXTATTR_ROBUST_APIS
#else
#endif
#include "test-skeleton.c"
