#include "includes.h"
#include "common.h"
#include "config.h"
#include "wpa_supplicant_i.h"
#include "bss.h"
#include "scan.h"
#include "autoscan.h"
#ifdef CONFIG_AUTOSCAN_EXPONENTIAL
#endif /* CONFIG_AUTOSCAN_EXPONENTIAL */
#ifdef CONFIG_AUTOSCAN_PERIODIC
#endif /* CONFIG_AUTOSCAN_PERIODIC */
void autoscan_deinit(struct wpa_supplicant *wpa_s)
{
	if (wpa_s->autoscan && wpa_s->autoscan_priv) {
		wpa_printf(MSG_DEBUG, "autoscan: Deinitializing module '%s'",
			   wpa_s->autoscan->name);
		wpa_s->autoscan->deinit(wpa_s->autoscan_priv);
		wpa_s->autoscan = NULL;
		wpa_s->autoscan_priv = NULL;

		wpa_s->scan_interval = 5;

		os_free(wpa_s->sched_scan_plans);
		wpa_s->sched_scan_plans = NULL;
		wpa_s->sched_scan_plans_num = 0;
	}
}
