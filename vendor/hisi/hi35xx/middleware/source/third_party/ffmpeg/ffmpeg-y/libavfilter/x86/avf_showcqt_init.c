#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavfilter/avf_showcqt.h"
#define DECLARE_CQT_CALC(type) \
#define permute_coeffs_0 NULL
#define SELECT_CQT_CALC(type, TYPE, align, perm) \
