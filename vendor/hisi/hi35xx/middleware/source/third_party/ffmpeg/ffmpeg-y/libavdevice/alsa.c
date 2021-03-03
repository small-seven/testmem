#include <alsa/asoundlib.h>
#include "avdevice.h"
#include "libavutil/avassert.h"
#include "libavutil/channel_layout.h"
#include "alsa.h"
#define MAKE_REORDER_FUNC(NAME, TYPE, CHANNELS, LAYOUT, MAP)                \
#define MAKE_REORDER_FUNCS(CHANNELS, LAYOUT, MAP) \
#define FORMAT_I8  0
#define FORMAT_I16 1
#define FORMAT_I32 2
#define FORMAT_F32 3
#define PICK_REORDER(layout)\
