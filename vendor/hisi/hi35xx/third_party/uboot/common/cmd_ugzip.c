#include <common.h>
#define HEAD_SIZE   0X10
#define COMPRESSED_SIZE_OFFSET      0X0
#define HEAD_MAGIC_NUM0 0X70697A67/*'g''z''i''p'*/
#define HEAD_MAGIC_NUM0_OFFSET 0X8
#define HEAD_MAGIC_NUM1 0X64616568/*'h''e''a''d'*/
#define HEAD_MAGIC_NUM1_OFFSET 0XC
#if (defined CONFIG_TARGET_HI3559AV100) || (defined CONFIG_HI3559AV100) || \
#endif
#if ((defined CONFIG_TARGET_HI3559V200) || (defined CONFIG_TARGET_HI3556V200) || \
#endif
#if (defined CONFIG_TARGET_HI3559AV100) || (defined CONFIG_HI3559AV100) || \
#endif
#if ((defined CONFIG_TARGET_HI3559V200) || (defined CONFIG_TARGET_HI3556V200) || \
#endif
