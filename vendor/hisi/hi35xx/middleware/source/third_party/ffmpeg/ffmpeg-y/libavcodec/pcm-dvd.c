#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct PCMDVDContext {
    uint32_t last_header;    // Cached header to see if parsing is needed
    int block_size;          // Size of a block of samples in bytes
    int last_block_size;     // Size of the last block of samples in bytes
    int samples_per_block;   // Number of samples per channel per block
    int groups_per_block;    // Number of 20/24-bit sample groups per block
    uint8_t *extra_samples;  // Pointer to leftover samples from a frame
    int extra_sample_count;  // Number of leftover samples in the buffer
} PCMDVDContext;
#if HAVE_BIGENDIAN
#else
#endif
