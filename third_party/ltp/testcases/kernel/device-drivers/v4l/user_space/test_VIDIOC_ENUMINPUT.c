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
#include "v4l2_validator.h"
#include "v4l2_show.h"
#include "test_VIDIOC_ENUMINPUT.h"
