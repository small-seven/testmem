#include "implementation/global_implementation.h"
#undef USB_DEBUG_VAR
#define USB_DEBUG_VAR   usb_proc_debug
#ifdef LOSCFG_USB_DEBUG
#endif
usb_proc_create(struct usb_process *up, struct mtx *p_mtx,
    const char *pmesg, uint8_t prio)
{
	uint32_t ret;
	pthread_t td = 0;
	up->up_mtx = p_mtx;
	up->up_prio = prio;

	TAILQ_INIT(&up->up_qhead);

	cv_init(&up->up_cv, "-");
	cv_init(&up->up_drain, "usbdrain");

	ret = usb_os_task_creat(&td, (TSK_ENTRY_FUNC)usb_process_thread, prio, pmesg, (UINTPTR)up);
	if (ret != LOS_OK) {
		DPRINTFN(0, "Unable to create USB process.");
		up->up_ptr = NULL;
		goto error;
	}
	up->up_ptr = (struct thread *)(UINTPTR)td;
	return (0);

error:
	usb_proc_free(up);
	return (ENOMEM);
}
usb_proc_free(struct usb_process *up)
{
	/* check if not initialised */
	if (up->up_mtx == NULL)
		return;

	usb_proc_drain(up);

	cv_destroy(&up->up_cv);
	cv_destroy(&up->up_drain);

	/* make sure that we do not enter here again */
	up->up_mtx = NULL;
}
#undef USB_DEBUG_VAR
