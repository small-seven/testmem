#include <common.h>
#include <command.h>
#include <net.h>
#if !defined(CONFIG_UPDATE_TFTP)
#error "CONFIG_UPDATE_TFTP required"
#endif
