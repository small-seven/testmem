#include <common.h>
#include <dm.h>
#include <usb.h>
#include <dm/device-internal.h>
#define SANDBOX_NUM_PORTS	4
#if SANDBOX_NUM_PORTS > 8
#error "This code sets up an incorrect mask"
#endif
