#include "includes.h"
#include "common.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "wps/wps_defs.h"
#include "p2p_i.h"
#include "p2p.h"
#define MAX_PROV_DISC_REQ_RETRIES 120
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
#define P2PS_PD_REQ_CHECK(_val, _attr) \
#undef P2PS_PD_REQ_CHECK
#define P2PS_PD_RESP_CHECK(_val, _attr) \
#undef P2PS_PD_RESP_CHECK
void p2ps_prov_free(struct p2p_data *p2p)
{
	os_free(p2p->p2ps_prov);
	p2p->p2ps_prov = NULL;
}
