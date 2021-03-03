#include "includes.h"
#include "common.h"
#include "wpa_supplicant_i.h"
#include "config_ssid.h"
#include "bgscan.h"
#ifdef CONFIG_BGSCAN_SIMPLE
#endif /* CONFIG_BGSCAN_SIMPLE */
#ifdef CONFIG_BGSCAN_LEARN
#endif /* CONFIG_BGSCAN_LEARN */
void bgscan_deinit(struct wpa_supplicant *wpa_s)
{
	if (wpa_s->bgscan && wpa_s->bgscan_priv) {
		wpa_printf(MSG_DEBUG, "bgscan: Deinitializing module '%s'",
			   wpa_s->bgscan->name);
		wpa_s->bgscan->deinit(wpa_s->bgscan_priv);
		wpa_s->bgscan = NULL;
		wpa_s->bgscan_priv = NULL;
	}
}
