#include "yaffs_packedtags2.h"
#include "yportenv.h"
#include "yaffs_trace.h"
#define EXTRA_HEADER_INFO_FLAG	0x80000000
#define EXTRA_SHRINK_FLAG	0x40000000
#define EXTRA_SHADOWS_FLAG	0x20000000
#define EXTRA_SPARE_FLAGS	0x10000000
#define ALL_EXTRA_FLAGS		0xf0000000
#define EXTRA_OBJECT_TYPE_SHIFT (28)
#define EXTRA_OBJECT_TYPE_MASK  ((0x0f) << EXTRA_OBJECT_TYPE_SHIFT)
