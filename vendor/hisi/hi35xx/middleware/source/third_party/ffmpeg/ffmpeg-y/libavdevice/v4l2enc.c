#include "v4l2-common.h"
#include "avdevice.h"
typedef struct {
    AVClass *class;
    int fd;
} V4L2Context;
