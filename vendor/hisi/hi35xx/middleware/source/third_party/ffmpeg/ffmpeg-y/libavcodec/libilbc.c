#include <ilbc.h>
#include "libavutil/channel_layout.h"
#include "libavutil/common.h"
#include "libavutil/opt.h"
#include "avcodec.h"
#include "internal.h"
typedef struct ILBCDecContext {
    const AVClass *class;
    iLBC_Dec_Inst_t decoder;
    int enhance;
} ILBCDecContext;
typedef struct ILBCEncContext {
    const AVClass *class;
    iLBC_Enc_Inst_t encoder;
    int mode;
} ILBCEncContext;
