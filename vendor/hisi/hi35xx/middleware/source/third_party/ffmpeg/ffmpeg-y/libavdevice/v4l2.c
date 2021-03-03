#include <stdatomic.h>
#include "v4l2-common.h"
#include <dirent.h>
#if CONFIG_LIBV4L2
#include <libv4l2.h>
#endif
#define V4L_ALLFORMATS  3
#define V4L_RAWFORMATS  1
#define V4L_COMPFORMATS 2
#define V4L_TS_DEFAULT  0
#define V4L_TS_ABS      1
#define V4L_TS_MONO2ABS 2
#define V4L_TS_CONVERT_READY V4L_TS_DEFAULT
#ifdef __GLIBC__
#else
#endif
#define SET_WRAPPERS(prefix) do {       \
#if CONFIG_LIBV4L2
#else
#endif
#define v4l2_open   s->open_f
#define v4l2_close  s->close_f
#define v4l2_dup    s->dup_f
#define v4l2_ioctl  s->ioctl_f
#define v4l2_read   s->read_f
#define v4l2_mmap   s->mmap_f
#define v4l2_munmap s->munmap_f
#if HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE
#endif
#ifdef V4L2_FMT_FLAG_EMULATED
#endif
#if HAVE_STRUCT_V4L2_FRMIVALENUM_DISCRETE
#endif
#if HAVE_CLOCK_GETTIME && defined(CLOCK_MONOTONIC)
#endif
#if HAVE_CLOCK_GETTIME && defined(CLOCK_MONOTONIC)
#endif
#if HAVE_CLOCK_GETTIME && defined(CLOCK_MONOTONIC)
#endif
#ifdef V4L2_BUF_FLAG_ERROR
#endif
#ifdef ENODATA
#endif
#if CONFIG_LIBV4L2
#endif
#if FF_API_CODED_FRAME && FF_API_LAVF_AVCTX
#endif
#if FF_API_CODED_FRAME && FF_API_LAVF_AVCTX
#endif
#define OFFSET(x) offsetof(struct video_data, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
