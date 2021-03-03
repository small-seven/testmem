#include <string.h>
#include <sys/types.h>
#include "libavutil/frame.h"
#include "libavutil/mem.h"
#include "avcodec.h"
#include "mediacodec_wrapper.h"
#include "mediacodec_sw_buffer.h"
#include "mediacodecdec_common.h"
#define QCOM_TILE_WIDTH 64
#define QCOM_TILE_HEIGHT 32
#define QCOM_TILE_SIZE (QCOM_TILE_WIDTH * QCOM_TILE_HEIGHT)
#define QCOM_TILE_GROUP_SIZE (4 * QCOM_TILE_SIZE)
