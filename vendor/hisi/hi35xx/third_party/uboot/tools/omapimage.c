#include "imagetool.h"
#include <compiler.h>
#include <image.h>
#include "gpheader.h"
#include "omapimage.h"
#define DIV_ROUND_UP(n, d)     (((n) + (d) - 1) / (d))
#define OMAP_CH_HDR_SIZE 512
#define OMAP_FILE_HDR_SIZE (OMAP_CH_HDR_SIZE + GPIMAGE_HDR_SIZE)
