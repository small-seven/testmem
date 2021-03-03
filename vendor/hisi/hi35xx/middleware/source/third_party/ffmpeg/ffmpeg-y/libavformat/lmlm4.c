#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define LMLM4_I_FRAME   0x00
#define LMLM4_P_FRAME   0x01
#define LMLM4_B_FRAME   0x02
#define LMLM4_INVALID   0x03
#define LMLM4_MPEG1L2   0x04
#define LMLM4_MAX_PACKET_SIZE   1024 * 1024
