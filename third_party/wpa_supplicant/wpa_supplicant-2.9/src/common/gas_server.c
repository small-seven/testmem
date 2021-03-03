#include "includes.h"
#include "utils/common.h"
#include "utils/list.h"
#include "utils/eloop.h"
#include "ieee802_11_defs.h"
#include "gas.h"
#include "gas_server.h"
#define MAX_ADV_PROTO_ID_LEN 10
#define GAS_QUERY_TIMEOUT 10
void gas_server_deinit(struct gas_server *gas)
{
	struct gas_server_handler *handler, *tmp;
	struct gas_server_response *response, *tmp_r;

	if (!gas)
		return;

	dl_list_for_each_safe(handler, tmp, &gas->handlers,
			      struct gas_server_handler, list) {
		dl_list_del(&handler->list);
		os_free(handler);
	}

	dl_list_for_each_safe(response, tmp_r, &gas->responses,
			      struct gas_server_response, list) {
		dl_list_del(&response->list);
		gas_server_free_response(response);
	}

	os_free(gas);
}
