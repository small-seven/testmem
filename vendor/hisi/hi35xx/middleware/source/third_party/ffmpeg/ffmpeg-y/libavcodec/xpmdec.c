#include "libavutil/parseutils.h"
#include "libavutil/avstring.h"
#include "avcodec.h"
#include "internal.h"
#define MIN_ELEMENT ' '
#define MAX_ELEMENT 0xfe
#define NB_ELEMENTS (MAX_ELEMENT - MIN_ELEMENT + 1)
typedef struct XPMContext {
    uint32_t  *pixels;
    int        pixels_size;
    uint8_t   *buf;
    int        buf_size;
} XPMDecContext;
typedef struct ColorEntry {
    const char *name;         ///< a string representing the name of the color
    uint32_t    rgb_color;    ///< RGB values for the color
} ColorEntry;
