#include "net_device_adapter.h"
#include <lwip/netif.h>
#include <lwip/pbuf.h>
#include <lwip/opt.h>
#include <lwip/netifapi.h>
#include "osal_mem.h"
#include "net_device.h"
#include "securec.h"
#define HDF_LOG_TAG NetDeviceLite
#define FREE_SPACE_SIZE 2
static int32_t LiteNetDevDeInit(struct NetDeviceImpl *netDeviceImpl)
{
    if (netDeviceImpl == NULL) {
        HDF_LOGE("netdevice lite deinit aready free.");
        return HDF_SUCCESS;
    }
    if (netDeviceImpl->osPrivate != NULL) {
        OsalMemFree(netDeviceImpl->osPrivate);
        netDeviceImpl->osPrivate = NULL;
    }
    HDF_LOGI("net device lite deinit success!");
    return HDF_SUCCESS;
}
static struct netif *CreateLwipNetIf(const struct NetDeviceImpl *netDeviceImpl, const struct NetDevice *netDev)
{
    if (netDev == NULL) {
        HDF_LOGE("%s : netDev = null!", __func__);
        return NULL;
    }
    struct netif *lwipNf = NULL;
    lwipNf = OsalMemCalloc(sizeof(struct netif));
    if (lwipNf == NULL) {
        HDF_LOGE("%s fail : netif malloc fail!", __func__);
        return NULL;
    }
    (void)memset_s(lwipNf, sizeof(struct netif), 0, sizeof(struct netif));

    /* register netif to lwip */
    lwipNf->state = (void *)netDeviceImpl;
    lwipNf->drv_send = LwipSend;
    lwipNf->drv_set_hwaddr = LwipSetHwaddr;
    lwipNf->link_layer_type = WIFI_DRIVER_IF;
    lwipNf->hwaddr_len = MAC_ADDR_SIZE;
    lwipNf->drv_config = LwipDrvConfig;
#if LOSCFG_NET_LWIP_SACK_2_0
    if (strncpy_s(lwipNf->name, IFNAMSIZ, netDev->name, IFNAMSIZ - FREE_SPACE_SIZE) != EOK) {
        HDF_LOGE("lite netif add fail : strncpy_s fail!");
        OsalMemFree(lwipNf);
        return NULL;
    }
    lwipNf->name[IFNAMSIZ - FREE_SPACE_SIZE] = '\0';
#endif
    return lwipNf;
}
static void DestroyLwipNetIf(struct netif *lwipNf)
{
    if (lwipNf == NULL) {
        return;
    }
    OsalMemFree(lwipNf);
    return;
}
#ifdef _PRE_WLAN_FEATURE_LWIP_IPV6_AUTOCONFIG
#endif
#if LOSCFG_NET_LWIP_SACK_2_0
#endif
