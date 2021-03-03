#define FSG_VENDOR_ID	0x0525	/* NetChip */
#define FSG_PRODUCT_ID	0xa4a5	/* Linux-USB File-backed Storage Gadget */
#ifndef DEBUG
#undef VERBOSE_DEBUG
#undef DUMP_MSGS
#endif /* !DEBUG */
#ifdef VERBOSE_DEBUG
#define VLDBG	LDBG
#else
#define VLDBG(lun, fmt, args...) do { } while (0)
#endif /* VERBOSE_DEBUG */
#define LDBG(lun, fmt, args...)   dev_dbg (&(lun)->dev, fmt, ## args)
#define LERROR(lun, fmt, args...) dev_err (&(lun)->dev, fmt, ## args)
#define LWARN(lun, fmt, args...)  dev_warn(&(lun)->dev, fmt, ## args)
#define LINFO(lun, fmt, args...)  dev_info(&(lun)->dev, fmt, ## args)
#define LDBG(lun, fmt, args...) do { } while (0)
#define LERROR(lun, fmt, args...) do { } while (0)
#define LWARN(lun, fmt, args...) do { } while (0)
#define LINFO(lun, fmt, args...) do { } while (0)
#define DBG(d, fmt, args...)     debug(fmt , ## args)
#define VDBG(d, fmt, args...)    debug(fmt , ## args)
#define ERROR(d, fmt, args...)   do { } while (0)
#define WARNING(d, fmt, args...) do { } while (0)
#define INFO(d, fmt, args...)    do { } while (0)
#ifdef DUMP_MSGS
# define dump_msg(fsg, label, buf, length) do {                         \
#  define dump_cdb(fsg) do { } while (0)
#else
#  define dump_msg(fsg, /* const char * */ label, \
#  ifdef VERBOSE_DEBUG
#    define dump_cdb(fsg)						\
#  else
#    define dump_cdb(fsg) do { } while (0)
#  endif /* VERBOSE_DEBUG */
#endif /* DUMP_MSGS */
#define TYPE_DISK	0x00
#define TYPE_CDROM	0x05
#define USB_PR_CBI	0x00		/* Control/Bulk/Interrupt */
#define USB_PR_CB	0x01		/* Control/Bulk w/o interrupt */
#define USB_PR_BULK	0x50		/* Bulk-only */
#define USB_SC_RBC	0x01		/* Reduced Block Commands (flash) */
#define USB_SC_8020	0x02		/* SFF-8020i, MMC-2, ATAPI (CD-ROM) */
#define USB_SC_QIC	0x03		/* QIC-157 (tape) */
#define USB_SC_UFI	0x04		/* UFI (floppy) */
#define USB_SC_8070	0x05		/* SFF-8070i (removable) */
#define USB_SC_SCSI	0x06		/* Transparent SCSI */
#define USB_BULK_CB_WRAP_LEN	31
#define USB_BULK_CB_SIG		0x43425355	/* Spells out USBC */
#define USB_BULK_IN_FLAG	0x80
#define USB_BULK_CS_WRAP_LEN	13
#define USB_BULK_CS_SIG		0x53425355	/* Spells out 'USBS' */
#define USB_STATUS_PASS		0
#define USB_STATUS_FAIL		1
#define USB_STATUS_PHASE_ERROR	2
#define USB_BULK_RESET_REQUEST		0xff
#define USB_BULK_GET_MAX_LUN_REQUEST	0xfe
#define CBI_INTERRUPT_DATA_LEN		2
#define USB_CBI_ADSC_REQUEST		0x00
#define MAX_COMMAND_SIZE	16
#define SC_FORMAT_UNIT			0x04
#define SC_INQUIRY			0x12
#define SC_MODE_SELECT_6		0x15
#define SC_MODE_SELECT_10		0x55
#define SC_MODE_SENSE_6			0x1a
#define SC_MODE_SENSE_10		0x5a
#define SC_PREVENT_ALLOW_MEDIUM_REMOVAL	0x1e
#define SC_READ_6			0x08
#define SC_READ_10			0x28
#define SC_READ_12			0xa8
#define SC_READ_CAPACITY		0x25
#define SC_READ_FORMAT_CAPACITIES	0x23
#define SC_READ_HEADER			0x44
#define SC_READ_TOC			0x43
#define SC_RELEASE			0x17
#define SC_REQUEST_SENSE		0x03
#define SC_RESERVE			0x16
#define SC_SEND_DIAGNOSTIC		0x1d
#define SC_START_STOP_UNIT		0x1b
#define SC_SYNCHRONIZE_CACHE		0x35
#define SC_TEST_UNIT_READY		0x00
#define SC_VERIFY			0x2f
#define SC_WRITE_6			0x0a
#define SC_WRITE_10			0x2a
#define SC_WRITE_12			0xaa
#define SS_NO_SENSE				0
#define SS_COMMUNICATION_FAILURE		0x040800
#define SS_INVALID_COMMAND			0x052000
#define SS_INVALID_FIELD_IN_CDB			0x052400
#define SS_LOGICAL_BLOCK_ADDRESS_OUT_OF_RANGE	0x052100
#define SS_LOGICAL_UNIT_NOT_SUPPORTED		0x052500
#define SS_MEDIUM_NOT_PRESENT			0x023a00
#define SS_MEDIUM_REMOVAL_PREVENTED		0x055302
#define SS_NOT_READY_TO_READY_TRANSITION	0x062800
#define SS_RESET_OCCURRED			0x062900
#define SS_SAVING_PARAMETERS_NOT_SUPPORTED	0x053900
#define SS_UNRECOVERED_READ_ERROR		0x031100
#define SS_WRITE_ERROR				0x030c02
#define SS_WRITE_PROTECTED			0x072700
#define SK(x)		((u8) ((x) >> 16))	/* Sense Key byte, etc. */
#define ASC(x)		((u8) ((x) >> 8))
#define ASCQ(x)		((u8) (x))
#define ETOOSMALL	525
#include <usb_mass_storage.h>
#define fsg_lun_is_open(curlun)	((curlun)->filp != NULL)
#if 0
#endif
#define EP0_BUFSIZE	256
#define DELAYED_STATUS	(EP0_BUFSIZE + 999)	/* An impossibly large value */
#define FSG_NUM_BUFFERS	2
#define FSG_BUFLEN	((u32)131072)
#define FSG_MAX_LUNS	8
#ifdef FSG_BUFFHD_STATIC_BUFFER
#else
#endif
#ifndef FSG_NO_DEVICE_STRINGS
#endif
#ifndef FSG_NO_OTG
#endif
#ifndef FSG_NO_INTR_EP
#ifndef FSG_NO_OTG
#  define FSG_FS_FUNCTION_PRE_EP_ENTRIES	2
#else
#  define FSG_FS_FUNCTION_PRE_EP_ENTRIES	1
#endif
#endif
#ifndef FSG_NO_OTG
#endif
#ifndef FSG_NO_INTR_EP
#endif
#ifndef FSG_NO_INTR_EP
#ifndef FSG_NO_OTG
#  define FSG_HS_FUNCTION_PRE_EP_ENTRIES	2
#else
#  define FSG_HS_FUNCTION_PRE_EP_ENTRIES	1
#endif
#endif
#ifndef FSG_NO_OTG
#endif
#ifndef FSG_NO_INTR_EP
#endif
#ifndef FSG_NO_DEVICE_STRINGS
#endif
