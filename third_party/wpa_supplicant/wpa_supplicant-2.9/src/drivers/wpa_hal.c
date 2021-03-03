#include "wpa_hal.h"
#include "includes.h"
#include "driver.h"
#include "ap/hostapd.h"
#include "l2_packet/l2_packet.h"
#include "eloop.h"
#include "wpa_hal_cmd.h"
#include "wpa_hal_service.h"
#include "wpa_hal_event.h"
#include "securec.h"
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
static void WifiKeyExtFree(WifiKeyExt **key)
{
    if (key == NULL || *key == NULL) {
        return;
    }

    if ((*key)->addr != NULL) {
        os_free((*key)->addr);
        (*key)->addr = NULL;
    }
    if ((*key)->seq != NULL) {
        os_free((*key)->seq);
        (*key)->seq = NULL;
    }
    if ((*key)->key != NULL) {
        os_free((*key)->key);
        (*key)->key = NULL;
    }

    os_free(*key);
    *key = NULL;
}
static void WifiWpaDeinit(void *priv)
{
    WifiDriverData *drv = NULL;
    WifiSetNewDev info;

    if (priv == NULL) {
        return;
    }

    drv = (WifiDriverData *)priv;
    info.status = FALSE;
    info.ifType = WIFI_IFTYPE_STATION;
    info.mode = WIFI_PHY_MODE_11N;
    WifiWpaCmdSetNetdev(drv->iface, &info);

    if (drv->eapolSock != NULL) {
        l2_packet_deinit(drv->eapolSock);
    }

    os_free(g_wifiDriverData);
    g_wifiDriverData = NULL;
    WpaMsgServiceDeinit();
    wpa_printf(MSG_INFO, "WifiWpaDeinit done");
}
static void WifiWpaConnectFree(WifiAssociateParams **params)
{
    if (params == NULL || *params == NULL) {
        return;
    }

    if ((*params)->ie != NULL) {
        os_free((*params)->ie);
        (*params)->ie = NULL;
    }
    if ((*params)->crypto != NULL) {
        os_free((*params)->crypto);
        (*params)->crypto = NULL;
    }
    if ((*params)->ssid != NULL) {
        os_free((*params)->ssid);
        (*params)->ssid = NULL;
    }
    if ((*params)->bssid != NULL) {
        os_free((*params)->bssid);
        (*params)->bssid = NULL;
    }
    if ((*params)->key != NULL) {
        os_free((*params)->key);
        (*params)->key = NULL;
    }

    os_free(*params);
    *params = NULL;
}
static void WifiWpaHwFeatureDataFree(struct hostapd_hw_modes **modes, uint16_t num)
{
    uint16_t loop;

    if (modes == NULL || *modes == NULL) {
        return;
    }
    for (loop = 0; loop < num; ++loop) {
        if ((*modes)[loop].channels != NULL) {
            os_free((*modes)[loop].channels);
            (*modes)[loop].channels = NULL;
        }
        if ((*modes)[loop].rates != NULL) {
            os_free((*modes)[loop].rates);
            (*modes)[loop].rates = NULL;
        }
    }
    os_free(*modes);
    *modes = NULL;
}
static void WifiWpaScanFree(WifiScan **scan)
{
    if (scan == NULL || *scan == NULL) {
        return;
    }

    if ((*scan)->ssids != NULL) {
        os_free((*scan)->ssids);
        (*scan)->ssids = NULL;
    }
    if ((*scan)->bssid != NULL) {
        os_free((*scan)->bssid);
        (*scan)->bssid = NULL;
    }

    if ((*scan)->extraIes != NULL) {
        os_free((*scan)->extraIes);
        (*scan)->extraIes = NULL;
    }

    if ((*scan)->freqs != NULL) {
        os_free((*scan)->freqs);
        (*scan)->freqs = NULL;
    }

    os_free(*scan);
    *scan = NULL;
}
static void WifiApSettingsFree(WifiApSetting **apsettings)
{
    if (apsettings == NULL || *apsettings == NULL) {
        return;
    }

    if ((*apsettings)->meshSsid != NULL) {
        os_free((*apsettings)->meshSsid);
        (*apsettings)->meshSsid = NULL;
    }

    if ((*apsettings)->ssid != NULL) {
        os_free((*apsettings)->ssid);
        (*apsettings)->ssid = NULL;
    }

    if ((*apsettings)->beaconData.head != NULL) {
        os_free((*apsettings)->beaconData.head);
        (*apsettings)->beaconData.head = NULL;
    }

    if ((*apsettings)->beaconData.tail != NULL) {
        os_free((*apsettings)->beaconData.tail);
        (*apsettings)->beaconData.tail = NULL;
    }

    os_free(*apsettings);
    *apsettings = NULL;
}
static void WifiWpaHapdDeinit(void *priv)
{
    int32_t ret;
    WifiDriverData *drv = NULL;
    WifiSetMode setMode;
    WifiSetNewDev info;

    if (priv == NULL) {
        return;
    }

    (void)memset_s(&setMode, sizeof(WifiSetMode), 0, sizeof(WifiSetMode));
    drv = (WifiDriverData *)priv;
    setMode.iftype = WIFI_IFTYPE_STATION;
    info.status = FALSE;
    info.ifType = WIFI_IFTYPE_AP;
    info.mode = WIFI_PHY_MODE_11N;

    WifiWpaCmdSetNetdev(drv->iface, &info);
    ret = WifiWpaCmdSetMode((char *)drv->iface, &setMode);
    if (ret != SUCC) {
        return;
    }

    if (drv->eapolSock != NULL) {
        l2_packet_deinit(drv->eapolSock);
    }
    os_free(g_wifiDriverData);
    g_wifiDriverData = NULL;
    WpaMsgServiceDeinit();
    wpa_printf(MSG_INFO, "WifiWpaHapdDeinit done");
}
static int32_t WifiWpaStaRemove(void *priv, const uint8_t *addr)
{
    WifiDriverData *drv = NULL;
    int32_t ret;

    if ((priv == NULL) || (addr == NULL)) {
        return -EFAIL;
    }
    drv = (WifiDriverData *)priv;
    ret = WifiWpaCmdStaRemove(drv->iface, addr, ETH_ADDR_LEN);
    if (ret != SUCC) {
        return -EFAIL;
    }
    wpa_printf(MSG_INFO, "WifiWpaStaRemove done, ret=%d", ret);
    return ret;
}
static void WifiActionDataBufFree(WifiActionData *actionData)
{
    if (actionData == NULL) {
        return;
    }
    if (actionData->data != NULL) {
        os_free(actionData->data);
        actionData->data = NULL;
    }
}
#ifdef __cplusplus
#if __cplusplus
#endif
#endif
