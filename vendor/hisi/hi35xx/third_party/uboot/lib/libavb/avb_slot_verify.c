#include "avb_slot_verify.h"
#include "avb_chain_partition_descriptor.h"
#include "avb_cmdline.h"
#include "avb_footer.h"
#include "avb_hash_descriptor.h"
#include "avb_hashtree_descriptor.h"
#include "avb_kernel_cmdline_descriptor.h"
#include "avb_sha.h"
#include "avb_util.h"
#include "avb_vbmeta_image.h"
#include "avb_version.h"
#define MAX_NUMBER_OF_LOADED_PARTITIONS 32
#define MAX_NUMBER_OF_VBMETA_IMAGES 32
#define VBMETA_MAX_SIZE (64 * 1024)
