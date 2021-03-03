#include "includes.h"
#include "common.h"
#include "crypto/ms_funcs.h"
#include "crypto/random.h"
#include "common/wpa_ctrl.h"
#include "mschapv2.h"
#include "eap_i.h"
#include "eap_config.h"
#ifdef _MSC_VER
#pragma pack(push, 1)
#endif /* _MSC_VER */
#ifdef _MSC_VER
#pragma pack(pop)
#endif /* _MSC_VER */
#define MSCHAPV2_OP_CHALLENGE 1
#define MSCHAPV2_OP_RESPONSE 2
#define MSCHAPV2_OP_SUCCESS 3
#define MSCHAPV2_OP_FAILURE 4
#define MSCHAPV2_OP_CHANGE_PASSWORD 7
#define ERROR_RESTRICTED_LOGON_HOURS 646
#define ERROR_ACCT_DISABLED 647
#define ERROR_PASSWD_EXPIRED 648
#define ERROR_NO_DIALIN_PERMISSION 649
#define ERROR_AUTHENTICATION_FAILURE 691
#define ERROR_CHANGING_PASSWORD 709
#define PASSWD_CHANGE_CHAL_LEN 16
#define MSCHAPV2_KEY_LEN 16
#ifdef CONFIG_NO_RC4
#else /* CONFIG_NO_RC4 */
#endif /* CONFIG_NO_RC4 */
