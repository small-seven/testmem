#include "pulse_audio_common.h"
#include "libavutil/attributes.h"
#include "libavutil/avstring.h"
#include "libavutil/mem.h"
#include "libavutil/avassert.h"
typedef struct PulseAudioDeviceList {
    AVDeviceInfoList *devices;
    int error_code;
    int output;
    char *default_device;
} PulseAudioDeviceList;
