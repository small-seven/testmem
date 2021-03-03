#include "libavutil/libm.h"
#include "aacenc.h"
#include "aacenc_tns.h"
#include "aactab.h"
#include "aacenc_utils.h"
#include "aacenc_quantization.h"
#define TNS_Q_BITS 4
#define TNS_Q_BITS_IS8 4
#define TNS_ENABLE_COEF_COMPRESSION
#define TNS_GAIN_THRESHOLD_LOW      1.4f
#define TNS_GAIN_THRESHOLD_HIGH     1.16f*TNS_GAIN_THRESHOLD_LOW
#ifndef TNS_ENABLE_COEF_COMPRESSION
#endif /* TNS_ENABLE_COEF_COMPRESSION */
