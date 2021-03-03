#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#include "avio_internal.h"
#define FILM_TAG MKBETAG('F', 'I', 'L', 'M')
#define FDSC_TAG MKBETAG('F', 'D', 'S', 'C')
#define STAB_TAG MKBETAG('S', 'T', 'A', 'B')
#define CVID_TAG MKBETAG('c', 'v', 'i', 'd')
#define RAW_TAG  MKBETAG('r', 'a', 'w', ' ')
typedef struct film_sample {
  int stream;
  int64_t sample_offset;
  unsigned int sample_size;
  int64_t pts;
  int keyframe;
} film_sample;
typedef struct FilmDemuxContext {
    int video_stream_index;
    int audio_stream_index;

    enum AVCodecID audio_type;
    unsigned int audio_samplerate;
    unsigned int audio_bits;
    unsigned int audio_channels;

    enum AVCodecID video_type;
    unsigned int sample_count;
    film_sample *sample_table;
    unsigned int current_sample;

    unsigned int base_clock;
    unsigned int version;
} FilmDemuxContext;
