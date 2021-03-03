#if (defined(_SUPPORT_SEC_CLONE_) || defined(_SUPPORT_SEC_CLONE_SERVER_))
#include "sec_clone_server.h"
#include <stdlib.h>
#include <string.h>
#include <securec.h>
#include "hks_client.h"
#include "huks_adapter.h"
#include "log.h"
#include "commonutil.h"
#include "distribution.h"
#include "hichain.h"
#define MAX_ITER_COUNT 10
void destroy_sec_clone_server(struct sec_clone_server *handle)
{
    if (handle == NULL) {
        return;
    }

    if (handle->start_request_data.val != NULL) {
        FREE(handle->start_request_data.val);
        handle->start_request_data.val = NULL;
    }

    if (handle->client_sec_data.val != NULL) {
        FREE(handle->client_sec_data.val);
        handle->client_sec_data.val = NULL;
    }

    if (handle->need_clean_temp_key) {
        struct hc_key_alias *temp_key_alias = &(handle->cert_key_alias);
        clear_temp_key(temp_key_alias);
        handle->need_clean_temp_key = false;
    }

    FREE(handle);
}
#else
#include "sec_clone_server.h"
#include "log.h"
#include "mem_stat.h"
void destroy_sec_clone_server(struct sec_clone_server *handle)
{
    LOGE("Donot support sec clone protocol");
    FREE(handle);
}
#endif
