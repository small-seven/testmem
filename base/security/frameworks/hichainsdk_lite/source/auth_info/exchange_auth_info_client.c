#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_CLIENT_) || defined(_CUT_EXCHANGE_) || defined(_CUT_EXCHANGE_CLIENT_))
#include "exchange_auth_info_client.h"
#include <securec.h>
#include "log.h"
#include "base.h"
#include "mem_stat.h"
#include "parsedata.h"
#include "commonutil.h"
#include "huks_adapter.h"
#ifdef DESC
#undef DESC
#endif
#define DESC(...) 1
#define HC_EXCHANGE_REQUEST_LEN 1024
#define HICHAIN_EXCHANGE_REQUEST  "hichain_exchange_request"
#define HICHAIN_EXCHANGE_RESPONSE "hichain_exchange_response"
#if DESC("interface")
#endif /* DESC */
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
typedef void (*COPY_CHALLENGE)(struct uint8_buff *sign_src_data, const struct challenge *peer_challenge,
    const struct challenge *self_challenge);
static int32_t generate_sign_src_data(const struct hichain *hichain, struct uint8_buff *auth_info,
    COPY_CHALLENGE copy_func, struct uint8_buff *sign_src_data);
static void copy_peer_self_challenge(struct uint8_buff *sign_src_data, const struct challenge *peer_challenge,
    const struct challenge *self_challenge);
static int32_t verify_peer_public_key(const struct hichain *hichain, struct uint8_buff *auth_info,
    struct signature *sign_result, struct ltpk *ltpk)
{
    struct uint8_buff sign_src_data;
    int32_t ret = generate_sign_src_data(hichain, auth_info, copy_peer_self_challenge, &sign_src_data);
    if (ret != HC_OK) {
        LOGE("Generate peer signature source data failed, error code is %d", ret);
        return ret;
    }
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
#else /* _CUT_XXX_ */
#include "exchange_auth_info_client.h"
#include "log.h"
#endif /* _CUT_XXX_ */
