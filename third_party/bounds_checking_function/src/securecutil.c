#include "securecutil.h"
#if defined(ANDROID) && (SECUREC_HAVE_WCTOMB || SECUREC_HAVE_MBTOWC)
#include <wchar.h>
#if SECUREC_HAVE_WCTOMB
#endif
#if SECUREC_HAVE_MBTOWC
#endif
#endif
#define SECUREC_C_VERSION     0x500U
#define SECUREC_SPC_VERSION   0xaU
#define SECUREC_VERSION_STR   "V100R001C01SPC010B002"
#if SECUREC_IN_KERNEL
#endif
