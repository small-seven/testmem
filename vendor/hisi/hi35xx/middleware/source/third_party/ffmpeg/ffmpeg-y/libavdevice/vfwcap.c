#include "libavutil/internal.h"
#include "libavutil/log.h"
#include "libavutil/opt.h"
#include "libavutil/parseutils.h"
#include "libavformat/internal.h"
#include <windows.h>
#include <vfw.h>
#include "avdevice.h"
#ifndef HWND_MESSAGE
#define HWND_MESSAGE ((HWND) -3)
#endif
#define dstruct(pctx, sname, var, type) \
#ifdef DEBUG
#endif
#define OFFSET(x) offsetof(struct vfw_ctx, x)
#define DEC AV_OPT_FLAG_DECODING_PARAM
