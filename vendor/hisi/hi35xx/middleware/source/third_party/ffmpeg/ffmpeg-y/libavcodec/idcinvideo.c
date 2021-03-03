#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avcodec.h"
#include "internal.h"
#include "libavutil/internal.h"
#define HUFFMAN_TABLE_SIZE 64 * 1024
#define HUF_TOKENS 256
#define PALETTE_COUNT 256
typedef struct hnode {
  int count;
  unsigned char used;
  int children[2];
} hnode;
typedef struct IdcinContext {

    AVCodecContext *avctx;

    const unsigned char *buf;
    int size;

    hnode huff_nodes[256][HUF_TOKENS*2];
    int num_huff_nodes[256];

    uint32_t pal[256];
} IdcinContext;
