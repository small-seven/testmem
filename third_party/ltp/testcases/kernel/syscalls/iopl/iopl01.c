#if defined __i386__ || defined(__x86_64__)
#include <errno.h>
#include <unistd.h>
#include <sys/io.h>
#include "test.h"
#else /* __i386__ */
#include "test.h"
#endif /* __i386__ */
