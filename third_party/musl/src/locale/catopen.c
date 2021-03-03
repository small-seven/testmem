#define _BSD_SOURCE
#include <nl_types.h>
#include <string.h>
#include <stdint.h>
#include <endian.h>
#include <errno.h>
#include <langinfo.h>
#include <locale.h>
#include <sys/mman.h>
#include "libc.h"
#define V(p) be32toh(*(uint32_t *)(p))
