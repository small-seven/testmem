#include "gtest/gtest.h"
#include "sys/socket.h"
#include "arpa/inet.h"
#include "netinet/tcp.h"
#include "securec.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#define WAIT() pthread_barrier_wait(&g_barrier)
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#else
#endif
