#include "avformat.h"
#include "voc.h"
typedef struct avs_format {
    VocDecContext voc;
    AVStream *st_video;
    AVStream *st_audio;
    int width;
    int height;
    int bits_per_sample;
    int fps;
    int nb_frames;
    int remaining_frame_size;
    int remaining_audio_size;
} AvsFormat;
typedef enum avs_block_type {
    AVS_NONE      = 0x00,
    AVS_VIDEO     = 0x01,
    AVS_AUDIO     = 0x02,
    AVS_PALETTE   = 0x03,
    AVS_GAME_DATA = 0x04,
} AvsBlockType;
#if FF_API_R_FRAME_RATE
#endif
