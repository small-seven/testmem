#include <stdint.h>
#include "libavutil/error.h"
#include "libavutil/ffmath.h"
#include "opus_celt.h"
#include "opustab.h"
#include "internal.h"
#include "vorbis.h"
#define NORMC(bits) ((bits) << (f->channels - 1) << f->size >> 2)
