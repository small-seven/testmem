#include "auth_conn_manager.h"
#include <arpa/inet.h>
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#include <los_task.h>
#include <lwip/sockets.h>
#else
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/time.h>
#endif
#include <stdbool.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/types.h>
#include <unistd.h>
#include "data_bus_error.h"
#include "os_adapter.h"
#include "tcp_socket.h"
#define DEFAULT_BACKLOG    4
#define SESSIONPORT        0
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#endif
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#define MIN_STACK_SIZE 0x8000
typedef void *(*Runnable)(void *argv);
typedef struct ThreadAttr ThreadAttr;
struct ThreadAttr {
    const char *name;   // name of the thread
    uint32_t stackSize;   // size of stack
    uint8_t priority;     // initial thread priority
    uint8_t reserved1;    // reserved1 (must be 0)
    uint16_t reserved2;   // reserved2 (must be 0)
};
typedef void *ThreadId;

ThreadId AuthCreate(Runnable run, const ThreadAttr *attr)
{
    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    pthread_attr_setstacksize(&threadAttr, (attr->stackSize | MIN_STACK_SIZE));
    struct sched_param sched = {attr->priority};
#endif
