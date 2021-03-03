#include <stdint.h>
#include "libavutil/libm.h"
#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "texturedsp.h"
#include "thread.h"
#define DDPF_FOURCC    (1 <<  2)
#define DDPF_PALETTE   (1 <<  5)
#define DDPF_NORMALMAP (1U << 31)
typedef struct DDSContext {
    TextureDSPContext texdsp;
    GetByteContext gbc;

    int compressed;
    int paletted;
    int bpp;
    enum DDSPostProc postproc;

    const uint8_t *tex_data; // Compressed texture
    int tex_ratio;           // Compression ratio
    int slice_count;         // Number of slices for threaded operations

    /* Pointer to the selected compress or decompress function. */
    int (*tex_funct)(uint8_t *dst, ptrdiff_t stride, const uint8_t *block);
} DDSContext;
