#include "includes.h"
#include <assert.h>
#include "common.h"
#include "utils/ext_password.h"
#include "common/version.h"
#include "crypto/tls.h"
#include "config.h"
#include "eapol_supp/eapol_supp_sm.h"
#include "eap_peer/eap.h"
#include "eap_server/eap_methods.h"
#include "eloop.h"
#include "utils/base64.h"
#include "rsn_supp/wpa.h"
#include "wpa_supplicant_i.h"
#include "radius/radius.h"
#include "radius/radius_client.h"
#include "common/wpa_ctrl.h"
#include "ctrl_iface.h"
#include "pcsc_funcs.h"
#include "wpas_glue.h"
#if defined(CONFIG_CTRL_IFACE) || !defined(CONFIG_NO_STDOUT_DEBUG)
#else /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#define eapol_test_eap_param_needed NULL
#endif /* CONFIG_CTRL_IFACE || !CONFIG_NO_STDOUT_DEBUG */
#if defined(CONFIG_NATIVE_WINDOWS) || defined(CONFIG_ANSI_C_EXTRA)
#else /* CONFIG_NATIVE_WINDOWS or CONFIG_ANSI_C_EXTRA */
#endif /* CONFIG_NATIVE_WINDOWS or CONFIG_ANSI_C_EXTRA */
#ifdef PCSC_FUNCS
#endif /* PCSC_FUNCS */
#define num_triplets 5
#define AKA_RAND_LEN 16
#define AKA_AUTN_LEN 16
#define AKA_AUTS_LEN 14
#define RES_MAX_LEN 16
#define IK_LEN 16
#define CK_LEN 16
#undef num_triplets
#ifdef CONFIG_AP
#endif /* CONFIG_AP */
