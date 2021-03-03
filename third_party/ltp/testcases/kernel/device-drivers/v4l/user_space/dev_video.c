#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include "dev_video.h"
#define DEV_VIDEO_STATE_NORMAL		0
#define DEV_VIDEO_STATE_ASUS		1
#define DEV_VIDEO_STATE_EEEPC		2
