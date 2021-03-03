#include "libavutil/imgutils.h"
#include "avcodec.h"
#include "bytestream.h"
#include "internal.h"
#define HEADER1_CHUNK    0x03
#define HEADER2_CHUNK    0x3D
#define IMAGE_DATA_CHUNK 0x21
typedef struct PixHeader {
    int width;
    int height;
    int format;
} PixHeader;
