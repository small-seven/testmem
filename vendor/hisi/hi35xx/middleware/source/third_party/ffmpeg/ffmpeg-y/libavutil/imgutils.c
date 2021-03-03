#include "avassert.h"
#include "common.h"
#include "imgutils.h"
#include "imgutils_internal.h"
#include "internal.h"
#include "intreadwrite.h"
#include "log.h"
#include "mathematics.h"
#include "pixdesc.h"
#include "rational.h"
typedef struct ImgUtils {
    const AVClass *class;
    int   log_offset;
    void *log_ctx;
} ImgUtils;
#if ARCH_X86
#endif
#define MAX_BLOCK_SIZE 32
