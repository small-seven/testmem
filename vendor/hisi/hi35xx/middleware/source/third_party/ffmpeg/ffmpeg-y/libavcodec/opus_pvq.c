#include "opustab.h"
#include "opus_pvq.h"
#define CELT_PVQ_U(n, k) (ff_celt_pvq_u_row[FFMIN(n, k)][FFMAX(n, k)])
#define CELT_PVQ_V(n, k) (CELT_PVQ_U(n, k) + CELT_PVQ_U(n, (k) + 1))
#if CONFIG_OPUS_DECODER
#else
#endif
#if CONFIG_OPUS_ENCODER
#else
#endif
