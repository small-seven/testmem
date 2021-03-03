#include "dirac_vlc.h"
#define LUT_SIZE   (1 << LUT_BITS)
#define RSIZE_BITS (CHAR_BIT*sizeof(residual))
#define CONVERT_TO_RESIDUE(a, b)                                               \
#define INIT_RESIDUE(N)                                                        \
#define SET_RESIDUE(N, I, B)                                                   \
#define APPEND_RESIDUE(N, M)                                                   \
#define READ_BIT(N) (((N) >> (N ## _count--)) & 1)
