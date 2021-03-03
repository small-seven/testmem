#include "imagetool.h"
#include <image.h>
#include "imximage.h"
#include "compiler.h"
#define ROM_V1 1
#define ROM_V2 2
#define CSF_SIZE 0x2000
#define HDMI_IVT_ID 0
#define IMAGE_IVT_ID 1
#define HDMI_FW_SIZE		0x17000 /* Use Last 0x1000 for IVT and CSF */
#define ALIGN_SIZE		0x1000
#define ALIGN(x,a)	__ALIGN_MASK((x), (__typeof__(x))(a) - 1, a)
#define __ALIGN_MASK(x,mask,mask2) (((x) + (mask)) / (mask2) * (mask2))
