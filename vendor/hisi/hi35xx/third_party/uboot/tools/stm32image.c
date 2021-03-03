#include <image.h>
#include "imagetool.h"
#define HEADER_MAGIC be32_to_cpu(0x53544D32)
#define VER_MAJOR_IDX	2
#define VER_MINOR_IDX	1
#define VER_VARIANT_IDX	0
#define HEADER_VERSION_V1	0x1
#define HEADER_DEFAULT_OPTION	(cpu_to_le32(0x00000001))
#define HEADER_TYPE_UBOOT	(cpu_to_le32(0x00000000))
