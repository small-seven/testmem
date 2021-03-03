#include <float.h>
#include "libavutil/float_dsp.h"
#include "avcodec.h"
#include "internal.h"
#include "fft.h"
#include "mathops.h"
#include "vorbis.h"
#include "vorbis_enc_data.h"
#include "audio_frame_queue.h"
#include "libavfilter/bufferqueue.h"
#define BITSTREAM_WRITER_LE
#include "put_bits.h"
#undef NDEBUG
#include <assert.h>
typedef struct vorbis_enc_codebook {
    int nentries;
    uint8_t *lens;
    uint32_t *codewords;
    int ndimensions;
    float min;
    float delta;
    int seq_p;
    int lookup;
    int *quantlist;
    float *dimensions;
    float *pow2;
} vorbis_enc_codebook;
typedef struct vorbis_enc_floor_class {
    int dim;
    int subclass;
    int masterbook;
    int *books;
} vorbis_enc_floor_class;
typedef struct vorbis_enc_floor {
    int partitions;
    int *partition_to_class;
    int nclasses;
    vorbis_enc_floor_class *classes;
    int multiplier;
    int rangebits;
    int values;
    vorbis_floor1_entry *list;
} vorbis_enc_floor;
typedef struct vorbis_enc_residue {
    int type;
    int begin;
    int end;
    int partition_size;
    int classifications;
    int classbook;
    int8_t (*books)[8];
    float (*maxes)[2];
} vorbis_enc_residue;
typedef struct vorbis_enc_mapping {
    int submaps;
    int *mux;
    int *floor;
    int *residue;
    int coupling_steps;
    int *magnitude;
    int *angle;
} vorbis_enc_mapping;
typedef struct vorbis_enc_mode {
    int blockflag;
    int mapping;
} vorbis_enc_mode;
typedef struct vorbis_enc_context {
    int channels;
    int sample_rate;
    int log2_blocksize[2];
    FFTContext mdct[2];
    const float *win[2];
    int have_saved;
    float *saved;
    float *samples;
    float *floor;  // also used for tmp values for mdct
    float *coeffs; // also used for residue after floor
    float *scratch; // used for tmp values for psy model
    float quality;

    AudioFrameQueue afq;
    struct FFBufQueue bufqueue;

    int ncodebooks;
    vorbis_enc_codebook *codebooks;

    int nfloors;
    vorbis_enc_floor *floors;

    int nresidues;
    vorbis_enc_residue *residues;

    int nmappings;
    vorbis_enc_mapping *mappings;

    int nmodes;
    vorbis_enc_mode *modes;

    int64_t next_pts;

    AVFloatDSPContext *fdsp;
} vorbis_enc_context;
#define MAX_CHANNELS     2
#define MAX_CODEBOOK_DIM 8
#define MAX_FLOOR_CLASS_DIM  4
#define NUM_FLOOR_PARTITIONS 8
#define MAX_FLOOR_VALUES     (MAX_FLOOR_CLASS_DIM*NUM_FLOOR_PARTITIONS+2)
#define RESIDUE_SIZE           1600
#define RESIDUE_PART_SIZE      32
#define NUM_RESIDUE_PARTITIONS (RESIDUE_SIZE/RESIDUE_PART_SIZE)
