#include "imagetool.h"
#include "mkimage.h"
#include "zynqmpimage.h"
#include <elf.h>
#include <image.h>
#define NEXT_CHAR(str, chr) ({		\
