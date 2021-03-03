#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>
#include "syscall.h"
#define IS32BIT(x) !((x)+0x80000000ULL>>32)
#define CLAMP(x) (int)(IS32BIT(x) ? (x) : 0x7fffffffU+((0ULL+(x))>>63))
