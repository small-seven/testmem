#include <string.h>
#include "libavutil/intreadwrite.h"
#include "libavutil/avstring.h"
#include "libavutil/opt.h"
#include "internal.h"
#include "mms.h"
#include "asf.h"
#include "http.h"
#include "url.h"
#define CHUNK_HEADER_LENGTH 4   // 2bytes chunk type and 2bytes chunk length.
#define EXT_HEADER_LENGTH   8   // 4bytes sequence, 2bytes useless and 2bytes chunk length.
#define USERAGENT  "User-Agent: NSPlayer/4.1.0.3856\r\n"
#define CLIENTGUID "Pragma: xClientGUID={c77e7400-738a-11d2-9add-0020af0a3278}\r\n"
typedef enum {
    CHUNK_TYPE_DATA          = 0x4424,
    CHUNK_TYPE_ASF_HEADER    = 0x4824,
    CHUNK_TYPE_END           = 0x4524,
    CHUNK_TYPE_STREAM_CHANGE = 0x4324,
} ChunkType;
typedef struct MMSHContext {
    MMSContext mms;
    uint8_t location[1024];
    int request_seq;  ///< request packet sequence
    int chunk_seq;    ///< data packet sequence
} MMSHContext;
