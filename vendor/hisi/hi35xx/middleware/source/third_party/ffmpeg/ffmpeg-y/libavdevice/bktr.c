#include "libavformat/internal.h"
#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavutil/time.h"
#if HAVE_DEV_BKTR_IOCTL_METEOR_H && HAVE_DEV_BKTR_IOCTL_BT848_H
# include <dev/bktr/ioctl_meteor.h>
# include <dev/bktr/ioctl_bt848.h>
#elif HAVE_MACHINE_IOCTL_METEOR_H && HAVE_MACHINE_IOCTL_BT848_H
# include <machine/ioctl_meteor.h>
# include <machine/ioctl_bt848.h>
#elif HAVE_DEV_VIDEO_METEOR_IOCTL_METEOR_H && HAVE_DEV_VIDEO_BKTR_IOCTL_BT848_H
# include <dev/video/meteor/ioctl_meteor.h>
# include <dev/video/bktr/ioctl_bt848.h>
#elif HAVE_DEV_IC_BT8XX_H
# include <dev/ic/bt8xx.h>
#endif
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <signal.h>
#include <stdint.h>
#include "avdevice.h"
typedef struct VideoData {
    AVClass *class;
    int video_fd;
    int tuner_fd;
    int width, height;
    uint64_t per_frame;
    int standard;
    char *framerate;  /**< Set by a private option. */
} VideoData;
#define PAL 1
#define PALBDGHI 1
#define NTSC 2
#define NTSCM 2
#define SECAM 3
#define PALN 4
#define PALM 5
#define NTSCJ 6
#define PAL_HEIGHT 576
#define SECAM_HEIGHT 576
#define NTSC_HEIGHT 480
#ifndef VIDEO_FORMAT
#define VIDEO_FORMAT NTSC
#endif
#define OFFSET(x) offsetof(VideoData, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
