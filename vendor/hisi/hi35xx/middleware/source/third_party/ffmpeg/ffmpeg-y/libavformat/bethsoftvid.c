#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "libavcodec/bethsoftvideo.h"
#define BVID_PALETTE_SIZE 3 * 256
#define DEFAULT_SAMPLE_RATE 11111
typedef struct BVID_DemuxContext
{
    int nframes;
    int sample_rate;        /**< audio sample rate */
    int width;              /**< video width       */
    int height;             /**< video height      */
    /** delay value between frames, added to individual frame delay.
     * custom units, which will be added to other custom units (~=16ms according
     * to free, unofficial documentation) */
    int bethsoft_global_delay;
    int video_index;        /**< video stream index */
    int audio_index;        /**< audio stream index */
    uint8_t *palette;

    int is_finished;

} BVID_DemuxContext;
#define BUFFER_PADDING_SIZE 1000
