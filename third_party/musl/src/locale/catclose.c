#define _BSD_SOURCE
#include <nl_types.h>
#include <stdint.h>
#include <endian.h>
#include <sys/mman.h>
#define V(p) be32toh(*(uint32_t *)(p))
