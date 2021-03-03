#include <libbluray/bluray.h>
#include "libavutil/avstring.h"
#include "libavformat/avformat.h"
#include "libavformat/url.h"
#include "libavutil/opt.h"
#define BLURAY_PROTO_PREFIX     "bluray:"
#define MIN_PLAYLIST_LENGTH     180     /* 3 min */
typedef struct {
    const AVClass *class;

    BLURAY *bd;

    int playlist;
    int angle;
    int chapter;
    /*int region;*/
} BlurayContext;
#define OFFSET(x) offsetof(BlurayContext, x)
