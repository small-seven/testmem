#include <string.h>
#include "crypto/chacha.h"
#include "crypto/ctype.h"
typedef unsigned int u32;
typedef unsigned char u8;
typedef union {
    u32 u[16];
    u8 c[64];
} chacha_buf;
# define ROTATE(v, n) (((v) << (n)) | ((v) >> (32 - (n))))
# define U32TO8_LITTLE(p, v) do { \
# define QUARTERROUND(a,b,c,d) ( \
