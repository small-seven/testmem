#include <atomic>
#include "libavformat/internal.h"
#include <DeckLinkAPI.h>
#include "config.h"
#include "libavformat/avformat.h"
#include "libavutil/avassert.h"
#include "libavutil/avutil.h"
#include "libavutil/common.h"
#include "libavutil/imgutils.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/time.h"
#include "libavutil/mathematics.h"
#include "libavutil/reverse.h"
#include "avdevice.h"
#if CONFIG_LIBZVBI
#include <libzvbi.h>
#endif
#include "decklink_common.h"
#include "decklink_dec.h"
#define MAX_WIDTH_VANC 1920
typedef struct VANCLineNumber {
    BMDDisplayMode mode;
    int vanc_start;
    int field0_vanc_end;
    int field1_vanc_start;
    int vanc_end;
} VANCLineNumber;
static void decklink_object_free(void *opaque, uint8_t *data)
{
    IUnknown *obj = (class IUnknown *)opaque;
    obj->Release();
}
#if CONFIG_LIBZVBI
#endif
ULONG decklink_input_callback::Release(void)
{
    int ret = --_refs;
    if (!ret)
        delete this;
    return ret;
}
#if CONFIG_LIBZVBI
#endif
#if !CONFIG_LIBZVBI
#endif
