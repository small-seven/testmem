#include "libavutil/intreadwrite.h"
#include "libavutil/imgutils.h"
#include "bytestream.h"
#include "avcodec.h"
#include "internal.h"
#include "texturedsp.h"
#define TXD_DXT1 0x31545844
#define TXD_DXT3 0x33545844
