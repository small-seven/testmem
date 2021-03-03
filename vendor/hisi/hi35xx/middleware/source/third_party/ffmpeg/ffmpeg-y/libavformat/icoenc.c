#include "libavutil/intreadwrite.h"
#include "libavutil/pixdesc.h"
#include "avformat.h"
typedef struct {
    int offset;
    int size;
    unsigned char width;
    unsigned char height;
    short bits;
} IcoImage;
typedef struct {
    int current_image;
    int nb_images;
    IcoImage *images;
} IcoMuxContext;
