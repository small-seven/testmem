#include <common.h>
#include <malloc.h>
#include <post.h>
#include <flash.h>
#if CONFIG_POST & CONFIG_SYS_POST_FLASH
#ifndef CONFIG_SYS_POST_FLASH_NUM
# define CONFIG_SYS_POST_FLASH_NUM 0
#endif
#if CONFIG_SYS_POST_FLASH_START >= CONFIG_SYS_POST_FLASH_END
# error "invalid flash block start/end"
#endif
#endif
