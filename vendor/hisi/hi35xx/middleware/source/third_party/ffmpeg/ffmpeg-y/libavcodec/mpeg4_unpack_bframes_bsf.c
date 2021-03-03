#include "avcodec.h"
#include "bsf.h"
#include "internal.h"
#include "mpeg4video.h"
typedef struct UnpackBFramesBSFContext {
    AVPacket *b_frame;
} UnpackBFramesBSFContext;
