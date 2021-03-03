#include "avcodec.h"
#include "get_bits.h"
#include "internal.h"
#define FRAME_HEADER_SIZE 64
#define MAGIC_0         0x19    /**< First header byte */
#define MAGIC_1         0x68    /**< Second header byte */
#define SUBSAMPLE_420      0
#define SUBSAMPLE_422      1
#define YUVORDER_YUYV      0
#define YUVORDER_UYVY      1
#define NOT_COMPRESSED     0
#define COMPRESSED         1
#define NO_DECIMATION      0
#define DECIMATION_ENAB    1
#define EOL             0xfd    /**< End Of Line marker */
#define EOI             0xff    /**< End Of Image marker */
typedef struct {
    AVFrame *frame;
} CpiaContext;
