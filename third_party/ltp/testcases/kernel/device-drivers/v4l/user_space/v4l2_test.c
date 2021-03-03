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
#include "test_VIDIOC_QUERYCAP.h"
#include "test_VIDIOC_QUERYSTD.h"
#include "test_VIDIOC_QUERYCTRL.h"
#include "test_VIDIOC_QUERYMENU.h"
#include "test_VIDIOC_CROPCAP.h"
#include "test_VIDIOC_G_SLICED_VBI_CAP.h"
#include "test_VIDIOC_ENUMAUDIO.h"
#include "test_VIDIOC_ENUMAUDOUT.h"
#include "test_VIDIOC_ENUMSTD.h"
#include "test_VIDIOC_ENUM_FMT.h"
#include "test_VIDIOC_ENUMINPUT.h"
#include "test_VIDIOC_ENUMOUTPUT.h"
#include "test_VIDIOC_ENUM_FRAMESIZES.h"
#include "test_VIDIOC_STD.h"
#include "test_VIDIOC_INPUT.h"
#include "test_VIDIOC_OUTPUT.h"
#include "test_VIDIOC_TUNER.h"
#include "test_VIDIOC_MODULATOR.h"
#include "test_VIDIOC_FREQUENCY.h"
#include "test_VIDIOC_PRIORITY.h"
#include "test_VIDIOC_AUDIO.h"
#include "test_VIDIOC_AUDOUT.h"
#include "test_VIDIOC_CROP.h"
#include "test_VIDIOC_CTRL.h"
#include "test_VIDIOC_EXT_CTRLS.h"
#include "test_VIDIOC_PARM.h"
#include "test_VIDIOC_FMT.h"
#include "test_VIDIOC_JPEGCOMP.h"
#include "test_VIDIOC_REQBUFS.h"
#include "test_VIDIOC_QUERYBUF.h"
#include "test_VIDIOC_LOG_STATUS.h"
#include "test_invalid_ioctl.h"