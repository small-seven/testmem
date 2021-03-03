#include "config.h"
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/soundcard.h>
#include "libavutil/internal.h"
#include "libavcodec/avcodec.h"
#include "avdevice.h"
#include "libavformat/internal.h"
#include "oss.h"
