#include <vorbis/vorbisenc.h>
#include "libavutil/avassert.h"
#include "libavutil/fifo.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "audio_frame_queue.h"
#include "internal.h"
#include "vorbis.h"
#include "vorbis_parser.h"
#define LIBVORBIS_FRAME_SIZE 64
#define BUFFER_SIZE (1024 * 64)
typedef struct LibvorbisEncContext {
    AVClass *av_class;                  /**< class for AVOptions            */
    vorbis_info vi;                     /**< vorbis_info used during init   */
    vorbis_dsp_state vd;                /**< DSP state used for analysis    */
    vorbis_block vb;                    /**< vorbis_block used for analysis */
    AVFifoBuffer *pkt_fifo;             /**< output packet buffer           */
    int eof;                            /**< end-of-file flag               */
    int dsp_initialized;                /**< vd has been initialized        */
    vorbis_comment vc;                  /**< VorbisComment info             */
    double iblock;                      /**< impulse block bias option      */
    AVVorbisParseContext *vp;           /**< parse context to get durations */
    AudioFrameQueue afq;                /**< frame queue for timestamps     */
} LibvorbisEncContext;
