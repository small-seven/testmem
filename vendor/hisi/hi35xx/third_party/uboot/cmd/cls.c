#include <common.h>
#include <command.h>
#include <dm.h>
#include <lcd.h>
#include <video.h>
#if defined(CONFIG_DM_VIDEO)
#elif defined(CONFIG_CFB_CONSOLE)
#elif defined(CONFIG_LCD)
#else
#endif
