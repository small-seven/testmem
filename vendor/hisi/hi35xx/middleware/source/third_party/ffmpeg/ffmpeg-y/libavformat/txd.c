#include "libavutil/intreadwrite.h"
#include "avformat.h"
#include "internal.h"
#define TXD_FILE            0x16
#define TXD_INFO            0x01
#define TXD_EXTRA           0x03
#define TXD_TEXTURE         0x15
#define TXD_TEXTURE_DATA    0x01
#define TXD_MARKER          0x1803ffff
#define TXD_MARKER2         0x1003ffff
