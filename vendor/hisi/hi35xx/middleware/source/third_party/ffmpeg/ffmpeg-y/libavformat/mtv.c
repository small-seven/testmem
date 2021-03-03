#include "libavutil/bswap.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define MTV_ASUBCHUNK_DATA_SIZE 500
#define MTV_HEADER_SIZE 512
#define MTV_AUDIO_PADDING_SIZE 12
#define MTV_IMAGE_DEFAULT_BPP 16
#define MTV_AUDIO_SAMPLING_RATE 44100
typedef struct MTVDemuxContext {

    unsigned int file_size;         ///< filesize, not always right
    unsigned int segments;          ///< number of 512 byte segments
    unsigned int audio_identifier;  ///< 'MP3' on all files I have seen
    unsigned int audio_br;          ///< bitrate of audio channel (mp3)
    unsigned int img_colorfmt;      ///< frame colorfmt rgb 565/555
    unsigned int img_bpp;           ///< frame bits per pixel
    unsigned int img_width;
    unsigned int img_height;
    unsigned int img_segment_size;  ///< size of image segment
    unsigned int video_fps;
    unsigned int full_segment_size;

} MTVDemuxContext;
