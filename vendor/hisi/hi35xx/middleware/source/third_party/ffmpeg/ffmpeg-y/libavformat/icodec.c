#include "libavutil/intreadwrite.h"
#include "libavcodec/bytestream.h"
#include "libavcodec/bmp.h"
#include "libavcodec/png.h"
#include "avformat.h"
#include "internal.h"
typedef struct {
    int offset;
    int size;
    int nb_pal;
} IcoImage;
typedef struct {
    int current_image;
    int nb_images;
    IcoImage * images;
} IcoDemuxContext;
