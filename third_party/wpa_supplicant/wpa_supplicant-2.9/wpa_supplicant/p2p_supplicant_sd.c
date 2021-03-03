#include "utils/includes.h"
#include "utils/common.h"
#include "p2p/p2p.h"
#include "wpa_supplicant_i.h"
#include "notify.h"
#include "p2p_supplicant.h"
#define DNS_HEADER_LEN 12
#define P2P_SD_IN_MEMORY_LEN 27
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#define MAX_WFD_SD_SUBELEMS 20
#endif /* CONFIG_WIFI_DISPLAY */
static void wpas_p2p_srv_bonjour_free(struct p2p_srv_bonjour *bsrv)
{
	dl_list_del(&bsrv->list);
	wpabuf_free(bsrv->query);
	wpabuf_free(bsrv->resp);
	os_free(bsrv);
}
static void wpas_p2p_srv_upnp_free(struct p2p_srv_upnp *usrv)
{
	dl_list_del(&usrv->list);
	os_free(usrv->service);
	os_free(usrv);
}
