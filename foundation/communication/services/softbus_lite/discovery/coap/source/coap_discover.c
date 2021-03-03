#include "coap_discover.h"
#include "coap_adapter.h"
#include "coap_socket.h"
#include "json_payload.h"
#include "nstackx_common.h"
#include "nstackx_device.h"
#include "nstackx_error.h"
#include "os_adapter.h"
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#include "lwip/sockets.h"
#include "lwip/netif.h"
#include "lwip/netifapi.h"
#include "wifi_device.h"
#include "wifi_hotspot_config.h"
#include <los_task.h>
#else
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#endif
#include <securec.h>
#define WIFI_QUEUE_SIZE  5
#define MIN_STACK_SIZE 0x8000
typedef struct {
    WIFI_PROC_FUNC     handler;
    AddressEvent       state;
} AddressEventHandler;
#define WLAN "wlan0"
#define ETH "eth0"
#define COAP_DEFAULT_PRIO 11
#define TEN_MS  (10 * 1000)
typedef struct CoapRequest {
    const char *remoteUrl;
    char *data;
    size_t dataLength;
    const char *remoteIp;
} CoapRequest;
#define TIME_MICRO_SEC 10000
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
typedef void *(*Runnable)(void *argv);
typedef struct ThreadAttr ThreadAttr;
struct ThreadAttr {
    const char *name;
    uint32_t stackSize;
    uint8_t priority;
    uint8_t reserved1;
    uint16_t reserved2;
};
int CreateThread(Runnable run, void *argv, const ThreadAttr *attr, unsigned int *threadId)
{
    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    pthread_attr_setstacksize(&threadAttr, (attr->stackSize | MIN_STACK_SIZE));
    struct sched_param sched = {attr->priority};
    pthread_attr_setschedparam(&threadAttr, &sched);
    int errCode = pthread_create((pthread_t *)threadId, &threadAttr, run, argv);
    return errCode;
}
#define IP_LEN 16
#endif
int CreateCoapListenThread(void)
{
    g_terminalFlag = 1;
    if (g_coapTaskId != -1) {
        return NSTACKX_EOK;
    }
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
    unsigned int ret;
    TSK_INIT_PARAM_S listenTask;
    listenTask.pfnTaskEntry = (TSK_ENTRY_FUNC)CoapReadHandle;
    listenTask.uwStackSize  = LOSCFG_BASE_CORE_TSK_DEFAULT_STACK_SIZE;
    listenTask.pcName = "coap_listen_task";
    listenTask.usTaskPrio = COAP_DEFAULT_PRIO;
    listenTask.uwResved = LOS_TASK_STATUS_DETACHED;
    ret = LOS_TaskCreate((unsigned int*)&g_coapTaskId, &listenTask);
    if (ret != 0) {
        g_terminalFlag = 0;
        SOFTBUS_PRINT("[DISCOVERY] create task fail\n");
        return NSTACKX_EFAILED;
    }
#else
    ThreadAttr attr = {"coap_listen_task", 0x800, 20, 0, 0};
    int error = CreateThread((Runnable)CoapReadHandle, NULL, &attr, (unsigned int*)&g_coapTaskId);
    if (error != 0) {
        g_terminalFlag = 0;
        SOFTBUS_PRINT("[DISCOVERY] create task fail\n");
        return NSTACKX_EFAILED;
    }
#endif
    return NSTACKX_EOK;
}
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#endif
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#endif
int CoapDeinitDiscovery(void)
{
    ExitCoapListenThread();
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
    int rtn = CoapDeinitWifiEvent();
    if (rtn  != NSTACKX_EOK) {
        return NSTACKX_EFAILED;
    }
#endif
    CoapDeinitSocket();
    return NSTACKX_EOK;
}
#define GET_IP_TIMES 300
#define GET_IP_INFINITE (-1)
