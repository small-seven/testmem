#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/modes.h>
#include "../crypto/modes/modes_local.h"
#include "testutil.h"
#include "internal/nelem.h"
typedef struct {
    size_t size;
    const unsigned char *data;
}  SIZED_DATA;
#define CTS128_TEST_VECTOR(len)                 \
typedef struct {
    const char *case_name;
    size_t (*last_blocks_correction)(const unsigned char *in,
                                     unsigned char *out, size_t len);
    size_t (*encrypt_block)(const unsigned char *in,
                            unsigned char *out, size_t len,
                            const void *key, unsigned char ivec[16],
                            block128_f block);
    size_t (*encrypt_stream)(const unsigned char *in, unsigned char *out,
                             size_t len, const void *key,
                             unsigned char ivec[16], cbc128_f cbc);
    size_t (*decrypt_block)(const unsigned char *in,
                            unsigned char *out, size_t len,
                            const void *key, unsigned char ivec[16],
                            block128_f block);
    size_t (*decrypt_stream)(const unsigned char *in, unsigned char *out,
                             size_t len, const void *key,
                             unsigned char ivec[16], cbc128_f cbc);
} CTS128_FIXTURE;
# define K2 K1
# define A2 A1
# define IV2 IV1
# define A3 A2
# define K4 K3
# define IV4 IV3
# define K5 K4
# define P5 P4
# define A5 A4
# define K6 K5
# define P6 P5
# define A6 A5
# define K8 K7
# define IV8 IV7
# define A8 A7
# define A9 A8
# define K10 K9
# define IV10 IV9
# define K11 K10
# define P11 P10
# define A11 A10
# define K12 K11
# define P12 P11
# define A12 A11
# define K14 K13
# define A14 A13
# define A15 A14
# define K16 K15
# define IV16 IV15
# define K17 K16
# define P17 P16
# define A17 A16
# define K18 K17
# define P18 P17
# define A18 A17
# define K19 K1
# define P19 P1
# define IV19 IV1
# define C19 C1
# define K20 K1
# define A20 A1
#define GCM128_TEST_VECTOR(n)                   \
