#include "libavutil/intreadwrite.h"
#include "libavcodec/dirac.h"
#include "libavcodec/get_bits.h"
#include "libavcodec/golomb.h"
#include "avformat.h"
#include "rtpenc.h"
#define RTP_VC2HQ_PL_HEADER_SIZE             4
#define DIRAC_DATA_UNIT_HEADER_SIZE          13
#define DIRAC_PIC_NR_SIZE                    4
#define DIRAC_RTP_PCODE_HQ_PIC_FRAGMENT      0xEC
