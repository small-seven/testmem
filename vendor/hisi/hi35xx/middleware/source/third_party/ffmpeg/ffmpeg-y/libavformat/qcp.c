#include "libavutil/channel_layout.h"
#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "riff.h"
typedef struct QCPContext {
    uint32_t data_size;                     ///< size of data chunk

#define QCP_MAX_MODE 4
    int16_t rates_per_mode[QCP_MAX_MODE+1]; ///< contains the packet size corresponding
                                            ///< to each mode, -1 if no size.
} QCPContext;
