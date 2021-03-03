#include <string.h>
#include "libavutil/avstring.h"
#include "libavutil/base64.h"
#include "url.h"
typedef struct {
    const uint8_t *data;
    void *tofree;
    size_t size;
    size_t pos;
} DataContext;
