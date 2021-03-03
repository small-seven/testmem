#include "yaffs_guts.h"
#include "yaffs_trace.h"
#include "yaffs_yaffs2.h"
#include "yaffs_checkptrw.h"
#include "yaffs_bitmap.h"
#include "yaffs_nand.h"
#include "yaffs_getblockinfo.h"
#include "yaffs_verify.h"
#include "yaffs_attribs.h"
#include "yaffs_summary.h"
#define YAFFS_CHECKPOINT_MIN_BLOCKS 60
#define YAFFS_SMALL_HOLE_THRESHOLD 4
