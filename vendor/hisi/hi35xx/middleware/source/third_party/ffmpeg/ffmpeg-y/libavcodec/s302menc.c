#include "avcodec.h"
#include "internal.h"
#include "mathops.h"
#include "put_bits.h"
#define AES3_HEADER_LEN 4
typedef struct S302MEncContext {
    uint8_t framing_index; /* Set for even channels on multiple of 192 samples */
} S302MEncContext;
