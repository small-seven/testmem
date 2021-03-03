#define PROGRAM_NAME "serve_image"
#define _POSIX_C_SOURCE 200112L
#include <time.h>
#include <errno.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <sys/mman.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <crc32.h>
#include <inttypes.h>
#include <common.h>
#include "mcast_image.h"
#include "libfec.h"
#undef RANDOMDROP
#ifdef RANDOMDROP
#endif
#ifdef RANDOMDROP
#endif
#if 1
#else
#endif
