#include "avcodec.h"
#include "get_bits.h"
#include "golomb.h"
#include "h264chroma.h"
#include "idctdsp.h"
#include "internal.h"
#include "mathops.h"
#include "qpeldsp.h"
#include "cavs.h"
#define SET_PARAMS                                                \
#undef SET_PARAMS
#define LOWPASS(ARRAY, INDEX)                                           \
#undef LOWPASS
