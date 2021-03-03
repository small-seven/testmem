#include "config.h"
#include <stdint.h>
#include <string.h>
#include <VideoToolbox/VideoToolbox.h>
#include "buffer.h"
#include "common.h"
#include "hwcontext.h"
#include "hwcontext_internal.h"
#include "hwcontext_videotoolbox.h"
#include "mem.h"
#include "pixfmt.h"
#include "pixdesc.h"
#ifdef kCFCoreFoundationVersionNumber10_7
#endif
#if HAVE_KCVPIXELFORMATTYPE_420YPCBCR10BIPLANARVIDEORANGE
#endif
