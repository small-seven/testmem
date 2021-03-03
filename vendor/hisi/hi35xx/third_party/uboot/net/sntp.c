#include <common.h>
#include <command.h>
#include <dm.h>
#include <net.h>
#include <rtc.h>
#include "sntp.h"
#define SNTP_TIMEOUT 10000UL
#ifdef CONFIG_TIMESTAMP
#endif
#ifdef CONFIG_TIMESTAMP
#if defined(CONFIG_CMD_DATE)
#  ifdef CONFIG_DM_RTC
#  else
#  endif
#endif
#endif
