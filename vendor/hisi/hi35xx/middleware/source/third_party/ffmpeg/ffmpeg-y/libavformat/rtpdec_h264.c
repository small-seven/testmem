#include "libavutil/attributes.h"
#include "libavutil/base64.h"
#include "libavutil/intreadwrite.h"
#include "libavutil/avstring.h"
#include "avformat.h"
#include "rtpdec.h"
#include "rtpdec_formats.h"
#ifdef DEBUG
#endif
#ifdef DEBUG
#define COUNT_NAL_TYPE(data, nal) data->packet_types_received[(nal) & 0x1f]++
#define NAL_COUNTERS data->packet_types_received
#else
#define COUNT_NAL_TYPE(data, nal) do { } while (0)
#define NAL_COUNTERS NULL
#endif
#define NAL_MASK 0x1f
#ifdef DEBUG
#endif
