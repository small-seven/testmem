#include <stdio.h>
#include <string.h>
#include "avassert.h"
#include "avstring.h"
#include "common.h"
#include "pixfmt.h"
#include "pixdesc.h"
#include "internal.h"
#include "intreadwrite.h"
#include "version.h"
#if FF_API_PLUS1_MINUS1
#endif
#if FF_API_VAAPI
#else
#endif
#define BAYER8_DESC_COMMON \
#define BAYER16_DESC_COMMON \
#if FF_API_PLUS1_MINUS1
#endif
#if HAVE_BIGENDIAN
#   define X_NE(be, le) be
#else
#   define X_NE(be, le) le
#endif
#if FF_API_VAAPI
#endif
#define FF_COLOR_NA      -1
#define FF_COLOR_RGB      0 /**< RGB color space */
#define FF_COLOR_GRAY     1 /**< gray color space */
#define FF_COLOR_YUV      2 /**< YUV color space. 16 <= Y <= 235, 16 <= U, V <= 240 */
#define FF_COLOR_YUV_JPEG 3 /**< YUV color space. 0 <= Y <= 255, 0 <= U, V <= 255 */
#define FF_COLOR_XYZ      4
#define pixdesc_has_alpha(pixdesc) \
