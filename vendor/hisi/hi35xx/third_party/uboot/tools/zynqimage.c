#include "imagetool.h"
#include "mkimage.h"
#include <image.h>
#define HEADER_INTERRUPT_DEFAULT (cpu_to_le32(0xeafffffe))
#define HEADER_REGINIT_NULL (cpu_to_le32(0xffffffff))
#define HEADER_WIDTHDETECTION (cpu_to_le32(0xaa995566))
#define HEADER_IMAGEIDENTIFIER (cpu_to_le32(0x584c4e58))
#define HEADER_INTERRUPT_VECTORS 8
#define HEADER_REGINITS 256
