#include <securec.h>
#include "commonutil.h"
#include "distribution.h"
#include "log.h"
#include "parsedata.h"
#include "jsonutil.h"
#include "auth_info.h"
#include "add_auth_info.h"
#include "build_object.h"
#include "mem_stat.h"
#include "huks_adapter.h"
#include "sec_clone_server.h"
#define LIST_TRUST_PEER_DEF_COUNT 0
#define FREE_SEND_DATA_FUNC(name) \
#define FREE_SEC_SEND_DATA_FUNC(name) \
#ifdef DESC
#undef DESC
#endif
#define DESC(...) 1
#if DESC("api")
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_) || defined(_CUT_EXCHANGE_) || defined(_CUT_EXCHANGE_SERVER_))
#endif
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_) || defined(_CUT_EXCHANGE_) || defined(_CUT_EXCHANGE_SERVER_))
#endif
DLL_API_PUBLIC void destroy(hc_handle *handle)
{
    LOGI("Begin destroy");
    check_ptr_return(handle);
    check_ptr_return(*handle);
    struct hichain *hichain = (struct hichain *)*handle;

    if (hichain->pake_server != NULL) {
        destroy_pake_server(hichain->pake_server);
    }
    if (hichain->pake_client != NULL) {
        destroy_pake_client(hichain->pake_client);
    }
    if (hichain->sts_server != NULL) {
        destroy_sts_server(hichain->sts_server);
    }
    if (hichain->sts_client != NULL) {
        destroy_sts_client(hichain->sts_client);
    }
    if (hichain->auth_info != NULL) {
        destroy_auth_client(hichain->auth_info);
    }
    if (hichain->sec_clone_server != NULL) {
        destroy_sec_clone_server(hichain->sec_clone_server);
    }
    FREE(hichain);
    *handle = NULL;
    LOGI("End destroy");
}
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
int32_t remove_auth_info(hc_handle handle, const struct operation_parameter *params,
    const struct hc_auth_id *auth_id, int32_t user_type)
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
{
    LOGI("Begin remove auth info");
    check_ptr_return_val(handle, HC_INPUT_ERROR);
    check_ptr_return_val(params, HC_INPUT_ERROR);
    check_ptr_return_val(auth_id, HC_INPUT_ERROR);
    struct hichain *hichain = (struct hichain *)handle;

    int32_t ret = build_object(hichain, STS_MODULAR, true, params);
    if (ret != HC_OK) {
        LOGE("Build sts client sub object failed, error code is %d", ret);
        return ret;
    }

    struct auth_info_cache auth_info = {
        .user_type = user_type,
        .auth_id = *auth_id
    };
    ret = build_object(hichain, REMOVE_MODULAR, true, &auth_info);
    if (ret != HC_OK) {
        LOGE("Build remove client sub object failed, error code is %d", ret);
        return ret;
    }

    ret = triggered_sts_client(hichain, REMOVE_AUTHINFO);
    LOGI("Triggered sts client error code is %d", ret);
    LOGI("End remove auth info");
    return ret;
}
#else
#endif
#ifndef _CUT_API_
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
#endif /* _CUT_XXX_ */
#endif /* DESC */
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_CLIENT_))
#else
#endif
#if !(defined(_CUT_STS_) || defined(_CUT_STS_CLIENT_))
#else
#endif
typedef void *(*parse_message_func)(const char *pay_load, enum json_object_data_type type);
struct parse_message_map {
    enum message_code msg_code;
    parse_message_func parse_message;
};
typedef void (*free_message_func)(void *obj);
struct free_message_map {
    enum message_code msg_code;
    free_message_func free_message;
};
static void destroy_receive_data_struct(const struct message *message)
{
    const struct free_message_map map[] = { { PAKE_REQUEST, free_pake_request },
                                            { PAKE_RESPONSE, free_pake_response },
                                            { PAKE_CLIENT_CONFIRM, free_pake_client_confirm },
                                            { PAKE_SERVER_CONFIRM_RESPONSE, free_pake_server_confirm },
                                            { AUTH_START_REQUEST, free_auth_start_request },
                                            { AUTH_START_RESPONSE, free_auth_start_response },
                                            { AUTH_ACK_REQUEST, free_auth_ack_request },
                                            { AUTH_ACK_RESPONSE, free_auth_ack_response },
                                            { ADD_AUTHINFO_REQUEST, free_add_auth_info_request },
                                            { REMOVE_AUTHINFO_REQUEST, free_rmv_auth_info_request },
                                            { ADD_AUTHINFO_RESPONSE, free_add_auth_info_response },
                                            { REMOVE_AUTHINFO_RESPONSE, free_rmv_auth_info_response },
                                            { EXCHANGE_REQUEST, free_exchange_request },
                                            { EXCHANGE_RESPONSE, free_exchange_response },
                                            { SEC_CLONE_START_REQUEST, sec_clone_free_client_request },
                                            { SEC_CLONE_ACK_REQUEST, sec_clone_free_client_ack } };

    for (uint32_t i = 0; i < sizeof(map) / sizeof(struct free_message_map); i++) {
        if (map[i].msg_code == message->msg_code) {
            map[i].free_message(message->payload);
        }
    }
}
typedef char *(*make_message_func)(void *data);
struct make_message_map {
    enum message_code msg_code;
    make_message_func make_message;
};
static void destroy_send_data(struct message *message)
{
    if (message->payload == NULL) {
        return;
    }

    switch (message->msg_code) {
        case ADD_AUTHINFO_RESPONSE: {
            add_response_data *add_res_data = message->payload;
            FREE_SEND_DATA_FUNC(add_res_data); /* add_res_data */
        }
        case ADD_AUTHINFO_REQUEST: {
            add_request_data *add_req_data = message->payload;
            FREE_SEND_DATA_FUNC(add_req_data); /* add_req_data */
        }
        case REMOVE_AUTHINFO_RESPONSE: {
            remove_response_data *rmv_auth_info_res_data = message->payload;
            FREE_SEND_DATA_FUNC(rmv_auth_info_res_data); /* rmv_auth_info_res_data */
        }
        case REMOVE_AUTHINFO_REQUEST: {
            remove_request_data *rmv_auth_info_req_data = message->payload;
            FREE_SEND_DATA_FUNC(rmv_auth_info_req_data); /* rmv_auth_info_req_data */
        }
        case EXCHANGE_RESPONSE: {
            exchange_response_data *exchange_response = message->payload;
            FREE_SEND_DATA_FUNC(exchange_response); /* exchange_response */
        }
        case EXCHANGE_REQUEST: {
            exchange_request_data *exchange_requeset = message->payload;
            FREE_SEND_DATA_FUNC(exchange_requeset); /* exchange_requeset */
        }
        case SEC_CLONE_START_RESPONSE: {
            struct uint8_buff *data = message->payload;
            FREE_SEC_SEND_DATA_FUNC(data); /* data */
        }
        case SEC_CLONE_ACK_RESPONSE: {
            struct uint8_buff *data = message->payload;
            FREE_SEC_SEND_DATA_FUNC(data); /* data */
        }
        default:
            break;
    }

    if (message->payload != NULL) {
        FREE(message->payload);
        message->payload = NULL;
    }
}
#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#else
#endif
