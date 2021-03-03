#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "mcast_image.h"
#include "libfec.h"
#include <crc32.h>
#define ERASE_SIZE 131072
#define NR_PKTS ((ERASE_SIZE + PKT_SIZE - 1) / PKT_SIZE)
#define DROPS 8
#if 1
#endif
