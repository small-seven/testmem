#if defined __i386__ || defined(__x86_64__)
#include <errno.h>
#include <unistd.h>
#include <sys/io.h>
#include "test.h"
#define NUM_BYTES 3		/* number of bytes from start address */
#define TURN_ON 1
#define TURN_OFF 0
#ifndef IO_BITMAP_BITS
#define IO_BITMAP_BITS 1024
#endif
#else /* __i386__ */
#include "test.h"
#endif /* __i386__ */
