#include "libavcodec/internal.h"
#include "libavcodec/mathops.h"
#include "avcodec.h"
#include "dsd.h"
#define DSD_SILENCE 0x69
#define DSD_DECODER(id_, name_, long_name_) \
