#include "includes.h"
#include "utils/common.h"
#include "utils/list.h"
#include "utils/eloop.h"
#include "common/ieee802_11_common.h"
#include "wpa_supplicant_i.h"
#include "bss.h"
#include "driver_i.h"
#include "wmm_ac.h"
#define PARAM_IN_RANGE(field, min_value, max_value) \
#undef PARAM_IN_RANGE
static void wmm_ac_deinit(struct wpa_supplicant *wpa_s)
{
	int i;

	for (i = 0; i < WMM_AC_NUM; i++)
		wmm_ac_del_ts(wpa_s, i, TS_DIR_IDX_ALL);

	/* delete pending add_ts request */
	wmm_ac_del_req(wpa_s, 1);

	os_free(wpa_s->wmm_ac_assoc_info);
	wpa_s->wmm_ac_assoc_info = NULL;
}
