#include <AL/al.h>
#include <AL/alc.h>
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavformat/internal.h"
#include "avdevice.h"
typedef struct {
    AVClass *class;
    /** OpenAL capture device context. **/
    ALCdevice *device;
    /** The number of channels in the captured audio. **/
    int channels;
    /** The sample rate (in Hz) of the captured audio. **/
    int sample_rate;
    /** The sample size (in bits) of the captured audio. **/
    int sample_size;
    /** The OpenAL sample format of the captured audio. **/
    ALCenum sample_format;
    /** The number of bytes between two consecutive samples of the same channel/component. **/
    ALCint sample_step;
    /** If true, print a list of capture devices on this system and exit. **/
    int list_devices;
} al_data;
typedef struct {
    ALCenum al_fmt;
    enum AVCodecID codec_id;
    int channels;
} al_format_info;
#define LOWEST_AL_FORMAT FFMIN(FFMIN(AL_FORMAT_MONO8,AL_FORMAT_MONO16),FFMIN(AL_FORMAT_STEREO8,AL_FORMAT_STEREO16))
#define OFFSET(x) offsetof(al_data, x)
