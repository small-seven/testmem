#include <common.h>
#include <command.h>
#include <linux/ctype.h>
#include <asm/io.h>
#include <stdio_dev.h>
#include <video_fb.h>
#include <fsl_diu_fb.h>
#include "../common/qixis.h"
#include "../common/diu_ch7301.h"
#include "t1040qds.h"
#include "t1040qds_qixis.h"
#define AD_BYTE_F		0x10000000
#define AD_ALPHA_C_SHIFT	25
#define AD_BLUE_C_SHIFT		23
#define AD_GREEN_C_SHIFT	21
#define AD_RED_C_SHIFT		19
#define AD_PIXEL_S_SHIFT	16
#define AD_COMP_3_SHIFT		12
#define AD_COMP_2_SHIFT		8
#define AD_COMP_1_SHIFT		4
#define AD_COMP_0_SHIFT		0
