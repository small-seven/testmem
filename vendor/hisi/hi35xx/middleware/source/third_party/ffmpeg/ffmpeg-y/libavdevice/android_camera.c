#include <errno.h>
#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <stdint.h>
#include <camera/NdkCameraDevice.h>
#include <camera/NdkCameraManager.h>
#include <media/NdkImage.h>
#include <media/NdkImageReader.h>
#include "libavformat/avformat.h"
#include "libavformat/internal.h"
#include "libavutil/avstring.h"
#include "libavutil/display.h"
#include "libavutil/imgutils.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/pixfmt.h"
#include "libavutil/threadmessage.h"
#include "libavutil/time.h"
#include "version.h"
#define IMAGE_FORMAT_ANDROID AIMAGE_FORMAT_YUV_420_888
#define MAX_BUF_COUNT 2
#define VIDEO_STREAM_INDEX 0
#define VIDEO_TIMEBASE_ANDROID 1000000000
#define RETURN_CASE(x) case x: return AV_STRINGIFY(x);
#define RETURN_DEFAULT(x) default: return AV_STRINGIFY(x);
typedef struct AndroidCameraCtx {
    const AVClass *class;

    int requested_width;
    int requested_height;
    AVRational framerate;
    int camera_index;
    int input_queue_size;

    uint8_t lens_facing;
    int32_t sensor_orientation;
    int width;
    int height;
    int32_t framerate_range[2];
    int image_format;

    ACameraManager *camera_mgr;
    char *camera_id;
    ACameraMetadata *camera_metadata;
    ACameraDevice *camera_dev;
    ACameraDevice_StateCallbacks camera_state_callbacks;
    AImageReader *image_reader;
    AImageReader_ImageListener image_listener;
    ANativeWindow *image_reader_window;
    ACaptureSessionOutputContainer *capture_session_output_container;
    ACaptureSessionOutput *capture_session_output;
    ACameraOutputTarget *camera_output_target;
    ACaptureRequest *capture_request;
    ACameraCaptureSession_stateCallbacks capture_session_state_callbacks;
    ACameraCaptureSession *capture_session;

    AVThreadMessageQueue *input_queue;
    atomic_int exit;
    atomic_int got_image_format;
} AndroidCameraCtx;
#define OFFSET(x) offsetof(AndroidCameraCtx, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
