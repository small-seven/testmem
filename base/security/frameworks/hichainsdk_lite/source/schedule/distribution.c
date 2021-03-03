#include "distribution.h"
#include <securec.h>
#include "log.h"
#include "pake_client.h"
#include "pake_server.h"
#include "sts_server.h"
#include "exchange_auth_info.h"
#include "exchange_auth_info_client.h"
#include "add_auth_info.h"
#include "remove_auth_info.h"
#include "add_auth_info_client.h"
#include "remove_auth_info_client.h"
#ifdef DESC
#undef DESC
#endif
#define DESC(...) 1
typedef int32_t (*proc_message_func)(struct hichain *handle, struct header_analysis *nav,
    struct message *receive, struct message *send);

struct message_code_map {
    uint32_t code;
    int32_t modular;
    bool is_request_msg;
};
#if DESC("interface")
#endif /* DESC */
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#define CUT_EMPTY_FUNC(d_name) \
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_CLIENT_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_) || defined(_CUT_EXCHANGE_) || defined(_CUT_EXCHANGE_SERVER_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_CLIENT_) || defined(_CUT_EXCHANGE_) || defined(_CUT_EXCHANGE_CLIENT_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_STS_) || defined(_CUT_STS_CLIENT_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_) || defined(_CUT_ADD_) || defined(_CUT_ADD_SERVER_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
static int32_t proc_remove_request_message(struct hichain *handle, struct header_analysis *nav,
    struct message *receive, struct message *send)
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_) || defined(_CUT_REMOVE_) || defined(_CUT_REMOVE_SERVER_))
{
    DBG_OUT("Object %u proc remove auth info request message", sts_server_sn(handle->sts_server));
    (void)nav;
    int32_t ret = send_remove_response(handle, receive, send);

    DBG_OUT("Object %u proc remove auth info message, error code is %d", sts_server_sn(handle->sts_server), ret);
    return ret;
}
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_STS_) || defined(_CUT_STS_CLIENT_) || defined(_CUT_ADD_) || defined(_CUT_ADD_CLIENT_))
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
static int32_t proc_remove_response_message(struct hichain *handle, struct header_analysis *nav,
                                            struct message *receive, struct message *send)
#if !(defined(_CUT_STS_) || defined(_CUT_STS_CLIENT_) || defined(_CUT_REMOVE_) || defined(_CUT_REMOVE_CLIENT_))
{
    (void)nav;
    int32_t ret = receive_remove_response(handle, receive);
    if (ret != HC_OK) {
        LOGE("Object %u proc add auth info request message, error code is %d",
             sts_client_sn(handle->sts_client), ret);
        return ret;
    }
    send->msg_code = INVALID_MESSAGE; /* remove_auth_info receives data and process ends, does not need to send */

    return HC_OK;
}
#else /* _CUT_XXX_ */
#endif /* _CUT_XXX_ */
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else /* _SUPPORT_SEC_ */
#endif /* _SUPPORT_SEC_ */
