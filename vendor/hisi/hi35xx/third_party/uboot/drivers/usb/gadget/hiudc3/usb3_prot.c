#include "usb3.h"
#include "usb3_drv.h"
#include "usb3_pcd.h"
#include "usb3_prot.h"
#include "onchiprom.h"
#include <common.h>
#include <linux/string.h>
#define USTART  0xFA
#define UHEAD   0xFE
#define UDATA   0xDA
#define UTAIL   0xED
#define UCMD    0XAB
#define UREQ    0XFB
typedef int (*USB3_HANDLE_REQUEST)(uint8_t * const buff, unsigned int * bufflen);
USB3_HANDLE_REQUEST handle_request = NULL;
void SetUSB3CallBackFunc(USB3_HANDLE_REQUEST func)
{
	handle_request = func;
}
#if 0
#endif
