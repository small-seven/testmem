#include "avb_rsa.h"
#include "avb_sha.h"
#include "avb_util.h"
#include "avb_vbmeta_image.h"
typedef struct IAvbKey {
  unsigned int len; /* Length of n[] in number of uint32_t */
  uint32_t n0inv;   /* -1 / n[0] mod 2^32 */
  uint32_t* n;      /* modulus as array (host-byte order) */
  uint32_t* rr;     /* R^2 as array (host-byte order) */
} IAvbKey;
