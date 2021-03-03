#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include "config.h"
#include "test.h"
#if HAVE_LIBCRYPTO
#include <openssl/sha.h>
#define MAX_EVENT_SIZE (1024*1024)
#define EVENT_HEADER_SIZE 32
#define MAX_EVENT_DATA_SIZE (MAX_EVENT_SIZE - EVENT_HEADER_SIZE)
#define NUM_PCRS 8		/*  PCR registers 0-7 in boot aggregate */
#if MAX_EVENT_DATA_SIZE < USHRT_MAX
#endif
#else
#endif
