#include "h264dec.h"
#undef MCFUNC
#if   CHROMA_IDC == 1
#   define MCFUNC(n) FUNC(n ## _420)
#elif CHROMA_IDC == 2
#   define MCFUNC(n) FUNC(n ## _422)
#elif CHROMA_IDC == 3
#   define MCFUNC(n) FUNC(n ## _444)
#endif
#undef  mc_part
#define mc_part MCFUNC(mc_part)
