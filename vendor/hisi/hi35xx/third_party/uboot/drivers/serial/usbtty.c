#include <common.h>
#include <config.h>
#include <circbuf.h>
#include <env.h>
#include <serial.h>
#include <stdio_dev.h>
#include <asm/unaligned.h>
#include "usbtty.h"
#include "usb_cdc_acm.h"
#include "usbdescriptors.h"
#ifdef DEBUG
#define TTYDBG(fmt,args...)\
#else
#define TTYDBG(fmt,args...) do{}while(0)
#endif
#if 1
#define TTYERR(fmt,args...)\
#else
#define TTYERR(fmt,args...) do{}while(0)
#endif
#define NUM_CONFIGS    1
#define MAX_INTERFACES 2
#define NUM_ENDPOINTS  3
#define ACM_TX_ENDPOINT 3
#define ACM_RX_ENDPOINT 2
#define GSERIAL_TX_ENDPOINT 2
#define GSERIAL_RX_ENDPOINT 1
#define NUM_ACM_INTERFACES 2
#define NUM_GSERIAL_INTERFACES 1
#define CONFIG_USBD_DATA_INTERFACE_STR "Bulk Data Interface"
#define CONFIG_USBD_CTRL_INTERFACE_STR "Control Interface"
#define USBTTY_BUFFER_SIZE 2048
#if defined(CONFIG_USBD_HS)
#endif
#define init_wMaxPacketSize(x)	le16_to_cpu(get_unaligned(\
#if defined(CONFIG_USBD_HS)
#endif
#if defined(CONFIG_USBD_HS)
#endif
#if defined(CONFIG_USBD_HS)
#endif
#if defined(CONFIG_USBD_HS)
#endif
#if defined(CONFIG_USBD_HS)
#endif
