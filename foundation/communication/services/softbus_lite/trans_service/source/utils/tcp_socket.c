#include "tcp_socket.h"
#include <arpa/inet.h>
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#include <lwip/sockets.h>
#else
#include <sys/socket.h>
#endif
#include <errno.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include "data_bus_error.h"
#include "os_adapter.h"
#define SEND_BUF_SIZE           0x200000
#define RECV_BUF_SIZE           0x100000
#define USER_TIMEOUT_MS         5000
#define DEFAULT_SEND_TIMEOUT    200
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#endif
