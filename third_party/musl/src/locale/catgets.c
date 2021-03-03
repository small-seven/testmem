#define _BSD_SOURCE
#include <nl_types.h>
#include <endian.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#define V(p) be32toh(*(uint32_t *)(p))
