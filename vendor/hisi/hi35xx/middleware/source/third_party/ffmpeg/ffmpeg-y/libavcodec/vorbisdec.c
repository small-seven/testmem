#include <inttypes.h>
#include <math.h>
#include "libavutil/avassert.h"
#include "libavutil/float_dsp.h"
#define BITSTREAM_READER_LE
#include "avcodec.h"
#include "fft.h"
#include "get_bits.h"
#include "internal.h"
#include "vorbis.h"
#include "vorbisdsp.h"
#include "xiph.h"
#define V_NB_BITS 8
#define V_NB_BITS2 11
#define V_MAX_VLCS (1 << 16)
#define V_MAX_PARTITIONS (1 << 20)
typedef struct vorbis_codebook {
    uint8_t      dimensions;
    uint8_t      lookup_type;
    uint8_t      maxdepth;
    VLC          vlc;
    float       *codevectors;
    unsigned int nb_bits;
} vorbis_codebook;
typedef union  vorbis_floor_u  vorbis_floor_data;
typedef struct vorbis_floor0_s vorbis_floor0;
typedef struct vorbis_floor1_s vorbis_floor1;
struct vorbis_context_s;
typedef
int (* vorbis_floor_decode_func)
    (struct vorbis_context_s *, vorbis_floor_data *, float *);
typedef struct vorbis_floor {
    uint8_t floor_type;
    vorbis_floor_decode_func decode;
    union vorbis_floor_u {
        struct vorbis_floor0_s {
            uint8_t       order;
            uint16_t      rate;
            uint16_t      bark_map_size;
            int32_t      *map[2];
            uint32_t      map_size[2];
            uint8_t       amplitude_bits;
            uint8_t       amplitude_offset;
            uint8_t       num_books;
            uint8_t      *book_list;
            float        *lsp;
        } t0;
typedef struct vorbis_residue {
    uint16_t      type;
    uint32_t      begin;
    uint32_t      end;
    unsigned      partition_size;
    uint8_t       classifications;
    uint8_t       classbook;
    int16_t       books[64][8];
    uint8_t       maxpass;
    uint16_t      ptns_to_read;
    uint8_t      *classifs;
} vorbis_residue;
typedef struct vorbis_mapping {
    uint8_t       submaps;
    uint16_t      coupling_steps;
    uint8_t      *magnitude;
    uint8_t      *angle;
    uint8_t      *mux;
    uint8_t       submap_floor[16];
    uint8_t       submap_residue[16];
} vorbis_mapping;
typedef struct vorbis_mode {
    uint8_t       blockflag;
    uint16_t      windowtype;
    uint16_t      transformtype;
    uint8_t       mapping;
} vorbis_mode;
typedef struct vorbis_context_s {
    AVCodecContext *avctx;
    GetBitContext gb;
    VorbisDSPContext dsp;
    AVFloatDSPContext *fdsp;

    FFTContext mdct[2];
    uint8_t       first_frame;
    uint32_t      version;
    uint8_t       audio_channels;
    uint32_t      audio_samplerate;
    uint32_t      bitrate_maximum;
    uint32_t      bitrate_nominal;
    uint32_t      bitrate_minimum;
    uint32_t      blocksize[2];
    const float  *win[2];
    uint16_t      codebook_count;
    vorbis_codebook *codebooks;
    uint8_t       floor_count;
    vorbis_floor *floors;
    uint8_t       residue_count;
    vorbis_residue *residues;
    uint8_t       mapping_count;
    vorbis_mapping *mappings;
    uint8_t       mode_count;
    vorbis_mode  *modes;
    uint8_t       mode_number; // mode number for the current packet
    int8_t       previous_window;
    float        *channel_residues;
    float        *saved;
} vorbis_context;
#define BARK(x) \
#define VALIDATE_INDEX(idx, limit) \
#define GET_VALIDATED_INDEX(idx, bits, limit) \
static void vorbis_free(vorbis_context *vc)
{
    int i;

    av_freep(&vc->channel_residues);
    av_freep(&vc->saved);
    av_freep(&vc->fdsp);

    if (vc->residues)
        for (i = 0; i < vc->residue_count; i++)
            av_freep(&vc->residues[i].classifs);
    av_freep(&vc->residues);
    av_freep(&vc->modes);

    ff_mdct_end(&vc->mdct[0]);
    ff_mdct_end(&vc->mdct[1]);

    if (vc->codebooks)
        for (i = 0; i < vc->codebook_count; ++i) {
            av_freep(&vc->codebooks[i].codevectors);
            ff_free_vlc(&vc->codebooks[i].vlc);
        }
    av_freep(&vc->codebooks);

    if (vc->floors)
        for (i = 0; i < vc->floor_count; ++i) {
            if (vc->floors[i].floor_type == 0) {
                av_freep(&vc->floors[i].data.t0.map[0]);
                av_freep(&vc->floors[i].data.t0.map[1]);
                av_freep(&vc->floors[i].data.t0.book_list);
                av_freep(&vc->floors[i].data.t0.lsp);
            } else {
                av_freep(&vc->floors[i].data.t1.list);
            }
        }
    av_freep(&vc->floors);

    if (vc->mappings)
        for (i = 0; i < vc->mapping_count; ++i) {
            av_freep(&vc->mappings[i].magnitude);
            av_freep(&vc->mappings[i].angle);
            av_freep(&vc->mappings[i].mux);
        }
    av_freep(&vc->mappings);
}
