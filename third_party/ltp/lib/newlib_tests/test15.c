#include <stdint.h>
#include <pthread.h>
#include "tst_test.h"
#include "tst_atomic.h"
#define THREADS 64
#define FILLER (1 << 20)
