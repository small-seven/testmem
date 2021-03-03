#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
typedef struct PCMDVDContext {
    uint8_t header[3];       // Header added to every frame
    int block_size;          // Size of a block of samples in bytes
    int samples_per_block;   // Number of samples per channel per block
    int groups_per_block;    // Number of 20/24-bit sample groups per block
    uint8_t *extra_samples;  // Pointer to leftover samples from a frame
    int extra_sample_count;  // Number of leftover samples in the buffer
} PCMDVDContext;
