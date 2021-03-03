#include "includes.h"
#include "common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/gas.h"
#include "common/wpa_ctrl.h"
#include "rsn_supp/wpa.h"
#include "wpa_supplicant_i.h"
#include "config.h"
#include "driver_i.h"
#include "offchannel.h"
#include "gas_query.h"
#define GAS_QUERY_TIMEOUT_PERIOD 2
#define GAS_QUERY_WAIT_TIME_INITIAL 1000
#define GAS_QUERY_WAIT_TIME_COMEBACK 150
static void gas_query_free(struct gas_query_pending *query, int del_list)
{
	struct gas_query *gas = query->gas;

	if (del_list)
		dl_list_del(&query->list);

	if (gas->work && gas->work->ctx == query) {
		radio_work_done(gas->work);
		gas->work = NULL;
	}

	wpabuf_free(query->req);
	wpabuf_free(query->adv_proto);
	wpabuf_free(query->resp);
	os_free(query);
}
void gas_query_deinit(struct gas_query *gas)
{
	struct gas_query_pending *query, *next;

	if (gas == NULL)
		return;

	dl_list_for_each_safe(query, next, &gas->pending,
			      struct gas_query_pending, list)
		gas_query_done(gas, query, GAS_QUERY_DELETED_AT_DEINIT);

	os_free(gas);
}
