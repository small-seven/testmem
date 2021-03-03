#include <stdio.h>
#include <stdint.h>
#include "libavutil/channel_layout.h"
#include "libavutil/display.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/log.h"
#include "libavutil/mastering_display_metadata.h"
#include "libavutil/mathematics.h"
#include "libavutil/opt.h"
#include "libavutil/avstring.h"
#include "libavutil/replaygain.h"
#include "libavutil/spherical.h"
#include "libavutil/stereo3d.h"
#include "avformat.h"
#define HEXDUMP_PRINT(...)                                                    \
