#include <string.h>
#include <sys/types.h>
#include <mfx/mfxvideo.h>
#include "libavutil/common.h"
#include "libavutil/hwcontext.h"
#include "libavutil/hwcontext_qsv.h"
#include "libavutil/mem.h"
#include "libavutil/log.h"
#include "libavutil/time.h"
#include "libavutil/imgutils.h"
#include "libavcodec/bytestream.h"
#include "avcodec.h"
#include "internal.h"
#include "qsv.h"
#include "qsv_internal.h"
#include "qsvenc.h"
#if QSV_VERSION_ATLEAST(1, 15)
#endif
#if QSV_VERSION_ATLEAST(1, 4)
#endif
#if QSV_VERSION_ATLEAST(1, 8)
#endif
#if QSV_HAVE_AVBR
#endif
#if QSV_HAVE_LA
#endif
#if QSV_HAVE_ICQ
#endif
#if QSV_HAVE_VCM
#endif
#if QSV_VERSION_ATLEAST(1, 10)
#endif
#if QSV_HAVE_LA_HRD
#endif
#if QSV_HAVE_QVBR
#endif
#if QSV_HAVE_CO2
#endif
#if QSV_HAVE_CO3
#endif
#if QSV_HAVE_VCM
#endif
#if QSV_HAVE_AVBR
#endif
#if QSV_HAVE_LA
#if QSV_HAVE_LA_HRD
#endif
#endif
#if QSV_HAVE_ICQ
#endif
#if QSV_HAVE_QVBR
#endif
#if QSV_HAVE_CO2
#if QSV_HAVE_MAX_SLICE_SIZE
#endif
#if QSV_HAVE_TRELLIS
#endif
#if QSV_HAVE_VDENC
#endif
#if QSV_VERSION_ATLEAST(1, 8)
#endif
#if QSV_VERSION_ATLEAST(1, 9)
#endif
#endif
#if QSV_HAVE_GPB
#endif
#if QSV_HAVE_VCM
#endif
#if QSV_HAVE_LA
#if QSV_HAVE_ICQ
#endif
#endif
#if QSV_HAVE_ICQ
#endif
#if QSV_HAVE_AVBR
#endif
#if QSV_HAVE_QVBR
#endif
#define UNMATCH(x) (param_out.mfx.x != q->param.mfx.x)
#if QSV_HAVE_VDENC
#else
#endif
#if QSV_HAVE_VCM
#endif
#if QSV_HAVE_QVBR
#endif
#if QSV_HAVE_QVBR
#endif
#if QSV_HAVE_AVBR
#endif
#if QSV_HAVE_LA
#if QSV_HAVE_ICQ
#endif
#endif
#if FF_API_CODER_TYPE
#endif
#if QSV_HAVE_CO2
#if QSV_HAVE_MAX_SLICE_SIZE
#endif
#if QSV_HAVE_TRELLIS
#endif
#if QSV_VERSION_ATLEAST(1, 8)
#if FF_API_PRIVATE_OPT
#endif
#endif
#if QSV_VERSION_ATLEAST(1, 9)
#endif
#endif
#if QSV_HAVE_MF
#endif
#if QSV_HAVE_CO3
#if QSV_HAVE_GPB
#endif
#endif
#if QSV_HAVE_CO2
#endif
#if QSV_HAVE_CO3
#endif
#if QSV_HAVE_CO_VPS
#endif
#if QSV_HAVE_CO2
#endif
#if QSV_HAVE_CO3
#endif
#if QSV_HAVE_CO_VPS
#endif
#if QSV_HAVE_CO_VPS
#endif
#if QSV_HAVE_CO_VPS
#endif
#if QSV_HAVE_CO_VPS
#endif
#if QSV_VERSION_ATLEAST(1, 26)
#endif
#if QSV_VERSION_ATLEAST(1, 26)
#endif
#if QSV_VERSION_ATLEAST(1, 26)
#endif
#if QSV_VERSION_ATLEAST(1, 26)
#endif
#if QSV_VERSION_ATLEAST(1, 26)
#endif
#if FF_API_CODED_FRAME
#endif
#if QSV_VERSION_ATLEAST(1, 26)
#endif
