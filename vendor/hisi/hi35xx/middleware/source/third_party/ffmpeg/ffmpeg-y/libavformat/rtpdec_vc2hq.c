#include "libavutil/intreadwrite.h"
#include "libavcodec/dirac.h"
#include "avio_internal.h"
#include "rtpdec_formats.h"
#define RTP_VC2HQ_PL_HEADER_SIZE             4
#define DIRAC_DATA_UNIT_HEADER_SIZE          13
#define DIRAC_PIC_NR_SIZE                    4
#define DIRAC_RTP_PCODE_HQ_PIC_FRAGMENT      0xEC
