#include <hi_types_base.h>
#include <hi_time.h>
#include <hi_i2c.h>
#include "es8311_codec.h"
#define CODEC_DEBUG
#ifdef CODEC_DEBUG
#define codec_print(ftm...) do { printf(ftm); printf("\r\n"); } while (0);
#else
#define codec_print(ftm...)
#endif
