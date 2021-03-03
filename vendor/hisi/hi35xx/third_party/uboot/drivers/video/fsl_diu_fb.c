#include <common.h>
#include <malloc.h>
#include <asm/io.h>
#include "videomodes.h"
#include <video_fb.h>
#include <fsl_diu_fb.h>
#include <linux/list.h>
#include <linux/fb.h>
#define RESOLUTION(x, y) (((u32)(x) << 16) | (y))
