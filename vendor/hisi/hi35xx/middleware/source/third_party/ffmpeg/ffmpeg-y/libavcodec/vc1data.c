#include "avcodec.h"
#include "vc1.h"
#include "vc1data.h"
#define VC1_BFRACTION_VLC_BITS 7
#define VC1_IMODE_VLC_BITS 4
#define VC1_NORM2_VLC_BITS 3
#define VC1_NORM6_VLC_BITS 9
#define VC1_TTMB_VLC_BITS 9 //12
#define VC1_MV_DIFF_VLC_BITS 9 //15
#define VC1_CBPCY_P_VLC_BITS 9 //14
#define VC1_ICBPCY_VLC_BITS 9
#define VC1_4MV_BLOCK_PATTERN_VLC_BITS 6
#define VC1_2MV_BLOCK_PATTERN_VLC_BITS 3
#define VC1_TTBLK_VLC_BITS 5
#define VC1_SUBBLKPAT_VLC_BITS 6
#define VC1_INTFR_4MV_MBMODE_VLC_BITS 9
#define VC1_INTFR_NON4MV_MBMODE_VLC_BITS 6
#define VC1_IF_MMV_MBMODE_VLC_BITS 5
#define VC1_IF_1MV_MBMODE_VLC_BITS 5
#define VC1_1REF_MVDATA_VLC_BITS 9
#define VC1_2REF_MVDATA_VLC_BITS 9
#define VC1_IF_MBMODE_VLC_BITS 5    // as a placeholder for VC1_IF_MMV_MBMODE_VLC_BITS
#if B_FRACTION_DEN == 840 // original bfraction from vc9data.h, not conforming to standard
#else
#endif
