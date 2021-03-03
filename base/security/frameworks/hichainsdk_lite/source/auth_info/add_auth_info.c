#include "add_auth_info.h"
#include <string.h>
#include <securec.h>
#include "log.h"
#include "base.h"
#include "mem_stat.h"
#include "parsedata.h"
#include "commonutil.h"
#include "huks_adapter.h"
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_) || defined(_CUT_ADD_) || defined(_CUT_ADD_SERVER_))
#define HC_ADDAUTH_CIPHER_LEN 32
#define HICHAIN_ADD_INFO_RESPONSE "hichain_add_info_response"
#define HICHAIN_ADD_INFO_REQUEST  "hichain_add_info_request"
#define AUTH_INFO_LENGTH 1000
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#endif
#endif /* _CUT_XXX_ */
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#endif
