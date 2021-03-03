#include <stdint.h>
#include <string.h>
#include <zlib.h>
#include "libavutil/imgutils.h"
#include "libavutil/internal.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define TILE_SIZE 8
typedef struct Tile {
    int x, y;
    int w, h;
} Tile;
typedef struct RsccContext {
    GetByteContext gbc;
    AVFrame *reference;
    Tile *tiles;
    unsigned int tiles_size;
    int component_size;

    uint8_t palette[AVPALETTE_SIZE];

    /* zlib interaction */
    uint8_t *inflated_buf;
    uLongf inflated_size;
    int valid_pixels;
} RsccContext;
