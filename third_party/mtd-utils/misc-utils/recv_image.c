#define PROGRAM_NAME "recv_image"
#define _XOPEN_SOURCE 500
#define _BSD_SOURCE	/* struct ip_mreq */
#define _DEFAULT_SOURCE
#include <errno.h>
#include <stdio.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <crc32.h>
#include "mtd/mtd-user.h"
#include "mcast_image.h"
#include "libfec.h"
#include "common.h"
#define WBUF_SIZE 4096
#if 1 /* Deliberately use bad blocks... test write failures */
#endif
