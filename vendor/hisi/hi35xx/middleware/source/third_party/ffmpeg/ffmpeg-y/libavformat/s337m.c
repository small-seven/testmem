#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "spdif.h"
#define MARKER_16LE         0x72F81F4E
#define MARKER_20LE         0x20876FF0E154
#define MARKER_24LE         0x72F8961F4EA5
#define IS_16LE_MARKER(state)   ((state & 0xFFFFFFFF) == MARKER_16LE)
#define IS_20LE_MARKER(state)   ((state & 0xF0FFFFF0FFFF) == MARKER_20LE)
#define IS_24LE_MARKER(state)   ((state & 0xFFFFFFFFFFFF) == MARKER_24LE)
#define IS_LE_MARKER(state)     (IS_16LE_MARKER(state) || IS_20LE_MARKER(state) || IS_24LE_MARKER(state))
