#include "hctest.h"
#include "lwip/sockets.h"
#include "lwip/inet.h"
#include "lwip/tcp.h"
#include "securec.h"
#include "cmsis_os2.h"
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#define LOCAL_HOST "127.0.0.1"
#define STACK_PORT 2277
#define STACK_IP LOCAL_HOST
#define PEER_PORT STACK_PORT
#define PEER_IP LOCAL_HOST
#define UDP_MSG "Hi, I am UDP"
#define SRV_MSG "Hi, I am TCP server"
#define CLI_MSG "Hi, I am TCP client"
#define BUF_SIZE (1024 * 8)
#define LWIP_TEST_SUCCESS 0
#define LWIP_TEST_FAIL (-1)
#define DEF_TASK_STACK 2000
#define DEF_TASK_PRIORITY 20
#define ONE_SECOND 1
#define TIMEOUT 4
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#else
#endif
