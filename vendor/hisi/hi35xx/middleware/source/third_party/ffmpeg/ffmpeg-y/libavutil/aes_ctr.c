#include "common.h"
#include "aes_ctr.h"
#include "aes.h"
#include "random_seed.h"
#define AES_BLOCK_SIZE (16)
typedef struct AVAESCTR {
    struct AVAES* aes;
    uint8_t counter[AES_BLOCK_SIZE];
    uint8_t encrypted_counter[AES_BLOCK_SIZE];
    int block_offset;
} AVAESCTR;
void av_aes_ctr_free(struct AVAESCTR *a)
{
    if (a) {
        av_freep(&a->aes);
        av_free(a);
    }
}
