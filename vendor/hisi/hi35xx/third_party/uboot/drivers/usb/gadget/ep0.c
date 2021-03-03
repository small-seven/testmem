#include <common.h>
#include <serial.h>
#include <usbdevice.h>
#if 0
#define dbg_ep0(lvl,fmt,args...) serial_printf("[%s] %s:%d: "fmt"\n",__FILE__,__FUNCTION__,__LINE__,##args)
#else
#define dbg_ep0(lvl,fmt,args...)
#endif
#if 0
#endif
#if 0
#endif
#if defined(CONFIG_USBD_HS)
#else
#endif
