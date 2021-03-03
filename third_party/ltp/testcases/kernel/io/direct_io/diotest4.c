#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/file.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/syscall.h>
#include <errno.h>
#include "diotest_routines.h"
#include "test.h"
#include "safe_macros.h"
#include "lapi/mmap.h"
#ifdef O_DIRECT
#define BUFSIZE 	4096
#define TRUE	1
#define LEN	30
#ifdef __GNUC__
#define ADDRESS_OF_MAIN __builtin_extract_return_addr(__builtin_return_address(0))
#else
#define ADDRESS_OF_MAIN main
#endif
#else /* O_DIRECT */
#endif /* O_DIRECT */
