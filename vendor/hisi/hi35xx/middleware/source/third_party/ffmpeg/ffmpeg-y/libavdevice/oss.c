#include "config.h"
#include <string.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>
#include "libavutil/log.h"
#include "libavcodec/avcodec.h"
#include "avdevice.h"
#include "oss.h"
#define CHECK_IOCTL_ERROR(event)                                              \
#if HAVE_BIGENDIAN
#else
#endif
#undef CHECK_IOCTL_ERROR
