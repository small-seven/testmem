#include <stdint.h>
#include "libavutil/crc.h"
#include "libavutil/intreadwrite.h"
#include "mlp.h"
#if CONFIG_SMALL
#define CRC_TABLE_SIZE 257
#else
#define CRC_TABLE_SIZE 1024
#endif
