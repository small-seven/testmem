#include <stdint.h>
#include "libavutil/avassert.h"
#include "libavutil/dict.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "avformat.h"
#include "avio.h"
#include "avio_internal.h"
#include "id3v2.h"
#include "internal.h"
#include "metadata.h"
#include "pcm.h"
#include "riff.h"
#include "w64.h"
#include "spdif.h"
typedef struct WAVDemuxContext {
    const AVClass *class;
    int64_t data_end;
    int w64;
    int64_t smv_data_ofs;
    int smv_block_size;
    int smv_frames_per_jpeg;
    int smv_block;
    int smv_last_stream;
    int smv_eof;
    int audio_eof;
    int ignore_length;
    int spdif;
    int smv_cur_pt;
    int smv_given_first;
    int unaligned; // e.g. if an odd number of bytes ID3 tag was prepended
    int rifx; // RIFX: integer byte order for parameters is big endian
} WAVDemuxContext;
#if CONFIG_WAV_DEMUXER
#define MAX_SIZE 4096
#define OFFSET(x) offsetof(WAVDemuxContext, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
#endif /* CONFIG_WAV_DEMUXER */
#if CONFIG_W64_DEMUXER
#endif /* CONFIG_W64_DEMUXER */
