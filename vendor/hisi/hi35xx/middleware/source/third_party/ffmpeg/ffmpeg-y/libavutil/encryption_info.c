#include "encryption_info.h"
#include "mem.h"
#include "intreadwrite.h"
#define FF_ENCRYPTION_INFO_EXTRA 24
void av_encryption_info_free(AVEncryptionInfo *info)
{
    if (info) {
        av_free(info->key_id);
        av_free(info->iv);
        av_free(info->subsamples);
        av_free(info);
    }
}
#define FF_ENCRYPTION_INIT_INFO_EXTRA 16
void av_encryption_init_info_free(AVEncryptionInitInfo *info)
{
    uint32_t i;
    if (info) {
        for (i = 0; i < info->num_key_ids; i++) {
            av_free(info->key_ids[i]);
        }
        av_encryption_init_info_free(info->next);
        av_free(info->system_id);
        av_free(info->key_ids);
        av_free(info->data);
        av_free(info);
    }
}
