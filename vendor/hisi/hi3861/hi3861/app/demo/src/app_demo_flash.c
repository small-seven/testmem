#define TEST_KERNEL_FLASH
#ifdef TEST_KERNEL_FLASH
#include <app_demo_flash.h>
#define CODE_IN_FLASH
#ifdef CODE_IN_FLASH
#else
#endif
#endif
