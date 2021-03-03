#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/ieee802_11_defs.h"
#include "common/wpa_ctrl.h"
#include "config.h"
#include "wpa_supplicant_i.h"
#include "driver_i.h"
#include "wps_supplicant.h"
#include "p2p_supplicant.h"
#include "p2p/p2p.h"
#include "hs20_supplicant.h"
#include "notify.h"
#include "bss.h"
#include "scan.h"
#include "mesh.h"
#ifdef CONFIG_WPS
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_WPS
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#endif /* CONFIG_WPS */
#ifdef CONFIG_HS20
#endif /* CONFIG_HS20 */
#ifdef CONFIG_FST
#endif /* CONFIG_FST */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_OWE
#endif /* CONFIG_OWE */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_P2P
#endif /* CONFIG_P2P */
#ifdef CONFIG_INTERWORKING
#endif /* CONFIG_INTERWORKING */
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifdef CONFIG_MBO
#endif /* CONFIG_MBO */
#define GREAT_SNR 25
#define IS_5GHZ(n) (n > 4000)
#define MIN(a,b) a < b ? a : b
#undef MIN
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
#ifndef CONFIG_NO_STDOUT_DEBUG
#endif /* CONFIG_NO_STDOUT_DEBUG */
#define DEFAULT_NOISE_FLOOR_2GHZ (-89)
#define DEFAULT_NOISE_FLOOR_5GHZ (-92)
#ifdef CONFIG_WPS
#endif /* CONFIG_WPS */
void wpa_scan_free_params(struct wpa_driver_scan_params *params)
{
	size_t i;

	if (params == NULL)
		return;

	for (i = 0; i < params->num_ssids; i++)
		os_free((u8 *) params->ssids[i].ssid);
	os_free((u8 *) params->extra_ies);
	os_free(params->freqs);
	os_free(params->filter_ssids);
	os_free(params->sched_scan_plans);

	/*
	 * Note: params->mac_addr_mask points to same memory allocation and
	 * must not be freed separately.
	 */
	os_free((u8 *) params->mac_addr);

	os_free((u8 *) params->bssid);

	os_free(params);
}
