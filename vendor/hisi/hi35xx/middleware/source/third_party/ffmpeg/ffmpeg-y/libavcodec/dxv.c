#include <stdint.h>
#include "libavutil/imgutils.h"
#include "mathops.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#include "lzf.h"
#include "texturedsp.h"
#include "thread.h"
typedef struct DXVContext {
    TextureDSPContext texdsp;
    GetByteContext gbc;

    uint8_t *tex_data;   // Compressed texture
    uint8_t *ctex_data;  // Compressed texture
    int tex_rat;         // Compression ratio
    int tex_step;        // Distance between blocks
    int ctex_step;       // Distance between blocks
    int64_t tex_size;    // Texture size
    int64_t ctex_size;   // Texture size

    /* Optimal number of slices for parallel decoding */
    int slice_count;

    uint8_t *op_data[4]; // Opcodes
    int64_t op_size[4];  // Opcodes size

    int texture_block_w;
    int texture_block_h;

    int ctexture_block_w;
    int ctexture_block_h;

    /* Pointer to the selected decompression function */
    int (*tex_funct)(uint8_t *dst, ptrdiff_t stride, const uint8_t *block);
    int (*tex_funct_planar[2])(uint8_t *plane0, ptrdiff_t stride0,
                               uint8_t *plane1, ptrdiff_t stride1,
                               const uint8_t *block);
} DXVContext;
#define CHECKPOINT(x)                                                         \
typedef struct OpcodeTable {
    int16_t next;
    uint8_t val1;
    uint8_t val2;
} OpcodeTable;
