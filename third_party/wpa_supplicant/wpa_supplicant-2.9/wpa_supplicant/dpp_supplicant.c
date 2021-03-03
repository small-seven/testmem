#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "utils/ip_addr.h"
#include "common/dpp.h"
#include "common/gas.h"
#include "common/gas_server.h"
#include "rsn_supp/wpa.h"
#include "rsn_supp/pmksa_cache.h"
#include "wpa_supplicant_i.h"
#include "config.h"
#include "driver_i.h"
#include "offchannel.h"
#include "gas_query.h"
#include "bss.h"
#include "scan.h"
#include "notify.h"
#include "dpp_supplicant.h"
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
static void wpas_dpp_listen_work_free(struct wpas_dpp_listen_work *lwork)
{
	if (!lwork)
		return;
	os_free(lwork);
}
#ifdef CONFIG_DPP2
#ifdef CONFIG_SAE
#else /* CONFIG_SAE */
#endif /* CONFIG_SAE */
#endif /* CONFIG_DPP2 */
#ifndef CONFIG_NO_CONFIG_WRITE
#endif /* CONFIG_NO_CONFIG_WRITE */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
int wpas_dpp_pkex_remove(struct wpa_supplicant *wpa_s, const char *id)
{
	unsigned int id_val;

	if (os_strcmp(id, "*") == 0) {
		id_val = 0;
	} else {
		id_val = atoi(id);
		if (id_val == 0)
			return -1;
	}

	if ((id_val != 0 && id_val != 1) || !wpa_s->dpp_pkex_code)
		return -1;

	/* TODO: Support multiple PKEX entries */
	os_free(wpa_s->dpp_pkex_code);
	wpa_s->dpp_pkex_code = NULL;
	os_free(wpa_s->dpp_pkex_identifier);
	wpa_s->dpp_pkex_identifier = NULL;
	os_free(wpa_s->dpp_pkex_auth_cmd);
	wpa_s->dpp_pkex_auth_cmd = NULL;
	wpa_s->dpp_pkex_bi = NULL;
	/* TODO: Remove dpp_pkex only if it is for the identified PKEX code */
	dpp_pkex_free(wpa_s->dpp_pkex);
	wpa_s->dpp_pkex = NULL;
	return 0;
}
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
