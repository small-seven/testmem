#undef _GNU_SOURCE
#define _XOPEN_SOURCE 600 /* XSI-compliant version of strerror_r */
#include "avutil.h"
#include "avstring.h"
#include "common.h"
#define ERROR_TAG(tag) AVERROR_##tag, #tag
#define EERROR_TAG(tag) AVERROR(tag), #tag
#define AVERROR_INPUT_AND_OUTPUT_CHANGED (AVERROR_INPUT_CHANGED | AVERROR_OUTPUT_CHANGED)
#if !HAVE_STRERROR_R
#endif
#if HAVE_STRERROR_R
#else
#endif
