#include "libavcodec/flac.h"
#include "avformat.h"
#include "flac_picture.h"
#include "internal.h"
#include "rawdec.h"
#include "oggdec.h"
#include "vorbiscomment.h"
#include "replaygain.h"
#define SEEKPOINT_SIZE 18
typedef struct FLACDecContext {
    AVClass *class;
    int raw_packet_size;
    int found_seektable;
} FLACDecContext;
