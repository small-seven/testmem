#include "avformat.h"
#include "libavutil/aes.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "url.h"
#define MAX_BUFFER_BLOCKS 257
#define BLOCKSIZE 16
typedef struct CryptoContext {
    const AVClass *class;
    URLContext *hd;
    uint8_t inbuffer [BLOCKSIZE*MAX_BUFFER_BLOCKS],
            outbuffer[BLOCKSIZE*MAX_BUFFER_BLOCKS];
    uint8_t *outptr;
    int indata, indata_used, outdata;
    int64_t position;  // position in file - used in seek
    int flags;
    int eof;
    uint8_t *key;
    int keylen;
    uint8_t *iv;
    int ivlen;
    uint8_t *decrypt_key;
    int decrypt_keylen;
    uint8_t *decrypt_iv;
    int decrypt_ivlen;
    uint8_t *encrypt_key;
    int encrypt_keylen;
    uint8_t *encrypt_iv;
    int encrypt_ivlen;
    struct AVAES *aes_decrypt;
    struct AVAES *aes_encrypt;
    uint8_t *write_buf;
    unsigned int write_buf_size;
    uint8_t pad[BLOCKSIZE];
    int pad_len;
} CryptoContext;
#define OFFSET(x) offsetof(CryptoContext, x)
#define D AV_OPT_FLAG_DECODING_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
