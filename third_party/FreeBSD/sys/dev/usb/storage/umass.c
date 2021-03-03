#include <sys/cdefs.h>
#include <driver.h>
#include <disk.h>
#include "implementation/global_implementation.h"
#include "scsi_all.h"
#include "scsi.h"
#include "umass_fs.h"
#if USB_HAVE_DEVICE_TOPOLOGY
#include "implementation/usb_btree.h"
#endif
#include "user_copy.h"
#ifdef LOSCFG_USB_DEBUG
#define	DIF(m, x)				\
#define	DPRINTF_UMASS(sc, m, fmt, ...)			\
#define	UDMASS_GEN	0x00010000	/* general */
#define	UDMASS_SCSI	0x00020000	/* scsi */
#define	UDMASS_UFI	0x00040000	/* ufi command set */
#define	UDMASS_ATAPI	0x00080000	/* 8070i command set */
#define	UDMASS_CMD	(UDMASS_SCSI|UDMASS_UFI|UDMASS_ATAPI)
#define	UDMASS_USB	0x00100000	/* USB general */
#define	UDMASS_BBB	0x00200000	/* Bulk-Only transfers */
#define	UDMASS_CBI	0x00400000	/* CBI transfers */
#define	UDMASS_WIRE	(UDMASS_BBB|UDMASS_CBI)
#define	UDMASS_ALL	0xffff0000	/* all of the above */
#else
#define	DIF(...) do { } while (0)
#define	DPRINTF_UMASS(...) do { } while (0)
#endif
#define	UMASS_BULK_SIZE (1 << 17)
#define	UMASS_CBI_DIAGNOSTIC_CMDLEN 12	/* bytes */
#define	UMASS_MAX_CMDLEN MAX(12, CBWCDBLENGTH)	/* bytes */
#define	UMASS_T_BBB_RESET1		0	/* Bulk-Only */
#define	UMASS_T_BBB_RESET2		1
#define	UMASS_T_BBB_RESET3		2
#define	UMASS_T_BBB_COMMAND		3
#define	UMASS_T_BBB_DATA_READ	4
#define	UMASS_T_BBB_DATA_RD_CS	5
#define	UMASS_T_BBB_DATA_WRITE	6
#define	UMASS_T_BBB_DATA_WR_CS	7
#define	UMASS_T_BBB_STATUS		8
#define	UMASS_T_BBB_MAX			9
#define	UMASS_T_CBI_RESET1		0	/* CBI */
#define	UMASS_T_CBI_RESET2		1
#define	UMASS_T_CBI_RESET3		2
#define	UMASS_T_CBI_COMMAND		3
#define	UMASS_T_CBI_DATA_READ	4
#define	UMASS_T_CBI_DATA_RD_CS	5
#define	UMASS_T_CBI_DATA_WRITE	6
#define	UMASS_T_CBI_DATA_WR_CS	7
#define	UMASS_T_CBI_STATUS		8
#define	UMASS_T_CBI_RESET4		9
#define	UMASS_T_CBI_MAX			10
#define	UMASS_T_MAX MAX(UMASS_T_CBI_MAX, UMASS_T_BBB_MAX)
#define	DIR_NONE	0
#define	DIR_IN		1
#define	DIR_OUT		2
#define	DEVNAME		"umass"
#define	DEVNAME_SIM	"umass-sim"
#define	UMASS_FULL_TRANSFER_SPEED	1000
#define	UMASS_HIGH_TRANSFER_SPEED	40000
#define	UMASS_SUPER_TRANSFER_SPEED	400000
#define	UMASS_FLOPPY_TRANSFER_SPEED	20
#define	UMASS_TIMEOUT			20000	/* ms */
#define	UMASS_SCSIID_MAX	1	/* maximum number of drives expected */
#define	UMASS_SCSIID_HOST	UMASS_SCSIID_MAX
#define	UR_BBB_RESET		0xff	/* Bulk-Only reset */
#define	UR_BBB_GET_MAX_LUN	0xfe	/* Get maximum lun */
typedef struct {
	uDWord	dCBWSignature;
#define	CBWSIGNATURE	0x43425355
	uDWord	dCBWTag;
	uDWord	dCBWDataTransferLength;
	uByte	bCBWFlags;
#define	CBWFLAGS_OUT	0x00
#define	CBWFLAGS_IN		0x80
	uByte	bCBWLUN;
	uByte	bCDBLength;
#define	CBWCDBLENGTH	16
	uByte	CBWCDB[CBWCDBLENGTH];
} __packed umass_bbb_cbw_t;
#define	UMASS_BBB_CBW_SIZE	31
typedef struct {
	uDWord	dCSWSignature;
#define	CSWSIGNATURE					0x53425355
#define	CSWSIGNATURE_IMAGINATION_DBX1	0x43425355
#define	CSWSIGNATURE_OLYMPUS_C1			0x55425355
	uDWord	dCSWTag;
	uDWord	dCSWDataResidue;
	uByte	bCSWStatus;
#define	CSWSTATUS_GOOD		0x0
#define	CSWSTATUS_FAILED	0x1
#define	CSWSTATUS_PHASE		0x2
} __packed umass_bbb_csw_t;
#define	UMASS_BBB_CSW_SIZE	13
#define	UR_CBI_ADSC	0x00
typedef union {
	struct {
		uint8_t	type;
#define	IDB_TYPE_CCI			0x00
		uint8_t	value;
#define	IDB_VALUE_PASS			0x00
#define	IDB_VALUE_FAIL			0x01
#define	IDB_VALUE_PHASE			0x02
#define	IDB_VALUE_PERSISTENT	0x03
#define	IDB_VALUE_STATUS_MASK	0x03
	} __packed common;
typedef void (umass_callback_t)(struct umass_softc *sc, union ccb *ccb,
		uint32_t residue, uint8_t status);

#define	STATUS_CMD_OK		0	/* everything ok */
#define	STATUS_CMD_UNKNOWN	1	/* will have to fetch sense */
#define	STATUS_CMD_FAILED	2	/* transfer was ok, command failed */
#define	STATUS_WIRE_FAILED	3	/* couldn't even get command across */

typedef uint8_t (umass_transform_t)(struct umass_softc *sc, uint8_t *cmd_ptr,
	    uint8_t cmd_len);

/* Wire and command protocol */
#define	UMASS_PROTO_BBB		0x0001	/* USB wire protocol */
#define	UMASS_PROTO_CBI		0x0002
#define	UMASS_PROTO_CBI_I	0x0004
#define	UMASS_PROTO_WIRE	0x00ff	/* USB wire protocol mask */
#define	UMASS_PROTO_SCSI	0x0100	/* command protocol */
#define	UMASS_PROTO_ATAPI	0x0200
#define	UMASS_PROTO_UFI		0x0400
#define	UMASS_PROTO_RBC		0x0800
#define	UMASS_PROTO_COMMAND	0xff00	/* command protocol mask */

/* Device specific quirks */
#define	NO_QUIRKS			0x0000
	/*
	 * The drive does not support Test Unit Ready. Convert to Start Unit
	 */
#define	NO_TEST_UNIT_READY	0x0001
	/*
	 * The drive does not reset the Unit Attention state after REQUEST
	 * SENSE has been sent. The INQUIRY command does not reset the UA
	 * either, and so CAM runs in circles trying to retrieve the initial
	 * INQUIRY data.
	 */
#define	RS_NO_CLEAR_UA		0x0002
	/* The drive does not support START STOP.  */
#define	NO_START_STOP		0x0004
	/* Don't ask for full inquiry data (255b).  */
#define	FORCE_SHORT_INQUIRY	0x0008
	/* Needs to be initialised the Shuttle way */
#define	SHUTTLE_INIT		0x0010
	/* Drive needs to be switched to alternate iface 1 */
#define	ALT_IFACE_1			0x0020
	/* Drive does not do 1Mb/s, but just floppy speeds (20kb/s) */
#define	FLOPPY_SPEED		0x0040
	/* The device can't count and gets the residue of transfers wrong */
#define	IGNORE_RESIDUE		0x0080
	/* No GetMaxLun call */
#define	NO_GETMAXLUN		0x0100
	/* The device uses a weird CSWSIGNATURE. */
#define	WRONG_CSWSIG		0x0200
	/* Device cannot handle INQUIRY so fake a generic response */
#define	NO_INQUIRY			0x0400
	/* Device cannot handle INQUIRY EVPD, return CHECK CONDITION */
#define	NO_INQUIRY_EVPD		0x0800
	/* Pad all RBC requests to 12 bytes. */
#define	RBC_PAD_TO_12		0x1000
	/*
	 * Device reports number of sectors from READ_CAPACITY, not max
	 * sector number.
	 */
#define	READ_CAPACITY_OFFBY1	0x2000
	/*
	 * Device cannot handle a SCSI synchronize cache command.  Normally
	 * this quirk would be handled in the cam layer, but for IDE bridges
	 * we need to associate the quirk with the bridge and not the
	 * underlying disk device.  This is handled by faking a success
	 * result.
	 */
#define	NO_SYNCHRONIZE_CACHE	0x4000
	/* Device does not support 'PREVENT/ALLOW MEDIUM REMOVAL'. */
#define	NO_PREVENT_ALLOW		0x8000

#if USB_HAVE_DEVICE_TOPOLOGY
extern usbd_bt_tree hub_tree;
#endif

struct umass_softc {
	union ccb *data_ccb;
	struct scsi_sense cam_scsi_sense;
	struct scsi_test_unit_ready cam_scsi_test_unit_ready;
	struct mtx sc_mtx;
	EVENT_CB_S sc_event;
	struct {
		uint8_t *data_ptr;
		union ccb *ccb;
		umass_callback_t *callback;

		uint32_t data_len;		/* bytes */
		uint32_t data_rem;		/* bytes */
		uint32_t data_timeout;	/* ms */
		uint32_t actlen;		/* bytes */

		uint8_t	cmd_data[UMASS_MAX_CMDLEN];
		uint8_t	cmd_len;		/* bytes */
		uint8_t	dir;
		uint8_t	lun;
	}	sc_transfer;
#if USB_SUPPORT_SD_HOT_PLUG
#define	umass_dev_mtx_init(id, type) (void)mtx_init(&g_umass_dev_array[id].dev_mtx, NULL, NULL, type)
#define	umass_dev_mtx_destroy(id)	 (void)mtx_destroy(&g_umass_dev_array[id].dev_mtx)
#define	umass_dev_lock(id)			 (void)mtx_lock(&g_umass_dev_array[id].dev_mtx)
#define	umass_dev_unlock(id)		 (void)mtx_unlock(&g_umass_dev_array[id].dev_mtx)
#else
#define	umass_dev_lock(id) (void)mtx_lock(NULL)
#define	umass_dev_unlock(id) (void)mtx_unlock(NULL)
#endif
#ifdef LOSCFG_USB_DEBUG
#endif
#define	UFI_COMMAND_LENGTH	12	/* UFI commands are always 12 bytes */
#define	ATAPI_COMMAND_LENGTH	12	/* ATAPI commands are always 12 bytes */
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#ifdef LOSCFG_USB_DEBUG
#endif
#define	SOFT_CACHE_SIZE 0x40
umass_detach(device_t dev)
{
	struct umass_softc *sc = (struct umass_softc *)device_get_softc(dev);
	unsigned int dev_unit = device_get_unit(dev);

	DPRINTF_UMASS(sc, UDMASS_USB, "\n");

	sc->sc_detach_status = TRUE;

	/* teardown our statemachine */
	usbd_transfer_unsetup(sc->sc_xfer, UMASS_T_MAX);

	mtx_lock(&sc->sc_mtx);

	/* cancel any leftover CCB's */
	umass_cancel_ccb(sc);

	mtx_lock(&sc->sc_umass_mtx);
	if (sc->data_ccb != NULL) {
		if (sc->data_ccb->csio.data_ptr != NULL) {
			free((void*)sc->data_ccb->csio.data_ptr);
			sc->data_ccb->csio.data_ptr = NULL;
		}
		free(sc->data_ccb);
		sc->data_ccb = NULL;
	}
	mtx_unlock(&sc->sc_umass_mtx);

	umass_detach_dev_sub(sc, dev_unit, 0);
#if USB_SUPPORT_SD_HOT_PLUG
	umass_task_check(1);
#endif

	mtx_unlock(&sc->sc_mtx);
	sc->sc_detach_status = FALSE;
	mtx_destroy(&sc->sc_mtx);
	mtx_destroy(&sc->sc_umass_mtx);

	p_umsf = NULL;
	return (0);			/* success */
}
#ifdef LOSCFG_USB_DEBUG
#endif
#define	SCSI_INQ_LEN	0x24
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
#if USB_SUPPORT_SD_HOT_PLUG
#endif
#if USB_SUPPORT_SD_HOT_PLUG
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
umass_detach_dev_sub(struct umass_softc *sc, int dev_unit, int flag)
{
	int disk_id;
	char devname[MASS_NAME]= {0};
#if USB_HAVE_DEVICE_TOPOLOGY
	struct node_info cur_info;
	struct node_info parent_info;
	device_t dev = NULL;
	struct usb_device *udev = NULL;
#endif

	umass_dev_lock(dev_unit);

#if USB_HAVE_DEVICE_TOPOLOGY
	dev = sc->sc_dev;
	udev = sc->sc_udev;
#if USB_SUPPORT_SD_HOT_PLUG
	if (umass_dev_is_attached(dev_unit))
#endif
	{
		parent_info.nameunit = device_get_nameunit(device_get_parent(dev));
		parent_info.port_no = udev->port_no;

		cur_info.nameunit = device_get_nameunit(dev);
		cur_info.port_no = udev->port_no;
		(void)usbd_remove_bt_node(hub_tree, &parent_info, &cur_info);
	}
#endif

#if USB_SUPPORT_SD_HOT_PLUG
	if (umass_dev_is_attached(dev_unit))
#endif
	{
		devunit_to_devname(dev_unit, devname);
		disk_id = los_get_diskid_byname(devname);
		(void)los_disk_deinit(disk_id);
		(void)OsClearUsbStatus(disk_id);
	}

	if (flag == 0) { /* 0: This interface is called from umass_detach, or is called elsewhere. */
#if USB_SUPPORT_SD_HOT_PLUG
		umass_dev_delete(sc, dev_unit);
#endif
	}

#if USB_HAVE_DEVICE_TOPOLOGY
	dev_quantity &= ~(1ull << (unsigned int)device_get_unit(dev));
#endif

	umass_dev_unlock(dev_unit);
}
#if USB_SUPPORT_SD_HOT_PLUG
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#else
#endif
#if USB_SUPPORT_SD_HOT_PLUG
#endif
#if USB_SUPPORT_SD_HOT_PLUG
#endif
#if USB_HAVE_DEVICE_TOPOLOGY
#endif
