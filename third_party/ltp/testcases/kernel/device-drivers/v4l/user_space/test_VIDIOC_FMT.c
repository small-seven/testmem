#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <linux/videodev2.h>
#include <linux/errno.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "v4l2_test.h"
#include "dev_video.h"
#include "video_limits.h"
#include "test_VIDIOC_FMT.h"
#ifdef V4L2_PIX_FMT_VYUY
#endif
#ifdef V4L2_PIX_FMT_NV16
#endif
#ifdef V4L2_PIX_FMT_NV61
#endif
#ifdef V4L2_PIX_FMT_SGBRG8
#endif
#ifdef V4L2_PIX_FMT_SGRBG8
#endif
#ifdef V4L2_PIX_FMT_SGRBG10
#endif
#ifdef V4L2_PIX_FMT_SGRBG10DPCM8
#endif
#ifdef V4L2_PIX_FMT_SPCA501
#endif
#ifdef V4L2_PIX_FMT_SPCA505
#endif
#ifdef V4L2_PIX_FMT_SPCA508
#endif
#ifdef V4L2_PIX_FMT_SPCA561
#endif
#ifdef V4L2_PIX_FMT_PAC207
#endif
#ifdef V4L2_PIX_FMT_MR97310A
#endif
#ifdef V4L2_PIX_FMT_SQ905C
#endif
#ifdef V4L2_PIX_FMT_PJPG
#endif
#ifdef V4L2_PIX_FMT_YVYU
#endif
#ifdef V4L2_PIX_FMT_OV511
#endif
#ifdef V4L2_PIX_FMT_OV518
#endif
