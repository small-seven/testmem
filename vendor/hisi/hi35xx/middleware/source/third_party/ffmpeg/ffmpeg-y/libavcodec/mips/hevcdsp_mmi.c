#include "libavcodec/hevcdec.h"
#include "libavcodec/bit_depth_template.c"
#include "libavcodec/mips/hevcdsp_mips.h"
#include "libavutil/mips/mmiutils.h"
#define PUT_HEVC_QPEL_H(w, x_step, src_step, dst_step)                   \
#define PUT_HEVC_QPEL_HV(w, x_step, src_step, dst_step)                  \
#define PUT_HEVC_QPEL_BI_H(w, x_step, src_step, src2_step, dst_step)    \
#define PUT_HEVC_QPEL_BI_HV(w, x_step, src_step, src2_step, dst_step)   \
#define PUT_HEVC_EPEL_BI_HV(w, x_step, src_step, src2_step, dst_step)   \
#define PUT_HEVC_PEL_BI_PIXELS(w, x_step, src_step, dst_step, src2_step)  \
#define PUT_HEVC_QPEL_UNI_HV(w, x_step, src_step, dst_step, tmp_step)   \
