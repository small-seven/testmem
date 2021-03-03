#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "lapi/syscalls.h"
#include "test.h"
#define NUMBER_OF_ENVIRON (sizeof(environ_list)/sizeof(char *))
#if defined(linux) && defined(__i386__)
#else /* if defined(linux) && defined(__i386__) */
#endif /* if defined(linux) && defined(__i386__) */
