#include "ff.h"
#if FF_USE_LFN	/* This module will be blanked at non-LFN configuration */
#if FF_DEFINED != 86604	/* Revision ID */
#error Wrong include file (ff.h).
#endif
#define MERGE2(a, b) a ## b
#define CVTBL(tbl, cp) MERGE2(tbl, cp)
#if FF_CODE_PAGE == 932 || FF_CODE_PAGE == 0	/* Japanese */
#endif
#if FF_CODE_PAGE == 936 || FF_CODE_PAGE == 0	/* Simplified Chinese */
#endif
#if FF_CODE_PAGE == 949 || FF_CODE_PAGE == 0	/* Korean */
#endif
#if FF_CODE_PAGE == 950 || FF_CODE_PAGE == 0	/* Traditional Chinese */
#endif
#if FF_CODE_PAGE == 437 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 720 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 737 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 771 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 775 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 850 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 852 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 855 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 857 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 860 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 861 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 862 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 863 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 864 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 865 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 866 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE == 869 || FF_CODE_PAGE == 0
#endif
#if FF_CODE_PAGE != 0 && FF_CODE_PAGE < 900
#endif
#if FF_CODE_PAGE >= 900
#endif
#if FF_CODE_PAGE == 0
#endif
#endif /* #if FF_USE_LFN */
