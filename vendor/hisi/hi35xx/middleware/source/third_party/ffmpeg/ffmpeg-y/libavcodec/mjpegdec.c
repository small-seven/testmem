#include "libavutil/imgutils.h"
#include "libavutil/avassert.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "blockdsp.h"
#include "copy_block.h"
#include "hwaccel.h"
#include "idctdsp.h"
#include "internal.h"
#include "jpegtables.h"
#include "mjpeg.h"
#include "mjpegdec.h"
#include "jpeglsdec.h"
#include "profiles.h"
#include "put_bits.h"
#include "tiff.h"
#include "exif.h"
#include "bytestream.h"
#if CONFIG_MJPEG_NVDEC_HWACCEL
#endif
#if CONFIG_MJPEG_VAAPI_HWACCEL
#endif
#define REFINE_BIT(j) {                                             \
#define ZERO_RUN                                                    \
#undef REFINE_BIT
#undef ZERO_RUN
#if CONFIG_MJPEG_DECODER
#define OFFSET(x) offsetof(MJpegDecodeContext, x)
#define VD AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_DECODING_PARAM
#if CONFIG_MJPEG_NVDEC_HWACCEL
#endif
#if CONFIG_MJPEG_VAAPI_HWACCEL
#endif
#endif
#if CONFIG_THP_DECODER
#endif
