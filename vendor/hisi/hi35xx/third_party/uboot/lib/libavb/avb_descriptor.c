#include "avb_descriptor.h"
#include "avb_util.h"
#include "avb_vbmeta_image.h"
typedef struct {
  size_t descriptor_number;
  const AvbDescriptor** descriptors;
} SetDescriptorData;
