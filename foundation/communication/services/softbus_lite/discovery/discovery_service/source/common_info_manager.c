#include "common_info_manager.h"
#include "coap_discover.h"
#include "discovery_error.h"
#include "discovery_service.h"
#include "hks_client.h"
#include "nstackx.h"
#include "os_adapter.h"
#include "securec.h"
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#include "utils_file.h"
#else
#include <fcntl.h>
#include <unistd.h>
#endif
#define MAX_VALUE_SIZE 64
#define DEVICEID_MAX_NUM 96
#define DEVICE_ID_FILE   "/storage/data/softbus/deviceid"
#define TWO_NUM 2
#define NUM_TEN 10
#define FOUR_BIT 4
#define NUM_SIXTEEN 16
#if defined(__LITEOS_A__) || defined(__LINUX__)
#endif
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#endif
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#endif
#if defined(__LITEOS_A__) || defined(__LINUX__)
#endif
#if defined(__LITEOS_M__) || defined(__LITEOS_RISCV__)
#else
#endif
void DeinitCommonManager(void)
{
    if (g_deviceInfo != NULL) {
        free(g_deviceInfo);
        g_deviceInfo = NULL;
    }
}
void ListRemoveNode(List *node)
{
    if (node == NULL) {
        return;
    }
    node->next->prev = node->prev;
    node->prev->next = node->next;
    node->next = NULL;
    node->prev = NULL;
}
