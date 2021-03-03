#include "includes.h"
#include "common.h"
#include "utils/eloop.h"
#include "utils/list.h"
#include "common/ieee802_11_defs.h"
#include "common/gas.h"
#include "common/wpa_ctrl.h"
#include "hostapd.h"
#include "sta_info.h"
#include "ap_drv_ops.h"
#include "gas_query_ap.h"
#define GAS_QUERY_TIMEOUT_PERIOD 2
#define GAS_QUERY_WAIT_TIME_INITIAL 1000
#define GAS_QUERY_WAIT_TIME_COMEBACK 150
static void gas_query_free(struct gas_query_pending *query, int del_list)
{
	if (del_list)
		dl_list_del(&query->list);

	wpabuf_free(query->req);
	wpabuf_free(query->adv_proto);
	wpabuf_free(query->resp);
	os_free(query);
}
