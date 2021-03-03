#include "utils/includes.h"
#include "utils/common.h"
#include "utils/eloop.h"
#include "common/dpp.h"
#include "common/gas.h"
#include "common/wpa_ctrl.h"
#include "hostapd.h"
#include "ap_drv_ops.h"
#include "gas_query_ap.h"
#include "gas_serv.h"
#include "wpa_auth.h"
#include "dpp_hostapd.h"
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
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
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
int hostapd_dpp_pkex_remove(struct hostapd_data *hapd, const char *id)
{
	unsigned int id_val;

	if (os_strcmp(id, "*") == 0) {
		id_val = 0;
	} else {
		id_val = atoi(id);
		if (id_val == 0)
			return -1;
	}

	if ((id_val != 0 && id_val != 1) || !hapd->dpp_pkex_code)
		return -1;

	/* TODO: Support multiple PKEX entries */
	os_free(hapd->dpp_pkex_code);
	hapd->dpp_pkex_code = NULL;
	os_free(hapd->dpp_pkex_identifier);
	hapd->dpp_pkex_identifier = NULL;
	os_free(hapd->dpp_pkex_auth_cmd);
	hapd->dpp_pkex_auth_cmd = NULL;
	hapd->dpp_pkex_bi = NULL;
	/* TODO: Remove dpp_pkex only if it is for the identified PKEX code */
	dpp_pkex_free(hapd->dpp_pkex);
	hapd->dpp_pkex = NULL;
	return 0;
}
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
#ifdef CONFIG_TESTING_OPTIONS
#endif /* CONFIG_TESTING_OPTIONS */
#ifdef CONFIG_DPP2
#endif /* CONFIG_DPP2 */
