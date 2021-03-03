#include "libavutil/channel_layout.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "bytestream.h"
#include "get_bits.h"
#include "internal.h"
#include "thread.h"
#include "unary.h"
#include "wavpack.h"
typedef struct SavedContext {
    int offset;
    int size;
    int bits_used;
    uint32_t crc;
} SavedContext;
typedef struct WavpackFrameContext {
    AVCodecContext *avctx;
    int frame_flags;
    int stereo, stereo_in;
    int joint;
    uint32_t CRC;
    GetBitContext gb;
    int got_extra_bits;
    uint32_t crc_extra_bits;
    GetBitContext gb_extra_bits;
    int data_size; // in bits
    int samples;
    int terms;
    Decorr decorr[MAX_TERMS];
    int zero, one, zeroes;
    int extra_bits;
    int and, or, shift;
    int post_shift;
    int hybrid, hybrid_bitrate;
    int hybrid_maxclip, hybrid_minclip;
    int float_flag;
    int float_shift;
    int float_max_exp;
    WvChannel ch[2];
    int pos;
    SavedContext sc, extra_sc;
} WavpackFrameContext;
#define WV_MAX_FRAME_DECODERS 14
typedef struct WavpackContext {
    AVCodecContext *avctx;

    WavpackFrameContext *fdec[WV_MAX_FRAME_DECODERS];
    int fdec_num;

    int block;
    int samples;
    int ch_offset;
} WavpackContext;
#define LEVEL_DECAY(a)  (((a) + 0x80) >> 8)
#if HAVE_THREADS
#endif
