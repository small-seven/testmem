#include <VideoToolbox/VideoToolbox.h>
#include <CoreVideo/CoreVideo.h>
#include <CoreMedia/CoreMedia.h>
#include <TargetConditionals.h>
#include <Availability.h>
#include "avcodec.h"
#include "libavutil/opt.h"
#include "libavutil/avassert.h"
#include "libavutil/avstring.h"
#include "libavcodec/avcodec.h"
#include "libavutil/pixdesc.h"
#include "internal.h"
#include <pthread.h>
#include "h264.h"
#include "h264_sei.h"
#include <dlfcn.h>
#if !HAVE_KCMVIDEOCODECTYPE_HEVC
#endif
#if !HAVE_KCVPIXELFORMATTYPE_420YPCBCR10BIPLANARVIDEORANGE
#endif
typedef OSStatus (*getParameterSetAtIndex)(CMFormatDescriptionRef videoDesc,
                                           size_t parameterSetIndex,
                                           const uint8_t **parameterSetPointerOut,
                                           size_t *parameterSetSizeOut,
                                           size_t *parameterSetCountOut,
                                           int *NALUnitHeaderLengthOut);

//These symbols may not be present
static struct{
    CFStringRef kCVImageBufferColorPrimaries_ITU_R_2020;
    CFStringRef kCVImageBufferTransferFunction_ITU_R_2020;
    CFStringRef kCVImageBufferYCbCrMatrix_ITU_R_2020;

    CFStringRef kVTCompressionPropertyKey_H264EntropyMode;
    CFStringRef kVTH264EntropyMode_CAVLC;
    CFStringRef kVTH264EntropyMode_CABAC;

    CFStringRef kVTProfileLevel_H264_Baseline_4_0;
    CFStringRef kVTProfileLevel_H264_Baseline_4_2;
    CFStringRef kVTProfileLevel_H264_Baseline_5_0;
    CFStringRef kVTProfileLevel_H264_Baseline_5_1;
    CFStringRef kVTProfileLevel_H264_Baseline_5_2;
    CFStringRef kVTProfileLevel_H264_Baseline_AutoLevel;
    CFStringRef kVTProfileLevel_H264_Main_4_2;
    CFStringRef kVTProfileLevel_H264_Main_5_1;
    CFStringRef kVTProfileLevel_H264_Main_5_2;
    CFStringRef kVTProfileLevel_H264_Main_AutoLevel;
    CFStringRef kVTProfileLevel_H264_High_3_0;
    CFStringRef kVTProfileLevel_H264_High_3_1;
    CFStringRef kVTProfileLevel_H264_High_3_2;
    CFStringRef kVTProfileLevel_H264_High_4_0;
    CFStringRef kVTProfileLevel_H264_High_4_1;
    CFStringRef kVTProfileLevel_H264_High_4_2;
    CFStringRef kVTProfileLevel_H264_High_5_1;
    CFStringRef kVTProfileLevel_H264_High_5_2;
    CFStringRef kVTProfileLevel_H264_High_AutoLevel;

    CFStringRef kVTProfileLevel_HEVC_Main_AutoLevel;
    CFStringRef kVTProfileLevel_HEVC_Main10_AutoLevel;

    CFStringRef kVTCompressionPropertyKey_RealTime;

    CFStringRef kVTVideoEncoderSpecification_EnableHardwareAcceleratedVideoEncoder;
    CFStringRef kVTVideoEncoderSpecification_RequireHardwareAcceleratedVideoEncoder;

    getParameterSetAtIndex CMVideoFormatDescriptionGetHEVCParameterSetAtIndex;
} compat_keys;
#define GET_SYM(symbol, defaultVal)                                     \
typedef enum VT_H264Profile {
    H264_PROF_AUTO,
    H264_PROF_BASELINE,
    H264_PROF_MAIN,
    H264_PROF_HIGH,
    H264_PROF_COUNT
} VT_H264Profile;
typedef enum VTH264Entropy{
    VT_ENTROPY_NOT_SET,
    VT_CAVLC,
    VT_CABAC
} VTH264Entropy;
typedef enum VT_HEVCProfile {
    HEVC_PROF_AUTO,
    HEVC_PROF_MAIN,
    HEVC_PROF_MAIN10,
    HEVC_PROF_COUNT
} VT_HEVCProfile;
typedef struct ExtraSEI {
  void *data;
  size_t size;
} ExtraSEI;
typedef struct BufNode {
    CMSampleBufferRef cm_buffer;
    ExtraSEI *sei;
    struct BufNode* next;
    int error;
} BufNode;
typedef struct VTEncContext {
    AVClass *class;
    enum AVCodecID codec_id;
    VTCompressionSessionRef session;
    CFStringRef ycbcr_matrix;
    CFStringRef color_primaries;
    CFStringRef transfer_function;
    getParameterSetAtIndex get_param_set_func;

    pthread_mutex_t lock;
    pthread_cond_t  cv_sample_sent;

    int async_error;

    BufNode *q_head;
    BufNode *q_tail;

    int64_t frame_ct_out;
    int64_t frame_ct_in;

    int64_t first_pts;
    int64_t dts_delta;

    int64_t profile;
    int64_t level;
    int64_t entropy;
    int64_t realtime;
    int64_t frames_before;
    int64_t frames_after;

    int64_t allow_sw;
    int64_t require_sw;

    bool flushing;
    bool has_b_frames;
    bool warned_color_range;
    bool a53_cc;
} VTEncContext;
#if !TARGET_OS_IPHONE
#endif
#if !TARGET_OS_IPHONE
#endif
#define VE AV_OPT_FLAG_VIDEO_PARAM | AV_OPT_FLAG_ENCODING_PARAM
#define COMMON_OPTIONS \
#define OFFSET(x) offsetof(VTEncContext, x)
