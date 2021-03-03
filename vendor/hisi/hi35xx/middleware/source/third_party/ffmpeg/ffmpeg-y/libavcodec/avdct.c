#include "avcodec.h"
#include "idctdsp.h"
#include "fdctdsp.h"
#include "pixblockdsp.h"
#include "avdct.h"
#define OFFSET(x) offsetof(AVDCT,x)
#define DEFAULT 0 //should be NAN but it does not work as it is not a constant in glibc as required by ANSI/ISO C
#define V AV_OPT_FLAG_VIDEO_PARAM
#define A AV_OPT_FLAG_AUDIO_PARAM
#define E AV_OPT_FLAG_ENCODING_PARAM
#define D AV_OPT_FLAG_DECODING_PARAM
#define COPY(src, name) memcpy(&dsp->name, &src.name, sizeof(dsp->name))
#if CONFIG_IDCTDSP
#endif
#if CONFIG_FDCTDSP
#endif
#if CONFIG_PIXBLOCKDSP
#endif
