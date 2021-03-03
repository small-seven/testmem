#include "avformat.h"
#include "rawdec.h"
#include "libavcodec/internal.h"
#define CAVS_SEQ_START_CODE       0x000001b0
#define CAVS_PIC_I_START_CODE     0x000001b3
#define CAVS_UNDEF_START_CODE     0x000001b4
#define CAVS_PIC_PB_START_CODE    0x000001b6
#define CAVS_VIDEO_EDIT_CODE      0x000001b7
#define CAVS_PROFILE_JIZHUN       0x20
