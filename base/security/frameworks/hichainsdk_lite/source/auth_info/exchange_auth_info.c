#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_) || defined(_CUT_EXCHANGE_) || defined(_CUT_EXCHANGE_SERVER_))
#include "exchange_auth_info.h"
#include <securec.h>
#include "log.h"
#include "base.h"
#include "mem_stat.h"
#include "parsedata.h"
#include "huks_adapter.h"
#ifdef DESC
#undef DESC
#endif
#define DESC(...) 1
#define HC_EXCHANGE_RESPONSE_LEN 1024
#define HICHAIN_EXCHANGE_REQUEST  "hichain_exchange_request"
#define HICHAIN_EXCHANGE_RESPONSE "hichain_exchange_response"
#if DESC("interface")
#endif /* DESC */
typedef const struct hc_auth_id *read_only_auth_id;
static int32_t get_self_key_id(const struct hichain *hichain, read_only_auth_id *auth_id, struct ltpk *ltpk);
static int32_t build_auth_info(struct uint8_buff *auth_info, const struct hc_auth_id *auth_id, struct ltpk *ltpk);
static int32_t sign_self_public_key(const struct hichain *hichain, struct uint8_buff *auth_info,
    const struct hc_auth_id *auth_id, struct signature *sign_result);
static int32_t build_exchange_response_data(const struct hichain *hichain, exchange_response_data *send)
{
    const struct hc_auth_id *auth_id = NULL;
    struct ltpk ltpk;
    int32_t ret = get_self_key_id(hichain, &auth_id, &ltpk);
    if (ret != HC_OK) {
        LOGE("Get ltpk and self auth id failed, error code is %d", ret);
        return ret;
    }
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
typedef void (*COPY_CHALLENGE)(struct uint8_buff *sign_src_data, const struct challenge *peer_challenge,
    const struct challenge *self_challenge);
static int32_t generate_sign_src_data(const struct hichain *hichain, struct uint8_buff *auth_info,
    COPY_CHALLENGE copy_func, struct uint8_buff *sign_src_data);
static void copy_self_peer_challenge(struct uint8_buff *sign_src_data, const struct challenge *peer_challenge,
    const struct challenge *self_challenge);
static int32_t sign_self_public_key(const struct hichain *hichain, struct uint8_buff *auth_info,
    const struct hc_auth_id *auth_id, struct signature *sign_result)
{
    struct uint8_buff sign_src_data;
    int32_t ret = generate_sign_src_data(hichain, auth_info, copy_self_peer_challenge, &sign_src_data);
    if (ret != HC_OK) {
        LOGE("Generate self signature source data failed, error code is %d", ret);
        return ret;
    }
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
#endif /* _CUT_XXX_ */
