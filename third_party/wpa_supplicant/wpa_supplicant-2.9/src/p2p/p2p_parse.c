#include "includes.h"
#include "common.h"
#include "common/ieee802_11_defs.h"
#include "common/ieee802_11_common.h"
#include "wps/wps_i.h"
#include "p2p_i.h"
#ifdef CONFIG_WIFI_DISPLAY
#endif /* CONFIG_WIFI_DISPLAY */
void p2p_parse_free(struct p2p_message *msg)
{
	wpabuf_free(msg->p2p_attributes);
	msg->p2p_attributes = NULL;
	wpabuf_free(msg->wps_attributes);
	msg->wps_attributes = NULL;
#ifdef CONFIG_WIFI_DISPLAY
	wpabuf_free(msg->wfd_subelems);
	msg->wfd_subelems = NULL;
#endif /* CONFIG_WIFI_DISPLAY */
}
