#include "auth_info.h"
#include <securec.h>
#include "log.h"
#include "mem_stat.h"
#include "huks_adapter.h"
#define HC_AUTH_DECRYPT_LEN 300
#if !(defined(_CUT_PAKE_) || defined(_CUT_PAKE_SERVER_))
#endif /* _CUT_XXX_ */
#if !(defined(_CUT_STS_) || defined(_CUT_STS_SERVER_))
#endif /* _CUT_XXX_ */
struct auth_info_message *malloc_auth_info_msg(uint32_t size)
{
    struct auth_info_message *data = (struct auth_info_message *)MALLOC(sizeof(struct auth_info_message));
    if (data == NULL) {
        LOGE("Malloc struct remove_response_data failed");
        return NULL;
    }
    (void)memset_s(data, sizeof(*data), 0, sizeof(*data));
    data->cipher.val = (uint8_t *)MALLOC(size);
    if (data->cipher.val == NULL) {
        LOGE("Malloc remove response val failed");
        FREE(data);
        return NULL;
    }
    (void)memset_s(data->cipher.val, size, 0, size);
    data->cipher.size = size;
    data->cipher.length = 0;
    return data;
}
void free_auth_info_msg(struct auth_info_message *data)
{
    FREE(data->cipher.val);
    data->cipher.val = NULL;
    FREE(data);
}
void destroy_auth_client(struct auth_info_cache *auth_info)
{
    if (auth_info == NULL) {
        LOGE("Destroy auth info client object failed");
        return;
    }
    FREE(auth_info);
}
