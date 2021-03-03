#include "time_impl.h"
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "libc.h"
#include <pthread.h>
#define VEC(...) ((const unsigned char[]){__VA_ARGS__})
