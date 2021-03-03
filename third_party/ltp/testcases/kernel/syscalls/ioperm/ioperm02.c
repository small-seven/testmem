#if defined __i386__ || defined(__x86_64__)
#include <errno.h>
#include <unistd.h>
#include <sys/io.h>
#include <pwd.h>
#include "test.h"
#include "safe_macros.h"
#define NUM_BYTES 3
#define TURN_ON 1
#define TURN_OFF 0
#define EXP_RET_VAL -1
#ifndef IO_BITMAP_BITS
#define IO_BITMAP_BITS 1024	/* set to default value since some H/W may not support 0x10000 even with a 2.6.8 kernel */
#define IO_BITMAP_BITS_16 65536
#endif
#else /* __i386__ */
#include "test.h"
#include "safe_macros.h"
#endif /* __i386__ */
