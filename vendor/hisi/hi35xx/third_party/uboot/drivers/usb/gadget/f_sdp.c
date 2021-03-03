#include <errno.h>
#include <common.h>
#include <console.h>
#include <env.h>
#include <malloc.h>
#include <linux/usb/ch9.h>
#include <linux/usb/gadget.h>
#include <linux/usb/composite.h>
#include <asm/io.h>
#include <g_dnl.h>
#include <sdp.h>
#include <spl.h>
#include <image.h>
#include <imximage.h>
#include <watchdog.h>
#define HID_REPORT_ID_MASK	0x000000ff
#define HID_REQ_GET_REPORT		0x01
#define HID_REQ_GET_IDLE		0x02
#define HID_REQ_GET_PROTOCOL		0x03
#define HID_REQ_SET_REPORT		0x09
#define HID_REQ_SET_IDLE		0x0A
#define HID_REQ_SET_PROTOCOL		0x0B
#define HID_USAGE_PAGE_LEN		76
#define SDP_READ_REGISTER	0x0101
#define SDP_WRITE_REGISTER	0x0202
#define SDP_WRITE_FILE		0x0404
#define SDP_ERROR_STATUS	0x0505
#define SDP_DCD_WRITE		0x0a0a
#define SDP_JUMP_ADDRESS	0x0b0b
#define SDP_SKIP_DCD_HEADER	0x0c0c
#define SDP_SECURITY_CLOSED		0x12343412
#define SDP_SECURITY_OPEN		0x56787856
#define SDP_WRITE_FILE_COMPLETE		0x88888888
#define SDP_WRITE_REGISTER_COMPLETE	0x128A8A12
#define SDP_SKIP_DCD_HEADER_COMPLETE	0x900DD009
#define SDP_ERROR_IMXHEADER		0x000a0533
#define SDP_COMMAND_LEN		16
#ifndef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_SPL_LOAD_FIT
#endif
#endif
#ifdef CONFIG_SPL_BUILD
#ifdef CONFIG_SPL_LOAD_FIT
#endif
#else
#endif
#ifndef CONFIG_SPL_BUILD
#else
#endif
#ifdef CONFIG_SPL_BUILD
#endif
#ifdef CONFIG_SPL_BUILD
#else
#endif
