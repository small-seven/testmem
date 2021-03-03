#include "libavutil/avstring.h"
#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/dict.h"
#include "avformat.h"
#include "internal.h"
#define FORM_TAG MKTAG('F', 'O', 'R', 'M')
#define MOVE_TAG MKTAG('M', 'O', 'V', 'E')
#define  PC__TAG MKTAG('_', 'P', 'C', '_')
#define SOND_TAG MKTAG('S', 'O', 'N', 'D')
#define BNAM_TAG MKTAG('B', 'N', 'A', 'M')
#define SIZE_TAG MKTAG('S', 'I', 'Z', 'E')
#define PALT_TAG MKTAG('P', 'A', 'L', 'T')
#define INDX_TAG MKTAG('I', 'N', 'D', 'X')
#define BRCH_TAG MKTAG('B', 'R', 'C', 'H')
#define SHOT_TAG MKTAG('S', 'H', 'O', 'T')
#define VGA__TAG MKTAG('V', 'G', 'A', ' ')
#define TEXT_TAG MKTAG('T', 'E', 'X', 'T')
#define AUDI_TAG MKTAG('A', 'U', 'D', 'I')
#define WC3_DEFAULT_WIDTH 320
#define WC3_DEFAULT_HEIGHT 165
#define WC3_SAMPLE_RATE 22050
#define WC3_AUDIO_CHANNELS 1
#define WC3_AUDIO_BITS 16
#define WC3_FRAME_FPS 15
#define PALETTE_SIZE (256 * 3)
typedef struct Wc3DemuxContext {
    int width;
    int height;
    int64_t pts;
    int video_stream_index;
    int audio_stream_index;

    AVPacket vpkt;

} Wc3DemuxContext;
